#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL_timer.h"

#include "ModuleEnemies.h"

//TODO: include the maps
#include "ModuleSceneCastle.h"

ModulePlayer2::ModulePlayer2()
{
	//godMode
	godMode.PushBack({ 152,0,31,29 });
	godMode.loop = true;

	// idle animation
	idle.PushBack({ 47, 446, 31, 30 });
	idle.PushBack({ 85, 446, 31, 30 });
	idle.speed = 0.05f;


	//idle right animation
	left_idle_animation.PushBack({ 114, 38, 21, 29 });
	left_idle_animation.PushBack({ 145, 76, 21, 29 });
	left_idle_animation.loop = true;
	left_idle_animation.speed = 0.1f;

	//idle left animation

	//dead animation
	dead_animation.PushBack({ 123, 446, 32, 38 });
	dead_animation.speed = 0.1f; // TODO: is it necessary if animation is only one frame long?
								 //dead animation EXPLOSION
	dead_animation_explosion.PushBack({ 95,187,47,49 });
	dead_animation_explosion.PushBack({ 72,151,35, 37 });
	dead_animation_explosion.PushBack({ 88,114,31,31 });
	dead_animation_explosion.speed = 0.2f;
	//right animation
	right_animation.PushBack({ 47, 484, 26, 30 });
	right_animation.PushBack({ 85, 484, 26, 29 });
	right_animation.PushBack({ 123, 484, 21, 30 });
	right_animation.PushBack({ 161, 484, 21, 29 });
	right_animation.speed = 0.2f;
	right_animation.loop = false;

	//left animation
	left_animation.PushBack({ 47, 522, 26, 30 });
	left_animation.PushBack({ 85, 522, 26, 29 });
	left_animation.PushBack({ 123, 522, 21, 30 });
	left_animation.PushBack({ 161, 522, 21, 29 });
	left_animation.speed = 0.2f;
	left_animation.loop = false;

	//Blink animation
	blink.PushBack({ 47,446,31,30 });
	blink.PushBack({ 876,243,31,30 });
	blink.PushBack({ 85, 446, 31, 29 });
	blink.speed = 0.5f;
	blink.loop = true;

	//Colision Animation
	{
		player2Collision_Anim.PushBack({ 57, 672, 26, 30 });
		player2Collision_Anim.PushBack({ 99, 672, 31, 30 });
		player2Collision_Anim.PushBack({ 145, 672, 26, 29 });
		player2Collision_Anim.PushBack({ 187, 672, 25, 30 });
		player2Collision_Anim.PushBack({ 231, 670, 31, 32 });
		player2Collision_Anim.PushBack({ 280, 670, 31, 32 });
		player2Collision_Anim.PushBack({ 327, 671, 29, 30 });
		player2Collision_Anim.PushBack({ 371, 672, 31, 32 });
		player2Collision_Anim.PushBack({ 415, 71, 29, 30 });
		player2Collision_Anim.PushBack({ 459, 671, 31, 31 });
		player2Collision_Anim.PushBack({ 506, 613, 31, 32 });
		player2Collision_Anim.PushBack({ 56, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 97, 719, 31, 32 });
		player2Collision_Anim.PushBack({ 141, 719, 31, 32 });
		player2Collision_Anim.PushBack({ 190, 719, 31, 32 });
		player2Collision_Anim.PushBack({ 237, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 326, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 374, 721, 31, 32 });
		player2Collision_Anim.PushBack({ 417, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 462, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 503, 720, 31, 32 });
		player2Collision_Anim.PushBack({ 57, 769, 31, 32 });
		player2Collision_Anim.PushBack({ 142, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 187, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 238, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 281, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 328, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 374, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 422, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 469, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 509, 770, 31, 32 });
		player2Collision_Anim.PushBack({ 55, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 96, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 144, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 189, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 234, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 281, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 328, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 375, 817, 31, 32 });
		player2Collision_Anim.PushBack({ 420, 815, 31, 32 });
		player2Collision_Anim.PushBack({ 467, 815, 31, 32 });
		player2Collision_Anim.PushBack({ 510, 815, 31, 32 });
		player2Collision_Anim.PushBack({ 57, 868, 31, 32 });
		player2Collision_Anim.PushBack({ 92, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 140, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 188, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 235, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 278, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 326, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 422, 869, 31, 32 });
		player2Collision_Anim.PushBack({ 463, 870, 31, 32 });
		player2Collision_Anim.PushBack({ 508, 870, 31, 32 });
		player2Collision_Anim.PushBack({ 57, 917, 31, 32 });
		player2Collision_Anim.PushBack({ 93, 917, 31, 32 });
		player2Collision_Anim.PushBack({ 138, 917, 31, 32 });
		player2Collision_Anim.PushBack({ 188, 917, 31, 32 });
		player2Collision_Anim.PushBack({ 232, 917, 31, 32 });
		player2Collision_Anim.PushBack({ 278, 917, 31, 32 });
		player2Collision_Anim.speed = 0.5f;
		player2Collision_Anim.loop = true;
	}

	playerLives = 2;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	hitted = false;
	shotPower = 0;
	spawnTime = 0;
	godModeControl = false;
	playerExpControl = false;
	playerLost = false;
	original_camera_y = App->render->camera.y;
	laserType = 0;

	LOG("Creating player collider");
	playerCollider = App->collision->AddCollider({ position.x,position.y,31,30 }, COLLIDER_PLAYER2, this);

	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/characters/valnus_spritesheet.png");
	if (graphics == nullptr)
		ret = false;

	LOG("Loading player audios");
	valnus_Hitted = App->audio->LoadFx("Assets/audio/effects/Valnus_hit_enemy.wav");
	valnus_PowerUp = App->audio->LoadFx("Assets/audio/effects/Valnus_voice_PowerUp.wav");
	valnus_Death = App->audio->LoadFx("Assets/audio/effects/Valnus_Scream_hitted.wav");

	this->position.x = 0;
	this->position.y = SCREEN_HEIGHT + 200;
	this->spawining = true;
	this->deadPlayer = true;

	return ret;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	update_status status = UPDATE_CONTINUE;

	int speed = 3;


	if (!deadPlayer && !hitted && !spawining) {
		if ((App->sceneCastle->background_y == -SCREEN_HEIGHT && App->sceneCastle->IsEnabled()))
		{
			speed = 5;
			position.y -= speed;
		}
		else {

			if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
			{
				if (position.x < SCREEN_WIDTH - 34) // TODO: correct limits so they are all equal
					position.x += speed;
				if (current_animation != &right_animation)
				{
					current_animation = &right_animation;
					right_animation.Reset();
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {
				if (position.x > 3)
					position.x -= speed;
				if (current_animation != &left_animation)
				{
					left_animation.Reset();
					current_animation = &left_animation;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
			{
				if (position.y > 34)
					position.y -= speed;
			}

			if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
			{
				if (position.y <  SCREEN_HEIGHT - 3)
					position.y += speed;
			}

			if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_STATE::KEY_DOWN || (0 < counter))
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
				if (shotPower == 0) {
					if (counter == 0)
					{
						App->particles->AddParticle(App->particles->laser0, position.x + 8, position.y - 40, COLLIDER_PLAYER2_SHOT);
						shotControl = false;
					}
					else if (counter == 7)
					{
						App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40, COLLIDER_PLAYER2_SHOT);
					}
					else if (counter == 14)
					{
						App->particles->AddParticle(App->particles->laser2, position.x + 8, position.y - 40, COLLIDER_PLAYER2_SHOT);
					}
					else if (counter == 21)
					{
						App->particles->AddParticle(App->particles->laser0, position.x + 8, position.y - 40, COLLIDER_PLAYER2_SHOT);
						counter = 0;
						shotControl = true;
					}

					if (!shotControl)
						counter++;
				}
				else if (shotPower == 1) {
					if (counter == 0)
					{
						App->particles->AddParticle(App->particles->laser0_1, position.x + 3, position.y - 38, COLLIDER_PLAYER2_SHOT);
						shotControl = false;
					}
					else if (counter == 7)
					{
						App->particles->AddParticle(App->particles->laser1_1, position.x + 3, position.y - 38, COLLIDER_PLAYER2_SHOT);
					}
					else if (counter == 14)
					{
						App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 38, COLLIDER_PLAYER2_SHOT);
					}
					else if (counter == 21)
					{
						App->particles->AddParticle(App->particles->laser0_1, position.x + 3, position.y - 38, COLLIDER_PLAYER2_SHOT);
						counter = 0;
						shotControl = true;
					}

					if (!shotControl)
						counter++;
				}

			} //end shot space

			if (App->input->keyboard[SDL_SCANCODE_KP_7] == KEY_STATE::KEY_DOWN && App->sceneCastle->IsEnabled())
			{
				godModeControl = !godModeControl;
				if (godModeControl)
					inmortal = true;

			}

			if (App->input->keyboard[SDL_SCANCODE_KP_8] == KEY_STATE::KEY_DOWN && App->sceneCastle->IsEnabled())
			{
				playerLives = -1;
				deadPlayer = true;
				playerExpControl = true;
			}

			if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE)
				current_animation = &idle;

		}
		App->render->camera.y = original_camera_y;
	}



	if (spawining || inmortal)
		current_animation = &blink;

	if (deadPlayer)
		current_animation = &dead_animation;

	if (godModeControl)
		current_animation = &godMode;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//update player collider
	playerCollider->SetPos(position.x, position.y - r.h);

	if (!App->render->Blit(graphics, position.x, position.y - r.h, &r)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (this->deadPlayer) {

		if (!inmortal) {
			App->particles->AddParticle(App->particles->deathPlayerExplosion, (playerCollider->rect.x - ((60 - ((playerCollider->rect.w)) / 2))), (playerCollider->rect.y - ((110 - (playerCollider->rect.h)) / 2)));
			inmortal = true;
		}

		if (lastTime == 0)
			lastTime = SDL_GetTicks();

		if (currentTime < lastTime + 2000)
		{
			position.y += speed;
		}
		else {
			if (playerLives < 0) {
				playerLost = true;
			}
			else {
				if (spawnTime == 0) {
					spawining = true;
					playerLives--;
					this->spawning();
					this->deadPlayer = false;
				}
			}
		}
	}

	if (hitted) {
		current_animation = &player2Collision_Anim;
		hitted = false;
	}

	//inmortal control time
	if (currentTime > (lastTime + INMORTAL_TIME) && inmortal && (godModeControl == false) && spawnTime == 0) {
		this->inmortal = false;
		lastTime = 0;
	}

	//hitted control time
	if (currentTime > (hittedTime + HITTED_TIME) && hitted) {
		hitted = false;
	}

	//spawining control time
	if (currentTime < spawnTime + 1000 && spawining)
	{
		position.y -= 1;
	}
	else if (spawining) {
		spawining = false;
		spawnTime = 0;
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	return status;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");
	this->playerLives += 1;
	App->textures->Unload(graphics);
	if (playerCollider != nullptr) {
		App->collision->EraseCollider(playerCollider);
		playerCollider = nullptr;
	}
	LOG("Unloading player sound fx");
	App->audio->UnLoadFx(valnus_Hitted);
	App->audio->UnLoadFx(valnus_Death);
	App->audio->UnLoadFx(valnus_PowerUp);

	return true;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {
	if (c2->type == COLLIDER_POWER_UP)
	{
		shotPower = 1;
		App->audio->PlayFx(valnus_PowerUp);
	}
	if (!inmortal && spawnTime == 0) {

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_SHOT && !hitted) {
			this->removePowerUp();
			App->audio->PlayFx(valnus_Hitted);
		}

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_FLYING && !hitted) {
			this->removePowerUp();
			hitted = true;
			App->audio->PlayFx(valnus_Hitted);
		}

		if (c2->type == COLLIDER_ENEMY_SHOT)
		{
			this->deadPlayer = true;
		}

		if (deadPlayer == true) {
			App->particles->AddParticle(App->particles->deathPlayerExplosion, (c1->rect.x - ((130 - (c1->rect.w)) / 2)), (c1->rect.y - ((130 - (c1->rect.h)) / 2)));
			App->audio->PlayFx(valnus_Death);
		}
	}
}

void ModulePlayer2::removePowerUp() {
	if (!hitted) {
		hittedTime = SDL_GetTicks();
		hitted = true;
		if (shotPower > 0) {
			shotPower = 0;
			App->enemies->AddEnemy(ENEMY_TYPES::POWER_UP, position.x, position.y - 50, ENEMY_MOVEMENT::NO_MOVEMENT);
		}
	}
}

void ModulePlayer2::spawning() {
	spawnTime = SDL_GetTicks();
	this->position.x = (SCREEN_WIDTH / 2) - 14 + 30;
	this->position.y = SCREEN_HEIGHT + 24;
}