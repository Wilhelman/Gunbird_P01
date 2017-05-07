#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL/include/SDL.h"

#define MAX_KEYS 300

//Analog joystick dead zone
#define JOYSTICK_DEAD_ZONE 8000

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum GAMEPAD_STATE
{
	PAD_BUTTON_IDLE = 0,
	PAD_BUTTON_DOWN,
	PAD_BUTTON_REPEAT,
	PAD_BUTTON_KEY_UP,
	PAD_X_AXIS_RIGHT,
	PAD_X_AXIS_LEFT,
	PAD_X_AXIS_IDLE,
	PAD_Y_AXIS_UP,
	PAD_Y_AXIS_DOWN,
	PAD_Y_AXIS_IDLE
};

struct Gamepad {
	GAMEPAD_STATE A;
	GAMEPAD_STATE B;
	GAMEPAD_STATE Y;
	GAMEPAD_STATE X;
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	Gamepad gamepad;

private:
	SDL_Event ev;
	SDL_GameController *controller;
};

#endif // __ModuleInput_H__