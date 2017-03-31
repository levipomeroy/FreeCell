/*****************************************************************************
* Class: HomeCell
*
* Purpose: This class manages the homecells of the game. It prints them, and 
*		   allows access to them.
*
* Manager functions:
* 	HomeCell ()
* 		The default size is set to 0.
*	HomeCell (const HomeCell & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const HomeCell & copy)
*		Sets the data memeber, using the Array op= to handle the assignment
*		of the array instead of copying data.
*	~HomeCell()
*		Nothing to delete here, resets size to default of 0.
*
* Methods:
*	SetLength (int len)
*		SetLength sets the length of the array representing the homecells
*		the index it is passed.
*	Display ()
*		Displays the homecells and the data within them.
*	AStack<Card> & SelectColumn(int index)
*		Selects the index within the array, alternative to overloading the
*		subscript operator.
**********************************************************************************/
#include "Card.h"
#include "AStack.h"

#ifndef  HOMECELL_H
#define HOMECELL_H

class HomeCell
{
public:
	HomeCell();
	~HomeCell();
	HomeCell(const HomeCell & copy);
	HomeCell & operator=(const HomeCell & rhs);

	void SetLength(int len);
	AStack<Card> & SelectColumn(int index);
	void Display();

private:
	Array<AStack<Card>> m_home;

};

#endif