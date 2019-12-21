/********************************************************************* 
** Program name: PrizeSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: PrizeSpace.cpp is the PrizeSpace class implementation 
**				file. 
*********************************************************************/
#include "PrizeSpace.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the PrizeSpace class.
*********************************************************************/
PrizeSpace::PrizeSpace() : Space(){

	this->item.name = "piece of a key";
	this->item.description = "A piece of the key to open the final door!";
	
	this->welcomeMessage = "You've landed on a Prize space!\n"
							"The jester would like to play a game!"
							"\nThere are 3 boxes, each containing a prize!"
							"\nChoose wisely, as one of the prizes you"
							" might not like! Or you may win a KEY!\n";

	this->keyWon = false;

	this->options = nullptr;
	this->optionItems = nullptr;
	this->vInputs = nullptr;

	this->spaceName = "prize";
}

/********************************************************************* 
** Description: playProblem function plays the prize selection game.
*********************************************************************/
int PrizeSpace::playProblem(){

	// Set visited to true
	this->visited = true;

	// Print space welcome message
	this->printWelcomeMessage();

	// Ask user to roll a die
	std::cout << "Let's begin. Please select a box below (Choices 1-3):" 
	<< std::endl;

	// Generate menu of boxes to choose from
	this->createMenu();

	// Create the prizes
	this->setPrizes();

	// Get user chosen box
	int userInput = this->options->runMenu()[0];
	
	// Check what's inside the box
	if(this->prizes.at(userInput - 1) == "key"){

		std::cout << "\nCongrats! You've won yourself a piece of a KEY!\n"
		<< std::endl;

		this->keyWon = true;

		// Set solved boolean
		this->solved = true;

		return 100;

	}else if(this->prizes.at(userInput - 1) == "potion"){

		std::cout << "\nCongrats! You've won a special potion which adds"
		" 1 life point!! Luck is on your side!\n" << std::endl;

		// Set solved boolean
		this->solved = true;

		return 1;

	}else{ // spell

		std::cout << "\nOh no! That box had the evil spell and you have lost"
		" 2 life points!\nDon't lose too many more on your journey!\n"
		<< std::endl;

		// Set solved boolean
		this->solved = false;

		return -2;

	}
}

/********************************************************************* 
** Description: setPrizes function assigns prizes randomly to 3 boxes.
**				One box will contain a key, another an evil spell
**				that will cost the user 2 life points, and one
**				containing a potion to regain a life point.
*********************************************************************/
void PrizeSpace::setPrizes(){

	int randInt = getRandomNumber(1,3);
	bool potionSet = false,
		 keySet = false,
		 spellSet = false;
	
	// Set first prize	
	switch(randInt){
		case 1:
		
			this->prizes.push_back("potion");
			potionSet = true;
			break;
		
		case 2:
			
			this->prizes.push_back("key");
			keySet = true;
			break;
		
		case 3:
			
			this->prizes.push_back("spell");
			spellSet = true;
			break;

		default:
			break;
	}	

	randInt = getRandomNumber(1,3);

	// Set second prize	
	switch(randInt){
		case 1:

			if(potionSet){
				this->prizes.push_back("key");
				keySet = true;
			}else{
				this->prizes.push_back("potion");
				potionSet = true;
			}
			
			break;
		
		case 2:

			if(keySet){
				this->prizes.push_back("spell");
				spellSet = true;
			}else{
				this->prizes.push_back("key");
				keySet = true;
			}

			break;
		
		case 3:

			if(spellSet){
				this->prizes.push_back("potion");
				potionSet = true;
			}else{
				this->prizes.push_back("spell");
				spellSet = true;
			}
			
			break;

		default:
			break;
	}	

	// Set third prize
	if(potionSet){
		if(keySet){
			this->prizes.push_back("spell");
		}else{
			this->prizes.push_back("key");
		}
	}else{
		this->prizes.push_back("potion");
	}

}

/********************************************************************* 
** Description: createMenu generates an option menu for the boxes to
**				choose from.
*********************************************************************/
int PrizeSpace::createMenu(){

	int menuSize = 3;

	this->optionItems = new std::string[menuSize];

	// Fill options
	optionItems[0] = "1 - Box # 1";
	optionItems[1] = "2 - Box # 2";
	optionItems[2] = "3 - Box # 3";

	// Valid multiple choice options
	this->vInputs = new int[menuSize];
	vInputs[0] = 1;
	vInputs[1] = 2;
	vInputs[2] = 3;

	// Set the answer menu
	this->options = new Menu(optionItems,nullptr,vInputs,menuSize,OPTIONS);

	return 0;
}

/********************************************************************* 
** Description: getKeyWon functions returns true or false, depending
**				if the user won the key.
*********************************************************************/
bool PrizeSpace::getKeyWon(){
	return this->keyWon;
}

/********************************************************************* 
** Description: Destructor for the PrizeSpace class. 
*********************************************************************/
PrizeSpace::~PrizeSpace(){
	if(options){
		delete [] optionItems;
		delete [] vInputs;
		delete options;
	}
}