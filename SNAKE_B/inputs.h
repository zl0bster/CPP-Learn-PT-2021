#pragma once
#define ESC_KEY 27

enum Actions
{
	NOPS,
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