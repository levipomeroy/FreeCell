/*****************************************************************************
* Class: FreeCell
*
* Purpose: This class handles the freecells within the game. It prints them, 
*		   checks if they are full or not and allows access to them.
*
* Manager functions:
* 	FreeCell ()
* 		The default size is set to 0.
*	FreeCell (const FreeCell & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const FreeCell & copy)
*		Sets the data memeber, using the Array op= to handle the assignment
*		of the array instead of copying data.
*	~FreeCell()
*		Nothing to delete here, resets size to default of 0.
*
* Methods:
*	SetLength (int len)
*		SetLength sets the length of the array representing the freecelss
*		the index it is passed.
*	Output ()
*		Displays the freecfells and the data within them.
*	Card & SelectIndex(int index)
*		Selects the index within the array, alternative to overloading the
*		subscript operator.
*	int & EmptyCells(int ra[], Card empty)
*		Traverses the free cells and returns which ones are empty in an array,
*		-1 represents empty free cells and positive numbers representing filled
*		free cels.
**********************************************************************************/
#include "Array.h"
#include "Card.h"

#ifndef FREECELL_H
#define FREECELL_H

class FreeCell
{
public:
	FreeCell();
	~FreeCell();
	FreeCell(const FreeCell & copy);
	FreeCell & operator=(const FreeCell & rhs);

	void SetLength(int len);
	void Output();
	Card & SelectIndex(int index);
	int & EmptyCells(int ra[], Card empty);

private:
	Array<Card> m_free;
};

#endif

