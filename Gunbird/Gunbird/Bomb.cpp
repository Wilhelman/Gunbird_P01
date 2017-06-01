#include "Application.h"
#include "Bomb.h"
#include "ModuleCollision.h"
#include "Path.h"

Bomb::Bomb(int x, int y) : Enemy(x, y)
{
	powerUp_animation.PushBack({ 563, 1014, 23, 12 });
	powerUp_animation.PushBack({ 592, 1014, 23, 12 });
	powerUp_animation.PushBack({ 620, 1014, 23, 12 });
	powerUp_animation.PushBack({ 648, 1014, 23, 12 });

	powerUp_animation.PushBack({ 563, 1034, 23, 12 });
	powerUp_animation.PushBack({ 592, 1034, 23, 12 });
	powerUp_animation.PushBack({ 620, 1034, 23, 12 });
	powerUp_animation.PushBack({ 648, 1034, 23, 12 });
	powerUp_animation.speed = 0.4f;

	animation = &powerUp_animation;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 23, 12 }, COLLIDER_TYPE::COLLIDER_BOMB, (Module*)App->enemies);

	up = true;
	right = true;
}

void Bomb::Move()
{
	//TODO: randomize start movement somehow

	if (up)
		position.y -= 1;
	else
		position.y += 1;

	if (right)
		position.x += 1;
	else
		position.x -= 1;


	if (position.x < 50)
		right = true;

	if (position.x > SCREEN_WIDTH - 50)
		right = false;

	if (position.y < 70)
		up = false;

	if (position.y > SCREEN_HEIGHT - 70)
		up = true;
}
