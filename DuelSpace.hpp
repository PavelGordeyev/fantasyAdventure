/********************************************************************* 
** Program name: DuelSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: DuelSpace.hpp is the DuelSpace class specification 
**				file. 
*********************************************************************/
#ifndef DUELSPACE_HPP
#define DUELSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include "Die.hpp"
#include <string>

class DuelSpace : public Space{

public:
	/********************************************************************* 
	** Description: Constructor for the DuelSpace class.
	*********************************************************************/
	DuelSpace();

	/********************************************************************* 
	** Description: Destructor for the DuelSpace class. 
	*********************************************************************/
	~DuelSpace();

	/********************************************************************* 
	** Description: playProblem function plays dice roll duel game
	**				between a warlock and the user.
	*********************************************************************/
	int playProblem();

private:

	// Answer menu for math problem
	Menu * options;
	std::string * optionItems;
	int * vInputs;

	Die * warlockDie,
		* userDie;

	/********************************************************************* 
	** Description: playRoundOfDice functions plays a round of dice rolls
	**				between the warlock and the user.  Returns the winner.
	**				0 for the warlock, 1 for the user.
	*********************************************************************/
	int playRoundOfDice();

	/********************************************************************* 
	** Description: createMenu generates an option menu for rolling
	**				the user die.
	*********************************************************************/
	int createMenu();

};

#endif