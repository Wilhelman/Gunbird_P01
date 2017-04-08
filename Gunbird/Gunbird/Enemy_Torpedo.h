#ifndef __Enemy_Torpedo_H__
#define __Enemy_Torpedo_H__

#include "Enemy.h"

class Enemy_Torpedo : public Enemy
{
private:
	int original_y = 0;
	Animation fly;

public:

	Enemy_Torpedo(int x, int y);

	void Move();
};

#endif