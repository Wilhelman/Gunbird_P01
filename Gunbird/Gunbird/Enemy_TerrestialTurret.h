#ifndef __Enemy_TerrestialTurres_H__
#define __Enemy_TerrestialTurres_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_TerrestialTurret : public Enemy
{
private:
	Animation turretAnimation;
	iPoint original_pos;
	Path path;

public:
	Enemy_TerrestialTurret(int x, int y);
	void Move();
};

#endif
