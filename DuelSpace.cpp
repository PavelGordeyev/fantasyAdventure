/********************************************************************* 
** Program name: DuelSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: DuelSpace.cpp is the DuelSpace class implementation 
**				file. 
*********************************************************************/
#include "DuelSpace.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the DuelSpace class.
*********************************************************************/
DuelSpace::DuelSpace() : Space(){
	this->welcomeMessage = "You've landed on a Dice space!\n"
							"An evil warlock is challening you to a duel!"
							"\nRoll a die and see if you can beat him!"
							" Best of 5 rounds wins..."
							"\nA loss or a tie will cost you a life point!!\n";

	this->warlockDie = new Die(6);
	this->userDie = new Die(6);

	this->options = nullptr;
	this->optionItems = nullptr;
	this->vInputs = nullptr;

	this->spaceName = "duel";
}

/********************************************************************* 
** Description: playProblem function plays dice roll duel game
**				between a warlock and the user.
*********************************************************************/
int DuelSpace::playProblem(){

	int rounds = 5,
		scoreUser = 0,
		scoreWarlock = 0,
		result;

	// Set visited to true
	this->visited = true;

	// Print space welcome message
	this->printWelcomeMessage();

	// Ask user to roll a die
	std::cout << "Let's begin. Please select an option below:" << std::endl;

	// Generate menu of possible answers
	this->createMenu();

	// Show user options menu
	int userInput = this->options->runMenu()[0];

	if(userInput == 1){ // Roll the dice

		for(int i=0;i<rounds;i++){

			std::cout << "\n*********" << std::endl;
			std::cout << "Round - " << i + 1 << std::endl;
			std::cout << "*********\n" << std::endl;

			// Play round of dice
			result = this->playRoundOfDice();

			switch(result){
				case 0:	// Warlock won
					
					scoreWarlock++;
					break;

				case 1:	 // User won
					
					scoreUser++;
					break;

				case 2: // Tie; no score updates

					break;
				
				default:
					break;
			}
		}

		// Print out the results
		std::cout << "\n************" <<std::endl;
		std::cout << "Duel Results" << std::endl;
		std::cout << "************" << std::endl;
		std::cout << "Your score: " << scoreUser << std::endl;
		std::cout << "Warlock's score: " << scoreWarlock << std::endl;

		if(scoreUser > scoreWarlock){
			std::cout << "\nWell done! You have defeated the warlock!"
			<< std::endl;
			std::cout << "No items to be found here, though! Keep movin along!\n"
			<< std::endl;

			// Set solved boolean
			this->solved = true;

			return 0;
		}else{
			std::cout << "\nYou weren't able to defeat the warlock!\n"
			"He reigns supreme and thus you lose 1 life point...\n"
			"Better luck next time!\n" << std::endl;

			// Set solved boolean
			this->solved = false;

			return -1;
		}
	}else{ // User doesn't want to play
		std::cout << "That's unfortunate for you! You lose 2 life points!!\n" << std::endl;

		// Set solved boolean
		this->solved = false;

		return -2;
	}
	
}

/********************************************************************* 
** Description: playRoundOfDice functions plays a round of dice rolls
**				between the warlock and the user.  Returns the winner.
**				0 for the warlock, 1 for the user, 2 for a tie.
*********************************************************************/
int DuelSpace::playRoundOfDice(){

	int userRoll = userDie->rollingDie(),
		warlockRoll = warlockDie->rollingDie();

	// Print out the rolled values
	std::cout << "You rolled a: " << userRoll << std::endl;
	std::cout << "The warlock rolled a: " << warlockRoll << std::endl;

	// Determine winner of the round
	if(warlockRoll > userRoll){
		std::cout << "\n The warlock won this round! " << std::endl;
		return 0;
	}else if(warlockRoll < userRoll){
		std::cout << "\n You won this round! " << std::endl;
		return 1;
	}else{
		std::cout << "\n Tie Round!!" << std::endl;
		return 2;
	}

}

/********************************************************************* 
** Description: createAnswerMenu generates an option menu for rolling
**				the user die.
*********************************************************************/
int DuelSpace::createMenu(){

	int menuSize = 2;

	optionItems = new std::string[menuSize];

	// Fill options
	optionItems[0] = "1 - Let's roll the dice!";
	optionItems[1] = "2 - I'm too scared! I have to leave!";

	// Valid multiple choice options
	vInputs = new int[menuSize];
	vInputs[0] = 1;
	vInputs[1] = 2;

	// Set the answer menu
	this->options = new Menu(optionItems,nullptr,vInputs,menuSize,OPTIONS);

	return 0;
}

/********************************************************************* 
** Description: Destructor for the DuelSpace class. 
*********************************************************************/
DuelSpace::~DuelSpace(){
	if(options){
		delete [] optionItems;
		delete [] vInputs;
		delete options;
	}

	delete warlockDie;
	delete userDie;
}