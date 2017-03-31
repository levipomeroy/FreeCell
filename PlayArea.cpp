#include "PlayArea.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		PlayArea.cpp
* Date Created:		02/08/17
* Modifications:	02/08/17 – Fixed print functions infinite loop
*  					02/08/17 – Added sequential order checker
*					02/10/17 - Fixed color order checker push order
********************************************************************/


/**********************************************************************
* Purpose: This function sets default size to 0.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
PlayArea::PlayArea()
{
	m_play.SetLength(0);
}

/**********************************************************************
* Purpose: This function resets the data member to the default size of 0.
*
* Precondition:	Data members may be initialized to some value.
*
* Postcondition: Data members are initialized to default values.
************************************************************************/
PlayArea::~PlayArea()
{
	m_play.SetLength(0);
}

/**********************************************************************
* Purpose: This function sets this to copy, calling the op= to handle
*		   operations.
*
* Precondition:	N/A
*
* Postcondition: Copied.
************************************************************************/
PlayArea::PlayArea(const PlayArea & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets m_play to rhs.m_play, allowing the array
*		   class to handle the operatios.
*
* Precondition:	Data members were uninitialized.
*
* Postcondition: Data members are initialized to rhs's values.
************************************************************************/
PlayArea & PlayArea::operator=(const PlayArea & rhs)
{
	if (this != &rhs)
	{
		m_play = rhs.m_play;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function sets the length of the play area.
*
* Precondition:	home cells length was undetermined.
*
* Postcondition: home cells length is determined.
************************************************************************/
void PlayArea::SetLength(int len)
{
	m_play.SetLength(len);
}

/**********************************************************************
* Purpose: This function allows you to select an index of the play area.
*		   to refer to in another class.
*
* Precondition:	home cells index was undetermined.
*
* Postcondition: home cells index is determined.
************************************************************************/
LStack<Card>& PlayArea::SelectColumn(int index)
{
	return m_play[index];
}

/**********************************************************************
* Purpose: This function outputs the play areas and their data.
*
* Precondition:	play area wasnt visible.
*
* Postcondition: play are is visible.
************************************************************************/
void PlayArea::Print()
{
	Card current;
	Array<LStack<Card>> temp;
	temp.SetLength(m_play.GetLength());
	int count = 0;

	cout << "\n\n\n\n";

	cout << "\t\t";
	for (int j = 1; j < 9; j++)	//Output header
	{
		cout << j << "     ";
	}
	cout << "\n\n";
	cout << "\t\t";

	while(!m_play[0].IsEmpty() || !m_play[1].IsEmpty() || !m_play[2].IsEmpty() || !m_play[3].IsEmpty() || !m_play[4].IsEmpty() || 
		!m_play[5].IsEmpty() || !m_play[6].IsEmpty() || !m_play[7].IsEmpty())
	{

		for (int i = 0; i < 8; i++)
		{
			if (!m_play[i].IsEmpty())
			{
				temp[i].Push(m_play[i].Pop());
			}
		}
	}

	count = 0;
	for (int i = 0; i < 90; i++)
	{
		if (temp[count].Size() > 0)
		{
			m_play[count].Push(temp[count].Pop());
			current = m_play[count].Peek();

			current.Display_Card();
			cout << "   ";
		}
		else
		{
			cout << "      ";
		}
		count++;
		if (count % 8 == 0)
		{
			count = 0;
			cout << "\n";
			cout << "\t\t";
		}
	}
	cout << "\n\n";
}

/**********************************************************************
* Purpose: This function returns whether the cards being moved within the 
*		   play area are in sequencial order or not.
*
* Precondition:	Sequential order is unknown.
*
* Postcondition: Sequential order is known.
************************************************************************/
bool PlayArea::SeqOrder(int num_cards, int to_col, int from_col)
{
	bool seq = false;
	Array<Card> temp;
	Card comparitor;
	Card top;
	top.X;
	top.x;
	comparitor.X;
	comparitor.x;	//make it empty
	int count = 0;

	temp.SetLength(num_cards-1);

	if (num_cards == 1)	//If only one card then it is in order
	{
		seq = true;
		top = m_play[from_col - 1].Peek();
	}
	else
	{
		for (int i = 0; i < num_cards - 1; i++)
		{
			temp[i] = m_play[from_col - 1].Pop();
		}

		top = m_play[from_col - 1].Peek();
		for (int i = num_cards - 2;i >= 0; i--)
		{
			comparitor = m_play[from_col - 1].Peek();

			m_play[from_col - 1].Push(temp[i]);
			if (num_cards > 1 && (m_play[from_col - 1].Peek().Get_Rank() + 1 == comparitor.Get_Rank()))
			{
				count++;
			}
		}
	}
	if (count == num_cards -1 && (top.Get_Rank() + 1 == m_play[to_col - 1].Peek().Get_Rank()))
	{
		seq = true;
	}
	else
	{
		seq = false;
	}

	return seq;
}

/**********************************************************************
* Purpose: This function returns whether the cards being moved within the
*		   play area are in the correct color order or not.
*
* Precondition:	Color order is unknown.
*
* Postcondition: Color order is known.
************************************************************************/
bool PlayArea::CorrectColor(int num_cards, int to_col, int from_col)
{
	bool correct_color = false;
	Array<Card> temp;
	temp.SetLength(num_cards);
	Card comparitor;
	Card top;
	top.X;
	top.x;
	comparitor.X;
	comparitor.x;	//make it empty
	int count = 0;

	if (num_cards == 1)
	{
		correct_color = true;
	}

	for (int i = 0; i < num_cards - 1; i++)
	{
		temp[i] = m_play[from_col - 1].Pop();
	}

	top = m_play[from_col - 1].Peek();	//card at top of cards being moved
	for (int i = num_cards - 2;i >= 0; i--)
	{
		comparitor = m_play[from_col - 1].Peek();
		m_play[from_col - 1].Push(temp[i]);	//put em back

		if ((comparitor.Get_Suit() <= 4 && m_play[from_col - 1].Peek().Get_Suit() >= 5) ||
			(comparitor.Get_Suit() >= 5 && m_play[from_col - 1].Peek().Get_Suit() <= 4))	//if colors are in cards to be moved
		{
			correct_color = true;
		}
		else
		{
			correct_color = false;
		}
	}
	if ((top.Get_Suit() <= 4 && m_play[to_col - 1].Peek().Get_Suit() >= 5) ||
		(top.Get_Suit() >= 5 && m_play[to_col - 1].Peek().Get_Suit() <= 4))
	{
		correct_color = true;
	}
	else
	{
		correct_color = false;
	}

	return correct_color;
}
