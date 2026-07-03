main: src/main.cpp
	g++ -g src/*.cpp -o ncc -Wall -Wextra -Wpedantic -Werror -std=c++20

clean: 
	rm ncc
