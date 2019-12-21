/********************************************************************* 
** Program name: checkInput
** Author: Pavel Gordeyev
** Date: 10/7/19
** Description: checkInput.cpp is the checkInput function
**              implementation file.
**              Input validation function that accepts a string and 
**              checks if each character is an integer. Includes
**              option to allow for negative integers.
**              Returns true if the input value is an integer and 
**              false otherwise.
*********************************************************************/
#include "checkInput.hpp"

/********************************************************************* 
** Description: Input validation function that accepts a string and 
**              checks if each character is an integer. Includes
**              option to allow for negative integers.
**              Returns true if the input value is an integer and 
**              false otherwise.
*********************************************************************/
bool checkInputInt(std::string input, bool allowNegativeVals){

	int charStart;

	if(!input.empty()){ // Check for empty string input
		if(allowNegativeVals){
			//Check for a negative sign and adjust starting location 
			if(input[0]=='-'){
				charStart = 1;
			}else{
				charStart = 0;
			}
		}else{
			charStart = 0;
		}

		// Check for integer characters
		// Unsigned designation from compiler warning
		// https://stackoverflow.com/questions/3660901/a-warning-comparison-between-signed-and-unsigned-integer-expressions
		for(int i=charStart;(unsigned)i<input.length();i++){
			if(!isdigit(input[i])){
				return false; // Input has a non-integer character
			}
		}  

		// Input is an integer
		return true;
	}else{
		return false;
	}
}