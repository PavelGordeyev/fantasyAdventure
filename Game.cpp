/********************************************************************* 
** Program name: Game Class
** Author: Pavel Gordeyev
** Date: 12/6/19
** Description: Game.cpp is the Game class implementation file. It
**				plays the fantasy board game, where a user traverses
**				between all the spaces, solves puzzles, battles
**				warlocks and gets prizes from jesters.  The goal is
**				to collect all the pieces of the key that will open
**				a door if the user comes across a door space.
*********************************************************************/
#include "Game.hpp"

/********************************************************************* 
** Description: Constructor for the Game class. Takes a menu as the 
**				parameter.
*********************************************************************/
Game::Game(Menu *startMenu){

	this->startMenu = startMenu;

	// Game will have 16 spaces
	this->numSpaces = 16;

	// Set max space counts
	this->maxMathSpace = 4;
	this->maxPrizeSpace = 5;
	this->maxDuelSpace = 5;
	this->maxDoorSpace = 2;

	// Max sachel size
	this->maxSachelSize = 5;

	movesToMake = nullptr;
	moves = nullptr;
	vInputs = nullptr;

	srand(time(0));
}

/********************************************************************* 
** Description: playGame function that runs the game environment to
**				move the player through the spaces until they either
**				win or lose all their life points.
*********************************************************************/
void Game::playGame(){

	int randInt,
		lifePoints = 5,
		result,
		moveMenuResult;

	bool won = false;

	// Show the start menu
	int start = this->startMenu->runMenu()[0];
	
	if(start == 1){
		Space * currentSpace;

		// Set up the game board
		this->setupSpaces();

		// Place user in a random spot
		// Uses vector spaces to initially set user position
		// Vector not used in game space traversal
		randInt = this->getRandomNumber(1,16);

		std::cout << "Starting Location: " << randInt << std::endl;

		currentSpace = this->spaces.at(randInt - 1);

		// Begin play
		do{

			if(currentSpace->hasVisited()){
				std::cout << "\n*** You've been at this space before!\n"
				<< std::endl;
			}

			if(currentSpace->hasSolved()){
					std::cout << "\n*** You have already completed the challenge"
					" at this space!\nPlease move along to a"
					" different space!" << std::endl;
			}else{

				// Pass the key pieces count to the door space for verification
				if(currentSpace->getSpaceName() == "door"){
					currentSpace->setKeyPieces(this->itemSachel.size());
				}

				// Play the problem/puzzle at the space
				result = currentSpace->playProblem();

				// Check if user found a key piece
				if(result == 100){

					// Add item to sachel
					if(itemSachel.size() < this->maxSachelSize){
						itemSachel.push_back(currentSpace->getItem().name);
					}else{
						std::cout << "\n ** The satchel is full!"
						" Can't add any more items.  Sorry...\n" << std::endl;
					}
					
					// Reset result to 0
					result = 0;

				}
			}

			if(result == 1000){ // Game is won
				won = true;

			}else{ // Continue

				std::cout << "\n################################" << std::endl;
				std::cout << "           SUMMARY" << std::endl;
				std::cout << "--------------------------------" << std::endl;
				// Show items in the sachel
				if(this->itemSachel.size() == 0){
					std::cout << "\nYour sachel is empty :(" << std::endl;
				}else{
					std::cout << "\nYour sachel contains..." << std::endl;
					for(unsigned int i=0;i<this->itemSachel.size();i++){
						std::cout << i + 1 << ": " << itemSachel.at(i)
						<< std::endl;
					}
				}

				// Adjust lifepoints for results from turn
				lifePoints += result;

				// Decrement life points by 1 every turn
				--lifePoints;

				// Show user's life points
				std::cout << "\n***************" << std::endl;
				std::cout << "Life Points: " << lifePoints << std::endl;
				std::cout << "***************" << std::endl;

				std::cout << "\n################################\n" << std::endl;

				if(lifePoints > 0){
					// Get available moves to make
					this->createMovesMenu(currentSpace);

					// Show available moves to make
					std::cout << "\nPlease make a choice of which space to move to next:"
					<< std::endl;
					moveMenuResult = this->moves->runMenu()[0];

					// Set next currentSpace to user's choice of space
					switch(moveMenuResult){
						case 1: // Right

							currentSpace = currentSpace->getRight();
							break;

						case 2: // Left

							currentSpace = currentSpace->getLeft();
							break;

						case 3: // Top

							currentSpace = currentSpace->getTop();
							break;

						case 4: // Bottom
							
							currentSpace = currentSpace->getBottom();
							break;

						default:
							break;
					}
				}else{

					std::cout << "\n\nYou have died! Come play again another"
					" time!!\n" << std::endl;
				}
			}
				

		}while(lifePoints > 0 && !won);
	}else{ // Exit game
		std::cout << "\nThe wizards and jesters are sad you don't want"
		" to play! \nCome back and play a bit in the fantasy world!!\n"
		<< std::endl;
	}

}

/********************************************************************* 
** Description: createMovesMenu creates the available moves menu for
**				each turn that the user can make.
*********************************************************************/
void Game::createMovesMenu(Space *& currentSpace){

	bool right = false,
		 left = false,
		 top = false,
		 bottom = false;

	int moveCount = 0,
		moveIndex = 0;

	std::string str = "";

	// Delete old menu if it exists
	if(moves){
		delete [] this->vInputs;
		delete [] this->movesToMake;
		delete this->moves;

		this->vInputs = nullptr;
		this->movesToMake = nullptr;
		this->moves = nullptr;
	}

	// Get available moves to make
	
	if(currentSpace->getRight()){
		moveCount++;
		right = true;
	}

	if(currentSpace->getLeft()){
		moveCount++;
		left = true;
	}

	if(currentSpace->getTop()){
		moveCount++;
		top = true;
	}

	if(currentSpace->getBottom()){
		moveCount++;
		bottom = true;
	}

	// Set available moves
	this->movesToMake = new std::string[moveCount];
	this->vInputs = new int[moveCount];

	for(int i=0;i<4;i++){
		
		str = "";

		switch(i){
			case 0: // Right
				if(right){
					str += std::to_string(i + 1) + " - RIGHT";
					this->movesToMake[moveIndex] = str;
					this->vInputs[moveIndex] = i + 1;

					moveIndex++;
				}

				break;

			case 1: // Left

				if(left){
					str += std::to_string(i + 1) + " - LEFT";
					this->movesToMake[moveIndex] = str;
					this->vInputs[moveIndex] = i + 1;

					moveIndex++;
				}

				break;

			case 2: // Top
				if(top){
					str += std::to_string(i + 1) + " - TOP";
					this->movesToMake[moveIndex] = str;
					this->vInputs[moveIndex] = i + 1;

					moveIndex++;
				}

				break;

			case 3: // Bottom
				if(bottom){
					str += std::to_string(i + 1) + " - BOTTOM";
					this->movesToMake[moveIndex] = str;
					this->vInputs[moveIndex] = i + 1;

					moveIndex++;
				}

				break;

			default:
				break;
		}
	}

	// Create menu
	this->moves = new Menu(movesToMake,nullptr,vInputs,moveCount,OPTIONS);

}
/********************************************************************* 
** Description: setupSpaces function sets up the spaces in the game.
**				Each space points to up to 4 other spaces. It is
**				setup as a 4x4 grid, with each space pointing to all
**				adjacent spaces available.
*********************************************************************/
void Game::setupSpaces(){

	// Create spaces vector
	this->setupSpacesVector();

	// Assign each space its top, bottom, left & right pointers
	for(int i=0;i<this->numSpaces;i++){

		switch(i){
			case 0: // Box #1

				this->spaces.at(i)->setRight(this->spaces.at(1));
				this->spaces.at(i)->setBottom(this->spaces.at(4));

				break;

			case 1: // Box #2

				this->spaces.at(i)->setRight(this->spaces.at(2));
				this->spaces.at(i)->setLeft(this->spaces.at(0));
				this->spaces.at(i)->setBottom(this->spaces.at(5));
				
				break;
			case 2: // Box #3

				this->spaces.at(i)->setRight(this->spaces.at(3));
				this->spaces.at(i)->setLeft(this->spaces.at(1));
				this->spaces.at(i)->setBottom(this->spaces.at(6));
			
				break;

			case 3: // Box #4

				this->spaces.at(i)->setLeft(this->spaces.at(2));
				this->spaces.at(i)->setBottom(this->spaces.at(7));
			
				break;
			case 4: // Box #5
				
				this->spaces.at(i)->setRight(this->spaces.at(5));
				this->spaces.at(i)->setTop(this->spaces.at(0));
				this->spaces.at(i)->setBottom(this->spaces.at(8));

				break;
			case 5: // Box #6
				this->spaces.at(i)->setRight(this->spaces.at(6));
				this->spaces.at(i)->setLeft(this->spaces.at(4));
				this->spaces.at(i)->setTop(this->spaces.at(1));
				this->spaces.at(i)->setBottom(this->spaces.at(9));
			
				break;
			case 6: // Box #7
				this->spaces.at(i)->setRight(this->spaces.at(7));
				this->spaces.at(i)->setLeft(this->spaces.at(5));
				this->spaces.at(i)->setTop(this->spaces.at(2));
				this->spaces.at(i)->setBottom(this->spaces.at(10));

				break;
			case 7: // Box #8
				this->spaces.at(i)->setLeft(this->spaces.at(6));
				this->spaces.at(i)->setTop(this->spaces.at(3));
				this->spaces.at(i)->setBottom(this->spaces.at(11));

				break;
			case 8: // Box #9
				this->spaces.at(i)->setRight(this->spaces.at(9));
				this->spaces.at(i)->setTop(this->spaces.at(4));
				this->spaces.at(i)->setBottom(this->spaces.at(12));
			
				break;
			case 9: // Box #10
				this->spaces.at(i)->setRight(this->spaces.at(10));
				this->spaces.at(i)->setLeft(this->spaces.at(8));
				this->spaces.at(i)->setTop(this->spaces.at(5));
				this->spaces.at(i)->setBottom(this->spaces.at(13));

				break;
			case 10: // Box #11
				this->spaces.at(i)->setRight(this->spaces.at(11));
				this->spaces.at(i)->setLeft(this->spaces.at(9));
				this->spaces.at(i)->setTop(this->spaces.at(6));
				this->spaces.at(i)->setBottom(this->spaces.at(14));

				break;
			case 11: // Box #12
				this->spaces.at(i)->setLeft(this->spaces.at(10));
				this->spaces.at(i)->setTop(this->spaces.at(7));
				this->spaces.at(i)->setBottom(this->spaces.at(15));
			
				break;
			case 12: // Box #13
				this->spaces.at(i)->setRight(this->spaces.at(13));
				this->spaces.at(i)->setTop(this->spaces.at(8));
			
				break;
			case 13: // Box #14
				this->spaces.at(i)->setRight(this->spaces.at(14));
				this->spaces.at(i)->setLeft(this->spaces.at(12));
				this->spaces.at(i)->setTop(this->spaces.at(9));

				break;
			case 14: // Box #15
				this->spaces.at(i)->setRight(this->spaces.at(15));
				this->spaces.at(i)->setLeft(this->spaces.at(13));
				this->spaces.at(i)->setTop(this->spaces.at(10));

				break;

			case 15: // Box #16
				this->spaces.at(i)->setLeft(this->spaces.at(14));
				this->spaces.at(i)->setTop(this->spaces.at(11));

				break;

			default:
				break;
		}
	}
	

}

/********************************************************************* 
** Description: setupSpacesVector function sets up the a random vector
**				of the 4 types of spaces.  These will then be used
**				to assign to the actual board game layout.
*********************************************************************/
void Game::setupSpacesVector(){

	int randInt,
		countMathSpace = 0,
		countPrizeSpace = 0,
		countDuelSpace = 0,
		countDoorSpace = 0,
		i = 0;

	bool spaceCreated;

	Space * space;

	// Create vector of spaces
	do{
		
		// Reset space created
		spaceCreated = false;

		// Generate a random number to determine space type
		randInt = this->getRandomNumber(1,1000);

		if(randInt < 280){
			randInt = 1;
		}else if(randInt < 560){
			randInt = 2;
		}else if(randInt < 840){
			randInt = 3;
		}else{
			randInt = 4;
		}

		switch(randInt){
			case 1: // Math Space

				if (countMathSpace < maxMathSpace){

					space = new MathSpace();
					this->spaces.push_back(space);

					countMathSpace++;
					spaceCreated = true;
				}
				break;

			case 2: // Prize Space

				if (countPrizeSpace < maxPrizeSpace){

					space = new PrizeSpace();
					this->spaces.push_back(space);

					countPrizeSpace++;
					spaceCreated = true;
				}

				break;

			case 3: // Duel Space

				if (countDuelSpace < maxDuelSpace){

					space = new DuelSpace();
					this->spaces.push_back(space);

					countDuelSpace++;
					spaceCreated = true;
				}

				break;

			case 4: // Door Space

				if (countDoorSpace < maxDoorSpace){

					space = new DoorSpace();
					this->spaces.push_back(space);
					
					countDoorSpace++;
					spaceCreated = true;
				}

				break;

			default:
				break;
		}

		if(spaceCreated){
			++i;
		}

	}while(i < this->numSpaces);
}

/********************************************************************* 
** Description: getRandomNumber function outputs a random number
**				between specified low and high integers >= 0.
*********************************************************************/
int Game::getRandomNumber(int low, int high){

	int randInt;

	randInt = low + rand() % (high-low + 1);
	
	return randInt;
}

/********************************************************************* 
** Description: Destructor for the Game class.
*********************************************************************/
Game::~Game(){

	// Free memory
	if(this->spaces.size() > 0){
		for(int i=0;i<this->numSpaces;++i){
			delete this->spaces.at(i);
		}
	}

	if(this->moves){
		delete [] this->vInputs;
		delete [] this->movesToMake;
		delete this->moves;
	}
	

}