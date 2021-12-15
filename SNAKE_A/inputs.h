#pragma once
#if defined _INPUTS_SET
#define _INPUTS_SET

#endif // 
#define ESC_KEY 27

enum Actions
{
	KEY_UP,
	KEY_DN,
	KEY_RT,
	KEY_LT,
	EXIT,
	UNDEF,
	OP1,
	OP2,
	OP3
};

int read_input();

