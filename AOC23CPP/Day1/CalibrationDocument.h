#pragma once
#include <string>

namespace Day1
{
	class CalibrationDocument
	{
	public:
		void processFile(std::string filePath);
		int getSum() { return sum; }

	private:
		int sum = 0;
		int extractNumberFromLine(std::string line);
	};
}