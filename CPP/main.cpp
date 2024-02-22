// AOC23CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Day1/Part1/day1part1.h"
#include "Day1/Part2/day1part2.h"
#include <iostream>

int main()
{
	int day1part1sum = Day1::processFile("C:\\Users\\gaming\\source\\repos\\gardc\\AOC23\\input\\day1\\part1\\data.txt");
	std::cout << "Day 1 part 1 sum: " << day1part1sum << std::endl;

	int day1part2sum = day1part2processFile("C:\\Users\\gaming\\source\\repos\\gardc\\AOC23\\input\\day1\\part1\\data.txt");
	printf("Day 1 part 2 sum: %i\n", day1part2sum);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
