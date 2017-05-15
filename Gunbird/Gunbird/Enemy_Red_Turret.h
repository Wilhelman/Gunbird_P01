#ifndef __Enemy_Red_Turret_H__
#define __Enemy_Red_Turret_H__

#include "Enemy.h"
#include "Path.h" 
#include "ModuleParticles.h"

class Enemy_Red_Turret : public Enemy
{
private:

	//ROTATION TURRET ANIMATIONS
	Animation redTurretIdle;

	iPoint original_pos;

	uint lastShot;
	Particle lastParticle;
	bool left;
	bool dead;
	float deadTimer;

public:

	Enemy_Red_Turret(int x, int y);
	void Move();
	void Shoot();
	uint getLives();
	void OnCollision(Collider* collider);
};

#endif
