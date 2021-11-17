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
	UNDEF,
	OP1,
	OP2
};

int read_input();

