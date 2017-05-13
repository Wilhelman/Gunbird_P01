#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCharacterSelection.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"

//TODO include only the random maps?
#include "ModuleSceneCastle.h"

ModuleCharacterSelection::ModuleCharacterSelection()
{

	selectorPos1[0] = false;
	selectorPos1[1] = false;
	selectorPos1[2] = true;
	selectorPos1[3] = false;
	selectorPos1[4] = false;

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
		selector_p1.w = 31;
		selector_p1.h = 52;
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
	
	if (graphics == nullptr || characterGraphics == nullptr) {
		LOG("Cannot load the texture in Character Selection");
		ret = false;
	}

	if (!App->audio->PlayMusic("Assets/audio/gunbird_characterSelection_music.ogg"))
		ret = false;

	LOG("Loading audio fx for Valnus selection");
	valnus_selection = App->audio->LoadFx("Assets/audio/effects/Valnus_Start.wav");

	return ret;
}

// Update: draw background
update_status ModuleCharacterSelection::Update()
{

	update_status status = UPDATE_CONTINUE;

	if (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver()) {
		
		App->audio->PlayFx(valnus_selection);
		App->fade->FadeToBlack(this, App->sceneCastle);
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, 0, &background, 1.0f)) {
		LOG("Cannot blit the texture in Character Selection %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN && selectorPos1[4] == false)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (selectorPos1[i] && selection_control == false)
			{
					selectorPos1[i] = false;
					selectorPos1[i + 1] = true;
					selection_control = true;
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN && selectorPos1[0] == false)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (selectorPos1[i] && selection_control == false)
			{
					selectorPos1[i] = false;
					selectorPos1[i - 1] = true;
					selection_control = true;
			}
		}
	}

	if (selectorPos1[0]) //ASH
	{
		App->render->Blit(characterGraphics, 12, 32, &ash_frame, 1.0f);
		App->render->Blit(characterGraphics, 14, 244, &selector_p1, 1.0f);
	}
	else if (selectorPos1[1]) //MARION
	{
		App->render->Blit(characterGraphics, 12, 32, &marion_frame, 1.0f);
		App->render->Blit(characterGraphics, 54, 244, &selector_p1, 1.0f);
	}
	else if (selectorPos1[2]) //VALNUS
	{
		App->render->Blit(characterGraphics, 12, 32, &valnus_frame, 1.0f);
		App->render->Blit(characterGraphics, 94, 244, &selector_p1, 1.0f);
	}
	else if (selectorPos1[3]) //YUANG NANG
	{
		App->render->Blit(characterGraphics, 12, 32, &yuang_nang_frame, 1.0f);
		App->render->Blit(characterGraphics, 134, 244, &selector_p1, 1.0f);
	}
	else if (selectorPos1[4]) //TETSU 
	{
		App->render->Blit(characterGraphics, 12, 32, &tetsu_frame, 1.0f);
		App->render->Blit(characterGraphics, 174, 244, &selector_p1, 1.0f);
	}

	if (selection_control)
		selection_control = false;

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