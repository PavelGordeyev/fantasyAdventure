/********************************************************************* 
** Program name: DoorSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: DoorSpace.cpp is the DoorSpace class implementation 
**				file. It is a door that leads to the end of the game.
**				If the user has at least 4 key pieces, they can open
**				the door and win the game. Otherwise, they will lose
**				points if they try to deceive the door into opening
**				itself.
*********************************************************************/
#include "DoorSpace.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the DoorSpace class.
*********************************************************************/
DoorSpace::DoorSpace() : Space(){
	this->welcomeMessage = "You've landed on a Door space!\n"
							"If you have 4 key pieces, you may unlock"
							" the door and win the game!!\nOtherwise,"
							" keep searching for the other key pieces!\n";
	this->keyPieces = 0;

	this->options = nullptr;
	this->optionItems = nullptr;
	this->vInputs = nullptr;

	this->spaceName = "door";
}

/********************************************************************* 
** Description: playProblem function will attempt to open the door
**				for the user to win the game.
*********************************************************************/
int DoorSpace::playProblem(){
	
	// Set visited to true
	this->visited = true;

	// Print space welcome message
	this->printWelcomeMessage();

	// Ask user to roll a die
	std::cout << "Would you like to try to open the door?" 
	<< std::endl;

	// Generate menu of boxes to choose from
	this->createMenu();

	// Get user choice to open the door or not
	int userInput = this->options->runMenu()[0];

	// Check to make sure there are enough key pieces to open the door
	if(userInput == 1){
		if(this->keyPieces == 4){
			std::cout << "You've done it! The real world awaits...See you"
			" next time in the fantasy world!" << std::endl;

			// Set solved boolean
			this->solved = true;

			return 1000;
		}else{
			std::cout << "\nThe door cannot be fooled!! You don't have"
			" enough key pieces! \nYou have lost 3 life points for the"
			" tricky games you are trying to play!\nGo on and find more"
			" key pieces, but don't take too long!\n" << std::endl;

			// Set solved boolean
			this->solved = false;
			
			return -3;
		}
	}else{
		std::cout << "\nGo on and find more key pieces, but don't"
		" take too long!\n" << std::endl;

		// Set solved boolean
		this->solved = false;

		return 0;
	}
}

/********************************************************************* 
** Description: createAnswerMenu generates an option menu for rolling
**				the user die.
*********************************************************************/
int DoorSpace::createMenu(){

	int menuSize = 2;

	this->optionItems = new std::string[menuSize];

	// Fill options
	optionItems[0] = "1 - Let's unlock the door!";
	optionItems[1] = "2 - I don't have enough key pieces!";

	// Valid multiple choice options
	this->vInputs = new int[menuSize];
	vInputs[0] = 1;
	vInputs[1] = 2;

	// Set the answer menu
	this->options = new Menu(optionItems,nullptr,vInputs,menuSize,OPTIONS);

	return 0;
}

/********************************************************************* 
** Description: Destructor for the DoorSpace class. 
*********************************************************************/
DoorSpace::~DoorSpace(){
	if(options){
		delete [] optionItems;
		delete [] vInputs;
		delete options;
	}
}