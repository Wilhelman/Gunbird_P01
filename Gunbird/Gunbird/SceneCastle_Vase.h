#ifndef __SceneCastle_Vase_H__
#define __SceneCastle_Vase_H__

#include "Enemy.h"


class SceneCastle_Vase : public Enemy
{
private:
	Animation vase;
	iPoint original_pos;

public:


	SceneCastle_Vase(int x, int y);
	
	void OnCollision(Collider* collider);

};

#endif