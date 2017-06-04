# GUNBIRD
We're going to replicate the 1994 Gunbird game arcade version developed and published by Psyko as a tribute to the game. This project has been done by four catalan students of CITM - UPC (Terrasa, Spain).  

* Github wiki of the project: https://github.com/Wilhelman/Gunbird_P01/wiki
* Project web: https://wilhelman.github.io/Gunbird_P01/

## About the game

Gunbird was released in 1994 for arcades and belongs to the vertically scrolling shoot'em up genre and has both single-player and two-player cooperative modes.

The game allows you to choose between five different characters, each one with their own skills and powers. The objective of the game is to obtain the four shards  of a magic mirror in order to get a wish once they are all assembled. They will fight against The Trump (a group of three pirates) for the fragments of the mirror.

There are two loop with seven levels each. The four shards of the mirror are obtained in the first four levels (which are randomly selected) and the wish is made once the player has completed three extra levels. In the end of each level you’ll have one boss to beat and a piece of the main plot is revealed. But in the second loop the difficult is increased and the story plot is removed.

## Installation instructions

Download the zip file and unzip it. Open the folder, execute the .exe and enjoy!*

_IMPORTANT: do not modify, change or add any folder or file as you might not be able to execute the game._

*The game is currently in development. The releases uploaded are just the first versions of the final game.

## Controls

### Keyboard:

Player 1 controls:
- UP: W key
- LEFT / MOVE SELECTOR LEFT: A key
- RIGHT / MOVE SELECTOR RIGHT:: D key
- DOWN: S key
- BASIC SHOT: SPACE key
- SELECT CHARACTER: SPACE key 
- BOMB: B key

Player 2 controls:
- UP: UP_ARROW key
- LEFT / MOVE SELECTOR LEFT: LEFT_ARROW key
- RIGHT / MOVE SELECTOR RIGHT:: RIGHT_ARROW key
- DOWN: DOWN_ARROW key
- BASIC SHOT: 1 key (NUMPAD)
- JOIN THE GAME: 2 key (NUMPAD)
- JOIN THE GAME (in-game): 1 key (NUMPAD)
- SELECT CHARACTER: 1 key (NUMPAD)
- BOMB: 2 key (NUMPAD)

General/developer controls:
- SKIP SCREEN: SPACE key
- EXIT GAME: ESC key
- SHOW COLLIDERS: F1
- DIRECT WIN: F3
- DIRECT TO BOSS: F5

General/developer controls for Player 1:
- GOD MODE: F2
- DIRECT LOSE: F4

General/developer controls for Player 2:
- GOD MODE: 7 key (NUMPAD)
- DIRECT LOSE: 8 key (NUMPAD)

### Gamepad:

- MOVE: JOYSTIC AND D-PAD
- SHOOT AND SELECT CHARACTER: A 
- SKIP SCREEN: A
- BOMB: B
- START GAME: START


## Changelist of all previous versions

_0.1 version:_

Project started with all the basic modules added. 

Main features: 

* Automatic background (sea level) scrolling.
* Player (Valnus) full movement working
* Player basic animation implemented
* Camera limits added
* Sea level music added
* Press ESC to quit available 

_0.2 version:_

* Implemented fade to black.
* Implemented transitions between screens.
* Added the songs of each screen.
* Now we have the loop that goes through the main game modules.
* Implemented the Welcome Screen Title*
* Implemented Character Selection*
* Implemented Scene Mine
* Implemented Score Ranking*

*Provisional static screens.

_0.3 version:_

* Implemented basic shot with sound fx.
* Added animations to Castle Scene.*
* Now we can load sound fx.

* Two soldier and one bridge.

_0.4 version:_

* Player collider implemented
* F2 - Debug Mode to show all colliders
* Solved problem with the texture array (Out of limits)
* Fixed problem with the particle array limits
* Bug fixed with the fx sound of the shot
* Player shot collider
* Almost finished animation rotatation torpedo enemy and implemented collide box
* Collision detetcted between torpedo enemy and player basic shot, now particles are destroyed when collided and screen change to ranking score window when player collide with torpedo enemey
* Soldier animations and bridge fixed with right spritesheet

_0.45 version:_

* Added UI Module with basic information
* Now the player have three lives
* Modules enemies and Path implemented
* Three enemies with their respective movement and interaction
* Implemented Power Up and the interaction with the player
* More sprites and animations added
* Death animation and functionality of the player
* Cooperative Mode
* God Mode with F2 key
* Direct win F3 key
* Direct loose F4 key

_0.46 version:_

* Score is totally implemented for one player
* Fixed a lot of minor bugs
* Added audio fx to player, welcome screen and character selection
* Welcome screen and character selection improved
* Enemies shots are implemented scouting the player
* Added more enemies and background houses to the castle scene
* Hit and life animation to each enemy / house
* Now the enemies have the lives of the original game
* Implemented the coin and the vase with all the functionality

_0.47 version:_

* Score is totally implemented for both players
* Now is avaliable the highest score
* Fixed a lot of minor bugs
* Now player 2 have more functionality and is fully playable
* The tank enemy now move the cannon in all directions
* Changed some of the controls ( Check the controls for more info )
* Now the god mode is visible

_0.48 version:_

* Removed memory leaks
* Fixed collider box problems

_0.49 version:_

* Fixed problem with the highest score
* Player2 collider is now visible
* Fixed lives problem
* Removed enter key functionality
* Now player2 is still alive when the Castle is over
* Removed credit and improved the backgrounds
* Add character selection animation with locks over not playable characters and remove other elements

_0.5 version:_

* Added the last turrets in the castle
* Fixed the fx sound of the coin for the player 2
* Release optimized

_0.55 version:_

* Castle Scene is now hidden
* Started all the Forest Scene
* Changed the background with some functionality
* Implemented the Bee enemy
* Implemented the Red Turret enemy
* Implemented the Big Red Turret enemy
* Character selector implemented
* Now you can play with Tetsu*

_*Unstable_

_0.56 version:_

* Added full character selector
* Started implementing tetsu character. Just movement and death for now
* Started red mecha enemy implementation
* Added motionless trees over main background
* Added jungle level music
* Fixed minor bugs and polished details

## Team members

_Altimira Bernat, Martí's responsability and Github account_

* QA
* Github account: https://github.com/martimab

_García Subirana, Guillermo's responsability and Github account_

* Code
* Github account: https://github.com/Wilhelman

_Masó Garcia, Víctor's responsability and Github account_

* Management
* Github account: https://github.com/nintervik

_Termens Vázquez, Ariadna's responsability and Github account_

* Art/Design
* Github account: https://github.com/AriTeva



 ~ FrozenSloth Studios ~ 
