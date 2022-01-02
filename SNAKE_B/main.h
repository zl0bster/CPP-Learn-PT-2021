#pragma once

enum Game_Modes { DEMO_MODE = 1, MANUAL_MODE };

struct MainData
{
	int gameMode = DEMO_MODE;
	const int moveDelay = 150;
	FieldData* fp;
	FoodData* fd;
	SnakeData* sd;
};
void set_new_dir(Directions dir);
void set_exit_flag();
void exit_game(MainData* md);
