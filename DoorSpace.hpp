/********************************************************************* 
** Program name: DoorSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: DoorSpace.hpp is the DoorSpace class specification 
**				file. It is a door that leads to the end of the game.
**				If the user has at least 4 key pieces, they can open
**				the door and win the game. Otherwise, they will lose
**				points if they try to deceive the door into opening
**				itself.
*********************************************************************/
#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include "Die.hpp"
#include <string>

class DoorSpace : public Space{

public:
	/********************************************************************* 
	** Description: Constructor for the DoorSpace class.
	*********************************************************************/
	DoorSpace();

	/********************************************************************* 
	** Description: Destructor for the DoorSpace class. 
	*********************************************************************/
	~DoorSpace();

	/********************************************************************* 
	** Description: playProblem function plays dice roll duel game
	**				between a warlock and the user.
	*********************************************************************/
	int playProblem();

	/********************************************************************* 
	** Description: setKeyPieces functions sets the number of key pieces
	**				the user has.  Set by the Game class.
	*********************************************************************/
	void setKeyPieces(int);


private:

	// Answer menu for math problem
	Menu * options;
	std::string * optionItems;
	int * vInputs;


	/********************************************************************* 
	** Description: createMenu generates an option menu for rolling
	**				the user die.
	*********************************************************************/
	int createMenu();

};

#endif