/********************************************************************* 
** Program name: Die Class
** Author: Pavel Gordeyev
** Date: 10/15/19
** Description: Die.cpp is the Die class implementation file. It
**				simulates a regular die, with an even probabilty
**				of rolling any side.
*********************************************************************/
#include "Die.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>

/********************************************************************* 
** Description: Default constructor for the Die class.  Initialize
**				sides to 0.
*********************************************************************/
Die::Die(){

	this->sides = 0;

	this->typeOf = "Regular";

	// Generate new random starting point
	srand(time(NULL));
}

/********************************************************************* 
** Description: Constructor for the Die class. Initalizes the
**				number of sides of the die, and sets the initial seed
**				to be used for the rollingDie function, as well as
**				the increment to be used for the seed after each roll.
**				Call an initial seed for the random number generator.
*********************************************************************/
Die::Die(int sides){

	this->sides = sides;

	this->typeOf = "Regular";

	// Generate new random starting point
	srand(time(NULL));
}

/********************************************************************* 
** Description: rollingDie function Returns a random integer between 1 
**				and N sides as the result of rolling the die once. 
*********************************************************************/
int Die::rollingDie(){

	static int randRoll;

	randRoll = (rand() % sides) + 1;

	return randRoll;
}

/********************************************************************* 
** Description: incSeed function that increments the seed that the
**				rand function uses in the rollingDie function.
*********************************************************************/
int Die::getSides(){

	return sides;

}

/********************************************************************* 
** Description: incSeed function that increments the seed that the
**				rand function uses in the rollingDie function.
*********************************************************************/
void Die::setSides(int sides){

	this->sides = sides;

}

/********************************************************************* 
** Description: incSeed function that increments the seed that the
**				rand function uses in the rollingDie function.
*********************************************************************/
std::string Die::getTypeOf(){

	return this->typeOf;
	
}

Die::~Die(){
	// Destructor
}