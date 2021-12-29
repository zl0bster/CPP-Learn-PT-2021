#include <conio.h>
#include <ctype.h>

#include "winconsole.h"

#include "inputs.h"
#include "screen.h"

struct KeyMapItem
{
	unsigned int key;
	char action;
};
static KeyMapItem keyMap[]
{
	{75, KEY_LT},
	{77, KEY_RT},
	{72, KEY_UP},
	{80, KEY_DN},
	{'A', KEY_LT},
	{'D', KEY_RT},
	{'W', KEY_UP},
	{'S', KEY_DN},
	{'Ô', KEY_LT},
	{'Â', KEY_RT},
	{'Ö', KEY_UP},
	{'Û', KEY_DN},
	{'0', EXIT},
	{ESC_KEY, EXIT},
	{'1', OP1},
	{'2', OP2},
	{'3', OP3}
};

int read_input()
{
	print_menu();
	int mapSize = sizeof(keyMap) / sizeof(keyMap[0]);
	int ch;
	ch = _getch();
	ch = toupper(ch);

#if _DEBUG
	_putch(ch);
	_putch('\r');    // Carriage return
	_putch('\n');    // Line feed
#endif
	char action = UNDEF;
	for (int i = 0; i < mapSize; i++)
	{
		if (ch == keyMap[i].key)
		{
			action = keyMap[i].action;
			break;
		}
	}
	return action;
}

bool if_exit()
{
	if (!_kbhit()) return false;
	int ch;
	ch = _getch();
	ch = toupper(ch);
	switch (ch) {
	case ESC_KEY:
		return true;
	case '0':
		return true;
	}
	return false;
}