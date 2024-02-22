#include "day1part1.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "day1part1.h"

#define MAX_LINE_LENGTH 256

// Using C style programming for fun.

static int extractNumberFromLine(const char* line)
{
	int first = -1,
		last = -1;

	for (int i = 0; i < strlen(line); i++)
	{
		if (isdigit(line[i]))
		{
			if (first == -1)
				first = line[i] - '0';
			else
				last = line[i] - '0';
		}
	}

	if (first == -1)
		return 0;
	else if (last == -1)
		return first * 10 + first;

	return first * 10 + last;
}

int Day1::processFile(const char* filePath)
{
	int sum = 0;
	FILE* file;
	char lineBuffer[MAX_LINE_LENGTH];
	errno_t err;

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
