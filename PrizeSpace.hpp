/********************************************************************* 
** Program name: PrizeSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: PrizeSpace.hpp is the PrizeSpace class specification 
**				file. 
*********************************************************************/
#ifndef PRIZESPACE_HPP
#define PRIZESPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include <string>
#include <vector>

class PrizeSpace : public Space{

public:
	/********************************************************************* 
	** Description: Constructor for the PrizeSpace class.
	*********************************************************************/
	PrizeSpace();

	/********************************************************************* 
	** Description: Destructor for the PrizeSpace class. 
	*********************************************************************/
	~PrizeSpace();
	
	/********************************************************************* 
	** Description: playProblem function plays the prize selection game.
	*********************************************************************/
	int playProblem();

	/********************************************************************* 
	** Description: getKeyWon functions returns true or false, depending
	**				if the user won the key.
	*********************************************************************/
	bool getKeyWon();

private:

	// Answer menu for math problem
	Menu * options;
	std::string * optionItems;
	int * vInputs;

	// Prizes
	std::vector<std::string> prizes;

	// Won a key
	bool keyWon;

	/********************************************************************* 
	** Description: setPrizes function assigns prizes randomly to 3 boxes.
	**				One box will contain a key, another an evil spell
	**				that will cost the user 2 life points, and one
	**				containing a potion to regain a life point.
	*********************************************************************/
	void setPrizes();

	/********************************************************************* 
	** Description: createMenu generates an option menu for the boxes to
	**				choose from.
	*********************************************************************/
	int createMenu();

};

#endif