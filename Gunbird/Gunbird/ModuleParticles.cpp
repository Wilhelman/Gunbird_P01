#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	//Death Player Explosion
	
	deathPlayerExplosion.anim.PushBack({ 241,1059,86,86 });
	deathPlayerExplosion.anim.PushBack({ 413,1058,97,96 });
	deathPlayerExplosion.anim.PushBack({ 580,1048,113,111 });
	deathPlayerExplosion.anim.PushBack({ 750,1055,97,96 });
	deathPlayerExplosion.anim.PushBack({ 910,1048,113,111 });
	deathPlayerExplosion.anim.PushBack({ 1089,1051,97,96 });
	deathPlayerExplosion.anim.PushBack({ 1268,1046,113,111 });
	deathPlayerExplosion.anim.PushBack({ 42,1202,128,129 });
	deathPlayerExplosion.anim.PushBack({ 234,1210,102,95 });
	deathPlayerExplosion.anim.PushBack({ 400,1195,128,129 });
	deathPlayerExplosion.anim.PushBack({ 582,1196,129,129 });
	deathPlayerExplosion.anim.PushBack({ 755,1204,106,103 });
	deathPlayerExplosion.anim.PushBack({ 911,1190,130,129 });
	deathPlayerExplosion.anim.PushBack({ 1099,1202,106,130 });
	deathPlayerExplosion.anim.PushBack({ 1267,1187,129,129 });
	deathPlayerExplosion.anim.PushBack({ 64,1381,100,101 });
	deathPlayerExplosion.anim.PushBack({ 227,1365,129,129 });
	deathPlayerExplosion.anim.PushBack({ 424,1375,100,102 });
	deathPlayerExplosion.anim.PushBack({ 538,1358,127,129 });
	deathPlayerExplosion.anim.PushBack({ 764,1369,100,102 });
	deathPlayerExplosion.anim.PushBack({ 917,1358,127,128 });
	deathPlayerExplosion.anim.PushBack({ 1105,1363,102,105 });
	deathPlayerExplosion.anim.PushBack({ 1275,1359,127,127 });
	deathPlayerExplosion.anim.PushBack({ 70,1562,102,104 });
	deathPlayerExplosion.anim.PushBack({ 248,1557,100,105 });
	deathPlayerExplosion.anim.PushBack({ 430,1552,100,105 });
	deathPlayerExplosion.anim.PushBack({ 608,1548,100,107 });
	deathPlayerExplosion.anim.PushBack({ 770,1551,100,107 });
	deathPlayerExplosion.anim.PushBack({ 939,1551,100,106 });
	deathPlayerExplosion.anim.PushBack({ 1121,1573,83,84 });
	deathPlayerExplosion.anim.PushBack({ 1297,1572,83,84 });
	deathPlayerExplosion.anim.PushBack({ 80,1757,84,109 });
	deathPlayerExplosion.anim.PushBack({ 259,1755,84,108 });
	deathPlayerExplosion.anim.PushBack({ 450,1768,66,81 });
	deathPlayerExplosion.anim.PushBack({ 629,1763,66,81 });
	deathPlayerExplosion.anim.PushBack({ 788,1783,71,51 });
	deathPlayerExplosion.anim.PushBack({ 930,1782,71,51 });

	deathPlayerExplosion.anim.speed = 0.03f;
	deathPlayerExplosion.speed.y = 0;
	deathPlayerExplosion.anim.loop = false;


	//laser particle
	laser0.anim.PushBack({ 613, 801, 15, 19 });
	laser1.anim.PushBack({ 634, 801, 15, 19 });
	laser2.anim.PushBack({ 652, 801, 15, 19 });

	laser0_1.anim.PushBack({ 673, 801, 25, 28 });
	laser1_1.anim.PushBack({ 706, 801, 25, 28 });
	laser2_1.anim.PushBack({ 737, 801, 25, 28 });

	laser0.anim.loop = false;
	laser0.anim.speed = 0.1f;
	laser0.speed.y = -5;
	laser0.life = 3000;
	laser0_1.anim.loop = false;
	laser0_1.anim.speed = 0.1f;
	laser0_1.speed.y = -5;
	laser0_1.life = 3000;

	laser1.anim.loop = false;
	laser1.anim.speed = 0.1f;
	laser1.speed.y = -5;
	laser1.life = 2000;
	laser1_1.anim.loop = false;
	laser1_1.anim.speed = 0.1f;
	laser1_1.speed.y = -5;
	laser1_1.life = 2000;

	laser2.anim.loop = false;
	laser2.anim.speed = 0.1f;
	laser2.speed.y = -5;
	laser2.life = 2000;
	laser2_1.anim.loop = false;
	laser2_1.anim.speed = 0.1f;
	laser2_1.speed.y = -5;
	laser2_1.life = 2000;

	//balloon death explosion
	balloonDeathExplosion.anim.PushBack({ 54, 504, 92, 86 });
	balloonDeathExplosion.anim.PushBack({ 153, 499, 101, 93 });
	balloonDeathExplosion.anim.PushBack({ 261, 496, 105, 102 });
	balloonDeathExplosion.anim.PushBack({ 378, 497, 99, 101 });
	balloonDeathExplosion.anim.PushBack({ 49, 606, 101, 104 });
	balloonDeathExplosion.anim.PushBack({ 157, 607, 99, 104 });
	balloonDeathExplosion.anim.PushBack({ 266, 606, 99, 106 });
	balloonDeathExplosion.anim.PushBack({ 380, 613, 100, 105 });
	balloonDeathExplosion.anim.PushBack({ 60, 750, 82, 83 });
	balloonDeathExplosion.anim.PushBack({ 160, 730, 83, 107 });
	balloonDeathExplosion.anim.PushBack({ 276, 749, 66, 79 });
	balloonDeathExplosion.anim.PushBack({ 388, 769, 70, 50 });


	balloonDeathExplosion.life = 1000;
	balloonDeathExplosion.anim.speed = 0.2f;
	balloonDeathExplosion.speed.y = 1;
	balloonDeathExplosion.anim.loop = false;

	//Terrestial Turret Explosion
	terrestialTurretExplosion.anim.PushBack({ 45,120,47,38 });
	terrestialTurretExplosion.anim.PushBack({ 114,119,47,45 });
	terrestialTurretExplosion.anim.PushBack({ 183,114,49,54 });
	terrestialTurretExplosion.anim.PushBack({ 253,110,55,62 });
	terrestialTurretExplosion.anim.PushBack({ 337,108,51,58 });
	terrestialTurretExplosion.anim.PushBack({ 416,105,54,61 });
	terrestialTurretExplosion.anim.PushBack({ 494,108,54,64 });
	terrestialTurretExplosion.anim.PushBack({ 11,321,54,64 });//change coords
	terrestialTurretExplosion.anim.PushBack({ 83,321,54,65 });//
	terrestialTurretExplosion.anim.PushBack({ 158,322,54,64 });//
	terrestialTurretExplosion.anim.PushBack({ 235,322,57,64 });//
	terrestialTurretExplosion.anim.PushBack({ 305,323,58,66 });//
	terrestialTurretExplosion.anim.PushBack({ 385,325,58,66 });//
	terrestialTurretExplosion.anim.PushBack({ 467,330,56,64 });//
	terrestialTurretExplosion.anim.PushBack({ 14,422,54,61 });//
	terrestialTurretExplosion.anim.PushBack({ 89,425,52,60 });//change coords
	
	terrestialTurretExplosion.life = 1000;
	terrestialTurretExplosion.anim.speed = 0.2f;
	terrestialTurretExplosion.speed.y = 1;
	terrestialTurretExplosion.anim.loop = false;

	//Torpedo Explosion

	torpedoExplosion.anim.PushBack({ 870,123,22,20 });
	torpedoExplosion.anim.PushBack({ 894,119,33,28 });
	torpedoExplosion.anim.PushBack({ 929,119,42,30 });
	torpedoExplosion.anim.PushBack({ 974,116,49,37 });
	torpedoExplosion.anim.PushBack({ 1031,118,48,35 });
	torpedoExplosion.anim.PushBack({ 817,157,41,30 });
	torpedoExplosion.anim.PushBack({ 919,162,33,22 });
	torpedoExplosion.anim.PushBack({ 957,166,31,16 });
	torpedoExplosion.anim.PushBack({ 993,167,26,15 });
	
	torpedoExplosion.life = 1000;
	torpedoExplosion.anim.speed = 0.2f;
	torpedoExplosion.speed.y = 1;
	torpedoExplosion.anim.loop = false;

}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{

	LOG("Loading particles");
	graphics = App->textures->Load("Assets/particles/particles.png"); 

	LOG("Loading fx sound to laser particle");
	laser0.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser2.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");

	laser0_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser1_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser2_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->audio->UnLoadFx(laser0.fx);

	App->textures->Unload(graphics);
	graphics = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i ];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
			}
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	if (collider_type != COLLIDER_NONE) {
		LOG("Creating particle colliders...");
		p->collider = App->collision->AddCollider({p->position.x, p->position.y, p->anim.GetCurrentFrame().w , p->anim.GetCurrentFrame().h}, collider_type, this);
	}
	 
	active[last_particle++] = p;
	if (last_particle == MAX_ACTIVE_PARTICLES)
		last_particle = 0;
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	if (!SDL_GetTicks() - born > 0) {
		position.x += speed.x;
		position.y += speed.y;
	}

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

Particle::~Particle() {
	if (collider != nullptr)
		collider->to_delete = true;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}