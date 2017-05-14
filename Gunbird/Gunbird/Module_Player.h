#ifndef __Module_Player_H__
#define __Module_Player_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCharacterSelection.h"

#define INMORTAL_TIME 2000
#define HITTED_TIME 1500

struct SDL_Texture;
struct Collider;


class Module_Player : public Module
{
private:
	
	uint characterResult(uint characterSlected, uint CharacterSelected)
	{

	}



public:
	Module_Player();
	~Module_Player();

	bool Init();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

	void removePowerUp();
	void spawning();

public:
	uint shotPower;
	SDL_Texture* graphics = nullptr;
	Animation godMode;
	Animation idle;
	Animation blink;
	Animation right_animation;
	Animation right_idle_animation;
	Animation left_idle_animation;
	Animation left_animation;
	Animation dead_animation;
	Animation dead_animation_explosion;
	Animation playerCollision_Anim;
	Animation* current_animation;
	iPoint position;
	Collider* playerCollider;

	bool inmortal;
	int playerLives;
	bool deadPlayer;
	int counter = 0;
	bool shotControl = false;
	bool playerExpControl;
	bool playerLost;
	bool godModeControl;
	bool spawining;

};

#endif