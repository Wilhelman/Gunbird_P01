#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCharacterSelection.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModulePlayer2.h"

//TODO include only the random maps?
#include "ModuleSceneCastle.h"
#include "ModuleSceneForest.h"

ModuleCharacterSelection::ModuleCharacterSelection()
{
	currentCharacter_P1 = VALNUS;
	currentCharacter_P2 = NONE;
	counter = 0;
	lastTime = SDL_GetTicks();

	sky_x = -182.0f;
	sky_speed = 0.3f;

	//characterSelected_P1 = VALNUS_SELECTED;
	characterSelected_P2 = NONE_SELECTED;

	selectorPos1[0] = false;
	selectorPos1[1] = false;
	selectorPos1[2] = true;
	selectorPos1[3] = false;
	selectorPos1[4] = false;

	selectorPos2[0] = false;
	selectorPos2[1] = false;
	selectorPos2[2] = false;
	selectorPos2[3] = false;
	selectorPos2[4] = false;

	player2_joined = false;

	selected_P1_done = false;
	selected_P2_done = false;

	moveAnim_y = 0;

	// Background
	background.x = 0;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;

	//Valnus name
	valnusName.x = 169;
	valnusName.y = 772;
	valnusName.w = 53;
	valnusName.h = 22;

	//Marion name
	marionName.x = 169;
	marionName.y = 668;
	marionName.w = 54;
	marionName.h = 21;

	//Ash name
	ashName.x = 168;
	ashName.y = 566;
	ashName.w = 27;
	ashName.h = 21;

	//Tetsu name
	tetsuName.x = 168;
	tetsuName.y = 981;
	tetsuName.w = 44;
	tetsuName.h = 20;

	//Yuang Nang name short
	yuangNangName_short.x = 168;
	yuangNangName_short.y = 875;
	yuangNangName_short.w = 49;
	yuangNangName_short.h = 43;
	
	//Yuang Nang name long
	yuangNangName.x = 168;
	yuangNangName.y = 930;
	yuangNangName.w = 83;
	yuangNangName.h = 21;


	// Characters frames
	{
		valnus_frame.x = 56;
		valnus_frame.y = 757;
		valnus_frame.w = 96;
		valnus_frame.h = 96;

		tetsu_frame.x = 56;
		tetsu_frame.y = 965;
		tetsu_frame.w = 96;
		tetsu_frame.h = 96;

		yuang_nang_frame.x = 56;
		yuang_nang_frame.y = 861;
		yuang_nang_frame.w = 96;
		yuang_nang_frame.h = 96;

		ash_frame.x = 56;
		ash_frame.y = 549;
		ash_frame.w = 96;
		ash_frame.h = 96;

		marion_frame.x = 56;
		marion_frame.y = 653;
		marion_frame.w = 96;
		marion_frame.h = 96;
	}

	// Characters selectors
	{
		selector_p1.x = 311;
		selector_p1.y = 74;
		selector_p1.w = 32;
		selector_p1.h = 52;

		selector_p2.x = 368;
		selector_p2.y = 74;
		selector_p2.w = 32;
		selector_p2.h = 52;
	}

	// SKY
	sky.x = 63;
	sky.y = 406;
	sky.w = 416;
	sky.h = 96;

	// Idle Tetsu Animation
	{
		idleTetsu.PushBack({ 11, 26, 30, 37 });
		idleTetsu.PushBack({ 51, 26, 30, 37 });
		idleTetsu.PushBack({ 91, 26, 30, 37 });
		idleTetsu.PushBack({ 131, 26, 30, 37 });
		idleTetsu.PushBack({ 171, 26, 30, 37 });

		idleTetsu.PushBack({ 11, 73, 30, 37 });
		idleTetsu.PushBack({ 51, 73, 30, 37 });
		idleTetsu.PushBack({ 91, 73, 30, 37 });
		idleTetsu.PushBack({ 131, 73, 30, 37 });
		idleTetsu.PushBack({ 171, 73, 30, 37 });

		idleTetsu.PushBack({ 11, 120, 30, 37 });
		idleTetsu.PushBack({ 51, 120, 30, 37 });
		idleTetsu.PushBack({ 91, 120, 30, 37 });
		idleTetsu.PushBack({ 129, 120, 30, 37 });
		idleTetsu.PushBack({ 171, 120, 30, 37 });

		idleTetsu.PushBack({ 11, 167, 30, 37 });
		idleTetsu.PushBack({ 51, 167, 30, 37 });
		idleTetsu.PushBack({ 91, 167, 30, 37 });
		idleTetsu.PushBack({ 131, 167, 30, 37 });
		idleTetsu.PushBack({ 171, 167, 30, 37 });

		idleTetsu.PushBack({ 11, 213, 30, 37 });
		idleTetsu.PushBack({ 51, 213, 30, 37 });
		idleTetsu.PushBack({ 91, 213, 30, 37 });
		idleTetsu.PushBack({ 131, 213, 30, 37 });

		idleTetsu.speed = 0.4f;
	}

	//Valnus idle animation
	{
		idleValnus.PushBack({ 0, 0, 31, 30 });
		idleValnus.PushBack({ 38, 0, 31, 29 });
		idleValnus.speed = 0.05f;
	}

	// Marion locked icon
	{
		lockedMarion.PushBack({63, 254, 20, 32});
		lockedMarion.speed = 0.05f;
	}

	// Yuang Nang locked icon
	{
		lockedYuangNang.PushBack({ 137, 249, 27, 48 });
		lockedYuangNang.speed = 0.05f;
	}

	// Ash locked icon
	{
		lockedAsh.PushBack({ 23, 256, 19, 32 });
		lockedAsh.speed = 0.05f;
	}

	//Valnus figure animation
	{
		valnusFigure.PushBack({ 746, 1283, 120, 116 });
		valnusFigure.PushBack({ 898, 1283, 120, 118 });
		valnusFigure.PushBack({ 1050, 1283, 120, 114 });
		valnusFigure.PushBack({ 1201, 1283, 120, 113 });
		valnusFigure.speed = 0.5f;
	}

	//Tetsu figure animation
	{
		//First row
		tetsuFigure.PushBack({ 599, 522, 121, 111 });
		tetsuFigure.PushBack({ 747, 521, 120, 112 });
		tetsuFigure.PushBack({ 894, 521, 120, 112 });
		tetsuFigure.PushBack({ 1029, 525, 119, 112 });
		tetsuFigure.PushBack({ 1177, 525, 119, 112 });
		tetsuFigure.PushBack({ 1324, 525, 117, 111 });

		//Second row


		//Third row


		//Fourth row


		//Fifth row



		tetsuFigure.speed = 0.1f;
	}

	//Marion figure animation
	{
		marionFigure.PushBack({ 25, 1193, 128, 103 });
		marionFigure.PushBack({ 184, 1197, 128, 103 });
		marionFigure.PushBack({ 328, 1195, 128, 103 });
		marionFigure.speed = 0.25f;
	}

	//Ash figure animation
	{
		ashFigure.PushBack({ 21 , 1316, 104, 101 });
		ashFigure.PushBack({ 140, 1317, 104, 108 });
		ashFigure.PushBack({ 260, 1319, 104, 108 });
		ashFigure.PushBack({ 373, 1321, 104, 108 });
		ashFigure.speed = 0.17f;
	}
}

ModuleCharacterSelection::~ModuleCharacterSelection()
{}

// Load assets
bool ModuleCharacterSelection::Start()
{
	LOG("Loading Character Selection assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/characterSelection/character_selection_template.png");
	characterGraphics = App->textures->Load("Assets/characterSelection/character_selection.png");
	tetsuAnimGraphics = App->textures->Load("Assets/characters/Tetsu/tetsu_spritesheet.png");
	valnusAnimGrahics = App->textures->Load("Assets/characters/valnus_spritesheet.png");
	icons_locked = App->textures->Load("Assets/characterSelection/exampleCharacterSelection.png");
	
	if (graphics == nullptr || characterGraphics == nullptr || valnusAnimGrahics == nullptr || icons_locked == nullptr) {
		LOG("Cannot load the texture in Character Selection");
		ret = false;
	}

	if (!App->audio->PlayMusic("Assets/audio/gunbird_characterSelection_music.ogg"))
		ret = false;

	LOG("Loading audio fx for Valnus selection");
	valnus_selection = App->audio->LoadFx("Assets/audio/effects/Valnus_Start.wav");
	tetsu_selection = App->audio->LoadFx("Assets/audio/effects/Tetsu_start.wav");
	selector_mov = App->audio->LoadFx("Assets/audio/effects/characterSelector_movement.wav");
	locked_character = App->audio->LoadFx("Assets/audio/effects/locked_character.wav");

	return ret;
}

// Update: draw background
update_status ModuleCharacterSelection::Update()
{

	update_status status = UPDATE_CONTINUE;
	currentTime = SDL_GetTicks();

	// Control animation time
	{
		if (currentTime < lastTime + 150)
			moveAnim_y = -1;
		if (currentTime < lastTime + 300)
			moveAnim_y = -2;
		else if (currentTime < lastTime + 375)
			moveAnim_y = 0;
		else if (currentTime < lastTime + 525)
			moveAnim_y = 1;
		else if (currentTime < lastTime + 825)
			moveAnim_y = 2;
		else if (currentTime < lastTime + 975)
			moveAnim_y = 0;
		else
			lastTime = currentTime;


		if (player2_joined)
		{
			if (counter == 1)
			{
				lastTime2 = SDL_GetTicks();
			}

			if (currentTime < lastTime2 + 150)
				moveAnim_y2 = -1;
			if (currentTime < lastTime2 + 300)
				moveAnim_y2 = -2;
			else if (currentTime < lastTime2 + 375)
				moveAnim_y2 = 0;
			else if (currentTime < lastTime2 + 525)
				moveAnim_y2 = 1;
			else if (currentTime < lastTime2 + 825)
				moveAnim_y2 = 2;
			else if (currentTime < lastTime2 + 975)
				moveAnim_y2 = 0;
			else
				lastTime2 = currentTime;

			counter = 0;
		}
	}

	if (((selected_P1_done && player2_joined == false) 
		|| (selected_P1_done && selected_P2_done))
		&& App->fade->FadeIsOver())
	{
		App->fade->FadeToBlack(this, App->sceneForest);

		selected_P1_done = false;
		selected_P2_done = false;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, 0, &background, 1.0f)) {
		LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	tetsu = &idleTetsu;
	SDL_Rect r_tetsu = tetsu->GetCurrentFrame();

	if (!App->render->Blit(tetsuAnimGraphics, 178, 254, &r_tetsu)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	valnus = &idleValnus;
	SDL_Rect r_valnus = valnus->GetCurrentFrame();

	if (!App->render->Blit(valnusAnimGrahics, 97, 255, &r_valnus)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	marion = &lockedMarion;
	SDL_Rect r_marion = marion->GetCurrentFrame();

	if (!App->render->Blit(icons_locked, 63, 254, &r_marion)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	yuangNang = &lockedYuangNang;
	SDL_Rect r_yuangNang = yuangNang->GetCurrentFrame();

	if (!App->render->Blit(icons_locked, 137, 249, &r_yuangNang)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	ash = &lockedAsh;
	SDL_Rect r_ash = ash->GetCurrentFrame();

	if (!App->render->Blit(icons_locked, 23, 256, &r_ash)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}


	if (sky_x < 0)
		sky_x += sky_speed;
	else
		sky_x = -182;
	
	if (!App->render->Blit(characterGraphics, (int)sky_x, 144, &sky, 1.0f)) {
		LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}


	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_STATE::KEY_DOWN && selected_P1_done == false && selected_P2_done == false)
	{
		player2_joined = true;
		counter = 1;
		if (selectorPos1[4])
			selectorPos2[2] = true;
		else
		selectorPos2[4] = true;
	}

	if (selected_P1_done == false)
	{
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos1[i] && selection_control_P1 == false)
				{
					//TRY THIS ONE
					if (selectorPos1[3] && selectorPos2[4])
					{
						selectorPos1[3] = false;
						selectorPos1[0] = true;
					}
					else if (selectorPos1[4] && selectorPos2[0])
					{
						selectorPos1[4] = false;
						selectorPos1[1] = true;
					}
					else if (selectorPos1[4] && (selectorPos2[0] == false || player2_joined == false))
					{
						selectorPos1[4] = false;
						selectorPos1[0] = true;
					}
					else if (selectorPos2[i + 1])
					{
						selectorPos1[i] = false;
						selectorPos1[i + 2] = true;
					}
					else
					{
						selectorPos1[i] = false;
						selectorPos1[i + 1] = true;
					}
					selection_control_P1 = true;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos1[i] && selection_control_P1 == false)
				{
					if (selectorPos1[1] && selectorPos2[0])
					{
						selectorPos1[1] = false;
						selectorPos1[4] = true;
					}
					else if (selectorPos1[0] && selectorPos2[4])
					{
						selectorPos1[0] = false;
						selectorPos1[3] = true;
					}
					else if (selectorPos1[0] && (selectorPos2[4] == false || player2_joined == false))
					{
						selectorPos1[0] = false;
						selectorPos1[4] = true;
					}
					else if (selectorPos2[i - 1])
					{
						selectorPos1[i] = false;
						selectorPos1[i - 2] = true;
					}
					else
					{
						selectorPos1[i] = false;
						selectorPos1[i - 1] = true;
					}
					selection_control_P1 = true;
				}
			}
		}
	}

	if (selected_P2_done == false && player2_joined)
	{
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos2[i] && selection_control_P2 == false)
				{
					if (selectorPos2[3] && selectorPos1[4])
					{
						selectorPos2[3] = false;
						selectorPos2[0] = true;
					}
					else if (selectorPos2[4] && selectorPos1[0])
					{
						selectorPos2[4] = false;
						selectorPos2[1] = true;
					}
					else if (selectorPos2[4] && selectorPos1[0] == false)
					{
						selectorPos2[4] = false;
						selectorPos2[0] = true;
					}
					else if (selectorPos1[i + 1])
					{
						selectorPos2[i] = false;
						selectorPos2[i + 2] = true;
					}
					else
					{
						selectorPos2[i] = false;
						selectorPos2[i + 1] = true;
					}
					selection_control_P2 = true;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos2[i] && selection_control_P2 == false)
				{
					if (selectorPos2[1] && selectorPos1[0])
					{
						selectorPos2[1] = false;
						selectorPos2[4] = true;
					}
					else if (selectorPos2[0] && selectorPos1[4])
					{
						selectorPos2[0] = false;
						selectorPos2[3] = true;
					}
					else if (selectorPos2[0] && selectorPos1[4] == false)
					{
						selectorPos2[0] = false;
						selectorPos2[4] = true;
					}
					else if (selectorPos1[i - 1])
					{
						selectorPos2[i] = false;
						selectorPos2[i - 2] = true;
					}
					else
					{
						selectorPos2[i] = false;
						selectorPos2[i - 1] = true;
					}
					selection_control_P2 = true;
				}
			}
		}
	}

	if (selectorPos1[0])
		currentCharacter_P1 = ASH;
	else if (selectorPos1[1])
		currentCharacter_P1 = MARION;
	else if (selectorPos1[2])
		currentCharacter_P1 = VALNUS;
	else if (selectorPos1[3])
		currentCharacter_P1 = YUANG_NANG;
	else if (selectorPos1[4])
		currentCharacter_P1 = TETSU;

	if (player2_joined)
	{
		if (selectorPos2[0])
			currentCharacter_P2 = ASH;
		else if (selectorPos2[1])
			currentCharacter_P2 = MARION;
		else if (selectorPos2[2])
			currentCharacter_P2 = VALNUS;
		else if (selectorPos2[3])
			currentCharacter_P2 = YUANG_NANG;
		else if (selectorPos2[4])
			currentCharacter_P2 = TETSU;
	}

	//IMPORTANT THINGS TO BE AWARE OF WHEN ADDING MISSING SPRITES/ANIMATIONS:
	/*
	- Player 1 big character animation appears under Player 2 big character animation. 
	  This means we must blit player 1 animation first, before player 2.
	- When player 2 has joined the game character names appear above character frames.
	- While player 2 has not joined the game "start icon" animation appears at the top right of window. 
	  If player 2 joins the game it disappears
	- All this is done in the next two sets of code (PLAYER 1 & PLAYER 2).
	*/

	//PLAYER 1

	if (currentCharacter_P1 == ASH)
	{
		App->render->Blit(characterGraphics, 12, 32, &ash_frame, 1.0f);

		if (player2_joined == false)
		{
			App->render->Blit(characterGraphics, 51, 165, &ashName, 1.0f);
			App->render->Blit(characterGraphics, 96, 129 + moveAnim_y, &(ashFigure.GetCurrentFrame()), 0.22f);

		}
		else
		{
			App->render->Blit(characterGraphics, 47, 5, &ashName, 1.0f);
			App->render->Blit(characterGraphics, 8, 129 + moveAnim_y, &(ashFigure.GetCurrentFrame()), 0.22f);

		}
		App->render->Blit(characterGraphics, 16, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == MARION)
	{
		App->render->Blit(characterGraphics, 12, 32, &marion_frame, 1.0f);

		if (player2_joined == false)
		{
			App->render->Blit(characterGraphics, 21, 165, &marionName, 1.0f);
			App->render->Blit(characterGraphics, 80, 132 + moveAnim_y, &(marionFigure.GetCurrentFrame()), 0.22f);
		}
		else
		{
			App->render->Blit(characterGraphics, 34, 5, &marionName, 1.0f);
			App->render->Blit(characterGraphics, 0, 134 + moveAnim_y, &(marionFigure.GetCurrentFrame()), 0.22f);
			
		}
		App->render->Blit(characterGraphics, 56, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == VALNUS)
	{
		App->render->Blit(characterGraphics, 12, 32, &valnus_frame, 1.0f);

		if (player2_joined == false)
		{
			App->render->Blit(characterGraphics, 22, 165, &valnusName, 1.0f);
			App->render->Blit(characterGraphics, 90, 117 + moveAnim_y, &(valnusFigure.GetCurrentFrame()), 0.22f);
		}
		else
		{
			App->render->Blit(characterGraphics, 2, 118 + moveAnim_y, &(valnusFigure.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterGraphics, 34, 5, &valnusName, 1.0f);
		}

		App->render->Blit(characterGraphics, 96, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == YUANG_NANG)
	{
		App->render->Blit(characterGraphics, 12, 32, &yuang_nang_frame, 1.0f);

		if (player2_joined == false)
		{
			App->render->Blit(characterGraphics, 19, 165, &yuangNangName_short, 1.0f);
		}
		else
		{
			App->render->Blit(characterGraphics, 19, 5, &yuangNangName, 1.0f);
		}
		
		App->render->Blit(characterGraphics, 136, 244, &selector_p1, 1.0f);
	}
	else if ((currentCharacter_P1 == TETSU))
	{
		App->render->Blit(characterGraphics, 12, 32, &tetsu_frame, 1.0f);

		if (player2_joined == false)
		{
			App->render->Blit(characterGraphics, 43, 166, &tetsuName, 1.0f);
			App->render->Blit(characterGraphics, 95, 128, &(tetsuFigure.GetCurrentFrame()), 0.22f);
		}
		else
		{
			App->render->Blit(characterGraphics, 39, 6, &tetsuName, 1.0f);
			App->render->Blit(characterGraphics, 11, 129, &(tetsuFigure.GetCurrentFrame()), 0.22f);

		}
		
			
		App->render->Blit(characterGraphics, 176, 244, &selector_p1, 1.0f);
	}

	if (selection_control_P1)
		selection_control_P1 = false;

	//PLAYER 2

	if (player2_joined)
	{
		if (currentCharacter_P2 == ASH)
		{
			App->render->Blit(characterGraphics, 151, 5, &ashName, 1.0f);
			App->render->Blit(characterGraphics, 116, 32, &ash_frame, 1.0f);
			App->render->Blit(characterGraphics, 120, 129 + moveAnim_y2, &(ashFigure.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterGraphics, 16, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == MARION)
		{
			App->render->Blit(characterGraphics, 138, 5, &marionName, 1.0f);
			App->render->Blit(characterGraphics, 116, 32, &marion_frame, 1.0f);
			App->render->Blit(characterGraphics, 112, 134 + moveAnim_y2, &(marionFigure.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterGraphics, 56, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == VALNUS)
		{
			App->render->Blit(characterGraphics, 138, 5, &valnusName, 1.0f);
			App->render->Blit(characterGraphics, 116, 32, &valnus_frame, 1.0f);
			App->render->Blit(characterGraphics, 114, 118 + moveAnim_y2, &(valnusFigure.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterGraphics, 96, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == YUANG_NANG)
		{
			if (!App->render->Blit(characterGraphics, 123, 5, &yuangNangName, 1.0f)) {
				LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			App->render->Blit(characterGraphics, 116, 32, &yuang_nang_frame, 1.0f);
			App->render->Blit(characterGraphics, 136, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == TETSU)
		{
			App->render->Blit(characterGraphics, 143, 6, &tetsuName, 1.0f);
			App->render->Blit(characterGraphics, 116, 32, &tetsu_frame, 1.0f);
			App->render->Blit(characterGraphics, 119, 129, &(tetsuFigure.GetCurrentFrame()), 0.22f);
			App->render->Blit(characterGraphics, 176, 244, &selector_p2, 1.0f);
		}

		if (selection_control_P2)
			selection_control_P2 = false;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		selected_P1_done = true;

		switch (currentCharacter_P1)
		{
		case ASH:
		case MARION:
		case YUANG_NANG:
			App->audio->PlayFx(locked_character);
			characterSelected_P1 = NONE_SELECTED;
			selected_P1_done = false; 
			break;
		case VALNUS:
			characterSelected_P1 = VALNUS_SELECTED;
			App->audio->PlayFx(valnus_selection);
			break;
		case TETSU:
			characterSelected_P1 = TETSU_SELECTED;
			App->audio->PlayFx(tetsu_selection);
			break;
		}
	}
		

	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_STATE::KEY_DOWN && player2_joined)
	{
		selected_P2_done = true;

		switch (currentCharacter_P2)
		{
		case ASH:
		case MARION:
		case YUANG_NANG:
			App->audio->PlayFx(locked_character);
			characterSelected_P2 = NONE_SELECTED;
			selected_P2_done = false;
			break;
		case VALNUS:
			characterSelected_P2 = VALNUS_SELECTED;
			App->audio->PlayFx(valnus_selection);
			break;
		case TETSU:
			characterSelected_P2 = TETSU_SELECTED;
			App->audio->PlayFx(tetsu_selection);
			break;
		}
	}
	return status;
}

bool ModuleCharacterSelection::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading character selection");

	App->audio->Disable();
	App->textures->Unload(graphics);

	return true;
}