main: src/main.cpp
	g++ src/*.cpp -o ncc

clean: 
	rm ncc
