#ifndef __Enemy_TerrestialTurres_H__
#define __Enemy_TerrestialTurres_H__

#include "Enemy.h"

class Enemy_TerrestialTurret : public Enemy
{
private:
	Animation turret;
	int original_y = 0;

public:
	Enemy_TerrestialTurret(int x, int y);
	void Move();
};

#endif
