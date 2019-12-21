/********************************************************************* 
** Program name: Die Class
** Author: Pavel Gordeyev
** Date: 10/15/19
** Description: Die.hpp is the Die class specification file. It
**				simulates a regular die, with an even probabilty
**				of rolling any side.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>

class Die{

private:
		int sides;

		std::string typeOf;

public:
		Die();
		Die(int);
		~Die();
		int rollingDie();
		int getSides();
		void setSides(int);
		std::string getTypeOf();
		
};


#endif