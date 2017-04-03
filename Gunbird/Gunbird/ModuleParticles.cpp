#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	//laser particle
	laser0.anim.PushBack({ 0, 114, 13, 19 });
	laser1.anim.PushBack({ 20, 114, 15, 19 });
	laser2.anim.PushBack({ 40, 114, 11, 19 });

	laser0.anim.loop = false;
	laser0.anim.speed = 0.1f;
	laser0.speed.y = -5;
	laser0.life = 3000;

	laser1.anim.loop = true;
	laser1.anim.speed = 0.1f;
	laser1.speed.y = -5;
	laser1.life = 2000;
	laser2.anim.loop = true;
	laser2.anim.speed = 0.1f;
	laser2.speed.y = -5;
	laser2.life = 2000;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/characters/valnus_spritesheet.png");

	
	LOG("Loading fx sound to laser particle");
	laser0.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->audio->UnLoadFx(laser0.fx);

	App->textures->Unload(graphics);

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
				if (!App->audio->PlayFx(p->fx)) {
					LOG("Error playing fx sound in Player Module");
					return UPDATE_ERROR;
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	active[last_particle++] = p;
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

	return ret;
}