#ifndef __Enemy_BossMecha_Hand_H__
#define __Enemy_BossMecha_Hand_H__

#include "Enemy.h"
#include "Path.h"
#include "ModuleParticles.h"

class Enemy_BossMecha_Hand : public Enemy
{
private:
	bool left;
	bool dead;
	Animation opening;
	Animation rotation;
	Animation hitWhite;
	Animation redNormal;
	Animation redNormal_2;
	Animation redNormal_3;
	Animation handClosed;
	iPoint original_pos;
	uint bombTimer;
	bool bomb;
	uint lastShot;
	int randomTimer;
	Particle lastParticle;

public:

	Enemy_BossMecha_Hand(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif