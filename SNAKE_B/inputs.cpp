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
	int mapSize = sizeof(keyMap) / sizeof(keyMap[0]);
	int ch;
	char action = UNDEF;
	if (!_kbhit()) return action;
	ch = _getch();
	ch = toupper(ch);

#if _DEBUG
	_putch(ch);
	_putch('\r');    // Carriage return
	_putch('\n');    // Line feed
#endif
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