#ifndef __Enemy_TerrestialTurres_H__
#define __Enemy_TerrestialTurres_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_TerrestialTurret : public Enemy
{
private:
	
	Animation turretAnimation;
	Animation death;
	iPoint original_pos;
	Path turret1_path;
	Path turret2_path;
	Path turret3_path;

public:

	Enemy_TerrestialTurret(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
};

#endif
