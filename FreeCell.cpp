#include "FreeCell.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		FreeCell.cpp
* Date Created:		02/08/17
* Modifications:	02/08/17 – Added display and setlength
*					02/10/17 - Added func to check free cells here 
*							   instead of in game class.
********************************************************************/


/**********************************************************************
* Purpose: This function sets default size to 0.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
FreeCell::FreeCell()
{
	m_free.SetLength(0);
}

/**********************************************************************
* Purpose: This function resets the data member to the default size of 0.
*
* Precondition:	Data members may be initialized to some value.
*
* Postcondition: Data members are initialized to default values.
************************************************************************/
FreeCell::~FreeCell()
{
	m_free.SetLength(0);
}

/**********************************************************************
* Purpose: This function sets this to copy, calling the op= to handle
*		   operations.
*
* Precondition:	N/A
*
* Postcondition: Copied.
************************************************************************/
FreeCell::FreeCell(const FreeCell & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets m_free to rhs.m_free, allowing the array
*		   class to handle the operatios.
*
* Precondition:	Data members were uninitialized.
*
* Postcondition: Data members are initialized to rhs's values.
************************************************************************/
FreeCell & FreeCell::operator=(const FreeCell & rhs)
{
	if (this != &rhs)
	{
		m_free = rhs.m_free;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function sets the length of the free cells.
*
* Precondition:	Free cells length was undetermined.
*
* Postcondition: Free cells length is determined.
************************************************************************/
void FreeCell::SetLength(int len)
{
	m_free.SetLength(len);
}

/**********************************************************************
* Purpose: This function outputsd the freecells and their data.
*
* Precondition:	Free cells werent visible.
*
* Postcondition: Free cells are visible.
************************************************************************/
void FreeCell::Output()
{
	cout << "    ";
	for (int j = 0; j < 4; j++)
	{
		cout << " ";

		m_free[j].Display_Card();
	}
	cout << "\t\t\t\t";	//Move over to where home cells will be
	cout << "      ";
}

/**********************************************************************
* Purpose: This function allows you to select an index of the free cells
*		   to refer to in another class.
*
* Precondition:	Free cells index was undetermined.
*
* Postcondition: Free cells index is determined.
************************************************************************/
Card & FreeCell::SelectIndex(int index)
{
	return  m_free[index];
}

/**********************************************************************
* Purpose: This function Traverses the free cells and returns which ones 
*		   are empty in an array, -1 represents empty free cells and 
*		   positive numbers representing filled	free cels.
*
* Precondition:	Free cells filled status was unknown.
*
* Postcondition: Free cells filled status is known.
************************************************************************/
int & FreeCell::EmptyCells(int ra[], Card empty)
{
	for (int i = 0; i < 4; i++)
	{
		ra[i] = -1;	//Reset to default values
	}

	for (int i = 0; i < 4; i++)	//Check which free cells are empty 
	{
		if (m_free[i].Get_Rank() != empty.Get_Rank() && m_free[i].Get_Suit() != empty.Get_Suit())
		{
			ra[i] = i;
		}
	}
	return *ra;
}
