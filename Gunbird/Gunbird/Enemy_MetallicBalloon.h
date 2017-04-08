#ifndef __Enemy_MetallicBalloon_H__
#define __Enemy_MetallicBallon_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_MetallicBalloon : public Enemy
{
private:
	Animation fly;
	Path path;
	iPoint original_pos;

public:

	Enemy_MetallicBalloon(int x, int y);

	void Move();
};

#endif