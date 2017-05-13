#ifndef __ModuleCharacterSelection_H__
#define __ModuleCharacterSelection_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

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

	SDL_Rect background;
	SDL_Rect valnus_frame;
	SDL_Rect tetsu_frame;
	SDL_Rect ash_frame;
	SDL_Rect marion_frame;
	SDL_Rect yuang_nang_frame;
	SDL_Rect selector_p1;
	SDL_Rect selector_p2;
	SDL_Rect sky;

	bool selectorPos1[5];
	bool selectorPos2[5];
	bool selection_control_P1;
	bool selection_control_P2;
	bool player2_joined;

	uint valnus_selection;
	uint scrollLeft;
	uint currentTime;

	enum CHARACTER
	{
		ASH, 
		MARION,
		VALNUS,
		YUANG_NANG,
		TETSU
	};

	CHARACTER currentCharacter_P1;
	CHARACTER currentCharacter_P2;
};

#endif