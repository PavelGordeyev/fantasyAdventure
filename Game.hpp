/********************************************************************* 
** Program name: Game Class
** Author: Pavel Gordeyev
** Date: 12/6/19
** Description: Game.hpp is the Game class specification file. It
**				plays the fantasy board game, where a user traverses
**				between all the spaces, solves puzzles, battles
**				warlocks and gets prizes from jesters.  The goal is
**				to collect all the pieces of the key that will open
**				a door if the user comes across a door space.
*********************************************************************/  
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Space.hpp"
#include "MathSpace.hpp"
#include "PrizeSpace.hpp"
#include "DuelSpace.hpp"
#include "DoorSpace.hpp"
#include <iostream>
#include <vector>
#include <string>

class Game{

private:
	Menu * startMenu;

	std::vector<Space*> spaces;
	std::vector<std::string> itemSachel;

	int numSpaces,
		maxMathSpace,
		maxPrizeSpace,
		maxDuelSpace,
		maxDoorSpace;
		
	unsigned int maxSachelSize;

	// Move menu
	Menu * moves;
	std::string * movesToMake;
	int * vInputs;


	/********************************************************************* 
	** Description: setupSpaces function sets up the spaces in the game.
	**				Each space points to up to 4 other spaces.
	*********************************************************************/
	void setupSpaces();

	/********************************************************************* 
	** Description: setupSpacesVector function sets up the a random array
	**				of the 4 types of spaces.  These will then be used
	**				to assign to the actual board game layout.
	*********************************************************************/
	void setupSpacesVector();

	/********************************************************************* 
	** Description: getRandomNumber function outputs a random number
	**				between specified low and high integers >= 0.
	*********************************************************************/
	int getRandomNumber(int,int);

	/********************************************************************* 
	** Description: createMovesMenu creates the available moves menu for
	**				each turn that the user can make.
	*********************************************************************/
	void createMovesMenu(Space *&);

	
public:
	/********************************************************************* 
	** Description: Constructor for the Game class. Takes a menu as the 
	**				parameter.
	*********************************************************************/
	Game(Menu*);

	/********************************************************************* 
	** Description: Destructor for the Game class.
	*********************************************************************/
	~Game();

	/********************************************************************* 
	** Description: playGame function that runs the game environment to
	**				move the player through the spaces until they either
	**				win or lose all their life points.
	*********************************************************************/
	void playGame();

};

#endif