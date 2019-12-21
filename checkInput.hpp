/********************************************************************* 
** Program name: checkInput
** Author: Pavel Gordeyev
** Date: 10/7/19
** Description: checkInput.hpp is the checkInput function 
**              specification file.
**              Input validation function that accepts a string and 
**              checks if each character is an integer. Supports use 
**              of negative integers with use of a '-' character.
**              Returns true if the input value is an integer and 
**              false otherwise.
*********************************************************************/
#ifndef CHECK_INPUT_HPP
#define CHECK_INPUT_HPP

#include <string>

bool checkInputInt(std::string,bool);

#endif