#ifndef __Enemy_Torpedo_H__
#define __Enemy_Torpedo_H__

#include "Enemy.h"
#include "ModuleParticles.h";


class Enemy_Torpedo : public Enemy
{
private:
	Animation fly;
	Animation torpedo_white;
	iPoint original_pos;

public:

	Enemy_Torpedo(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
};

#endif