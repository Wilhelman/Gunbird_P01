#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

	void OnCollision(Collider* c1, Collider* c2);

private:

	SDL_Texture* graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;

public:

	//Valnus shots
	Particle laser0;
	Particle laser1;
	Particle laser2;

	Particle laser0_1;
	Particle laser1_1;
	Particle laser2_1;

	Particle laser0_2;
	Particle laser1_2;
	Particle laser2_2;

	Particle laser0_3;
	Particle laser1_3;
	Particle laser2_3;

	//Valnus special green thunder shots
	Particle greenThunder_1;
	Particle greenThunder_2;
	Particle greenThunder_3;
	Particle greenThunder_4;
	Particle greenThunder_5;
	Particle greenThunder_6;
	Particle greenThunder_7;
	Particle greenThunder_8;
	Particle greenThunder_9;
	Particle greenThunder_10;
	Particle greenThunder_11;
	Particle greenThunder_12;

	//TETSU shots
	Particle laser_Tetsu0_0;
	Particle laser_Tetsu1_0;
	Particle laser_Tetsu2_0;
	Particle laser_Tetsu3_0;

	Particle laser_Tetsu0_1;
	Particle laser_Tetsu1_1;
	Particle laser_Tetsu2_1;
	Particle laser_Tetsu3_1;

	//player death explosion
	Particle deathPlayerExplosion;

	//enemies basic shot
	Particle enemyBasicShot_start;
	Particle enemyBasicShot;

	//enemies death explosion
	Particle balloonDeathExplosion;
	Particle terrestialTurretExplosion;
	Particle torpedoExplosion;
	Particle vaseExplosion;

	//Particles for player shot collision
	Particle playerShotCollison;

	uint enemy_hitted;

};

#endif // __MODULEPARTICLES_H__