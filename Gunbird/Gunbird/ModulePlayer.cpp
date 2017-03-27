#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSea.h"

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 100;

	// idle animation
	idle.PushBack({ 0, 0, 31, 30 });
	idle.PushBack({ 38, 0, 31, 29 });
	idle.speed = 0.05f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/characters/valnus_spritesheet.png");
	if (graphics == nullptr)
		ret = false;
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 3;

	if (App->sceneSea->background_y == -SCREEN_HEIGHT) {
		speed = 5;
		position.y -= speed;
	}
	else {
		if (App->input->keyboard[SDL_SCANCODE_D] == 1)
		{
			if (position.x < SCREEN_WIDTH - 34)
				position.x += speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == 1)
		{
			if (position.x > 3)
				position.x -= speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		{
			if (position.y > 34)
				position.y -= speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == 1)
		{
			if (position.y <  SCREEN_HEIGHT - 3)
				position.y += speed;
		}
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}