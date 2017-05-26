#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL_gamecontroller.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{

	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	LOG("Init the controller (search and asign)");
	controller = nullptr;
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i)) {
			controller = SDL_GameControllerOpen(i);
			break;
		}
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	if (keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) == 1) {
		if (gamepad.A == PAD_BUTTON_IDLE)
			gamepad.A = PAD_BUTTON_DOWN;
		else
			gamepad.A = PAD_BUTTON_REPEAT;
	}

	//Normalized direction
	/*int xDir = 0;
	int yDir = 0;

	while (SDL_PollEvent(&ev) != 0) {
		if (ev.type == SDL_CONTROLLERBUTTONDOWN) {
			LOG("HOLA SOY EL MANDO");
			if (ev.cbutton.button == SDL_CONTROLLER_BUTTON_A) {
				//TODO: implement the stuff
			}
			if (ev.cbutton.button == SDL_CONTROLLER_BUTTON_B) {

			}
			
		}
		if (ev.type == SDL_JOYAXISMOTION) {
			//Motion on controller 0
			if (ev.jaxis.which == 0)
			{
				//X axis motion
				if (ev.jaxis.axis == 0)
				{
					//Left of dead zone
					if (ev.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						xDir = -1;
					}
					//Right of dead zone
					else if (ev.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						xDir = 1;
					}
					else
					{
						xDir = 0;
					}
				}
				//Y axis motion
				else if (ev.jaxis.axis == 1)
				{
					//Below of dead zone
					if (ev.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						yDir = -1;
					}
					//Above of dead zone
					else if (ev.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						yDir = 1;
					}
					else
					{
						yDir = 0;
					}
				}
		}
	}*/

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}