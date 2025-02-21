#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable : 4996) 

typedef struct {
	char test[100];
	char pattern[100];
	char antipattern[100];
	char includes[100];
	char nincludes[100];
} PARAMS;

void pause()
{
	puts("\nPress [Enter] to continue...");
	getchar();
}

void clrscr() //microsoft garbage
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT srect;
	COORD sctrget;
	CHAR_INFO fill;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	srect.Left = srect.Top = 0;
	srect.Right = csbi.dwSize.X;
	srect.Bottom = csbi.dwSize.Y;

	sctrget.X = 0;
	sctrget.Y = 0 - csbi.dwSize.Y;

	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(hConsole, &srect, NULL, sctrget, &fill);

	csbi.dwCursorPosition.X = csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}

void format(PARAMS *in) //replace newline with null-terminator for all the inputs except test (cuz test changes every time)
{
	if (in->pattern[strlen(in->pattern) - 1] == '\n')
	{
		in->pattern[strlen(in->pattern) - 1] = '\0';
	}

	if (in->antipattern[strlen(in->antipattern) - 1] == '\n')
	{
		in->antipattern[strlen(in->antipattern) - 1] = '\0';
	}

	if (in->includes[strlen(in->includes) - 1] == '\n')
	{
		in->includes[strlen(in->includes) - 1] = '\0';
	}

	if (in->nincludes[strlen(in->nincludes) - 1] == '\n')
	{
		in->nincludes[strlen(in->nincludes) - 1] = '\0';
	}
}

int compare(PARAMS* in)
{
	if (in->test[strlen(in->test) - 1] == '\n') //remove newline and replace with null terminator for test word
	{
		in->test[strlen(in->test) - 1] = '\0';
	}

	int lenp = strlen(in->pattern);
	int lenap = strlen(in->antipattern);
	int lent = strlen(in->test);

	if (lenp > 0 && (lent != lenp)) //if length of pattern > 0 then length of test word needs to match it (obviously)
	{
		return 0;
	}

	if (lenap > 0 && (lent != lenap)) //if length of anti-pattern > 0 then length of test word needs to match it (also obviously)
	{
		return 0;
	}

	for (int i = 0; i < lenp; i++) //if we made it this far then lenp = lent; step through each string at the same time and try to find differences; if there are then return 0 (false)
	{
		if (in->pattern[i] != '_' && (in->pattern[i] != in->test[i]))
		{
			return 0;
		}
	}

	for (int i = 0; i < lenap; i++) //same thing, but compare test string and anti-pattern; if there is any similarity then return 0 (false)
	{
		if (in->antipattern[i] != '_' && (in->antipattern[i] == in->test[i]))
		{
			return 0;
		}
	}

	for (int i = 0; i < strlen(in->includes); i++) //if the test string doesn't include smth it's supposed to, return 0
	{
		if (strchr(in->test, in->includes[i]) == NULL)
		{
			return 0;
		}
	}

	for (int i = 0; i < strlen(in->nincludes); i++) //if the test string includes smth it shouldnt, return 0
	{
		if (strchr(in->test, in->nincludes[i]))
		{
			return 0;
		}
	}

	return 1; //every check passed and the test string can be listed as a match! Yippee!
}

int main()
{
start:

	int count = 0; //count number of matches

	PARAMS input = {0};

	FILE *file;
	file = fopen("words.txt", "r");

	if (file == NULL) //somebody didn't follow directions
	{
		puts("Failed to load word list... Check README.txt for help.");
		pause();
		return 1;
	}

	puts("If you need help check README.txt for instructions."); //real
	
	puts("Enter pattern:");
	fgets(input.pattern, 99, stdin);

	puts("Enter exclusion pattern:");
	fgets(input.antipattern, 99, stdin);

	puts("What letters does the word contain?");
	fgets(input.includes, 99, stdin);

	puts("What letters does the word NOT contain?");
	fgets(input.nincludes, 99, stdin);

	puts("---------------------------------------\nWords Found:");

	format(&input);

	while (!feof(file))
	{
		if (fgets(input.test, 99, file)) //if fgets didn't explode (guarantees an array with >= 1 characters so other functions don't blow up)
		{
			if (compare(&input)) //if check passed
			{
				puts(input.test); //write it down
				count++;
			}
		}
	}

	printf("\n%d word(s) found.", count);

	fclose(file); //don't want no mem leak

	pause();
	clrscr();
	goto start;
}
