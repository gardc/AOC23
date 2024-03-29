package day1

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func extractNumberFromLine(line string) int {
	var first, second int = -1, -1

	for _, r := range line {
		if unicode.IsDigit(r) {
			if first == -1 {
				first = int(r - '0')
			} else {
				second = int(r - '0')
			}
		}
	}

	if first == -1 {
		return -1
	} else if second == -1 {
		return first*10 + first
	} else {
		return first*10 + second
	}
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
