/********************************************************************* 
** Program name: MathSpace Class
** Author: Pavel Gordeyev
** Date: 12/5/19
** Description: MathSpace.hpp is the MathSpace class specification 
**				file. It generates a random math problem for the user
**				to solve to be able to get a piece of a key. 
*********************************************************************/
#ifndef MATHSPACE_HPP
#define MATHSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include <string>
#include <vector>

class MathSpace : public Space{

public:
	/********************************************************************* 
	** Description: Constructor for the MathSpace class.
	*********************************************************************/
	MathSpace();

	/********************************************************************* 
	** Description: Destructor for the MathSpace class. 
	*********************************************************************/
	~MathSpace();

	/********************************************************************* 
	** Description: playProblem function plays the puzzle problem for 
	**				the math space.
	*********************************************************************/
	int playProblem();

private:

	// Values for math problem
	std::vector<int> vals;

	// Operators for math problem
	std::vector<std::string> operators;

	// Answer menu for math problem
	Menu * answers;
	std::string * answerItems;
	int * vInputs;

	double solution;

	/********************************************************************* 
	** Description: getMathProblem functino generates a random math 
	**				problem and	returns a vector of the first operand, 
	**				second operand, and the operator.
	*********************************************************************/
	void setMathProblem();

	/********************************************************************* 
	** Description: solveMathProblem function solves the math problem 
	**				specified and returns the result.
	*********************************************************************/
	void solveMathProblem();

	/********************************************************************* 
	** Description: getMathString function generates the math question
	**				string to output to the user.
	*********************************************************************/
	std::string getMathString();

	/********************************************************************* 
	** Description: createMenu generates an answer menu for the 
	**				math question. Returns location of correct answer.
	*********************************************************************/
	int createMenu();

};

#endif