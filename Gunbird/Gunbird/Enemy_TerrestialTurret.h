#ifndef __Enemy_TerrestialTurres_H__
#define __Enemy_TerrestialTurres_H__

#include "Enemy.h"
#include "Path.h" 
#include "ModuleParticles.h"

class Enemy_TerrestialTurret : public Enemy
{
private:

	//ROTATION TURRET ANIMATIONS
	Animation turretDownAnimation;
	Animation turretRight_1;
	Animation turretRight_2;
	Animation turretRight_3;
	Animation turretRight_4;
	Animation turretRight_5;
	Animation turretRight_6;
	Animation turretRight_7;
	Animation turretRight_8;
	Animation turretRight_9;
	Animation turretRight_10;
	Animation turretRight_11;
	Animation turretRight_12;
	Animation turretRight_13;
	Animation turretRight_14;
	Animation turretRight_15;
	Animation turretRight_16;
	Animation turretRight_17;
	Animation turretRight_18;
	Animation turretRight_19;
	Animation turretRight_20;
	Animation turretRight_21;
	Animation turretRight_22;
	Animation turretRight_23;
	Animation turretRight_24;
	Animation turretRight_25;
	Animation turretRight_26;
	Animation turretRight_27;
	Animation turretRight_28;
	Animation turretRight_29;
	Animation turretRight_30;

	Animation death;
	iPoint original_pos;
	Path turret1_path;
	Path turret2_path;
	Path turret3_path;

	uint lastShot;
	Particle lastParticle;
	bool left;

public:

	Enemy_TerrestialTurret(int x, int y);
	void Move();
	void Shoot();          
	uint getLives();
	void OnCollision(Collider* collider);
};

#endif
