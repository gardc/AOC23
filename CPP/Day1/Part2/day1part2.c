#include "day1part2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

// Using C style programming for fun.

// returns -1 if no found
static int extractTextualNumberFromLine(const char* line)
{
	static const char* number_strings[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	for (int i = 0; i < 10; i++) {
		size_t len = strlen(number_strings[i]);
		if (strncmp(line, number_strings[i], len) == 0) {
			return i;
		}
	}
	return -1;
}

static int extractNumberFromLine(const char* line)
{
	int first = -1,
		last = -1;

	for (int i = 0; i < strlen(line); i++)
	{
		int extractedTextNumber = extractTextualNumberFromLine(&line[i]);
		if (isdigit(line[i]))
		{
			if (first == -1)	first = line[i] - '0';
			else				last = line[i] - '0';
		}
		else if (extractedTextNumber != -1)
		{
			if (first == -1)	first = extractedTextNumber;
			else				last = extractedTextNumber;
		}
	}

	if (first == -1)		return 0;
	else if (last == -1)	return first * 10 + first;

	return first * 10 + last;
}

int day1part2processFile(const char* filePath)
{
	FILE* file;
	char lineBuffer[MAX_LINE_LENGTH];
	errno_t err;
	int sum = 0;

	if (err = fopen_s(&file, filePath, "r") != 0)
		exit(EXIT_FAILURE);

	while (fgets(lineBuffer, MAX_LINE_LENGTH, file) != NULL)
	{
		lineBuffer[strcspn(lineBuffer, "\n")] = 0;
		lineBuffer[strcspn(lineBuffer, "\r\n")] = 0;

		int linesum = extractNumberFromLine(lineBuffer);

		sum += linesum;
	}

	fclose(file);

	return sum;
}
