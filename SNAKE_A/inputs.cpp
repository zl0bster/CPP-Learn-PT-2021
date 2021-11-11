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
	{75, MOVE_LT},
	{77, MOVE_RT},
	{72, MOVE_UP},
	{80, MOVE_DN},
	{'A', MOVE_LT},
	{'D', MOVE_RT},
	{'W', MOVE_UP},
	{'S', MOVE_DN},
	{'0', EXIT}
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