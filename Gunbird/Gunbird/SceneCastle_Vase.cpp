#include "Application.h"
#include "SceneCastle_Vase.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleCollision.h"
#include "Path.h"


SceneCastle_Vase::SceneCastle_Vase(int x, int y) : Enemy(x, y)
{
	lives = 11;

	vase.PushBack({ 552,578,33,49 });
	vase.loop = true;

	/*vaseRed.PushBack({ 552,578,33,49 });
	vaseRed.PushBack({ 552,578,33,49 });
	vaseRed.PushBack({ 552,578,33,49 });
	vaseRed.PushBack({ 552,578,33,49 });*/
	
	vaseWhite.PushBack({ 593,579,33,49 });
	vaseWhite.loop = false;

	animation = &vase;

	original_pos.x = x;
	original_pos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 33, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}
void SceneCastle_Vase::Move()
{
	position = original_pos + movement.GetCurrentPosition(&animation);

	if (animation == &vaseWhite && lastTime == 0) {
		lastTime = SDL_GetTicks();
	}

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &vase;
		lastTime = 0;
	}
}
void SceneCastle_Vase::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || collider->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) {
		App->particles->AddParticle(App->particles->playerShotCollison, (collider->rect.x + (((collider->rect.w)) / 2)), (collider->rect.y - (((collider->rect.h)))));
		animation = &vaseWhite;
		lives--;
	}
}
uint SceneCastle_Vase::getLives() {
	return lives;
}