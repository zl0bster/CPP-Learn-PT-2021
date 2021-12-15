#include <iostream>
#include <conio.h>
#include "game.h"
#include "screen.h"

void game_over()
{
	std::cout << "GAME OVER";
	_getch();
	std::exit(EXIT_SUCCESS);
}