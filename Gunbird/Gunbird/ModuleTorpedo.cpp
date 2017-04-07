#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTorpedo.h"
#include "ModuleCollision.h"


ModuleTorpedo::ModuleTorpedo()//test
{
	// idle animation
	idle.PushBack({ 0, 37, 18, 32 });
	idle.PushBack({ 23, 38, 16, 32 });
	idle.PushBack({ 42, 38, 22, 32 });
	idle.PushBack({ 65, 38, 26, 32 });
	idle.PushBack({ 0, 74, 28, 32 });
	idle.PushBack({ 30, 74, 26, 32 });
	idle.PushBack({ 60, 74, 23, 32 });
	idle.PushBack({ 84, 74, 16, 32 });
	idle.speed = 0.25f;
	
}

ModuleTorpedo::~ModuleTorpedo()
{}

// Load assets
bool ModuleTorpedo::Start()
{
	livesTorpedo = 3;
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;

	LOG("Creating torpedo collider...");
	torpedoCollider = App->collision->AddCollider({ position.x, position.y, 28 , idle.GetCurrentFrame().h }, COLLIDER_ENEMY, this);

	LOG("Loading torpedo textures...");
	bool ret = true;
	graphics = App->textures->Load("Assets/maps/castle/enemies_castle.png");
	if (graphics == nullptr)
		ret = false;

	return ret;
}

// Update: draw background
update_status ModuleTorpedo::Update()
{
	update_status status = UPDATE_CONTINUE;

	Animation* current_animation = &idle;

	int speed = 3;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//update player collider
	torpedoCollider->SetPos(position.x, position.y - r.h);

	if (!App->render->Blit(graphics, position.x, position.y - r.h, &r)) {
		LOG("Cannot blit the texture in ModuleTorpedo %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	return status;
}

// Unload assets
bool ModuleTorpedo::CleanUp()
{
	LOG("Unloading torpedo enemy");

	App->collision->EraseCollider(torpedoCollider);
	App->textures->Unload(graphics);

	return true;
}

void ModuleTorpedo::OnCollision(Collider* c1, Collider* c2) {
	if (c2->type == COLLIDER_PLAYER_SHOT) {
		livesTorpedo--;
	}
	
}