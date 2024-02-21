#pragma once
#include <string>

namespace Day1Part2
{
	class CalibrationDocument
	{
	public:
		void processFile(std::string filePath);
		int getSum() { return sum; }

	private:
		int sum = 0;
		int extractNumberFromLine(std::string line);
		int extractNumberFromText(std::string text);
	};
}