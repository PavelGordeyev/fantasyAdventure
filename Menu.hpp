/********************************************************************* 
** Program name: Menu Class
** Author: Pavel Gordeyev
** Date: 10/15/19
** Description: Menu.hpp is the Menu class specification file. The
**				Menu class can create either menus with options to
**				select from or to enter in prompts.  It can check
**				for valid inputs from the user for valid integer
**				entries. It uses an enum to designate between 
**				Options and Prompts menu types.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>

enum MenuType {NOMENU, OPTIONS, PROMPTS};

class Menu{

	private:
		int *inputs,
			size,
			*validInputs;
		std::string *menuItems,
					*errorOutputs;

		MenuType menuType;

		void printMenu();
		void printPrompt(int);
		int getUserInput(int);
		bool inputCheckValidOptions(int);
		bool inputCheckValidPrompts(int,int,std::string);

	public:
		Menu();
		Menu(std::string*,std::string*,int*,int, MenuType);
		~Menu();
		int * runMenu();	

};

#endif