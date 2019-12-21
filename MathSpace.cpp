/********************************************************************* 
** Program name: MathSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: MathSpace.cpp is the MathSpace class implementation 
**				file. It generates a random math problem for the user
**				to solve to be able to get a piece of a key. 
*********************************************************************/
#include "MathSpace.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the MathSpace class.
*********************************************************************/
MathSpace::MathSpace() : Space(){
	
	this->item.name = "piece of a key";
	this->item.description = "A piece of the key to open the final door!";

	this->welcomeMessage = "You've landed on a Math space! +-/* \n"
							"Here your skills will be tested and in return,"
							"\nyou will get a piece of the key, if you"
							" manage to get past the challening puzzle!";

	// Setup operators
	this->operators.push_back("+");
	this->operators.push_back("-");
	this->operators.push_back("/");
	this->operators.push_back("*");

	this->answers = nullptr;
	this->answerItems = nullptr;
	this->vInputs = nullptr;

	this->spaceName = "math";

}

/********************************************************************* 
** Description: playProblem function plays the math problem for 
**				the math space.
*********************************************************************/
int MathSpace::playProblem(){

	// Set visited to true
	this->visited = true;

	// Generate a math problem
	this->setMathProblem();

	// Get the solution to the math problem
	this->solveMathProblem();

	// Print space welcome message
	this->printWelcomeMessage();

	// Show user math problem
	std::cout << "\nThe wizard has a math problem for you..." << std::endl;
	std::cout << this->getMathString();
	std::cout << " = ? (Choices 1-4)\n" << std::endl;

	// Generate menu of possible answers
	int locSolution = this->createMenu();

	// Show multiple choice results of answers
	int userAnswer = answers->runMenu()[0];

	// Check if user entered the correct answer
	if(userAnswer == locSolution + 1){
		std::cout << "Brilliant! You can now add a piece of the KEY to your" 
		" sachel!" << std::endl;

		// Set solved boolean
		this->solved = true;

		return 100;
	}else{
		std::cout << "The wizard is saddened by your incorrect response :<("
		"\nYou can come back later and try again!"
		"\nThere will be a piece of a KEY waiting here for you!\n"
		<< std::endl;

		// Set solved boolean
		this->solved = false;

		return 0;
	}
	
}

/********************************************************************* 
** Description: createMenu generates an answer menu for the 
**				math question. Returns location of correct answer.
*********************************************************************/
int MathSpace::createMenu(){

	int menuSize = 4,
		locCorrectAnswer = getRandomNumber(0,3),
		randInt;

	answerItems = new std::string[menuSize];

	std::string str = "";

	// Add the correct answer to a random menu item
	str += std::to_string(locCorrectAnswer + 1) + ") " + std::to_string(this->solution);
	answerItems[locCorrectAnswer] = str;

	// Loop through answers and add values
	for(int i=0;i<menuSize;i++){
		
		// Reset the string
		str = "";

		// Random number to add/subtract to throw off correct answer
		randInt = getRandomNumber(1,5);

		// Fill in answers
		if(answerItems[i] == ""){
			if(i % 2 == 0){
				str += std::to_string(i + 1) + ") " + std::to_string(this->solution + randInt * 1.1);
				answerItems[i] = str;
			}else{
				str += std::to_string(i + 1) + ") " + std::to_string(this->solution - randInt * 1.1);
				answerItems[i] = str;
			}
			
		}
	}

	// Valid multiple choice options
	vInputs = new int[menuSize];
	vInputs[0] = 1;
	vInputs[1] = 2;
	vInputs[2] = 3;
	vInputs[3] = 4;

	// Set the answer menu
	this->answers = new Menu(answerItems,nullptr,vInputs,menuSize,OPTIONS);

	return locCorrectAnswer;
}


/********************************************************************* 
** Description: getMathProblem functino generates a random math 
**				problem and	returns a vector of the first operand, 
**				second operand, and the operator.
*********************************************************************/
void MathSpace::setMathProblem(){
	
	// Set random number for the first operand
	this->vals.push_back(getRandomNumber(1,10));

	// Set random number for the second operand
	this->vals.push_back(getRandomNumber(1,10));

	// Set random number for the operator selection
	this->vals.push_back(getRandomNumber(0,3));
}

/********************************************************************* 
** Description: solveMathProblem function solves the math problem 
**				specified and returns the result.
*********************************************************************/
void MathSpace::solveMathProblem(){
	
	double result;

	// Get first operand
	double first = this->vals.at(0);

	// Get second operand
	double second = this->vals.at(1);

	// Perform math
	switch(this->vals.at(2)){
		case 0: // +
			result = first + second;
			break;

		case 1: // -
			result = first - second;
			break;

		case 2: // /
			result = first / second;
			break;

		case 3: // *
			result = first * second;
			break;

		default:
			result = 0;
			break;
	}

	this->solution = result;
}

/********************************************************************* 
** Description: getMathString function generates the math question
**				string to output to the user.
*********************************************************************/
std::string MathSpace::getMathString(){
	
	// Build math string
	std::string str = std::to_string(this->vals.at(0));
	str += " " + this->operators.at(this->vals.at(2));
	str += " " + std::to_string(this->vals.at(1));

	return str;
}

/********************************************************************* 
** Description: Destructor for the MathSpace class. 
*********************************************************************/
MathSpace::~MathSpace(){
	if(answers){
		delete [] answerItems;
		delete [] vInputs;
		delete answers;
	}

}