#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_WALL][COLLIDER_COIN] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOMB] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_POWER_UP] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOMB] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_POWER_UP] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_BOMB] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_COIN] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_BOMB] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2_BOMB] = true;

	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_COIN] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER_BOMB] = true;
	matrix[COLLIDER_ENEMY_FLYING][COLLIDER_PLAYER2_BOMB] = true;

	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_COIN] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER_BOMB] = true;
	matrix[COLLIDER_ENEMY_FLYING_AGGRESSIVE][COLLIDER_PLAYER2_BOMB] = true;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_COIN] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_POWER_UP][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_WALL] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_COIN] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_BOMB] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_COIN][COLLIDER_COIN] = false;
	matrix[COLLIDER_COIN][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_COIN][COLLIDER_WALL] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_COIN][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_COIN][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_COIN][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_COIN][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_COIN][COLLIDER_BOMB] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_COIN][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_BOMB][COLLIDER_BOMB] = false;
	matrix[COLLIDER_BOMB][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_BOMB][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_FLYING] = false;
	matrix[COLLIDER_BOMB][COLLIDER_COIN] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER_BOMB][COLLIDER_PLAYER2_BOMB] = false;

	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_ENEMY_FLYING] = true;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_COIN] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_ENEMY_FLYING_AGGRESSIVE] = true;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER_BOMB] = false;
	matrix[COLLIDER_PLAYER2_BOMB][COLLIDER_PLAYER2_BOMB] = false;
	
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if (debug == false)
		return;

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_ENEMY_FLYING: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_ENEMY_FLYING_AGGRESSIVE: // red with blue
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 200, alpha);
			break;
		case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER2_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case COLLIDER_COIN: // brown
			App->render->DrawQuad(colliders[i]->rect, 204, 102, 0, alpha);
			break;
		case COLLIDER_BOMB: // brown
			App->render->DrawQuad(colliders[i]->rect, 204, 102, 0, alpha);
			break;
		case COLLIDER_POWER_UP: // orange
			App->render->DrawQuad(colliders[i]->rect, 255, 165, 0, alpha);
			break;
		case COLLIDER_PLAYER2: // pink
			App->render->DrawQuad(colliders[i]->rect, 243, 143, 237, alpha);
			break;
		case COLLIDER_PLAYER2_BOMB: // idk
			App->render->DrawQuad(colliders[i]->rect, 100, 102, 20, alpha);
			break;
		case COLLIDER_PLAYER_BOMB: // idk
			App->render->DrawQuad(colliders[i]->rect, 100, 102, 20, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool ModuleCollision::EraseCollider(Collider* collider)
{
	if (collider != nullptr)
	{
		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] == collider)
			{
				collider->to_delete = true;
				break;
			}
		}
	}


	return false;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}

