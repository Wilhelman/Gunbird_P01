#ifndef __Bomb_H__
#define __Bomb_H__

#include "Enemy.h"

class Bomb : public Enemy
{
private:
	Animation powerUp_animation;
	bool up;
	bool right;

public:

	Bomb(int x, int y);
	void Move();

};

#endif