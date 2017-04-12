#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "SDL\include\SDL_timer.h"

//TODO: include the maps
#include "ModuleSceneCastle.h"

ModulePlayer::ModulePlayer()
{
	// idle animation
	idle.PushBack({ 0, 0, 31, 30 });
	idle.PushBack({ 38, 0, 31, 29 });
	idle.speed = 0.05f;

	//TODO: the animations are wrong

	//idle right animation
	left_idle_animation.PushBack({ 114, 38, 21, 29 });
	left_idle_animation.PushBack({ 145, 76, 21, 29 });
	left_idle_animation.loop = true;
	left_idle_animation.speed = 0.1f;

	//idle left animation

	//dead animation
	dead_animation.PushBack({ 76, 0, 32, 38 });
	dead_animation.speed = 0.1f; // TODO: is it necessary if animation is only one frame long?
	//dead animation EXPLOSION
	dead_animation_explosion.PushBack({ 95,187,47,49});
	dead_animation_explosion.PushBack({ 72,151,35, 37});
	dead_animation_explosion.PushBack({ 88,114,31,31});
	dead_animation_explosion.speed = 0.2f;
	//right animation
	right_animation.PushBack({ 0, 38, 26, 30 });
	right_animation.PushBack({ 38, 38, 26, 29 });
	right_animation.PushBack({ 76, 38, 21, 30 });
	right_animation.PushBack({ 114, 38, 21, 29 });
	right_animation.speed = 0.2f;
	right_animation.loop = false;

	//left animation
	left_animation.PushBack({ 0, 74, 28, 33 });
	left_animation.PushBack({ 36, 74, 28, 33 });
	left_animation.PushBack({ 74, 74, 25, 33 });
	left_animation.PushBack({ 112, 74, 25, 33 });
	left_animation.speed = 0.2f;
	left_animation.loop = false;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	playerLives = 2;
	playerLost = false;
	deadPlayer = false;
	original_camera_y = App->render->camera.y;
	laserType = 0;

	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2 + 100;

	LOG("Creating player collider");
	playerCollider = App->collision->AddCollider({ position.x,position.y,31,30 }, COLLIDER_PLAYER, this);
	
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
	update_status status = UPDATE_CONTINUE;

	int speed = 3;
	

	if (!deadPlayer) {
		if ((App->sceneCastle->background_y == -SCREEN_HEIGHT && App->sceneCastle->IsEnabled())) 
		{
			speed = 5;
			position.y -= speed;
		}
		else {

			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				if (position.x < SCREEN_WIDTH - 34) // TODO: correct limits so they are all equal
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

			if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || (0 < counter))
			{
				//Old switch. Keep it it here for now
				/*switch (laserType)
				{
				case 0:
					App->particles->AddParticle(App->particles->laser0, position.x + 9, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				case 1:
					App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				case 2:
					App->particles->AddParticle(App->particles->laser2, position.x + 10, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				default:
					break;
				}
				laserType++;
				if (laserType > 2)
					laserType = 0;*/

				if (counter == 0)
				{
					App->particles->AddParticle(App->particles->laser0, position.x + 9, position.y - 40, COLLIDER_PLAYER_SHOT);
					control = false;
				}
				else if (counter == 7)
				{
					App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
				}
				else if (counter == 14)
				{
					App->particles->AddParticle(App->particles->laser2, position.x + 10, position.y - 40, COLLIDER_PLAYER_SHOT);
				}
				else if (counter == 21)
				{
					App->particles->AddParticle(App->particles->laser0, position.x + 9, position.y - 40, COLLIDER_PLAYER_SHOT);
					counter = 0;
					control = true;
				}

				if(!control)
					counter++;
			}
				
			if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_REPEAT && App->sceneCastle->IsEnabled())
			{
				deadPlayer = true;
			}
			
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
				current_animation = &idle;

		}
		App->render->camera.y = original_camera_y;
	}
	else
	{
		current_animation = &dead_animation;
		counter++;

		if (counter > 12) 
		{
			position.y += speed;
		}
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//update player collider
	playerCollider->SetPos(position.x, position.y - r.h);

	if (!App->render->Blit(graphics, position.x, position.y -r.h, &r)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (this->deadPlayer) {
		LOG("Player is dead");
		//anim dead player
		//WHEN DEATH ANIMATION IS FINISHED{
		if (playerLives < 0) {
			playerLost = true;
		}
		else {
			this->deadPlayer = false;
			this->position.x = SCREEN_WIDTH / 2;
			App->player->position.y = SCREEN_HEIGHT / 2 + 50;
			playerLives--;
			//TODO: set bombs too
			App->player->inmortal = true;

			lastTime = SDL_GetTicks();
		}
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 2000))
		App->player->inmortal = false;

	return status;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {
	if (!inmortal) {
		if (c2->type == COLLIDER_ENEMY)
			deadPlayer = true;
		if (deadPlayer == true) {
			App->particles->AddParticle(App->particles->balloonDeathExplosion, (c1->rect.x - ((101 - (c1->rect.w)) / 2)), (c1->rect.y - ((107 - (c1->rect.h)) / 2)));
		}
	}
}