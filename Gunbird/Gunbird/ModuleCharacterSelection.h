#ifndef __ModuleCharacterSelection_H__
#define __ModuleCharacterSelection_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

struct SDL_Texture;

enum CHARACTER_SELECTED
{
	NONE_SELECTED,
	ASH_SELECTED,
	MARION_SELECTED,
	VALNUS_SELECTED,
	YUANG_NANG_SELECTED,
	TETSU_SELECTED
};

class ModuleCharacterSelection : public Module
{
public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* characterGraphics = nullptr;
	SDL_Texture* tetsuAnimGraphics = nullptr;
	SDL_Texture* valnusAnimGrahics = nullptr;
	SDL_Texture* icons_locked = nullptr;

	SDL_Rect background;
	SDL_Rect valnus_frame;
	SDL_Rect tetsu_frame;
	SDL_Rect ash_frame;
	SDL_Rect marion_frame;
	SDL_Rect yuang_nang_frame;
	SDL_Rect selector_p1;
	SDL_Rect selector_p2;
	SDL_Rect sky;
	SDL_Rect valnusName;
	SDL_Rect marionName;
	SDL_Rect ashName;
	SDL_Rect tetsuName;
	SDL_Rect yuangNangName;
	SDL_Rect yuangNangName_short;

	bool selectorPos1[5];
	bool selectorPos2[5];
	bool selection_control_P1;
	bool selection_control_P2;
	bool player2_joined;
	bool selected_P1_done;
	bool selected_P2_done;
	
	//AUDIO
	uint valnus_selection;
	uint tetsu_selection;
	uint selector_mov;
	uint locked_character;

	uint scrollLeft;
	uint currentTime;
	uint lastTime;
	uint lastTime2;
	uint counter;

	float sky_speed;
	float sky_x;

	Animation idleTetsu;
	Animation* tetsu;

	Animation idleValnus;
	Animation* valnus;

	Animation lockedYuangNang;
	Animation* yuangNang;

	Animation lockedAsh;
	Animation* ash;

	Animation lockedMarion;
	Animation* marion;

	Animation valnusFigure;
	Animation tetsuFigure;
	Animation marionFigure;
	Animation yuangNangFigure;
	Animation ashFigure;

	enum CHARACTER_SELECTOR
	{
		NONE,
		ASH,
		MARION,
		VALNUS,
		YUANG_NANG,
		TETSU
	};

	int moveAnim_y;
	int moveAnim_y2;

	CHARACTER_SELECTOR currentCharacter_P1;
	CHARACTER_SELECTOR currentCharacter_P2;

	CHARACTER_SELECTED characterSelected_P1;
	CHARACTER_SELECTED characterSelected_P2;
};

#endif