// AOC23CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "Day1/CalibrationDocument.h"

int main()
{
    Day1::CalibrationDocument day1;

    auto start = std::chrono::high_resolution_clock::now();

    day1.processFile("C:\\Users\\gaming\\source\\repos\\AOC23\\AOC23CPP\\Day1\\data.txt");
    std::cout << "Sum: " << day1.getSum() << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> execution_time = end - start;
    std::cout << "Execution Time: " << execution_time.count() << " ms" << std::endl;
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
