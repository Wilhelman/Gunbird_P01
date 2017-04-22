#include "Application.h"
#include "SceneCastle_houseFlag.h"
#include "ModuleCollision.h"
#include "Path.h"
#include "SDL\include\SDL_timer.h"

SceneCastle_houseFlag::SceneCastle_houseFlag(int x, int y) : Enemy(x, y)
{

	lives = 10; // Blink red when lives = 8

	houseFlag.PushBack({ 433, 2, 95, 100 });
	houseFlag.PushBack({ 433, 104, 95, 100 });
	houseFlag.PushBack({ 433, 206, 95, 101 });
	houseFlag.PushBack({ 433, 309, 95, 101 });
	houseFlag.PushBack({ 433, 412, 95, 101 });
	houseFlag.PushBack({ 433, 515, 95, 101 });
	houseFlag.PushBack({ 433, 619, 95, 103 });
	houseFlag.PushBack({ 433, 723, 95, 103 });
	houseFlag.speed = 0.08f;
	houseFlag.loop = true;

	hitWhite.PushBack({333, 4, 94, 99});
	hitWhite.speed = 0.5f;
	hitWhite.loop = true;

	hitRed.PushBack({ 433, 2, 95, 100 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 104, 95, 100 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 206, 95, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 309, 95, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 412, 95, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 515, 95, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 619, 95, 103 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 433, 723, 95, 103 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.PushBack({ 333, 106, 94, 101 });
	hitRed.speed = 0.08f;
	hitRed.loop = true;

	animation = &houseFlag;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 22, 64, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void SceneCastle_houseFlag::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);

	if (animation == &hitWhite && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &houseFlag;
		lastTime = 0;
	}

	if (lives <= 2 && animation != &hitWhite)
		animation = &hitRed;
	

}

void SceneCastle_houseFlag::OnCollision(Collider* collider) {

	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		animation = &hitWhite;
		//App->particles->AddParticle(&(App->particles->playerShotCollison), ); 
		lives--;
		// TODO: check if PowerUp increases damage to houses too
	}
	
}
uint SceneCastle_houseFlag::getLives() {
	return lives;
}