#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

//TODO: include the maps
#include "ModuleSceneCastle.h"
#include "ModuleSceneMine.h"

ModulePlayer::ModulePlayer()
{
	// idle animation
	idle.PushBack({ 0, 0, 31, 30 });
	idle.PushBack({ 38, 0, 31, 29 });
	idle.speed = 0.05f;

	//right animation
	right_animation.PushBack({ 0, 38, 26, 30 });
	right_animation.PushBack({ 38, 38, 26, 29 });
	right_animation.PushBack({ 76, 38, 21, 30 });
	right_animation.PushBack({ 114, 38, 21, 29 });
	right_animation.speed = 1.0f;

	//left animation
	left_animation.PushBack({ 0, 74, 28, 33 });
	left_animation.PushBack({ 36, 74, 28, 33 });
	left_animation.PushBack({ 74, 74, 25, 33 });
	left_animation.PushBack({ 112, 74, 25, 33 });
	left_animation.speed = 1.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	laserType = 0;

	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;
	
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/characters/valnus_spritesheet.png");
	if (graphics == nullptr)
		ret = false;

	LOG("Loading player effects");
	laserShot1_2 = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	update_status status = UPDATE_CONTINUE;

	Animation* current_animation = &idle;

	int speed = 3;

	if ((App->sceneCastle->background_y == -SCREEN_HEIGHT && App->sceneCastle->IsEnabled()) || App->sceneMine->background_y == -SCREEN_HEIGHT && App->sceneMine->IsEnabled()) {
		speed = 5;
		position.y -= speed;
	}
	else {

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			if (position.x < SCREEN_WIDTH - 34)
				position.x += speed;
			if (current_animation != &right_animation)
			{
				current_animation = &right_animation;
				right_animation.Reset();
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
			if (position.x > 3)
				position.x -= speed;
			if (current_animation != &left_animation)
			{
				left_animation.Reset();
				current_animation = &left_animation;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			if (position.y > 34)
				position.y -= speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			if (position.y <  SCREEN_HEIGHT - 3)
				position.y += speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		{
			switch (laserType)
			{
			case 0:
				App->particles->AddParticle(App->particles->laser0, position.x + 9, position.y - 40);
				break;
			case 1:
				App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40);
				break;
			case 2:
				App->particles->AddParticle(App->particles->laser2, position.x + 10, position.y - 40);
				break;
			default:
				break;
			}
			laserType++;
			if (laserType > 2)
				laserType = 0;
			if (!App->audio->PlayFx(laserShot1_2)) {
				LOG("Error playing fx sound in Player Module");
				status = UPDATE_ERROR;
			}
		}
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	if (!App->render->Blit(graphics, position.x, position.y - r.h, &r)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	return status;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->audio->UnLoadFx(laserShot1_2);

	return true;
}