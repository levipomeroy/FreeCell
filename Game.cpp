#include "Game.h"
/*******************************************************************
* Author:		Levi Pomeroy
* Filename:		Game.cpp
* Date Created:		02/04/17
* Modifications:	02/05/17 – Got menu working and output of cells 
*							   and cards
*  					02/06/17 – Able to move multipe cards andmove to 
*							   free and home cells.
*					02/08/17 - Divided into peices and seperated amongst
*							   classes because todd doesnt like my design ;)
*					02/09/17 - Added new logic to move within play areas
*					02/10/17 - Added new game feature and fixed minor errors
********************************************************************/


/**********************************************************************
* Purpose: This function sets the defualt length of m_free cell to 4,
*		   m_home to 4, and m_play to 8.
*
* Precondition:	Data members lengths were unitialized.
*
* Postcondition: Data members lengths are initialized.
************************************************************************/
Game::Game()
{
	m_free.SetLength(4);
	m_home.SetLength(4);
	m_play.SetLength(8);
}

/**********************************************************************
* Purpose: This function sets this to copy, calling the op= to handle
*		   operations.
*
* Precondition:	N/A
*
* Postcondition: Copied.
************************************************************************/
Game::Game(const Game & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets all data members to rhs data memebers, 
*		   allowing the data members classes op= to handle the assignment.
*
* Precondition:	Data members are uninitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
Game & Game::operator=(const Game & rhs)
{
	if (this != &rhs)
	{
		m_deck = rhs.m_deck;	//These types all have op='s that will take care of everything;
		m_free = rhs.m_free;
		m_home = rhs.m_home;
		m_play = rhs.m_play;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function sets all data members back to default values.
*
* Precondition:	Data members may be initialized.
*
* Postcondition: Data members are initialized to default values.
************************************************************************/
Game::~Game()
{
	m_free.SetLength(0);
	m_home.SetLength(0);
	m_play.SetLength(0);
}

/**********************************************************************
* Purpose: This function outputs the free cells and home cells by calling 
*		   the two types output functions.
*
* Precondition:	Cells were not dispalyed.
*
* Postcondition: Cells are displayed.
************************************************************************/
void Game::OutputCells()
{
	cout << "      Free Cells" << "\t\tNew game = 99\t\t" << "Home Cells" << endl;

	m_free.Output();
	m_home.Display();
}

/**********************************************************************
* Purpose: This function assigns the cards of a deck randomly into the
*		   stacks of the play area.
*
* Precondition:	Cards were not dealt.
*
* Postcondition: Cards are dealt and play area is full.
************************************************************************/
void Game::AssignCards()
{
	Card temp;
	m_deck.Shuffle();

	int count = 0;
	for (int i = 0; i < 52; i++)
	{
		temp = m_deck.Deal();
		m_play.SelectColumn(count).Push(temp);
		count++;

		if (count % 8 == 0)
		{
			count = 0;
		}
	}
}

/**********************************************************************
* Purpose: This function prints the play area by calling play areas print
*		   function.
*
* Precondition:	Play is not visible.
*
* Postcondition: Play area is visible.
************************************************************************/
void Game::PrintCards()
{
	m_play.Print();
}

/**********************************************************************
* Purpose: This function is the main control loop of the game. It prints
*		   a menu and takes in the user's moves. It then enacts those moves
*		   appropriatly.
*
* Precondition:	Board is displayed but moves arent possible.
*
* Postcondition: Moves can be carried out.
************************************************************************/
void Game::Play()
{
	int choice = 0;			//Decides which intitial menu choice to enact
	bool success = false;	//Decides whether a move is legal or not
	bool seq = false;		//Determines if cards within selected move are in seq order
	int from_col = 0;		//Holds which column user wants to move from
	int to_col = 0;			//Holds which column the user wants to go to
	int num_cards = 0;		//The numbers of cards the user wants to move
	int count = 0;			//Count of how many cards are in free cells
	int moveable = 0;		//Number of movable cards
	bool color = false;		//Decides if colors are in alternating order

	bool win = false;		//Did the user win??
	char play_again = '\0'; //Will the user play again?
	int to_or_from = 0;		//Decides sub-menu choice, to or from a cell
	int home_count = 0;		//Determines which home cell to write to
	Card empty;				//This is used to reset a free cell once empty
	empty.x;				//These values initialize it so that it can be reset
	empty.X;
	int free_choice = 0;	//Used to pick which free cell to move to/from
	int free_ray[] = { -1,-1,-1,-1 };	//Keeps track of which free cells are full/empty, if negative then empty
	int free_ray_index = 0;	//Keeps track of which index of free cell to operate on

	OutputCells();
	AssignCards();
	PrintCards();

	while (choice != 4)
	{
		do
		{
			cout << "1.)Move within play cards" << endl;
			cout << "2.)Move to/from free cells" << endl;
			cout << "3.)Move to home cells" << endl;
			cout << "4.)Exit" << endl;
			cout << "=>";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 99);	//Repeat until input is valid

		switch (choice)
		{
		case 1:
		{
			do
			{
				cout << "\nFrom which column? ";
				cin >> from_col;
			} while (from_col > 8 || from_col < 1);	//Repeat until input is valid

			do
			{
				cout << "To which column? ";
				cin >> to_col;
			} while (to_col > 8 || to_col < 1);	//Repeat until input is valid

			cout << "How many cards? ";
			cin >> num_cards;

			seq = m_play.SeqOrder(num_cards, to_col, from_col);
			color = m_play.CorrectColor(num_cards, to_col, from_col);
			if (seq == true && color == true)	//if cards are sequential and alternating in color
			{
				if (num_cards == 1)
				{
					m_play.SelectColumn(to_col - 1).Push(m_play.SelectColumn(from_col - 1).Pop());
					success = true;
				}
				else
				{
					moveable = NumMovableCards(free_ray);
					if (num_cards <= moveable)
					{
						if (m_play.SelectColumn(from_col - 1).Size() > num_cards)
						{
							Array<Card> temp(num_cards);
							success = true;
							for (int i = 0; i < num_cards; i++)
							{
								temp[i] = m_play.SelectColumn(from_col - 1).Pop();
							}

							for (int i = num_cards-1; i >=0; i--)
							{
								m_play.SelectColumn(to_col - 1).Push(temp[i]);
							}
						}
						else
						{
							success = false;
						}
					}
					else
					{
						success = false;
					}
				}
			}
			if (success == false)
			{
				InvalidMove();
			}

			system("cls");	//Clear and reprint baord with new mods made
			OutputCells();
			PrintCards();
			break;
		}
		case 2:
		{
			do
			{
				cout << "\n1.Move to free cell" << endl;
				cout << "2.Move from free cell" << endl;
				cout << "=>";
				cin >> to_or_from;
			} while (to_or_from != 1 && to_or_from != 2);   //Repeat until input is valid

			if (to_or_from == 1)
			{
				do
				{
					cout << "\nFrom which column? ";
					cin >> from_col;
				} while (from_col > 8 || from_col < 1); //Repeat until input is valid

				do
				{
					cout << "To which free cell?(1-4) ";
					cin >> free_choice;
				} while (free_choice < 1 || free_choice > 4);

				*free_ray = m_free.EmptyCells(free_ray, empty);	//Check which free cells are empty

				if (free_ray[free_choice - 1] < 0)	//If that free cell is empty
				{
					m_free.SelectIndex(free_choice - 1) = m_play.SelectColumn(from_col - 1).Pop();
					count++;
				}
				else
				{
					InvalidMove();
				}
			}
			//*************************Move from free cell to play area*******************************
			else if (to_or_from == 2)
			{
				do
				{
					cout << "\nFrom which free cell?(1-4) ";
					cin >> free_choice;
				} while (free_choice > 4 || free_choice < 1); //Repeat until input is valid

				do
				{
					cout << "To which column? ";
					cin >> to_col;
				} while (to_col > 8 || to_col < 1); //Repeat until input is valid

				if (m_free.SelectIndex(free_choice - 1).Get_Rank() +1 == m_play.SelectColumn(to_col - 1).Peek().Get_Rank())
				{	//Check if move will be in seq order
					seq = true;
				}
				if ((m_free.SelectIndex(free_choice - 1).Get_Suit() <= 4 && m_play.SelectColumn(to_col - 1).Peek().Get_Suit() >= 5) ||
					(m_free.SelectIndex(free_choice).Get_Suit() >= 5 && m_play.SelectColumn(from_col - 1).Peek().Get_Suit() <= 4))
				{	//check if correct color order
					color = true;
				}

				*free_ray = m_free.EmptyCells(free_ray, empty);	//Check which free cells are empty

				if (seq == true && color == true && free_ray[free_choice -1] >=0/*count >= 0*/)
				{
					count--;
					success = true;
					m_play.SelectColumn(to_col - 1).Push(m_free.SelectIndex(free_choice - 1));
					m_free.SelectIndex(free_choice - 1) = empty;
				}
				else
				{
					success = false;
				}

				if (success == false)
				{
					InvalidMove();
				}
			}

			system("cls");
			OutputCells();
			PrintCards();
			break;
		}
		case 3:
		{
			do
			{
				cout << "From which column? ";
				cin >> from_col;
			} while (from_col > 8 || from_col < 1); //Repeat until input is valid

			do
			{
				cout << "To which home cell(1-4)? ";
				cin >> home_count;
			} while (home_count > 4 || home_count < 1); //Repeat until input is valid

			if (m_home.SelectColumn(home_count - 1).IsEmpty())	//if index of home cells is empty
			{
				if (m_play.SelectColumn(from_col - 1).Peek().Get_Rank() == 1)	//and first card is an ace
				{
					m_home.SelectColumn(home_count - 1).Push(m_play.SelectColumn(from_col - 1).Pop());
				}
				else
				{
					cout << "\n****First card must be an ace!!****" << endl;
					cout << "Press enter to continue.." << endl;
					cin.get();
					cin.get();
				}
			}
			else    //Every time pat the first
			{
				if ((m_play.SelectColumn(from_col - 1).Peek().Get_Suit() == m_home.SelectColumn(home_count - 1).Peek().Get_Suit())
					&& ((m_play.SelectColumn(from_col - 1).Peek().Get_Rank() == m_home.SelectColumn(home_count - 1).Peek().Get_Rank() + 1)))
				{   //If same suit and in seq order
					m_home.SelectColumn(home_count - 1).Push(m_play.SelectColumn(from_col - 1).Pop());
				}
				else
				{
					InvalidMove();
				}
			}
			system("cls");
			OutputCells();
			PrintCards();

			win = DidIWin();
			//win = true;	//For testing only

			if (win == true)
			{
				do
				{
					cout << "\n*****YOU WIN!!!!*****" << endl;
					cout << " Would you like to play again? (y or n) ";
					cin >> play_again;
				} while (play_again != 'y' && play_again != 'n');
				if (play_again == 'y')
				{
					NewGame();
				}
				else
				{
					cout << "Thanks for playing..." << endl;
					choice = 4; //exit
				}
			}
			break;
		}
		case 4:
			break;	//Exit
		case 99:
			NewGame();	//Clears everything and reshuffles and reprints
			break;
		default:
		{
			throw Exception("Invalid input for menu");	//should never get to here
		}
		}
	}
}

/**********************************************************************
* Purpose: This function returns whether or not the user has won the game.
*
* Precondition:	Win status is unknown.
*
* Postcondition: Win status is known.
************************************************************************/
bool Game::DidIWin()
{
	bool win = false;
	for (int i = 0; i < 4; i++)
	{
		if (m_home.SelectColumn(i).IsFull())	//if home cells are all full
		{
			win = true;
		}
		else
		{
			win = false;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (m_play.SelectColumn(i).IsEmpty()) //and play cards are all empty
		{
			win = true;	//user wins
		}
		else
		{
			win = false;
		}
	}
	return win;
}

/**********************************************************************
* Purpose: This function outputs an error message and waits for the user
*		   to acknowlesge the error before proceeding.
*
* Precondition:	N/A
*
* Postcondition: Arror message is displayed.
************************************************************************/
void Game::InvalidMove()
{
	cout << "\n*****Invalid move!!*****" << endl;
	cout << "Press Enter to continue..." << endl;
	cin.get();
	cin.get();	//Waits for user to acknowledge and hit enter to move on
}

/**********************************************************************
* Purpose: This function clears out the free cells, home cells, and play
*		   area and then reshuffles the deck, reassigns the cards into the
*		   play area and reprints the game.
*
* Precondition:	Current game running.
*
* Postcondition: New game started.
************************************************************************/
void Game::NewGame()
{
	Card empty;
	empty.x;
	empty.X;

	for (int i = 0; i < 4; i++)	//Clear home cells
	{
		while (!m_home.SelectColumn(i).IsEmpty())
		{
			m_home.SelectColumn(i).Pop();
		}
	}

	for (int i = 0; i < 8; i++)	//Clear play area
	{
		while (!m_play.SelectColumn(i).IsEmpty())
		{
			m_play.SelectColumn(i).Pop();
		}
	}

	for (int i = 0; i < 4; i++)	//Clear free cells
	{
		m_free.SelectIndex(i) = empty;
	}

	AssignCards();	//Reassign cards into play area
	system("cls");	//Clear screen
	OutputCells();	//Re-ouput cells
	PrintCards();	//Re-print cards
}	

/**********************************************************************
* Purpose: This function calculates and returns the max number of cards
*		   a player is allowed to move from one play area column to another.
*
* Precondition:	Number of cards moveable is unknown.
*
* Postcondition: Number of cards moveable is known.
************************************************************************/
int Game::NumMovableCards(int * ra)
{
	int moveable = 0;
	Card empty;
	empty.x;
	empty.X;
	int empty_free = 0;
	int empty_col = 0;

	for (int i = 0; i < 4; i++)
	{
		ra[i] = -1;	//reset to default values
	}

	for (int i = 0; i < 4; i++)	//Check which free cells are empty 
	{
		if (m_free.SelectIndex(i).Get_Rank() == empty.Get_Rank() && m_free.SelectIndex(i).Get_Suit() == empty.Get_Suit())
		{
			empty_free++;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (m_play.SelectColumn(i).IsEmpty())	//For every empty column
		{
			empty_col++;
		}
	}

	moveable = ((1 + empty_free) * (pow(2, empty_col)));	//Calculate number of cards allowed

	return moveable;
}


