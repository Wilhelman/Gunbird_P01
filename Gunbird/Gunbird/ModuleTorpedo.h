#ifndef __ModuleTorpedo_H__
#define __ModuleTorpedo_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModuleTorpedo : public Module
{

public:
	ModuleTorpedo();
	~ModuleTorpedo();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	iPoint position;
	Collider* torpedoCollider;

};

#endif