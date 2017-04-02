#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleScoreRanking.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"

ModuleScoreRanking::ModuleScoreRanking()
{
	// Background
	background.x = 0;
	background.y = 0;
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT;
}

ModuleScoreRanking::~ModuleScoreRanking()
{}

// Load assets
bool ModuleScoreRanking::Start()
{
	LOG("Loading ScoreRanking assets");
	bool ret = true;

	graphics = App->textures->Load("Assets/scoreRanking/scoreRanking_example.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in ScoreRanking");
		ret = false;
	}
	if (!App->audio->PlayMusic("Assets/audio/gunbird_scoreRanking_music.ogg"))
		ret = false;
	return ret;
}

// Update: draw background
update_status ModuleScoreRanking::Update()
{

	update_status status = UPDATE_CONTINUE;

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, 0, 0, &background, 1.0f)) {
		LOG("Cannot blit the texture in ScoreRanking %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//TODO change the position of the player to private to be more pro

	if (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver())
		App->fade->FadeToBlack(this, App->welcomeScreen);

	return status;
}

bool ModuleScoreRanking::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading Score Ranking");

	App->textures->Unload(graphics);
	App->audio->StopMusic();

	return true;
}