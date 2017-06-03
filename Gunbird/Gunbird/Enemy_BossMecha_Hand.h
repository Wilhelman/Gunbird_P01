#ifndef __Enemy_BossMecha_Hand_H__
#define __Enemy_BossMecha_Hand_H__

#include "Enemy.h"
#include "Path.h"
#include "ModuleParticles.h"

class Enemy_BossMecha_Hand : public Enemy
{
private:
	bool left;

	Animation idle;
	Animation hitWhite;
	Animation redNormal;
	Animation redNormal_2;
	Animation redNormal_3;
	iPoint original_pos;

	uint lastShot;

	Particle lastParticle;

public:

	Enemy_BossMecha_Hand(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif