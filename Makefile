CXX = g++
OBJS  = main.o compiler.o scanner.o token.o helpers.o
CXXFLAGS = -g -c -Wall -Wextra -Wpedantic -Werror -std=c++20

ncc: $(OBJS) 
	$(CXX) $(OBJS) -o ncc 

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o main.o

compiler.o: src/Compiler/Compiler.cpp
	$(CXX) $(CXXFLAGS) src/Compiler/Compiler.cpp -o compiler.o

scanner.o: src/Scanner/Scanner.cpp
	$(CXX) $(CXXFLAGS) src/Scanner/Scanner.cpp -o scanner.o

token.o: src/Tokenizer/Token.cpp 
	$(CXX) $(CXXFLAGS) src/Tokenizer/Token.cpp -o token.o

helpers.o: src/Helpers/Helpers.cpp 
	$(CXX) $(CXXFLAGS) src/Helpers/Helpers.cpp -o helpers.o

clean: 
	rm $(OBJS) ncc
