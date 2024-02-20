#include "CalibrationDocument.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void Day1::CalibrationDocument::processFile(std::string filePath)
{
	std::ifstream fileStream(filePath);

	if (!fileStream.is_open())
		throw std::invalid_argument("File not found");

	std::string line;
	while (std::getline(fileStream, line))
	{
		this->sum += extractNumberFromLine(line);
	}
}

int Day1::CalibrationDocument::extractNumberFromLine(std::string line)
{
	// step over all characters and collect those that are digits
	std::vector<char> nums;
	for (char c : line)
	{
		if (isdigit(c))
		{
			/*auto len = numberString.length();
			if (len >= 2)				break;
			if (len == 0 || len == 1)	numberString += c;*/
			nums.push_back(c);
		}
	}

	std::ostringstream numberString;
	if (nums.size() == 0)
	{
		return 0;
	}
	if (nums.size() == 1)
	{
		// do twice
		for (int i = 0; i < 2; i++)
			numberString << nums[0];
	}
	if (nums.size() >= 2)
	{
		numberString << nums[0] << nums[nums.size() - 1];
	}

	// convert the string to an integer
	return std::stoi(numberString.str());
}
