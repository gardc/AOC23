all: day1part1 day1part2

OUTPUT_SUFFIX :=
ifeq ($(OS),Windows_NT)
 OUTPUT_SUFFIX = .exe
endif

day1part1:
	go build -o bin/day1part1$(OUTPUT_SUFFIX) cmd/day1/part1/main.go
day1part2:
	go build -o bin/day1part2$(OUTPUT_SUFFIX) cmd/day1/part2/main.go
day2part1:
	go build -o bin/day2part1$(OUTPUT_SUFFIX) cmd/day2/part1/main.go