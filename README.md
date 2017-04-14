# GUNBIRD
We're going to replicate the 1994 Gunbird game arcade version developed and published by Psyko as a tribute to the game. This project has been done by four catalan students of CITM - UPC (Terrasa, Spain).  

* Github wiki of the project: https://github.com/Wilhelman/Gunbird_P01/wiki
* Project web: available soon

## About the game

Gunbird was released in 1994 for arcades and belongs to the vertically scrolling shoot'em up genre and has both single-player and two-player cooperative modes.

The game allows you to choose between five different characters, each one with their own skills and powers. The objective of the game is to obtain the four shards  of a magic mirror in order to get a wish once they are all assembled. They will fight against The Trump (a group of three pirates) for the fragments of the mirror.

There are two loop with seven levels each. The four shards of the mirror are obtained in the first four levels (which are randomly selected) and the wish is made once the player has completed three extra levels. In the end of each level you’ll have one boss to beat and a piece of the main plot is revealed. But in the second loop the difficult is increased and the story plot is removed.

## Installation instructions

Download the zip file and unzip it. Open the folder, execute the .exe and enjoy!*

_IMPORTANT: do not modify, change or add any folder or file as you might not be able to execute the game._

*The game is currently in development. The releases uploaded are just the first versions of the final game.

## Controls

Player controls:
- UP: W key
- LEFT: A key
- RIGHT: D key
- DOWN: S key
- BASIC SHOT: SPACE key

Player 2 controls:
- UP: UP_ARROW key
- LEFT: LEFT_ARROW key
- RIGHT: RIGHT_ARROW key
- DOWN: DOWN_ARROW key
- JOIN THE GAME: 2 key (NUMPAD)
- BASIC SHOT: ENTER key (NUMPAD)

General/developer controls:
- SKIP SCREEN: INTRO key
- EXIT GAME: ESC key
- Show colliders: F1
- God mode: F2
- Direct win: F3
- Direct lose: F4

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



FrozenSloth Studios
