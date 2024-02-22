package day1

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"unicode"
)

func _extractNumberFromLine(line string) int {
	var numericChars []rune
	// iterate over the characters in the line and add numeric characters to array
	for _, char := range line {
		if unicode.IsNumber(char) {
			numericChars = append(numericChars, char)
		}
	}

	var result string
	if len(numericChars) == 0 {
		return 0
	} else if len(numericChars) == 1 {
		for i := 0; i < 2; i++ {
			result += string(numericChars[0])
		}
	} else if len(numericChars) >= 2 {
		result += string(numericChars[0])
		result += string(numericChars[len(numericChars)-1])
	}

	// convert the string to an integer
	number, err := strconv.Atoi(result)
	if err != nil {
		panic(err)
	}
	return number
}

func Day1Part1ProcessFile(filePath string) int {
	// open file for streaming
	readFile, err := os.Open(filePath)

	if err != nil {
		fmt.Println(err)
	}
	fileScanner := bufio.NewScanner(readFile)

	fileScanner.Split(bufio.ScanLines)

	sum := 0
	for fileScanner.Scan() {
		sum += extractNumberFromLine(fileScanner.Text())
	}
	readFile.Close()

	return sum
}
