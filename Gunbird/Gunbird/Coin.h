#ifndef __Coin_H__
#define __Coin_H__

#include "Enemy.h"

class Coin : public Enemy
{
private:
	Animation coin_animation;
	iPoint original_pos;

public:

	Coin(int x, int y);
	void Move();

};

#endif