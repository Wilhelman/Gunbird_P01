#ifndef __Enemy_Flying_Machine_H__
#define __Enemy_Flying_Machine_H__

#include "Enemy.h"
#include "Path.h" 
#include "ModuleParticles.h"

class Enemy_Flying_Machine : public Enemy
{
private:


	Animation fly;
	Animation shot_phase_anim_open;
	Animation shot_phase_anim_close;

	iPoint original_pos;

	uint lastShot;
	Particle lastParticle;
	bool dead;
	bool shot_done;
	float deadTimer;

public:

	Enemy_Flying_Machine(int x, int y);
	void Move();
	void Shoot();
	uint getLives();
	void OnCollision(Collider* collider);
};

#endif
