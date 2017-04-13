#ifndef __SceneCastle_houseFlag_H__
#define __SceneCastle_houseFlag_H__

#include "Enemy.h"


class SceneCastle_houseFlag : public Enemy
{
private:
	Animation houseFlag;
	iPoint original_pos;

public:


	SceneCastle_houseFlag(int x, int y);
	void Move();
	void OnCollision(Collider* collider);

	uint lives;
	uint getLives();
};

#endif