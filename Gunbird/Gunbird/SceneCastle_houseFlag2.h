#ifndef __SceneCastle_houseFlag2_H__
#define __SceneCastle_houseFlag2_H__

#include "Enemy.h"


class SceneCastle_houseFlag2 : public Enemy
{
private:
	Animation houseFlag_2;
	iPoint original_pos;

public:


	SceneCastle_houseFlag2(int x, int y);
	void Move();
	void OnCollision(Collider* collider);

	uint lives;
	uint getLives();
};

#endif