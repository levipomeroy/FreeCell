#include "Card.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		Deck.cpp
* Date Created:		Sometime last year
* Modifications:	02/04/17 - Added to freecell game
*					02/06/17 - Edited DisplayCard to allow for colored
*							   ouput
********************************************************************/


/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A
*	Exit:	  Sets m_rank to rank and m_suit to suit.
****************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Card::~Card()
{
}
Card & Card::operator=(const Card & rhs)
{
	if (this != &rhs)
	{
		m_rank = rhs.m_rank;
		m_suit = rhs.m_suit;
	}
	return *this;
}
/**************************************************************
*	Purpose:  The purpose of this function is to display a card.
*	Entry:	  N/A
*	Exit:	  Displays the rank and suit of a card.
****************************************************************/
void Card::Display_Card()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);	//for color changes

	const char*rank_txt[] = { "A","2", "3", "4", "5", "6", "7", "8",
		"9", "10", "J", "Q","K" };

	switch (m_suit)
	{
	case 3:	//Hearts
		SetConsoleTextAttribute(hstdout, 4);
		if (m_rank == 10)
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit);
		}
		else
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit) << " ";
		}
		break;
	case 4:	//Diamonds
		SetConsoleTextAttribute(hstdout, 12);
		if (m_rank == 10)
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit);
		}
		else
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit) << " ";
		}
		break;
	case 5:	//Clubs
		SetConsoleTextAttribute(hstdout, 7);
		if (m_rank == 10)
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit);
		}
		else
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit) << " ";
		}
		break;
	case 6:	//Spades
		SetConsoleTextAttribute(hstdout, 15);
		if (m_rank == 10)
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit);
		}
		else
		{
			cout << rank_txt[m_rank - 1] << static_cast<char>(m_suit) << " ";
		}
		break;
	default:
		SetConsoleTextAttribute(hstdout, 15);
		cout << "--";
	}
	SetConsoleTextAttribute(hstdout, 15);
}
/**************************************************************
*	Purpose:  The purpose of this function is to set m_rank to
*			  rank, type: enum Rank.
*	Entry:	  Enum Rank
*	Exit:	  Sets m_rank to rank, type: enum Rank.
****************************************************************/
void Card::Set_Rank(Rank rank)
{
	m_rank = rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to set m_suit to
*			  suit, type: enum Suit.
*	Entry:	  Enum Suit
*	Exit:	  Sets m_suit to suit, type: enum Suit.
****************************************************************/
void Card::Set_Suit(Suit suit)
{
	m_suit = suit;

}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the suit of a card for the instance of the player.
*	Entry:	  N/A
*	Exit:	  Returns m_suit for the player.
****************************************************************/
Card::Rank Card::Get_Players_Rank()
{
	if (m_rank == KING || m_rank == QUEEN || m_rank == JACK)
	{
		m_rank = TEN;	//Face cards equal 10.
	}

	if (m_rank == ACE)
	{
		int selection = 0;

		cout << "\nDo you want your ace to be 1 or 11?";
		cin >> selection;

		if (selection == 1)
		{
			m_rank = ACE;	//Low ace
		}

		else if (selection == 11)
		{
			m_rank = JACK;	//High ace
		}

		else
		{
			cout << "\n Invalid input!\n";
		}
	}
	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the rank of a card.
*	Entry:	  N/A
*	Exit:	  Returns m_rank.
****************************************************************/
Card::Rank Card::Get_Rank()
{
	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the suit of a card for the instance of the dealer.
*	Entry:	  Integer current.
*	Exit:	  Returns m_suit for the dealer.
****************************************************************/
Card::Rank Card::Get_Dealers_Rank(int current)
{
	if (m_rank == KING || m_rank == QUEEN || m_rank == JACK)
	{
		m_rank = TEN;	//Face cards equal 10.
	}
	if (current>17 && m_rank == ACE)
	{
		m_rank = JACK;
	}
	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_suit,
*			  the suit of a card.
*	Entry:	  N/A
*	Exit:	  Returns m_suit.
****************************************************************/
Card::Suit Card::Get_Suit()
{
	return m_suit;
}

bool Card::operator==(Card first)
{
	bool same = false;
	if (m_suit == first.m_suit && m_rank == first.m_rank)
	{
		same = true;
	}
	return same;
}

bool Card::operator!=(Card first)
{
	bool equal = false;
	if (m_rank != first.m_rank || m_suit != first.m_suit)
	{
		equal = true;
	}
	return equal;
}

ostream & operator<<(ostream & stream, const Card & card)
{
	const char*rank_txt[] = { "A","2", "3", "4", "5", "6", "7", "8",
		"9", "10", "J", "Q","K" };
	return stream << rank_txt[card.m_rank - 1] << static_cast<char>(card.m_suit);
}
