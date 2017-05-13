#ifndef __Enemy_Bee_H__
#define __Enemy_Bee_H__

#include "Enemy.h"
#include "ModuleParticles.h";


class Enemy_Bee : public Enemy
{
private:
	Animation fly;
	Animation bee_white;
	iPoint original_pos;

public:

	Enemy_Bee(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif