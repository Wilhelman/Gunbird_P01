#ifndef __Enemy_Big_Red_Turret_H__
#define __Enemy_Big_Red_Turret_H__

#include "Enemy.h"
#include "Path.h"
#include "ModuleParticles.h"

class Enemy_Big_Red_Turret : public Enemy
{
private:
	bool left;

	Animation fly;
	iPoint original_pos;

	uint lastShot;
	uint lastComboShot;
	Particle lastParticle;
	uint shotCombo;

public:

	Enemy_Big_Red_Turret(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif