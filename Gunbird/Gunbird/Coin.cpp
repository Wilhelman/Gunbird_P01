#include"Coin.h"
#include "Application.h"
#include "ModuleCollision.h"
#include "Path.h"

Coin::Coin(int x, int y) : Enemy(x, y)
{

	coin_animation.PushBack({ 689,585,13,17 });
	coin_animation.PushBack({ 713,584,13,17 });
	coin_animation.PushBack({ 738,586,13,17 });
	coin_animation.PushBack({ 766,588,13,17 });
	coin_animation.PushBack({ 692,613,13,17 });
	coin_animation.PushBack({ 716,615,13,17 });
	coin_animation.PushBack({ 742,615,13,17 });
	coin_animation.PushBack({ 765,616,13,17 });

	coin_animation.speed = 0.5f;
	coin_animation.loop = true;
	
	animation = &coin_animation;

	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 13, 17 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

}

void Coin::Move(){

	position.y += 1;

}