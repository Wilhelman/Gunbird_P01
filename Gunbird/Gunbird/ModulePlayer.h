#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define INMORTAL_TIME 2000
#define HITTED_TIME 1500

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
private:
	unsigned short laserType;
	int original_camera_y;

	uint currentTime;
	uint lastTime;
	uint spawnTime;

	bool hitted;
	uint hittedTime;
	

public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

	void removePowerUp();

public:
	uint shotPower;
	SDL_Texture* graphics = nullptr;
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
};

#endif