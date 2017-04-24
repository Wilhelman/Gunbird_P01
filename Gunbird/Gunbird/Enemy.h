#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"

struct Path;
struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	uint lives;
	uint currentTime;
	uint lastTime;

public:
	iPoint position;
	int type;
	Path movement;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Shoot() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	virtual uint getLives() { return 0; }
};

#endif // __ENEMY_H__