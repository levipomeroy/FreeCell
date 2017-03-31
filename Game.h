/************************************************************************
* Class: Game
*
* Purpose: This class creates a dynamic one-dimensional array that can be
*		   started at any index.
*
* Manager functions:
* 	Game ()
*		Sets the lengths of the free cells and home cells and play areas.
*	Game (const Game & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const Game & rhs)
*		Checks for self-assignment, and if not self assigned, sets each data
*		member to the rhs data member. Each classes op= will take care of that
*		types assignment.
*	~Game()
*		Resets lengths of all of the data members back to 0.
*
Methods:
*	OutputCells()
*		Outputs the free cells and the home cells by calling the output 
*		function of both the types.
*	AssignCards()
*		Assigns the deck of cards into stacks within the play area.
*	Play()
*		This funtion manages the playing of the game. It outputs the menu
*		and takes in the users moves, and acts accordingly.
*	PrintCards()
*		Outputs the cards in the play area, calls the play area print function.
*	DidIWin()
*		Returns whether or not the user has won or not.
*	InvalidMove()
*		Outputs an error message and waits for the user to respond.
*	NewGame()
*		Clears all the cells and re-shuffles and then reprints the board.
*	NumMovableCards(int * ra)
*		This function calculates the number of cards a player can move from
*		one column to another.
*************************************************************************/
#include"HomeCell.h"
#include "PlayArea.h"
#include "FreeCell.h"
#include "Deck.h"
#include <cmath>

#ifndef Game_H
#define Game_H

class Game
{
public:
	Game();
	Game(const Game & copy);
	Game & operator=(const Game & rhs);
	~Game();

	void OutputCells();
	void AssignCards();
	void Play();
	void PrintCards();
	bool DidIWin();
	void InvalidMove();
	void NewGame();
	int NumMovableCards(int * ra);

private:
	Deck m_deck;
	FreeCell m_free;
	HomeCell m_home;
	PlayArea m_play;
};

#endif