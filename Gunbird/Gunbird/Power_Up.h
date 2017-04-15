#ifndef __Power_Up_H__
#define __Power_Up_H__

#include "Enemy.h"

class Power_Up : public Enemy
{
private:
	Animation powerUp_animation;
	bool up;
	bool right;

public:
	
	Power_Up(int x, int y);
	void Move();

};

#endif