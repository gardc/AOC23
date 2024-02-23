package day1part2

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

var textualNumbers = []string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}

func extractTextualNumberFromLine(line string) int {
	for i, n := range textualNumbers {
		if strings.HasPrefix(line, n) {
			return i
		}
	}
	return -1
}

func extractNumberFromLine(line string) int {
	var first, second int = -1, -1

	for i, r := range line {
		if unicode.IsDigit(r) {
			if first == -1 {
				first = int(r - '0')
			} else {
				second = int(r - '0')
			}
		} else if x := extractTextualNumberFromLine(line[i:]); x != -1 {
			if first == -1 {
				first = x
			} else {
				second = x
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

func Day1Part2ProcessFile(filePath string) int {
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
