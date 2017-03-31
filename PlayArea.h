/*****************************************************************************
* Class: PlayArea
*
* Purpose: This class 
*
* Manager functions:
* 	PlayArea ()
* 		The default size is set to 0.
*	PlayArea (const PlayArea & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const PlayArea & copy)
*		Sets the data memeber, using the Array op= to handle the assignment
*		of the array instead of copying data.
*	~PlayArea()
*		Nothing to delete here, resets size to default of 0.
*
* Methods:
*	SetLength (int len)
*		SetLength sets the length of the array representing the play areas
*		the index it is passed.
*	Print ()
*		Displays the play areas and the data within them.
*	LStack<Card> & SelectColumn(int index)
*		Selects the index within the array, alternative to overloading the
*		subscript operator.
*	bool SeqOrder(int num_cards, int to_col, int from_col)
*		This function decides whether the cards being moved within the play cells 
*		are in sequencial order or not.
*	bool CorrectColor(int num_cards, int to_col, int from_col)
*		This function decides whether the cards being moved within the play cells 
*		are in the correct order of color.
**********************************************************************************/
#include "LStack.h"
#include "Array.h"
#include "Card.h"

#ifndef PLAY_AREA_H
#define PLAY_AREA_H

class PlayArea
{
public:
	PlayArea();
	~PlayArea();
	PlayArea(const PlayArea & copy);
	PlayArea & operator=(const PlayArea & rhs);

	void SetLength(int len);
	LStack<Card> & SelectColumn(int index);
	void Print();
	bool SeqOrder(int num_cards, int to_col, int from_col);
	bool CorrectColor(int num_cards, int to_col, int from_col);

private:
	Array<LStack<Card>> m_play;
};

#endif