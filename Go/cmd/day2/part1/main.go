package main

import "gardc/aoc23/day2/part1"

func main() {
	sum, err := part1.Do("../input/day2/test.txt")
	if err != nil {
		panic(err)
	}
	println(sum)
}
