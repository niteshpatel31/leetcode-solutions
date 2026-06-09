bin:=main
file:=test
lib:=-lfmt
run: build

build:
	@g++ $(file).cpp -g -Wall -Werror -Wextra -o $(bin) -std=c++23 $(lib)&& ./$(bin)

clean:
	rm -rf $(file).o $(bin)

.PHONY: run build clean
