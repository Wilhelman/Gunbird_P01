#ifndef __Enemy_Trump_Red_Mecha_H__
#define __Enemy_Trump_Red_Mecha_H__

#include "Enemy.h"
#include "Path.h"
#include "ModuleParticles.h"

class Enemy_Trump_Red_Mecha : public Enemy
{
private:
	bool left;

	Animation walking_around;
	Animation standing;
	iPoint original_pos;

	uint lastShot;
	uint lastComboShot;
	Particle lastParticle;
	uint shotCombo;

public:

	Enemy_Trump_Red_Mecha(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif