/************************************************************************
* Class: Deck
*
* Purpose: This class deals the cards, shuffles them, and keeps track of
*		   the current number dealt.
*
* Manager functions:
* 	Deck()
* 		The default constructor, allocates memory for card
*		array and assigns 52 cards into it.
*	~Card()
*		Default constructor - frees up memory of m_deck.
*
* Methods:
*	Shuffle()
*		Randomizes the deck, resets count to 0.
*	Deal()
*		Returns the instance of [m_Current_Count] of m_deck
*	Get_Count()
*		Static method that returns the current number of cards dealt.
*	Display_Count()
*		Displays the curent number of cards dealt.
*************************************************************************/
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <time.h>

class Deck
{
public:
	Deck();
	~Deck();

	void Shuffle();	//Shuffles the cards
	Card Deal();	//Deals the cards

private:
	Card ** m_deck;	//Array of pointers to cards in deck
	static int m_current_card;	//Keeps track of the current card number
};

#endif s