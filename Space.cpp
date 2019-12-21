/********************************************************************* 
** Program name: Space Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: Space.cpp is the Space class implementation file. 
*********************************************************************/
#include "Space.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor for the Space class.
*********************************************************************/
Space::Space(){
	this->visited = false;
	this->solved = false;

	this->top = nullptr;
	this->bottom = nullptr;
	this->left = nullptr;
	this->right = nullptr;

	this->item.name = "";
	this->item.description = "";
}

/********************************************************************* 
** Description: getLeft function returns the space to the left.
*********************************************************************/
Space * Space::getLeft(){

	return this->left;
}

/********************************************************************* 
** Description: getRight function returns the space to the right.
*********************************************************************/
Space * Space::getRight(){
	return this->right;
}

/********************************************************************* 
** Description: getTop function returns the space above.
*********************************************************************/
Space * Space::getTop(){
	return this->top;
}

/********************************************************************* 
** Description: getBottom function returns the space below.
*********************************************************************/
Space * Space::getBottom(){
	return this->bottom;
}

/********************************************************************* 
** Description: getSpaceName function returns the name of the space
**				type.
*********************************************************************/
std::string Space::getSpaceName(){
	return this->spaceName;
}

/********************************************************************* 
** Description: setLeft function sets the space to the left.
*********************************************************************/
void Space::setLeft(Space * left){
	this->left = left;
}

/********************************************************************* 
** Description: setRight function sets the space to the right.
*********************************************************************/
void Space::setRight(Space * right){
	this->right = right;
}

/********************************************************************* 
** Description: setTop function sets the space above.
*********************************************************************/
void Space::setTop(Space * top){
	this->top = top;
}

/********************************************************************* 
** Description: setBottom function sets the space below.
*********************************************************************/
void Space::setBottom(Space * bottom){
	this->bottom = bottom;
}

/********************************************************************* 
** Description: getItem function returns the spaces item to be
**				collected.
*********************************************************************/
Item Space::getItem(){
	return this->item;
}

/********************************************************************* 
** Description: getRandomNumber function outputs a random number
**				between specified low and high integers >= 0.
*********************************************************************/
int Space::getRandomNumber(int low, int high){

	static int randInt;

	randInt = low + rand() % (high-low + 1);
	
	return randInt;
}
/********************************************************************* 
** Description: hasVisited function returns if the user has already
**				visited this space.
*********************************************************************/
bool Space::hasVisited(){

	return this->visited;

}

/********************************************************************* 
** Description: hasSolved function returns if the user has already
**				solved this space.
*********************************************************************/
bool Space::hasSolved(){

	return this->solved;

}

/********************************************************************* 
** Description: printWelcomeMessage prints out the space's welcome
**				message.
*********************************************************************/
void Space::printWelcomeMessage(){

	std::cout << "\n" << this->welcomeMessage << "\n" << std::endl;
}

/********************************************************************* 
** Description: setKeyPieces functions sets the number of key pieces
**				the user has.  Set by the Game class.
*********************************************************************/
void Space::setKeyPieces(int pieces){
	this->keyPieces = pieces;
}

/********************************************************************* 
** Description: Destructor for the Space class. 
*********************************************************************/
Space::~Space(){

}