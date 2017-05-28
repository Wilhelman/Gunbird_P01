#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL/include/SDL.h"
#include "p2Point.h"

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
	PAD_BUTTON_KEY_UP
};

struct Gamepad {
	GAMEPAD_STATE A = PAD_BUTTON_IDLE;
	GAMEPAD_STATE B;
	GAMEPAD_STATE Y;
	GAMEPAD_STATE X;
	GAMEPAD_STATE START;
	GAMEPAD_STATE BACK;
	GAMEPAD_STATE CROSS_UP;
	GAMEPAD_STATE CROSS_DOWN;
	GAMEPAD_STATE CROSS_LEFT;
	GAMEPAD_STATE CROSS_RIGHT;
	p2Point<float> movementJoystick;
	bool joystickUp;
	bool joystickDown;
	bool joystickLeft;
	bool joystickRight;
	bool joystickLeftCharacterSelection;
	bool joystickRightCharacterSelection;
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
	void buttonForGamepad();

private:
	int controllerCharacterSelection;
	SDL_Event ev;
	SDL_GameController *controller;
};

#endif // __ModuleInput_H__