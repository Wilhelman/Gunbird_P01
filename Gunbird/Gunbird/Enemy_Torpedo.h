#ifndef __Enemy_Torpedo_H__
#define __Enemy_Torpedo_H__

#include "Enemy.h"


class Enemy_Torpedo : public Enemy
{
private:
	Animation fly;
	iPoint original_pos;

public:

	Enemy_Torpedo(int x, int y);

	void Move();
};

#endif