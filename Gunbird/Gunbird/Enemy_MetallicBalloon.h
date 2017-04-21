#ifndef __Enemy_MetallicBalloon_H__
#define __Enemy_MetallicBallon_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MetallicBalloon : public Enemy
{
private:
	Animation fly;
	Animation hitWhite;
	Animation redNormal;
	Animation redNormal_2;
	Animation redNormal_3;
	iPoint original_pos;

	uint lastShot;
	

public:

	Enemy_MetallicBalloon(int x, int y);

	void Move();
	void Shoot();

	void OnCollision(Collider* collider);
	uint getLives();
};

#endif