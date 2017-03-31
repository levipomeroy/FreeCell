#include "Deck.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		Deck.cpp
* Date Created:		Sometime last year
* Modifications:	02/04/17 - Added to freecell game, unedited
********************************************************************/

int Deck::m_current_card = 0;	//Initialize the static card count to 0

/**************************************************************
*	Purpose:  The purpose of this function is to initialize the
*			  m_deck, it allocates memory for it and assigns values
*		      into it.
*	Entry:	  N/A
*	Exit:	  Allocates memory for m_array, puts 52 cards into it.
****************************************************************/
Deck::Deck()
{
	m_deck = new Card *[52];	//Array of 52 cards to make up m_deck

	for (int suit = 0; suit <= 3; suit++)
	{
		for (int rank = 0; rank < 13; rank++)
		{
			m_deck[suit * 13 + rank] = new Card(static_cast<Card::Rank>(rank + 1),
				static_cast<Card::Suit>(suit + 3));
		}
	}
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up. It deletes each element of the
*			  m_deck and then the m_deck itself and resets to
*			  nullptr.
*	Entry:	  N/A
*	Exit:	  m_deck is gone.
****************************************************************/
Deck::~Deck()
{
	for (int i = 0; i < 52; i++)
	{
		delete m_deck[i];
		m_deck[i] = nullptr;
	}
	delete[] m_deck;
	m_deck = nullptr;
}
/**************************************************************
*	Purpose:  The purpose of this function is to randomize the
*			  deck.
*	Entry:	  N/A
*	Exit:	  The deck is not in sequential order now.
****************************************************************/
void Deck::Shuffle()
{
	Card *temp = nullptr;
	int number = 0;

	srand(time(NULL));

	for (int cur = 0; cur <= 51; cur++)
	{
		number = rand() % 52;
		temp = m_deck[cur];
		m_deck[cur] = m_deck[number];
		m_deck[number] = temp;
	}
	m_current_card = 0;
}
/**************************************************************
*	Purpose:  The purpose of this function is deal the cards in
*		      the deck, one card at a time.
*	Entry:	  N/A
*	Exit:	  Returns derefernced m_deck element and inncrements
*			  to the next one.
****************************************************************/
Card Deck::Deal()
{
	return *m_deck[m_current_card++];
}
