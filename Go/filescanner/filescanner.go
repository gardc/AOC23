package filescanner

import (
	"bufio"
	"os"
)

func NewScannerForFile(filePath string) (*bufio.Scanner, *os.File, error) {
	readFile, err := os.Open(filePath)
	if err != nil {
		return nil, nil, err
	}

	fileScanner := bufio.NewScanner(readFile)
	fileScanner.Split(bufio.ScanLines)
	return fileScanner, readFile, nil
}
