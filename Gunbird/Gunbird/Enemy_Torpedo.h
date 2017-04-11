#ifndef __Enemy_Torpedo_H__
#define __Enemy_Torpedo_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Torpedo : public Enemy
{
private:
	Animation fly;
	Path diagonalPathL_R;
	Path horizontalPathR_L;
	iPoint original_pos;

public:

	Enemy_Torpedo(int x, int y);

	void Move();
};

#endif