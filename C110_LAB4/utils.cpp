#include <string.h>
#include <cstdlib>
#include <iostream>

void get_rnd_str1(char* newStr, size_t maxLen)
{
	using std::cout;
	const char* genCharSet = "abcdefghijklmnopqrstuvwxyz";
	const char* charSet1 = "aeiou ";
	size_t genSetLen = strlen(genCharSet);
	size_t set1Len = strlen(charSet1);
	//static char* newStr = new char[maxLen];
#if _DEBUG
	cout << maxLen << '\t' << genSetLen << '\t' << set1Len << '\n';
#endif
	unsigned int i = 0;
	while (i < maxLen)
	{
		if (i % 2 == 0)
			newStr[i] = genCharSet[rand() % genSetLen];
		else
			newStr[i] = charSet1[rand() % set1Len];
		i++;
	}
	newStr[maxLen - 1] = '\0';
#if _DEBUG
	cout << newStr << '\n';
#endif

}