#pragma once
#if defined _INPUTS_SET
#define _INPUTS_SET

#endif // 

enum Actions
{
	KEY_UP,
	KEY_DN,
	KEY_RT,
	KEY_LT,
	EXIT,
	UNDEF,
	OP1,
	OP2
};

int read_input();

