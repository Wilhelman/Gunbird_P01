#include"Coin.h"
#include "Application.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "Path.h"

Coin::Coin(int x, int y) : Enemy(x, y)
{
	LOG("Loading audio fx for coin");
	pickup_audio = App->audio->LoadFx("Assets/audio/effects/gunbird_Collect_Coin.wav");

	coin_animation.PushBack({ 689,585,13,17 });
	coin_animation.PushBack({ 713,584,13,17 });
	coin_animation.PushBack({ 738,586,13,17 });
	coin_animation.PushBack({ 766,588,13,17 });
	coin_animation.PushBack({ 692,613,13,17 });
	coin_animation.PushBack({ 716,615,13,17 });
	coin_animation.PushBack({ 742,615,13,17 });
	coin_animation.PushBack({ 765,616,13,17 });

	coin_animation.speed = 0.25f;
	coin_animation.loop = true;
	
	animation = &coin_animation;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 13, 17 }, COLLIDER_TYPE::COLLIDER_COIN, (Module*)App->enemies);

}

void Coin::Move(){

	position = original_pos + movement.GetCurrentPosition(&animation);

}

void Coin::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2) {
		App->audio->PlayFx(pickup_audio);
	}
}