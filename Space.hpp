/********************************************************************* 
** Program name: Space Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: Space.hpp is the Space class specification file. 
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

/********************************************************************* 
** Description: Item struct that is an item to be collected in a 
**				space.
*********************************************************************/
struct Item{
	std::string name;
	std::string description;
};

class Space{

public:
	/********************************************************************* 
	** Description: Constructor for the Space class.
	*********************************************************************/
	Space();

	/********************************************************************* 
	** Description: Destructor for the Space class. 
	*********************************************************************/
	virtual ~Space();

	/********************************************************************* 
	** Description: getLeft function returns the space to the left.
	*********************************************************************/
	Space * getLeft();

	/********************************************************************* 
	** Description: getRight function returns the space to the right.
	*********************************************************************/
	Space * getRight();

	/********************************************************************* 
	** Description: getTop function returns the space above.
	*********************************************************************/
	Space * getTop();

	/********************************************************************* 
	** Description: getBottom function returns the space below.
	*********************************************************************/
	Space * getBottom();

	/********************************************************************* 
	** Description: getItem function returns the spaces item to be
	**				collected.
	*********************************************************************/
	Item getItem();

	/********************************************************************* 
	** Description: getSpaceName function returns the name of the space
	**				type.
	*********************************************************************/
	std::string getSpaceName();

	/********************************************************************* 
	** Description: hasVisited function returns if the user has already
	**				visited this space.
	*********************************************************************/
	bool hasVisited();

	/********************************************************************* 
	** Description: hasSolved function returns if the user has already
	**				solved this space.
	*********************************************************************/
	bool hasSolved();

	/********************************************************************* 
	** Description: createMenu generates a menu for a space.
	*********************************************************************/
	virtual int createMenu() = 0;

	/********************************************************************* 
	** Description: playProblem function plays the puzzle problem for 
	**				respective space.
	*********************************************************************/
	virtual int playProblem() = 0;

	/********************************************************************* 
	** Description: setKeyPieces functions sets the number of key pieces
	**				the user has.  Set by the Game class.
	*********************************************************************/
	void setKeyPieces(int);

	/********************************************************************* 
	** Description: setLeft function sets the space to the left.
	*********************************************************************/
	void setLeft(Space*);

	/********************************************************************* 
	** Description: setRight function sets the space to the right.
	*********************************************************************/
	void setRight(Space*);

	/********************************************************************* 
	** Description: setTop function sets the space above.
	*********************************************************************/
	void setTop(Space*);

	/********************************************************************* 
	** Description: setBottom function sets the space below.
	*********************************************************************/
	void setBottom(Space*);

	

protected:
	Space *top,
		  *bottom,
		  *left,
		  *right;

	bool visited,
		 solved;

	std::string welcomeMessage,
				spaceName;

	int keyPieces;

	Item item;

	/********************************************************************* 
	** Description: getRandomNumber function outputs a random number
	**				between specified low and high integers >= 0.
	*********************************************************************/
	int getRandomNumber(int low, int high);

	/********************************************************************* 
	** Description: printWelcomeMessage prints out the space's welcome
	**				message.
	*********************************************************************/
	void printWelcomeMessage();

};

#endif