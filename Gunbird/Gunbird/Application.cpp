#pragma once
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcomeScreen.h"
#include "ModuleCharacterSelection.h"
#include "ModuleScoreRanking.h"
#include "ModuleSceneCastle.h"
#include "ModuleSceneForest.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"

Application::Application()
{
	int i = 0; 
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = welcomeScreen = new ModuleWelcomeScreen();
	modules[i++] = characterSelection = new ModuleCharacterSelection();
	modules[i++] = scoreRanking = new ModuleScoreRanking();
	modules[i++] = sceneForest = new ModuleSceneForest();
	modules[i++] = sceneCastle = new ModuleSceneCastle();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = ui = new ModuleUI();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = fade = new ModuleFadeToBlack();
}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	// Disable the modules that you do not start with
	welcomeScreen->Disable();
	characterSelection->Disable();
	scoreRanking->Disable();
	sceneCastle->Disable();
	sceneForest->Disable();
	ui->Disable();
	player->Disable();
	player2->Disable();

	scoreRanking->Disable();
	collision->Disable();
	enemies->Disable();
	
	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	//TODO: remove this in release mode
	sceneForest->Enable();
	//sceneCastle->Enable();

	//player->Enable();

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;
	 
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}