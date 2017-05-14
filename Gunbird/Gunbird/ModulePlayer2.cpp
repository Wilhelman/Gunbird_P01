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
#include "ModuleCharacterSelection.h"
#include "SDL\include\SDL_timer.h"

#include "ModuleEnemies.h"

//TODO: include the maps
#include "ModuleSceneCastle.h"
#include "ModuleSceneForest.h"

ModulePlayer2::ModulePlayer2()
{
	//godMode
	{
		godMode.PushBack({ 481, 27, 26, 37 });
		godMode.loop = true;
	}

	//Idle animation
	{
		idle.PushBack({ 11, 26, 30, 37 });
		idle.PushBack({ 51, 26, 30, 37 });
		idle.PushBack({ 91, 26, 30, 37 });
		idle.PushBack({ 131, 26, 30, 37 });
		idle.PushBack({ 171, 26, 30, 37 });

		idle.PushBack({ 11, 73, 30, 37 });
		idle.PushBack({ 51, 73, 30, 37 });
		idle.PushBack({ 91, 73, 30, 37 });
		idle.PushBack({ 131, 73, 30, 37 });
		idle.PushBack({ 171, 73, 30, 37 });

		idle.PushBack({ 11, 120, 30, 37 });
		idle.PushBack({ 51, 120, 30, 37 });
		idle.PushBack({ 91, 120, 30, 37 });
		idle.PushBack({ 129, 120, 30, 37 });
		idle.PushBack({ 171, 120, 30, 37 });

		idle.PushBack({ 11, 167, 30, 37 });
		idle.PushBack({ 51, 167, 30, 37 });
		idle.PushBack({ 91, 167, 30, 37 });
		idle.PushBack({ 131, 167, 30, 37 });
		idle.PushBack({ 171, 167, 30, 37 });

		idle.PushBack({ 11, 213, 30, 37 });
		idle.PushBack({ 51, 213, 30, 37 });
		idle.PushBack({ 91, 213, 30, 37 });
		idle.PushBack({ 131, 213, 30, 37 });

		idle.speed = 0.4f;
	}

	//Dead animation - TO CHANGE
	{
		dead_animation.PushBack({ 123, 446, 32, 38 });
		dead_animation.speed = 0.1f;
	}

	//remove (valnus sprites)?
	{
		dead_animation_explosion.PushBack({ 95,187,47,49 });
		dead_animation_explosion.PushBack({ 72,151,35, 37 });
		dead_animation_explosion.PushBack({ 88,114,31,31 });
		dead_animation_explosion.speed = 0.2f;
	}

	//Right animation
	{
		right_animation.PushBack({ 243, 29, 28, 37 });
		right_animation.PushBack({ 283, 29, 28, 37 });
		right_animation.PushBack({ 323, 29, 28, 37 });
		right_animation.PushBack({ 363, 29, 28, 37 });
		right_animation.PushBack({ 403, 29, 28, 37 });

		right_animation.PushBack({ 243, 76, 28, 37 });
		right_animation.PushBack({ 283, 76, 28, 37 });
		right_animation.PushBack({ 323, 76, 28, 37 });
		right_animation.PushBack({ 363, 76, 28, 37 });
		right_animation.PushBack({ 403, 76, 28, 37 });

		right_animation.PushBack({ 243, 123, 28, 37 });
		right_animation.PushBack({ 283, 123, 28, 37 });
		right_animation.PushBack({ 323, 123, 28, 37 });
		right_animation.PushBack({ 363, 123, 28, 37 });
		right_animation.PushBack({ 403, 123, 28, 37 });

		right_animation.PushBack({ 243, 170, 28, 37 });
		right_animation.PushBack({ 283, 170, 28, 37 });
		right_animation.PushBack({ 323, 170, 28, 37 });
		right_animation.PushBack({ 363, 170, 28, 37 });
		right_animation.PushBack({ 403, 170, 28, 37 });

		right_animation.PushBack({ 243, 217, 28, 37 });
		right_animation.PushBack({ 283, 217, 28, 37 });
		right_animation.PushBack({ 323, 217, 28, 37 });
		right_animation.PushBack({ 363, 217, 28, 37 });
		right_animation.PushBack({ 402, 217, 28, 37 });

		right_animation.PushBack({ 243, 262, 28, 37 });
		right_animation.PushBack({ 282, 264, 28, 37 });
		right_animation.PushBack({ 326, 262, 28, 37 });
		right_animation.PushBack({ 363, 264, 28, 37 });
		right_animation.PushBack({ 402, 264, 28, 37 });

		right_animation.PushBack({ 243, 305, 28, 37 });
		right_animation.PushBack({ 284, 305, 28, 37 });
		right_animation.PushBack({ 324, 306, 28, 37 });
		right_animation.PushBack({ 363, 306, 28, 37 });
		right_animation.PushBack({ 406, 306, 28, 37 });

		right_animation.PushBack({ 243, 356, 28, 37 });
		right_animation.PushBack({ 283, 357, 28, 37 });
		right_animation.PushBack({ 323, 357, 28, 37 });
		right_animation.PushBack({ 362, 357, 28, 37 });
		right_animation.PushBack({ 402, 357, 28, 37 });

		right_animation.PushBack({ 242, 404, 28, 37 });
		right_animation.PushBack({ 285, 404, 28, 37 });
		right_animation.PushBack({ 322, 404, 28, 37 });
		right_animation.PushBack({ 364, 404, 28, 37 });
		right_animation.PushBack({ 403, 404, 28, 37 });

		right_animation.PushBack({ 245, 451, 28, 37 });
		right_animation.PushBack({ 287, 451, 28, 37 });
		right_animation.PushBack({ 322, 451, 28, 37 });
		right_animation.PushBack({ 361, 451, 28, 37 });
		right_animation.PushBack({ 403, 451, 28, 37 });

		right_animation.speed = 0.4f;
		right_animation.loop = true;

	}

	//Left animation
	{

	left_animation.PushBack({ 8, 294, 28, 37 });
	left_animation.PushBack({ 48, 294, 28, 37 });
	left_animation.PushBack({ 88, 294, 28, 37 });
	left_animation.PushBack({ 128, 294, 28, 37 });
	left_animation.PushBack({ 168, 294, 28, 37 });

	left_animation.PushBack({ 8, 341, 28, 37 });
	left_animation.PushBack({ 48, 341, 28, 37 });
	left_animation.PushBack({ 88, 341, 28, 37 });
	left_animation.PushBack({ 128, 341, 28, 37 });
	left_animation.PushBack({ 168, 341, 28, 37 });

	left_animation.PushBack({ 8, 388, 28, 37 });
	left_animation.PushBack({ 48, 388, 28, 37 });
	left_animation.PushBack({ 88, 388, 28, 37 });
	left_animation.PushBack({ 128, 388, 28, 37 });
	left_animation.PushBack({ 168, 388, 28, 37 });

	left_animation.PushBack({ 8, 435, 28, 37 });
	left_animation.PushBack({ 48, 435, 28, 37 });
	left_animation.PushBack({ 88, 435, 28, 37 });
	left_animation.PushBack({ 128, 435, 28, 37 });
	left_animation.PushBack({ 168, 435, 28, 37 });

	left_animation.PushBack({ 8, 482, 28, 37 });
	left_animation.PushBack({ 48, 482, 28, 37 });
	left_animation.PushBack({ 88, 482, 28, 37 });
	left_animation.PushBack({ 128, 482, 28, 37 });
	left_animation.PushBack({ 168, 482, 28, 37 });

	left_animation.PushBack({ 8, 527, 28, 37 });
	left_animation.PushBack({ 47, 529, 28, 37 });
	left_animation.PushBack({ 91, 527, 28, 37 });
	left_animation.PushBack({ 128, 529, 28, 37 });
	left_animation.PushBack({ 167, 529, 28, 37 });

	left_animation.PushBack({ 8, 570, 28, 37 });
	left_animation.PushBack({ 49, 570, 28, 37 });
	left_animation.PushBack({ 89, 571, 28, 37 });
	left_animation.PushBack({ 128, 571, 28, 37 });
	left_animation.PushBack({ 171, 571, 28, 37 });

	left_animation.PushBack({ 8, 621, 28, 37 });
	left_animation.PushBack({ 48, 622, 28, 37 });
	left_animation.PushBack({ 88, 622, 28, 37 });
	left_animation.PushBack({ 127, 622, 28, 37 });
	left_animation.PushBack({ 167, 622, 28, 37 });

	left_animation.PushBack({ 7, 669, 28, 37 });
	left_animation.PushBack({ 50, 669, 28, 37 });
	left_animation.PushBack({ 87, 669, 28, 37 });
	left_animation.PushBack({ 129, 669, 28, 37 });
	left_animation.PushBack({ 168, 669, 28, 37 });

	left_animation.PushBack({ 10, 716, 28, 37 });
	left_animation.PushBack({ 52, 716, 28, 37 });
	left_animation.PushBack({ 67, 716, 28, 37 });
	left_animation.PushBack({ 126, 716, 28, 37 });
	left_animation.PushBack({ 168, 716, 28, 37 });

	left_animation.speed = 0.4f;
	left_animation.loop = true;
}

	//Blink animation
	{
		blink.PushBack({ 11, 26, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		blink.PushBack({ 51, 26, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		blink.PushBack({ 91, 26, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		blink.PushBack({ 131, 26, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		blink.PushBack({ 171, 26, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		idle.PushBack({ 11, 73, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		idle.PushBack({ 51, 73, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		idle.PushBack({ 91, 73, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		idle.PushBack({ 131, 73, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space
		idle.PushBack({ 171, 73, 30, 37 });
		blink.PushBack({ 188, 224, 30, 37 }); // space

		blink.speed = 0.8f;
		blink.loop = true;
	}

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
	graphics = App->textures->Load("Assets/characters/Tetsu/tetsu_spritesheet.png");
	if (graphics == nullptr)
		ret = false;

	LOG("Loading player audios");
	tetsu_Hitted = App->audio->LoadFx("Assets/audio/effects/Valnus_hit_enemy.wav");
	tetsu_PowerUp = App->audio->LoadFx("Assets/audio/effects/Tetsu_voice_PowerUp.wav");
	tetsu_Death = App->audio->LoadFx("Assets/audio/effects/tetsu_scream_hitted.wav");

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
		if ((App->sceneCastle->background_y == -SCREEN_HEIGHT || App->sceneForest->background_y == -SCREEN_HEIGHT) && (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()))
		{
			speed = 5;
			position.y -= speed;
		}
		else {

			if (App->characterSelection->characterSelected_P1 == CHARACTER_SELECTED::TETSU_SELECTED)
			{
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

				if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN && (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()))
				{
					godModeControl = !godModeControl;
					if (godModeControl)
						inmortal = true;

				}

				if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN && (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()))
				{
					playerLives = -1;
					deadPlayer = true;
					playerExpControl = true;
				}

				if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
					current_animation = &idle;
			}
			else if (App->characterSelection->characterSelected_P2 == CHARACTER_SELECTED::TETSU_SELECTED)
			{
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
				if (App->input->keyboard[SDL_SCANCODE_KP_7] == KEY_STATE::KEY_DOWN && (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()))
				{
					godModeControl = !godModeControl;
					if (godModeControl)
						inmortal = true;
				}
				if (App->input->keyboard[SDL_SCANCODE_KP_8] == KEY_STATE::KEY_DOWN && (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()))
				{
					playerLives = -1;
					deadPlayer = true;
					playerExpControl = true;
				}
				if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE)
					current_animation = &idle;
			}
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
	App->audio->UnLoadFx(tetsu_Hitted);
	App->audio->UnLoadFx(tetsu_Death);
	App->audio->UnLoadFx(tetsu_PowerUp);

	return true;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {
	if (c2->type == COLLIDER_POWER_UP)
	{
		shotPower = 1;
		App->audio->PlayFx(tetsu_PowerUp);
	}
	if (!inmortal && spawnTime == 0) {

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_SHOT && !hitted) {
			this->removePowerUp();
			App->audio->PlayFx(tetsu_Hitted);
		}

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_FLYING && !hitted) {
			this->removePowerUp();
			hitted = true;
			App->audio->PlayFx(tetsu_Hitted);
		}

		if (c2->type == COLLIDER_ENEMY_SHOT)
		{
			this->deadPlayer = true;
		}

		if (deadPlayer == true) {
			App->particles->AddParticle(App->particles->deathPlayerExplosion, (c1->rect.x - ((130 - (c1->rect.w)) / 2)), (c1->rect.y - ((130 - (c1->rect.h)) / 2)));
			App->audio->PlayFx(tetsu_Death);
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