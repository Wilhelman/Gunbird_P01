#include "Application.h"
#include "SceneCastle_houseFlag2.h"
#include "ModuleCollision.h"
#include "Path.h"
#include "SDL\include\SDL_timer.h"

SceneCastle_houseFlag2::SceneCastle_houseFlag2(int x, int y) : Enemy(x, y)
{

	lives = 26; // blinks red when lives = 15 

	houseFlag_2.PushBack({ 45, 659, 96, 99 });
	houseFlag_2.PushBack({ 162, 659, 98, 98 });
	houseFlag_2.PushBack({ 279, 659, 98, 100 });
	houseFlag_2.PushBack({ 45, 769, 96, 98 });
	houseFlag_2.PushBack({ 162, 769, 97, 98 });
	houseFlag_2.PushBack({ 279, 769, 98, 100 });
	houseFlag_2.PushBack({ 45, 870, 96, 98 });
	houseFlag_2.PushBack({ 162, 870, 98, 98 });
	houseFlag_2.speed = 0.08f;
	houseFlag_2.loop = true;


	hitWhite.PushBack({297, 877, 98, 97});
	hitWhite.speed = 0.5f;
	hitWhite.loop = true;



	hitRed.PushBack({ 45, 659, 96, 99 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 162, 659, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 279, 659, 98, 100 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 45, 769, 96, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 162, 769, 97, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 279, 769, 98, 100 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 45, 870, 96, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 162, 870, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.PushBack({ 409, 876, 98, 98 });
	hitRed.speed = 0.08f;
	hitRed.loop = true;

	animation = &houseFlag_2;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 23, 72, 75 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void SceneCastle_houseFlag2::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);

	if (animation == &hitWhite && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &houseFlag_2;
		lastTime = 0;
	}

	if (lives <= 15 && animation != &hitWhite)
		animation = &hitRed;

}

void SceneCastle_houseFlag2::OnCollision(Collider* collider) {
	
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		animation = &hitWhite;
		lives--;
		// TODO: check if PowerUp increases damage to houses too
	}
}
uint SceneCastle_houseFlag2::getLives() {
	return lives;
}