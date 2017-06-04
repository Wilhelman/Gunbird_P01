#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "SDL\include\SDL_pixels.h"
#include "Animation.h"

#define MAX_FONTS 10
#define MAX_FONT_CHARS 256

struct SDL_Texture;

struct Font
{
	char table[MAX_FONT_CHARS];
	SDL_Texture* graphic = nullptr;
	uint rows, len, char_w, char_h, row_chars;
};

class ModuleUI : public Module
{

public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;

	SDL_Rect liveIcon;
	SDL_Rect p1_Icon;
	SDL_Rect liveIcon_Tetsu;
	SDL_Rect bombIcon;

	Animation p2_insertCoin;
	SDL_Rect p2_Icon;
	SDL_Rect p2_liveIcon;

	// Load Font
	int Load(const char* texture_path, const char* characters, uint rows = 1);
	void UnLoad(int font_id);

	// Create a surface from text
	void BlitText(int x, int y, int bmp_font_id, const char* text) const;

	int score;
	int scoreP2;
	int highestScore;
	bool p2;
private:

	Font	 fonts[MAX_FONTS];

	int font_score = -1;
};

#endif