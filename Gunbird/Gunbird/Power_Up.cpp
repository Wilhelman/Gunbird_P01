#include "Application.h"
#include "Power_Up.h"
#include "ModuleCollision.h"
#include "Path.h"

Power_Up::Power_Up(int x, int y) : Enemy(x, y)
{
	powerUp_animation.PushBack({ 561, 935, 22, 13 });
	powerUp_animation.PushBack({ 586, 935, 22, 13 });
	powerUp_animation.PushBack({ 611, 935, 22, 13 });
	powerUp_animation.PushBack({ 636, 935, 22, 13 });
	powerUp_animation.PushBack({ 661, 935, 22, 13 });

	powerUp_animation.PushBack({ 561, 951, 22, 13 });
	powerUp_animation.PushBack({ 586, 951, 22, 13 });
	powerUp_animation.PushBack({ 611, 951, 22, 13 });
	powerUp_animation.PushBack({ 636, 951, 22, 13 });
	powerUp_animation.PushBack({ 661, 951, 22, 13 });

	powerUp_animation.PushBack({ 561, 968, 22, 13 });
	powerUp_animation.PushBack({ 586, 968, 22, 13 });
	powerUp_animation.PushBack({ 611, 968, 22, 13 });
	powerUp_animation.PushBack({ 636, 968, 22, 13 });
	powerUp_animation.PushBack({ 661, 968, 22, 13 });

	powerUp_animation.PushBack({ 561, 987, 22, 13 });
	powerUp_animation.PushBack({ 586, 987, 22, 13 });
	powerUp_animation.PushBack({ 611, 987, 22, 13 });
	powerUp_animation.PushBack({ 636, 987, 22, 13 });
	powerUp_animation.speed = 0.4f;

	animation = &powerUp_animation;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 22, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

	up = true;
	right = true;
}

void Power_Up::Move()
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
