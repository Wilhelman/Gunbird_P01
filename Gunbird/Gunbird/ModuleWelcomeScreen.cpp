#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleCharacterSelection.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleWelcomeScreen::ModuleWelcomeScreen()
{
	welcomeScreenAnimation.PushBack({ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	welcomeScreenAnimation.PushBack({ 224, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	welcomeScreenAnimation.speed = 0.05f;
}

ModuleWelcomeScreen::~ModuleWelcomeScreen()
{}

// Load assets
bool ModuleWelcomeScreen::Start()
{
	LOG("Loading welcome screen");
	bool ret = true;

	graphics = App->textures->Load("Assets/welcomeScreen/welcomeScreen_spritesheet.png");
	if (graphics == nullptr) {
		ret = false;
		LOG("Error loading the welcomeScreen spritesheet");
	}
	if (!App->audio->PlayMusic("Assets/audio/gunbird_welcome_CastleScreen_music.ogg"))
		ret = false;

	return ret;
}

// Update: draw background
update_status ModuleWelcomeScreen::Update()
{

	if (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver()) {
		App->fade->FadeToBlack(this, App->characterSelection, 0.5f);
	}

	update_status status = UPDATE_CONTINUE;

	if (!App->render->Blit(graphics, 0, 0, &(welcomeScreenAnimation.GetCurrentFrame()))) //welcomeScreen animation
		status = UPDATE_ERROR;

	return status;
}

bool ModuleWelcomeScreen::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading welcome screen");

	App->audio->StopMusic();
	App->textures->Unload(graphics);

	return true;
}