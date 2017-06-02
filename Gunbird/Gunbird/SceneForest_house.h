#ifndef __SceneForest_house_H__
#define __SceneForest_house_H__

#include "Enemy.h"
#include "ModuleParticles.h"

class SceneForest_house : public Enemy {


private: 
	Animation Forest_house;
	iPoint original_pos;



public:
	SceneForest_house(int x, int y);
	void Move();
	void OnCollision(Collider* collider);

	uint lives;
	uint getLives();

};





#endif // !__SceneForest_house_H__
