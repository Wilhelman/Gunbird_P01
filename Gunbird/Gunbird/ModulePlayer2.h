#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"

#define INMORTAL_TIME 2000
#define HITTED_TIME 1500

struct SDL_Texture;
struct Collider;


class ModulePlayer2 : public Module
{
private:
	unsigned short laserType;
	int original_camera_y;

	uint currentTime;
	uint lastTime;
	uint spawnTime;
	uint bombTimer;

	bool hitted;
	uint hittedTime;

	//playerSoundEffects
	uint tetsu_Hitted = 0;
	uint tetsu_Death = 0;
	uint tetsu_PowerUp = 0;

public:
	ModulePlayer2();
	~ModulePlayer2();

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
	Animation player2Collision_Anim;
	Animation* current_animation;
	iPoint position;
	Collider* playerCollider;
	Collider* bombCollider_H;
	Collider* bombCollider_V;
	iPoint bombPos;

	Particle init_bomb1;
	Particle init_bomb2;
	Particle init_bomb3;
	Particle init_bomb4;
	Particle init_flames;

	bool inmortal;
	int playerLives;
	int playerBombs;
	bool deadPlayer;
	int counter = 0;
	bool shotControl = false;
	bool playerExpControl;
	bool playerLost;
	bool godModeControl;
	bool spawining;
	bool canThrowBomb;

};

#endif