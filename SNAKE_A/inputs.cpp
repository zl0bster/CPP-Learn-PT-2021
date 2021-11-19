#include <conio.h>
#include <ctype.h>

#include "inputs.h"

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
	{'0', EXIT},
	{'1', OP1}
};

int read_input()
{
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