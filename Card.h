#include <iostream>
#include <Windows.h>
#include <ostream>
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
/************************************************************************
* Class: Card
* Purpose: This class sets and displays the cards, setting the structure
*		   for the deck.
*
* Manager functions:
* 	Card(Rank rank = ACE, Suit suit = SPADE)
* 		The 2 arg constructor, sets dfault to ACE of SPADES.
*	~Card()
*		Default constructor - doesnt delete any memory.
*
* Methods:
*	Display()
*		Displays a card based on its suit and rank.
*	Set_Rank(Rank rank)
*		Sets the rank of a card to the rank passed in.
*	Set_Suit(Suit suit)
*		Sets the suit of a card to the suit passed in.
*	Rank Get_Players_Rank()
*		Gets the rank of the player.
*	Rank Get_Dealers_Rank(int current)
*		Gets the rank of the dealer.
*	Get_Rank()
*		Returns the rank of a card
*	Get_Suit()
*		Returns the suit of a card
*************************************************************************/
#ifndef CARD_H
#define CARD_H

class Card
{
public:
	enum Rank { x=1, ACE, DEUCE, TREY, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { X=3,HEART, DIAMOND, CLUB, SPADE };

	Card(Rank rank = ACE, Suit suit = SPADE);
	~Card();
	Card & operator=(const Card & rhs);

	void Display_Card();		//Displays a card
	void Set_Rank(Rank rank);	//Sets the rank of the card
	void Set_Suit(Suit suit);	//Sets the suit of the card
	Rank Get_Players_Rank();	//Gets the players rank
	Rank Get_Dealers_Rank(int current);	//Gets the dealers rank
	Rank Get_Rank();	//Gets the rank
	Suit Get_Suit();	//Gets the suit
	friend ostream & operator<< (ostream & stream, const Card & except);	//Output operator
	bool operator==(Card first);
	bool operator!=(Card first);

private:
	Rank m_rank;	//The rank of a card
	Suit m_suit;	//The suit of a card
};

#endif

