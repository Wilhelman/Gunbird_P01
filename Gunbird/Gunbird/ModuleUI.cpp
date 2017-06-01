#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleSceneCastle.h"
#include "ModuleSceneForest.h"

#include <string.h>
#include<stdio.h>


ModuleUI::ModuleUI()
{

	liveIcon.x = 255;
	liveIcon.y = 152;
	liveIcon.w = 15;
	liveIcon.h = 12;

	p1_Icon.x = 77;
	p1_Icon.y = 69;
	p1_Icon.w = 15;
	p1_Icon.h = 12;

	bombIcon.x = 207;
	bombIcon.y = 151;
	bombIcon.w = 12;
	bombIcon.h = 15;

	p2_insertCoin.PushBack({ 77, 24, 77, 13 });
	p2_insertCoin.PushBack({ 77, 11, 77, 13 });
	p2_insertCoin.speed = 0.03f;

	p2_Icon.x = 77;
	p2_Icon.y = 91;
	p2_Icon.w = 16;
	p2_Icon.h = 12;

	score = 0;
	scoreP2 = 0;
	highestScore = 0;

	p2 = false;
}

ModuleUI::~ModuleUI()
{}

// Load assets
bool ModuleUI::Start()
{
	LOG("Loading ModuleUI assets");
	bool ret = true;
	font_score = this->Load("Assets/Userinterface/score_numberPoints.png", "0123456789", 1);
	graphics = App->textures->Load("Assets/Userinterface/userinterface.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in ModuleUI");
		ret = false;
	}

	return ret;
}

// Update: draw background
update_status ModuleUI::Update()
{

	update_status status = UPDATE_CONTINUE;
	if (App->sceneCastle->IsEnabled() || App->sceneForest->IsEnabled()) {
		char str[10];
		sprintf_s(str, "%i", score);

		int x_correction = 70;
		if (score > 99)
			x_correction -= fonts[font_score].char_w;
		if (score > 999)
			x_correction -= fonts[font_score].char_w;
		if (score > 9999)
			x_correction -= fonts[font_score].char_w;
		this->BlitText(x_correction, 4, font_score, str);

		if (App->player->playerLives >= 0) {
			if (!App->render->Blit(graphics, 5, 18, &liveIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}

		if (App->player->playerLives >= 1) {
			if (!App->render->Blit(graphics, 22, 18, &liveIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}

		if (App->player->playerLives >= 2) {
			if (!App->render->Blit(graphics, 38, 18, &liveIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}

		//BLITTING BOMBS
		if (App->player->playerBombs >= 1) {
			if (!App->render->Blit(graphics, 5, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}
		if (App->player->playerBombs >= 2) {
			if (!App->render->Blit(graphics, 20, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}

		if (App->player->playerBombs >= 3) {
			if (!App->render->Blit(graphics, 35, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}

		//BLITTING 1P
		if (!App->render->Blit(graphics, 5, 4, &p1_Icon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!p2) {
			//BLITTING 2P INSERT COIN
			if (!App->render->Blit(graphics, SCREEN_WIDTH / 2 + 6, 4, &(p2_insertCoin.GetCurrentFrame()), 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}
		else { //2P STUFF
			   //BLITTING 2P
			if (!App->render->Blit(graphics, SCREEN_WIDTH / 2 + 6, 4, &p2_Icon, 1.0f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			//BLITTING BOMBS 2P
			if (App->player2->playerLives >= 1) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 17, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (App->player2->playerLives >= 2) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 32, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (App->player2->playerLives >= 3) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 47, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (App->player2->playerLives >= 0) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 87, 18, &liveIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (App->player2->playerLives >= 1) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 70, 18, &liveIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			if (App->player2->playerLives >= 2) {
				if (!App->render->Blit(graphics, SCREEN_WIDTH - 53, 18, &liveIcon, 1.0f)) {
					LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}

			char str[10];
			sprintf_s(str, "%i", scoreP2);

			int x_correction = SCREEN_WIDTH - 30;
			if (scoreP2 > 99)
				x_correction -= fonts[font_score].char_w;
			if (scoreP2 > 999)
				x_correction -= fonts[font_score].char_w;
			if (scoreP2 > 9999)
				x_correction -= fonts[font_score].char_w;
			this->BlitText(x_correction, 4, font_score, str);
		}
	}
	else { //UI

		if (highestScore > 0) {
			char str3[10];
			sprintf_s(str3, "%i", highestScore);
			int x_correction = SCREEN_WIDTH / 2;
			if (highestScore > 99)
				x_correction -= fonts[font_score].char_w;
			if (highestScore > 999)
				x_correction -= fonts[font_score].char_w;
			if (highestScore > 9999)
				x_correction -= fonts[font_score].char_w;
			this->BlitText( x_correction, 44, font_score, str3);
		}

		if (!App->render->Blit(graphics, 40, 60, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		
		if (!App->render->Blit(graphics, 60, 60, &p1_Icon, 1.0f)) {
			LOG("Cannot blit the texture in ScoreRanking %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		char str[10];
		sprintf_s(str, "%i", score);
		this->BlitText(140, 60, font_score, str);


		if (!App->render->Blit(graphics, 40, 80, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphics, 60, 80, &p2_Icon, 1.0f)) {
			LOG("Cannot blit the texture in ScoreRanking %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		char str2[10];
		sprintf_s(str2, "%i", scoreP2);
		this->BlitText(140, 80, font_score, str2);
	}
	
	
	

	return status;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading ModuleUI");

	if (score >= scoreP2 && score > highestScore) {
		highestScore = score;
	}
	else if (score < scoreP2 && scoreP2 > highestScore) {
		highestScore = scoreP2;
	}

	bool ret = true;

	this->UnLoad(font_score);

	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in ModuleUI");
		ret = false;
	}

	return ret;
}

// Load new texture from file path
int ModuleUI::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if (texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if (tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for (; id < MAX_FONTS; ++id)
		if (fonts[id].graphic == nullptr)
			break;

	if (id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	fonts[id].graphic = tex; // graphic: pointer to the texture
	fonts[id].rows = rows; // rows: rows of characters in the texture

	fonts[id].len = strlen(characters);

	fonts[id].row_chars = fonts[id].len / rows;

	strcpy_s(fonts[id].table, MAX_FONT_CHARS, characters);

	uint wTex = 0, hTex = 0;
	App->textures->GetSize(tex, wTex, hTex);

	fonts[id].char_w = wTex / fonts[id].row_chars;
	fonts[id].char_h = hTex / rows;


	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleUI::UnLoad(int font_id)
{
	if (font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bitmap font
void ModuleUI::BlitText(int x, int y, int font_id, const char* text) const
{
	if (text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	if (strcmp(text ,"0") == 0)
		text = "00";

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	for (uint i = 0; i < len; ++i)
	{
		// TODO 2: Find the character in the table and its position in the texture, then Blit
		for (int j = 0; j < font->len; j++)
		{
			if (text[i] == fonts->table[j]) {
				rect.x = rect.w * (j % font->row_chars);
				rect.y = rect.h * (j / font->row_chars);
				App->render->Blit(font->graphic, x, y, &rect, 1.0f);
				x += font->char_w;
				break;
			}
		}
		
	}
}
