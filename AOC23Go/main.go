package main

import (
	"fmt"
	"gardc/aoc23/day1"
	"time"
)

func main() {
	startTime := time.Now()

	res := day1.ProcessFile("./day1/data.txt")
	fmt.Println(res)

	elapsedTime := time.Since(startTime)

	fmt.Println("Execution time: ", elapsedTime)
}
