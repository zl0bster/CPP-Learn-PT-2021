#pragma once
#if defined _INPUTS_SET
#define _INPUTS_SET

#endif // 

enum Actions
{
	MOVE_UP,
	MOVE_DN,
	MOVE_RT,
	MOVE_LT,
	EXIT,
	UNDEF
};

int read_input();

