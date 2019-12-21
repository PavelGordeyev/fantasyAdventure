/********************************************************************* 
** Program name: Menu Class
** Author: Pavel Gordeyev
** Date: 10/15/19
** Description: Menu.cpp is the Menu class implementation file. The
**				Menu class can create either menus with options to
**				select from or to enter in prompts.  It can check
**				for valid inputs from the user for valid integer
**				entries. It uses an enum to designate between 
**				Options and Prompts menu types.
*********************************************************************/
#include "Menu.hpp"
#include "checkInput.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/********************************************************************* 
** Description: Default constructor for the Menu class. Initializes
**				all pointers to nullptr and sets type to NOMENU, and
**				size to 0.
*********************************************************************/
Menu::Menu(){

	menuType = NOMENU;
	menuItems = nullptr;
	validInputs = nullptr;
	size = 0;

	inputs = nullptr;
}

/********************************************************************* 
** Description: Constructor for the Menu class. It initialized the
**				type of menu, either Options or Prompts, the items
**				in the menu itself, the valid inputs for the menu
**				items and the number of elements in the menu.
**				Inputs are saved as a dynamically created 1D array.
*********************************************************************/
Menu::Menu(std::string *items,std::string *errorItems, int *vInputs, int s,MenuType mt){

	menuType = mt;
	menuItems = items;
	validInputs = vInputs;
	if(menuType == PROMPTS){
		errorOutputs = errorItems;
	}else{
		errorOutputs = nullptr;
	}

	size = s;

	inputs = new int[size];
}

/********************************************************************* 
** Description: runMenu function that prints the menu and returns
**				the user's input as a pointer to an dynamic array.
**				Returns a single value for Options and multiple 
**				values for Prompts, if there are more than 1 prompt.
*********************************************************************/
int * Menu::runMenu(){

	// Separate actions to handle options or prompts
	switch (menuType){

		case OPTIONS:
			printMenu();

			// Argument is a placeholder
			inputs[0] = getUserInput(-1);

			break;
			
		case PROMPTS:
			for(int i = 0;i<size;i++){
				printPrompt(i);
				inputs[i] = getUserInput(i);
			}
			break;

		default:
			break;
	}

	return inputs;
}

/********************************************************************* 
** Description: printMenu function that prints each menu item on a 
**				separate line. Only to be used with Options, not 
**				Prompts.
*********************************************************************/
void Menu::printMenu(){

	for(int i = 0;i<size;i++){
		cout << menuItems[i] << endl;
	}

	// User input indication
	std::cout << "\n> ";
}

/********************************************************************* 
** Description: printPrompt function that prints a single prompt
**				based on the specified location in the menuItems 
**				array.  Only to be used with Prompts, not Options.
*********************************************************************/
void Menu::printPrompt(int prompt){
	cout << menuItems[prompt] << endl;
}

/********************************************************************* 
** Description: getUserInput function returns the integer value of a
**				user's input.  It initially validates that the input
**				is not blank, not a negative integer and contains only
**				numeric characters.  Decimals are not allowed.  It
**				then verifies the input against specific menu options
**				or prompts, depending on this instances type.  It will
**				loop until a proper value is entered.
*********************************************************************/
int Menu::getUserInput(int item){
	std::string input;
	bool err;

	do{
		std::getline(cin,input);
		err = false;

		if(!checkInputInt(input,false)){ // Check if a positive integer
			cout << "Invalid entry.\n" << endl;
			err = true;
			if(menuType == OPTIONS){
				printMenu();
			}else{ // PROMPTS
				printPrompt(item);
			}
		}else{ // Check for valid values for options & prompts
			if(menuType == OPTIONS){
				if(!inputCheckValidOptions(stoi(input))){
					err = true;
					cout << "Not a valid option.\n" << endl;
					printMenu();
				}
			}else{ // PROMPTS
				switch(item){
					case 0: // Number of turtles
						if(stoi(input) == 0 || !inputCheckValidPrompts(stoi(input),item,"le")){
							err = true;
							cout << errorOutputs[item] << endl;
							printPrompt(item);
						}
						break;
					case 1: // Number of penguins
						if(stoi(input) == 0 || !inputCheckValidPrompts(stoi(input),item,"le")){
							err = true;
							cout << errorOutputs[item] << endl;
							printPrompt(item);
						}
						break;
					case 2: // Number of tigers
						if(stoi(input) == 0 || !inputCheckValidPrompts(stoi(input),item,"le")){
							err = true;
							cout << errorOutputs[item] << endl;
							printPrompt(item);
						}
						break;
					default:
						break;
				}
			}
		}

	}while(err); // Loop while an error is recorded

	return stoi(input);
}

/********************************************************************* 
** Description: inputCheckValidOptions function to validate that
**				the input matches one of the given options.
*********************************************************************/
bool Menu::inputCheckValidOptions(int input){

	// Loop through the valid options
	for(int i=0;i<size;i++){
	
		if(input == validInputs[i]){
			return true;
		}
	}	

	return false;
}

/********************************************************************* 
** Description: inputCheckValidPrompts function to validate that the
**				input matching a corresponding prompt valid value
**				through different types of comparisons, based on the 
**				need. The comparison type is specified by the
**				respective keywords.
*********************************************************************/
bool Menu::inputCheckValidPrompts(int input, int item, std::string typeCheck){

	
	if(typeCheck == "g"){ // Greater than
		if(input > validInputs[item]){
			return true;
		}
	}else if(typeCheck == "l"){ // Less than
		if(input < validInputs[item]){
			return true;
		}
	}else if(typeCheck == "ge"){ // Greater than or equal to
		if(input >= validInputs[item]){
			return true;
		}
	}else if(typeCheck == "le"){ // Less than or equal to
		if(input <= validInputs[item]){
			return true;
		}
	}else if(typeCheck == "e"){ // Equal to
		if(input == validInputs[item]){
			return true;
		}
	}	

	return false;
}

/********************************************************************* 
** Description: eraseInputs function to delete the allocated array
**				for the user inputs.
*********************************************************************/
Menu::~Menu(){

	delete [] inputs;
	
}


