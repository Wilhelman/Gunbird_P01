#ifndef __Enemy_Mecha_Boss_H__
#define __Enemy_Mecha_Boss_H__

#include "Enemy.h"
#include "Path.h"
#include "ModuleParticles.h"

class Enemy_Mecha_Boss : public Enemy
{
private:
	bool left;

	Animation idle;
	Animation hitWhite;
	Animation redNormal;
	Animation redNormal_2;
	Animation redNormal_3;
	iPoint original_pos;
	uint bombTimer;
	bool bomb;
	uint lastShot;
	uint burstTimer;
	uint burstCombo;

	Particle lastParticle;

public:

	Enemy_Mecha_Boss(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif