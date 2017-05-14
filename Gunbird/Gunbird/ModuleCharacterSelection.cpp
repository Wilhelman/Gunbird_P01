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
	selectorPos2[4] = true;

	player2_joined = false;

	selected_P1_done = false;
	selected_P2_done = false;

	// Background
	background.x = 0;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;

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

	currentTime = SDL_GetTicks();
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
	
	if (graphics == nullptr || characterGraphics == nullptr) {
		LOG("Cannot load the texture in Character Selection");
		ret = false;
	}

	if (!App->audio->PlayMusic("Assets/audio/gunbird_characterSelection_music.ogg"))
		ret = false;

	LOG("Loading audio fx for Valnus selection");
	valnus_selection = App->audio->LoadFx("Assets/audio/effects/Valnus_Start.wav");
	tetsu_selection = App->audio->LoadFx("Assets/audio/effects/Tetsu_start.wav");
	selector_mov = App->audio->LoadFx("Assets/audio/effects/characterSelector_movement.wav");

	return ret;
}

// Update: draw background
update_status ModuleCharacterSelection::Update()
{

	update_status status = UPDATE_CONTINUE;

	if ((App->input->keyboard[SDL_SCANCODE_RETURN] 
		|| (selected_P1_done && player2_joined == false) 
		|| (selected_P1_done && selected_P2_done)
		/*|| (currentTime + 10000) <= SDL_GetTicks()*/)
		&& App->fade->FadeIsOver()) 
	{
		
		App->audio->PlayFx(valnus_selection);
		App->fade->FadeToBlack(this, App->sceneForest);
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, 0, &background, 1.0f)) {
		LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (currentTime + 10000 > SDL_GetTicks())
	{
		sky.x--;
	}

	if (!App->render->Blit(characterGraphics, -182, 144, &sky, 1.0f)) {
		LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_STATE::KEY_DOWN && selected_P1_done == false && selected_P2_done == false)
	{
		player2_joined = true;
		characterSelected_P2 = VALNUS_SELECTED;
	}

	/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		selected_P1_done = true;

	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_STATE::KEY_DOWN && player2_joined)
		selected_P2_done = true;*/

	if (selected_P1_done == false)
	{
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && selectorPos1[4] == false)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos1[i] && selection_control_P1 == false)
				{
					selectorPos1[i] = false;
					selectorPos1[i + 1] = true;
					selection_control_P1 = true;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && selectorPos1[0] == false)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos1[i] && selection_control_P1 == false)
				{
					selectorPos1[i] = false;
					selectorPos1[i - 1] = true;
					selection_control_P1 = true;
				}
			}
		}
	}

	if (selected_P2_done == false)
	{
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN && selectorPos2[4] == false && player2_joined)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos2[i] && selection_control_P2 == false)
				{
					selectorPos2[i] = false;
					selectorPos2[i + 1] = true;
					selection_control_P2 = true;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN && selectorPos2[0] == false && player2_joined)
		{
			App->audio->PlayFx(selector_mov);
			for (int i = 0; i < 5; ++i)
			{
				if (selectorPos2[i] && selection_control_P2 == false)
				{
					selectorPos2[i] = false;
					selectorPos2[i - 1] = true;
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

	//PLAYER 1

	if (currentCharacter_P1 == ASH)
	{
		App->render->Blit(characterGraphics, 12, 32, &ash_frame, 1.0f);
		App->render->Blit(characterGraphics, 14, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == MARION) 
	{
		App->render->Blit(characterGraphics, 12, 32, &marion_frame, 1.0f);
		App->render->Blit(characterGraphics, 54, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == VALNUS)
	{
		App->render->Blit(characterGraphics, 12, 32, &valnus_frame, 1.0f);
		App->render->Blit(characterGraphics, 94, 244, &selector_p1, 1.0f);
	}
	else if (currentCharacter_P1 == YUANG_NANG)
	{
		App->render->Blit(characterGraphics, 12, 32, &yuang_nang_frame, 1.0f);
		App->render->Blit(characterGraphics, 134, 244, &selector_p1, 1.0f);
	}
	else if ((currentCharacter_P1 == TETSU))
	{
		App->render->Blit(characterGraphics, 12, 32, &tetsu_frame, 1.0f);
		App->render->Blit(characterGraphics, 174, 244, &selector_p1, 1.0f);
	}

	if (selection_control_P1)
		selection_control_P1 = false;

	//PLAYER 2

	if (player2_joined)
	{
		if (currentCharacter_P2 == ASH)
		{
			App->render->Blit(characterGraphics, 116, 32, &ash_frame, 1.0f);
			App->render->Blit(characterGraphics, 14, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == MARION)
		{
			App->render->Blit(characterGraphics, 116, 32, &marion_frame, 1.0f);
			App->render->Blit(characterGraphics, 54, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == VALNUS)
		{
			App->render->Blit(characterGraphics, 116, 32, &valnus_frame, 1.0f);
			App->render->Blit(characterGraphics, 94, 244, &selector_p2, 1.0f);
		}
		else if (currentCharacter_P2 == YUANG_NANG)
		{
			App->render->Blit(characterGraphics, 116, 32, &yuang_nang_frame, 1.0f);
			App->render->Blit(characterGraphics, 134, 244, &selector_p2, 1.0f);
		}
		else if ((currentCharacter_P2 == TETSU))
		{
			App->render->Blit(characterGraphics, 116, 32, &tetsu_frame, 1.0f);
			App->render->Blit(characterGraphics, 174, 244, &selector_p2, 1.0f);
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
			characterSelected_P1 = ASH_SELECTED;
			break;
		case MARION:
			characterSelected_P1 = MARION_SELECTED;
			break;
		case VALNUS:
			characterSelected_P1 = VALNUS_SELECTED;
			App->audio->PlayFx(valnus_selection);
			break;
		case YUANG_NANG:
			characterSelected_P1 = YUANG_NANG_SELECTED;
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
			characterSelected_P2 = ASH_SELECTED;
			break;
		case MARION:
			characterSelected_P2 = MARION_SELECTED;
			break;
		case VALNUS:
			characterSelected_P2 = VALNUS_SELECTED;
			App->audio->PlayFx(valnus_selection);
			break;
		case YUANG_NANG:
			characterSelected_P2 = YUANG_NANG_SELECTED;
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