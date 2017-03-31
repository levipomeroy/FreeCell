#include "HomeCell.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		HomeCell.cpp
* Date Created:		02/08/17
* Modifications:	02/08/17 – Added display and setlength
********************************************************************/

/**********************************************************************
* Purpose: This function sets default size to 0.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
HomeCell::HomeCell()
{
	m_home.SetLength(0);
}

/**********************************************************************
* Purpose: This function resets the data member to the default size of 0.
*
* Precondition:	Data members may be initialized to some value.
*
* Postcondition: Data members are initialized to default values.
************************************************************************/
HomeCell::~HomeCell()
{
	m_home.SetLength(0);
}

/**********************************************************************
* Purpose: This function sets this to copy, calling the op= to handle
*		   operations.
*
* Precondition:	N/A
*
* Postcondition: Copied.
************************************************************************/
HomeCell::HomeCell(const HomeCell & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets m_home to rhs.m_home, allowing the array
*		   class to handle the operatios.
*
* Precondition:	Data members were uninitialized.
*
* Postcondition: Data members are initialized to rhs's values.
************************************************************************/
HomeCell & HomeCell::operator=(const HomeCell & rhs)
{
	if (this != &rhs)
	{
		m_home = rhs.m_home;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function sets the length of the home cells.
*
* Precondition:	home cells length was undetermined.
*
* Postcondition: home cells length is determined.
************************************************************************/
void HomeCell::SetLength(int len)
{
	m_home.SetLength(len);
}

/**********************************************************************
* Purpose: This function allows you to select an index of the home cells
*		   to refer to in another class.
*
* Precondition:	home cells index was undetermined.
*
* Postcondition: home cells index is determined.
************************************************************************/
AStack<Card>& HomeCell::SelectColumn(int index)
{
	return m_home[index];
}

/**********************************************************************
* Purpose: This function outputs the homecells and their data.
*
* Precondition:	home cells werent visible.
*
* Postcondition: home cells are visible.
************************************************************************/
void HomeCell::Display()
{
	for (int j = 0; j < 4; j++)
	{
		cout << " ";
		if (m_home[j].IsEmpty() != true)	//this is wrong must fix this
		{
			m_home[j].Peek().Display_Card();
		}
		else
		{
			cout << "--";
		}
	}

	cout << "\n\n";
}
