package part1

import (
	"errors"
	"fmt"
	"gardc/aoc23/filescanner"
	"regexp"
	"strconv"
	"strings"
)

type CubeColor uint8

const (
	red CubeColor = iota
	blue
	green
)

type Game struct {
	ID   int
	Sets []Set
}

type Set struct {
	Cubes []Cube
}

type Cube struct {
	Amount int
	Color  CubeColor
}

func parseGameLine(games *[]Game, line string) error {
	// example line:
	// Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue

	g := Game{}

	re := regexp.MustCompile(`Game (\d+): ((?:\d+ (green|red|blue),? ?)+)`)
	matches := re.FindStringSubmatch(line)

	convertToInt := func(s string) int {
		i, err := strconv.Atoi(s)
		if err != nil {
			panic(fmt.Sprintf("failed to convert int: %s", err.Error()))
		}
		return i
	}

	if matches == nil {
		return errors.New("invalid line")
	} else {
		for i, match := range matches {
			fmt.Printf("Match %d: ''%s\n''", i, match)
			// game ID
			if i == 0 {
				g.ID = convertToInt(match)
			} else {
				s := Set{}
				cubeSets := strings.Split(match, "; ")
				for _, set := range cubeSets {
					cubes := strings.Split(set, ", ")
					for _, cubeStr := range cubes {
						parts := strings.Split(cubeStr, " ")
						cube := Cube{
							Amount: convertToInt(parts[0]),
							Color:  CubeColor(convertToInt(parts[1])),
						}
						s.Cubes = append(s.Cubes, cube)
						fmt.Println(" - Cube: ", cube)
					}
				}
				g.Sets = append(g.Sets, s)
			}
		}
	}
	*games = append(*games, g)
	fmt.Print("\n\n")

	return nil
}

func Do(filename string) (int, error) {
	scanner, file, err := filescanner.NewScannerForFile(filename)
	if err != nil {
		panic(err)
	}

	var games []Game
	for scanner.Scan() {
		err := parseGameLine(&games, scanner.Text())
		if err != nil {
			return 0, err
		}
	}
	file.Close()

	fmt.Printf("Games: %v\n", games)

	return 0, nil
}
