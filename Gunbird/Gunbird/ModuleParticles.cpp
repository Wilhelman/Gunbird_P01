#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	
	//Death Player Explosion
	{
		deathPlayerExplosion.anim.PushBack({ 216,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 397,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 568,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 733,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 901,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1072,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1259,1038,130,129 });
		deathPlayerExplosion.anim.PushBack({ 40,1200,130,129 });
		deathPlayerExplosion.anim.PushBack({ 220,1200,130,129 });
		deathPlayerExplosion.anim.PushBack({ 400,1195,130,129 });
		deathPlayerExplosion.anim.PushBack({ 581,1195,130,129 });
		deathPlayerExplosion.anim.PushBack({ 742,1195,130,129 });
		deathPlayerExplosion.anim.PushBack({ 911,1190,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1085,1190,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1267,1187,130,129 });
		deathPlayerExplosion.anim.PushBack({ 47,1370,130,129 });
		deathPlayerExplosion.anim.PushBack({ 226,1365,130,129 });
		deathPlayerExplosion.anim.PushBack({ 407,1365,130,129 });
		deathPlayerExplosion.anim.PushBack({ 582,1358,130,129 });
		deathPlayerExplosion.anim.PushBack({ 747,1359,130,129 });
		deathPlayerExplosion.anim.PushBack({ 915,1358,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1093,1353,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1274,1357,130,129 });
		deathPlayerExplosion.anim.PushBack({ 54,1552,130,129 });
		deathPlayerExplosion.anim.PushBack({ 232,1545,130,129 });
		deathPlayerExplosion.anim.PushBack({ 413,1542,130,129 });
		deathPlayerExplosion.anim.PushBack({ 592,1539,130,129 });
		deathPlayerExplosion.anim.PushBack({ 754,1540,130,129 });
		deathPlayerExplosion.anim.PushBack({ 923,1540,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1094,1549,130,129 });
		deathPlayerExplosion.anim.PushBack({ 1272,1540,130,129 });
		deathPlayerExplosion.anim.PushBack({ 60,1747,130,129 });
		deathPlayerExplosion.anim.PushBack({ 236,1747,130,129 });
		deathPlayerExplosion.anim.PushBack({ 420,1747,130,129 });
		deathPlayerExplosion.anim.PushBack({ 597,1742,130,129 });
		deathPlayerExplosion.anim.PushBack({ 762,1744,130,129 });
		deathPlayerExplosion.anim.PushBack({ 906,1744,130,129 });

		deathPlayerExplosion.anim.speed = 1.0f;
		deathPlayerExplosion.speed.y = 1;
		deathPlayerExplosion.anim.loop = false;
	}

	//laser particle VALNUS
	{
		laser0.anim.PushBack({ 613, 801, 15, 19 });
		laser1.anim.PushBack({ 634, 801, 15, 19 });
		laser2.anim.PushBack({ 652, 801, 15, 19 });

		laser0_1.anim.PushBack({ 673, 801, 25, 28 });
		laser1_1.anim.PushBack({ 706, 801, 25, 28 });
		laser2_1.anim.PushBack({ 737, 801, 25, 28 });

		laser0.anim.loop = false;
		laser0.anim.speed = 0.1f;
		laser0.speed.y = -5;
		laser0.life = 3000;

		laser0_1.anim.loop = false;
		laser0_1.anim.speed = 0.1f;
		laser0_1.speed.y = -5;
		laser0_1.life = 3000;


		laser1.anim.loop = false;
		laser1.anim.speed = 0.1f;
		laser1.speed.y = -5;
		laser1.life = 2000;

		laser1_1.anim.loop = false;
		laser1_1.anim.speed = 0.1f;
		laser1_1.speed.y = -5;
		laser1_1.life = 2000;


		laser2.anim.loop = false;
		laser2.anim.speed = 0.1f;
		laser2.speed.y = -5;
		laser2.life = 2000;

		laser2_1.anim.loop = false;
		laser2_1.anim.speed = 0.1f;
		laser2_1.speed.y = -5;
		laser2_1.life = 2000;


		////////////////////////////////////////////////////
		laser0_2.anim.PushBack({ 614, 839, 31, 32 });
		laser1_2.anim.PushBack({ 652, 839, 31, 32 });
		laser2_2.anim.PushBack({ 690, 839, 29, 32 });

		laser0_3.anim.PushBack({ 614, 877, 45, 42 });
		laser1_3.anim.PushBack({ 664, 877, 43, 42 });
		laser2_3.anim.PushBack({ 712, 877, 41, 42 });

		laser0_2.anim.loop = false;
		laser0_2.anim.speed = 0.1f;
		laser0_2.speed.y = -5;
		laser0_2.life = 3000;

		laser1_2.anim.loop = false;
		laser1_2.anim.speed = 0.1f;
		laser1_2.speed.y = -5;
		laser1_2.life = 3000;

		laser2_2.anim.loop = false;
		laser2_2.anim.speed = 0.1f;
		laser2_2.speed.y = -5;
		laser2_2.life = 3000;


		laser0_3.anim.loop = false;
		laser0_3.anim.speed = 0.1f;
		laser0_3.speed.y = -5;
		laser0_3.life = 3000;

		laser1_3.anim.loop = false;
		laser1_3.anim.speed = 0.1f;
		laser1_3.speed.y = -5;
		laser1_3.life = 3000;

		laser2_3.anim.loop = false;
		laser2_3.anim.speed = 0.1f;
		laser2_3.speed.y = -5;
		laser2_3.life = 3000;

	}

	// Valnus green thunder shots
	{
		greenThunder1_1.anim.PushBack({ 6,2201,104,280 });
		greenThunder1_1.anim.PushBack({ 115,2200,104,280 });
		greenThunder1_1.anim.PushBack({ 222,2199,104,280 });
		greenThunder1_1.anim.PushBack({ 342,2205,104,280 });
		greenThunder1_1.anim.loop = false;
		greenThunder1_1.anim.speed = 0.2f;
		greenThunder1_1.life = 200;

		greenThunder1_2.anim.PushBack({ 459,2202,104,280 });
		greenThunder1_2.anim.PushBack({ 608,2207,104,280 });
		greenThunder1_2.anim.PushBack({ 934,2207,104,280 });
		greenThunder1_2.anim.PushBack({ 788,2207,104,280 });
		greenThunder1_2.anim.PushBack({ 1097,2207,104,280 });
		greenThunder1_2.anim.loop = false;
		greenThunder1_2.anim.speed = 0.2f;
		greenThunder1_2.life = 200;

		greenThunder1_3.anim.PushBack({ 59,2570,104,280 });
		greenThunder1_3.anim.PushBack({ 226,2570,104,280 });
		greenThunder1_3.anim.PushBack({ 395,2560,104,280 });
		greenThunder1_3.anim.loop = false;
		greenThunder1_3.anim.speed = 0.2f;
		greenThunder1_3.life = 200;

		////////////////////
		greenThunder2_1.anim.PushBack({798, 3414, 134, 288});
		greenThunder2_1.anim.PushBack({ 79, 3096, 134, 288 });
		greenThunder2_1.anim.PushBack({ 229, 3096, 134, 288 });
		greenThunder2_1.anim.PushBack({ 372, 3096, 134, 288 });
		greenThunder2_1.anim.loop = false;
		greenThunder2_1.anim.speed = 0.2f;
		greenThunder2_1.life = 200;

		greenThunder2_2.anim.PushBack({ 522, 3101, 134, 288 });
		greenThunder2_2.anim.PushBack({ 659, 3101, 134, 288 });
		greenThunder2_2.anim.PushBack({ 859, 3098, 134, 288 });
		greenThunder2_2.anim.PushBack({ 1015, 3100, 134, 288 });
		greenThunder2_2.anim.PushBack({ 75, 3455, 134, 288 });
		greenThunder2_2.anim.loop = false;
		greenThunder2_2.anim.speed = 0.2f;
		greenThunder2_2.life = 200;

		greenThunder2_3.anim.PushBack({ 272, 3472, 134, 288 });
		greenThunder2_3.anim.PushBack({ 475, 3472, 134, 288 });
		greenThunder2_3.anim.PushBack({ 1007, 3472, 134, 288 });
		greenThunder2_3.anim.loop = false;
		greenThunder2_3.anim.speed = 0.2f;
		greenThunder2_3.life = 200;
	}

	// Valnus bomb
	{
		valnusBomb.anim.PushBack({2473, 854, 576, 576});
		valnusBomb.anim.PushBack({ 3073, 862, 576, 576 });
		valnusBomb.anim.PushBack({ 2459, 167, 576, 576 });
		valnusBomb.anim.PushBack({ 2573, 1806, 576, 576 });
		valnusBomb.anim.PushBack({ 3118, 1806, 576, 576 });
		valnusBomb.anim.PushBack({ 2168, 2714, 576, 576 });
		valnusBomb.anim.PushBack({ 2749, 2714, 576, 576 });
		valnusBomb.anim.PushBack({ 3329, 2713, 576, 576 });
		valnusBomb.anim.PushBack({ 2167, 3297, 576, 576 });
		valnusBomb.anim.PushBack({ 2701, 3297, 576, 576 });
		valnusBomb.anim.loop = false;
		valnusBomb.anim.speed = 0.2f;
		valnusBomb.life = 3000;
	}


	//laser particle TETSU
	{
		laser_Tetsu0_0.anim.PushBack({ 1390,2177,15,29 });
		laser_Tetsu1_0.anim.PushBack({ 1390,2217,15,29 });
		laser_Tetsu2_0.anim.PushBack({ 1390,2257,15,29 });
		laser_Tetsu3_0.anim.PushBack({ 1390,2297,15,29 });
		
		laser_Tetsu0_0.anim.loop = false;
		laser_Tetsu0_0.anim.speed = 0.1f;
		laser_Tetsu0_0.speed.y = -5;
		laser_Tetsu0_0.life = 3000;

		laser_Tetsu1_0.anim.loop = false;
		laser_Tetsu1_0.anim.speed = 0.1f;
		laser_Tetsu1_0.speed.y = -5;
		laser_Tetsu1_0.life = 3000;

		laser_Tetsu2_0.anim.loop = false;
		laser_Tetsu2_0.anim.speed = 0.1f;
		laser_Tetsu2_0.speed.y = -5;
		laser_Tetsu2_0.life = 3000;

		laser_Tetsu3_0.anim.loop = false;
		laser_Tetsu3_0.anim.speed = 0.1f;
		laser_Tetsu3_0.speed.y = -5;
		laser_Tetsu3_0.life = 3000;


		laser_Tetsu0_1.anim.PushBack({ 1431,2105,31,41 });
		laser_Tetsu1_1.anim.PushBack({ 1429,2161,31,41 });
		laser_Tetsu2_1.anim.PushBack({ 1429,2225,31,41 });
		laser_Tetsu3_1.anim.PushBack({ 1429,2285,31,41 });

		laser_Tetsu0_1.anim.loop = false;
		laser_Tetsu0_1.anim.speed = 0.1f;
		laser_Tetsu0_1.speed.y = -5;
		laser_Tetsu0_1.life = 3000;

		laser_Tetsu1_1.anim.loop = false;
		laser_Tetsu1_1.anim.speed = 0.1f;
		laser_Tetsu1_1.speed.y = -5;
		laser_Tetsu1_1.life = 3000;

		laser_Tetsu2_1.anim.loop = false;
		laser_Tetsu2_1.anim.speed = 0.1f;
		laser_Tetsu2_1.speed.y = -5;
		laser_Tetsu2_1.life = 3000;

		laser_Tetsu3_1.anim.loop = false;
		laser_Tetsu3_1.anim.speed = 0.1f;
		laser_Tetsu3_1.speed.y = -5;
		laser_Tetsu3_1.life = 3000;

		laser_Tetsu0_2.anim.PushBack({ 1477,2282,45,45 });
		laser_Tetsu0_2.anim.loop = false;
		laser_Tetsu0_2.anim.speed = 0.1f;
		laser_Tetsu0_2.speed.y = -5;
		laser_Tetsu0_2.life = 3000;
	
	}


	//balloon death explosion
	{
		balloonDeathExplosion.anim.PushBack({ 54, 504, 92, 86 });
		balloonDeathExplosion.anim.PushBack({ 153, 499, 101, 93 });
		balloonDeathExplosion.anim.PushBack({ 261, 496, 105, 102 });
		balloonDeathExplosion.anim.PushBack({ 378, 497, 99, 101 });
		balloonDeathExplosion.anim.PushBack({ 49, 606, 101, 104 });
		balloonDeathExplosion.anim.PushBack({ 157, 607, 99, 104 });
		balloonDeathExplosion.anim.PushBack({ 266, 606, 99, 106 });
		balloonDeathExplosion.anim.PushBack({ 380, 613, 100, 105 });
		balloonDeathExplosion.anim.PushBack({ 60, 750, 82, 83 });
		balloonDeathExplosion.anim.PushBack({ 160, 730, 83, 107 });
		balloonDeathExplosion.anim.PushBack({ 276, 749, 66, 79 });
		balloonDeathExplosion.anim.PushBack({ 388, 769, 70, 50 });

		balloonDeathExplosion.life = 1000;
		balloonDeathExplosion.anim.speed = 0.2f;
		balloonDeathExplosion.speed.y = 1;
		balloonDeathExplosion.anim.loop = false;
	}

	//Terrestial Turret Explosion
	{
		terrestialTurretExplosion.anim.PushBack({ 45,120,47,38 });
		terrestialTurretExplosion.anim.PushBack({ 114,119,47,45 });
		terrestialTurretExplosion.anim.PushBack({ 183,114,49,54 });
		terrestialTurretExplosion.anim.PushBack({ 253,110,55,62 });
		terrestialTurretExplosion.anim.PushBack({ 337,108,51,58 });
		terrestialTurretExplosion.anim.PushBack({ 416,105,54,61 });
		terrestialTurretExplosion.anim.PushBack({ 494,108,54,64 });
		terrestialTurretExplosion.anim.PushBack({ 11,321,54,64 });//change coords
		terrestialTurretExplosion.anim.PushBack({ 83,321,54,65 });//
		terrestialTurretExplosion.anim.PushBack({ 158,322,54,64 });//
		terrestialTurretExplosion.anim.PushBack({ 235,322,57,64 });//
		terrestialTurretExplosion.anim.PushBack({ 305,323,58,66 });//
		terrestialTurretExplosion.anim.PushBack({ 385,325,58,66 });//
		terrestialTurretExplosion.anim.PushBack({ 467,330,56,64 });//
		terrestialTurretExplosion.anim.PushBack({ 14,422,54,61 });//
		terrestialTurretExplosion.anim.PushBack({ 89,425,52,60 });//change coords

		terrestialTurretExplosion.life = 1000;
		terrestialTurretExplosion.anim.speed = 0.2f;
		terrestialTurretExplosion.speed.y = 1;
		terrestialTurretExplosion.anim.loop = false;
	}

	//Torpedo Explosion
	{
		torpedoExplosion.anim.PushBack({ 870,123,22,20 });
		torpedoExplosion.anim.PushBack({ 894,119,33,28 });
		torpedoExplosion.anim.PushBack({ 929,119,42,30 });
		torpedoExplosion.anim.PushBack({ 974,116,49,37 });
		torpedoExplosion.anim.PushBack({ 1031,118,48,35 });
		torpedoExplosion.anim.PushBack({ 817,157,41,30 });
		torpedoExplosion.anim.PushBack({ 919,162,33,22 });
		torpedoExplosion.anim.PushBack({ 957,166,31,16 });
		torpedoExplosion.anim.PushBack({ 993,167,26,15 });

		torpedoExplosion.life = 1000;
		torpedoExplosion.anim.speed = 0.2f;
		torpedoExplosion.speed.y = 1;
		torpedoExplosion.anim.loop = false;
	}

	//Vase Explosion
	{
		vaseExplosion.anim.PushBack({ 45,120,47,38 });
		vaseExplosion.anim.PushBack({ 114,119,47,45 });
		vaseExplosion.anim.PushBack({ 183,114,49,54 });
		vaseExplosion.anim.PushBack({ 253,110,55,62 });
		vaseExplosion.anim.PushBack({ 337,108,51,58 });
		vaseExplosion.anim.PushBack({ 416,105,54,61 });
		vaseExplosion.anim.PushBack({ 494,108,54,64 });
		vaseExplosion.anim.PushBack({ 11,321,54,64 });//change coords
		vaseExplosion.anim.PushBack({ 83,321,54,65 });//
		vaseExplosion.anim.PushBack({ 158,322,54,64 });//
		vaseExplosion.anim.PushBack({ 235,322,57,64 });//
		vaseExplosion.anim.PushBack({ 305,323,58,66 });//
		vaseExplosion.anim.PushBack({ 385,325,58,66 });//
		vaseExplosion.anim.PushBack({ 467,330,56,64 });//
		vaseExplosion.anim.PushBack({ 14,422,54,61 });//
		vaseExplosion.anim.PushBack({ 89,425,52,60 });//change coords

		vaseExplosion.life = 1000;
		vaseExplosion.anim.speed = 0.2f;
		vaseExplosion.speed.y = 1;
		vaseExplosion.anim.loop = false;
	}

	//Enemy Basic Shot
	{
		enemyBasicShot.anim.PushBack({ 1509,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1525,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1541,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1557,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1573,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1589,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1605,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1621,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1637,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1653,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1669,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1685,245,6,6 });
		enemyBasicShot.anim.PushBack({ 1701,245,6,6 });

		enemyBasicShot.anim.PushBack({ 1509,261,6,6 });
		enemyBasicShot.anim.PushBack({ 1525,261,6,6 });
		enemyBasicShot.anim.PushBack({ 1541,261,6,6 });
		enemyBasicShot.anim.PushBack({ 1557,261,6,6 });
		enemyBasicShot.anim.PushBack({ 1573,261,6,6 });

		enemyBasicShot.life = 3000;
		enemyBasicShot.anim.speed = 0.1f;
		enemyBasicShot.anim.loop = true;
	}

	//Enemy Basic Shot Start
	{
		enemyBasicShot_start.anim.PushBack({ 1509,229,8,8 });
		enemyBasicShot_start.anim.PushBack({ 1525,229,8,8 });

		enemyBasicShot_start.anim.speed = 2.0f;
		//enemyBasicShot.speed.y = 0;
		enemyBasicShot_start.anim.loop = false;
	}


	//Player shot collision animation
	{
		playerShotCollison.anim.PushBack({ 888, 776, 11, 16 });
		playerShotCollison.anim.PushBack({ 913, 772, 12, 20 });
		playerShotCollison.anim.PushBack({ 935, 772, 12, 20 });
		playerShotCollison.anim.PushBack({ 959, 765, 12, 27 });
		playerShotCollison.anim.PushBack({ 984, 759, 12, 33 });
		playerShotCollison.anim.PushBack({ 1010, 753, 13, 29 });
		playerShotCollison.anim.PushBack({ 1037, 747, 13, 45 });
		playerShotCollison.anim.PushBack({ 1064, 749, 14, 42 });
		playerShotCollison.anim.PushBack({ 886, 810, 14, 37 });
		playerShotCollison.anim.PushBack({ 918, 810, 14, 37 });
		playerShotCollison.anim.PushBack({ 948, 805, 14, 41 });
		playerShotCollison.anim.PushBack({ 983, 808, 14, 38 });
		playerShotCollison.anim.PushBack({ 1013, 805, 14, 41 });
		playerShotCollison.anim.PushBack({ 1045, 804, 14, 42 });
		playerShotCollison.anim.PushBack({ 886, 871, 14, 9 });
		playerShotCollison.anim.PushBack({ 920, 869, 14, 9 });
		playerShotCollison.anim.PushBack({ 954, 866, 14, 11 });
		playerShotCollison.anim.PushBack({ 1025, 866, 14, 9 });
		playerShotCollison.anim.PushBack({ 1062, 865, 9, 8 });
		playerShotCollison.anim.PushBack({ 897, 894, 3, 11 });
		playerShotCollison.anim.PushBack({ 931, 893, 3, 12 });
		playerShotCollison.anim.PushBack({ 965, 893, 3, 12 });
		playerShotCollison.anim.PushBack({ 1000, 892, 3, 13 });
		playerShotCollison.anim.PushBack({ 1036, 892, 3, 13 });
		playerShotCollison.anim.PushBack({ 1073, 891, 3, 5 });
		playerShotCollison.anim.PushBack({ 887, 925, 14, 26 });
		playerShotCollison.anim.speed = 0.5f;
		playerShotCollison.anim.loop = true;
	}

	//tetsu ini bomb

	{
		
		tetsu_iniBomb.anim.PushBack({ 1694,2094,20,15 });
		tetsu_iniBomb.anim.PushBack({ 1717,2094,21,15 });
		tetsu_iniBomb.anim.PushBack({ 1741,2095,22,13 });
		tetsu_iniBomb.anim.PushBack({ 1765,2094,23,14 });
		tetsu_iniBomb.anim.PushBack({ 1791,2094,24,14 });
		tetsu_iniBomb.anim.PushBack({ 1818,2094,25,14 });
		tetsu_iniBomb.anim.PushBack({ 1846,2094,26,15 });
		tetsu_iniBomb.anim.PushBack({ 1875,2093,27,155 });
		tetsu_iniBomb.anim.PushBack({ 1905,2095,26,11 });
		tetsu_iniBomb.anim.PushBack({ 1934,2095,26,12 });
		tetsu_iniBomb.anim.PushBack({ 1962,2094,26,13 });
		tetsu_iniBomb.anim.PushBack({ 1991,2093,28,15 });
		tetsu_iniBomb.anim.PushBack({ 2024,2093,26,15 });

		tetsu_iniBomb.life = 500;
		tetsu_iniBomb.anim.loop = true;


	}
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{

	LOG("Loading particles");
	graphics = App->textures->Load("Assets/particles/particles.png"); 

	LOG("Loading fx sound to laser particle");
	laser0.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser2.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");

	laser0_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser1_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");
	laser2_1.fx = App->audio->LoadFx("Assets/audio/effects/valnus_shot_1_2.wav");

	LOG("Loading audio fx for enemy hitted by player shot");
	enemy_hitted = App->audio->LoadFx("Assets/audio/effects/enemy_hitted.wav");
	
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->audio->UnLoadFx(laser0.fx);

	App->textures->Unload(graphics);
	graphics = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->position.y < -10 || p->position.y > SCREEN_HEIGHT && p != &valnusBomb) {
			delete p;
			active[i] = nullptr;
		}
		else if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
			}
		}
		
	}
	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	if (collider_type != COLLIDER_NONE) {
		p->collider = App->collision->AddCollider({p->position.x, p->position.y, p->anim.GetCurrentFrame().w , p->anim.GetCurrentFrame().h}, collider_type, this);
	}
	 
	active[last_particle++] = p;
	if (last_particle == MAX_ACTIVE_PARTICLES)
		last_particle = 0;
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	if (!SDL_GetTicks() - born > 0) {
		position.x += speed.x;
		position.y += speed.y;
	}

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

Particle::~Particle() {
	if (collider != nullptr){
		App->collision->EraseCollider(collider);
		collider = nullptr;
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}

	if((c1-> type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT || c1->type == COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT) && (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_FLYING))
		App->audio->PlayFx(enemy_hitted);
}