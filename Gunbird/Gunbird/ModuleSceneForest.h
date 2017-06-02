#ifndef __ModuleSceneForest_H__
#define __ModuleSceneForest_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "ModuleParticles.h"

struct SDL_Texture;

class ModuleSceneForest : public Module
{
private:
	int spawned = 0;

	Animation miner_down;
	Animation miner_up;
	Animation miner_dright_down;
	float miner_up_y;
	float beam_y;
	float beamShadow_y;
	float miner_brokenMecha_y;
	float miner_down_y;
	float miner_right_x;
	float miner_dright_x;
	float miner_dright_y;
	float trump_y;
	float trump_x;
	Animation beamRight;
	Animation beamLeft;
	Animation shadowBeam;
	Animation miner_rigth;
	Animation miner_drigth;
	Animation miner_dleft;
	Animation brokenMecha;
	Animation trump_spikyHair1;
	Animation trump_spikyHair2;
	Animation trumphat1;
	Animation trumpHat2;
	
	SDL_Rect motion_trees_1;
	float motion_trees_1_x;
	float motion_trees_1_y;
	
	SDL_Rect motion_trees_2;
	float motion_trees_2_x;
	float motion_trees_2_y;
	
	SDL_Rect motion_trees_3;
	float motion_trees_3_x;
	float motion_trees_3_y;
	
	SDL_Rect motion_trees_4;
	float motion_trees_4_x;
	float motion_trees_4_y;
	
	SDL_Rect motion_trees_5;
	float motion_trees_5_x;
	float motion_trees_5_y;
	
	SDL_Rect motion_trees_6;
	float motion_trees_6_x;
	float motion_trees_6_y;

	SDL_Rect motion_trees_7;
	float motion_trees_7_x;
	float motion_trees_7_y;

	SDL_Rect motion_trees_8;
	float motion_trees_8_x;
	float motion_trees_8_y;
public:
	ModuleSceneForest();
	~ModuleSceneForest();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphic_miner = nullptr;
	SDL_Texture* motionless_trees = nullptr;
	SDL_Texture* motion_trees = nullptr;
	SDL_Rect background;
	SDL_Rect m_trees;
	float background_x;
	float background_y;

	float background_speed;

	uint player2joined;

	
};

#endif