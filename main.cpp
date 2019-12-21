/********************************************************************* 
** Program name: Project Final
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: main.cpp is the main function implementation file for
**              Project Final.  It plays the fantasy board game, 
**				where a user traverses between all the spaces, solves 
**				puzzles, battles warlocks and gets prizes from jesters.
**				The goal is to collect all the pieces of the key that 
**				will open a door if the user comes across a door space.
*********************************************************************/
#include "Menu.hpp"
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;

int main(){

	int startMenuSize = 2,
		validOption1 = 1,
		validOption2 = 2;

	//**********************//
	//      START MENU      //
	//**********************//

	// End options menu
	string *startMenuItems = new string[startMenuSize];
	startMenuItems[0] = "1 - Play in the fantasy world!";
	startMenuItems[1] = "2 - Exit";

	// End of day options menu valid user selections
	int *vInputsStart= new int[startMenuSize];
	vInputsStart[0] = validOption1;
	vInputsStart[1] = validOption2;

	//**********************//
	//      Play game       //
	//**********************//

	// Create the menus
	Menu *startMenu = new Menu(startMenuItems,nullptr,vInputsStart,startMenuSize,OPTIONS);

	// Create the game
	Game *game = new Game(startMenu);

	// Display the game description and goal
	std::cout << "\n#################################################################"
	"#################"<< std::endl;
	std::cout << "Welcome to the fantasy world!!\n"
	"It is a place filled with jesters, warlocks and wizards with random math problems!\n"
	"As you traverse through the spaces in the board game, you will"
	"\nencounter various challenges and questions to answer.\n*** Be careful,"
	" some of these questions are tricky and may cost you life points!!\n"
	"\nLife points can only be gained if you win a prize at a specific space!\n"
	"You will begin the game with 25 life points, and each turn costs 1"
	" life point.\n\nGoal: Collect at least 4 pieces of the key that will open"
	" a door at a Door space.\nYou can carry at most 5 pieces at any one time."
	<< std::endl;
	std::cout << "#################################################################"
	"#################"<< std::endl;
	std::cout << "\nWell then, let's begin the journey!! Enter the fantasy world, if"
	" you are brave enough!!!\n" << std::endl;

	// Play the game
	game->playGame();


	//**********************//
	//     Free Memory      //
	//**********************//
	delete game;
	delete startMenu;
	delete [] startMenuItems;
	delete [] vInputsStart;

	return 0;
}