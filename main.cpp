/***********************************************************
* Author:				Levi Pomeroy
* Date Created:			02/10/17
* Last Mod Date:		02/10/17
* Lab Number:			CST 211
* Filename:				Free Cell game
*
* Overview:
*	This program will allow the user to play freecell in console.
*	The user can make every move from the menu and will be notified
*	and prompted to play again if the user wins.
*
* Input:
*	The input will consist of the users move choices.
*
* Output:
*	The output of this program will be the free cells, home cells,
*	and the play areas of cards. Also it will have the menu of move
*	options available.
************************************************************/
#include "Game.h"
#include <crtdbg.h>
using std::cout;
using std::endl;

int main()
{
	Game game;
	try
	{
		game.Play();
	}
	catch (Exception & ex)
	{
		cout << ex;
	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Memory leak check
	return 0;
}

