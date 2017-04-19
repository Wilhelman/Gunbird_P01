#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"

#include <string.h>
#include<stdio.h>


ModuleUI::ModuleUI()
{
	for (int i = 0; i < 3; i++)
	{
		livesCount[i] = true;
	}

	liveIcon.x = 255;
	liveIcon.y = 152;
	liveIcon.w = 15;
	liveIcon.h = 12;

	bombIcon.x = 207;
	bombIcon.y = 151;
	bombIcon.w = 12;
	bombIcon.h = 15;
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

	char str[10];
	sprintf_s(str, "%i", score);
	this->BlitText(100, 100, font_score, str);

	if (App->player->playerLives >= 0) {
		if (!App->render->Blit(graphics, 5, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (App->player->playerLives >= 1) {
		if (!App->render->Blit(graphics, 22, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (App->player->playerLives >= 2) {
		if (!App->render->Blit(graphics, 38, 16, &liveIcon, 1.0f)) {
			LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (!App->render->Blit(graphics, 5 , SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
		LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (!App->render->Blit(graphics, 20, SCREEN_HEIGHT - 24, &bombIcon, 1.0f)) {
		LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}
	

	return status;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading ModuleUI");

	bool ret = true;

	this->UnLoad(font_score);

	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in ModuleUI");
		ret = false;
	}

	return false;
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
