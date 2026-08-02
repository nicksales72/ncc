CXX = g++
OBJS  = build/main.o build/lexer.o build/helpers.o build/parser.o build/codegen.o build/token.o
TEST_OBJS  = build/test_lexer.o build/lexer.o build/helpers.o build/token.o
CXXFLAGS = -g -c -Wall -Wextra -Wpedantic -Werror -std=c++20
GTEST_CXXFLAGS = -lgtest_main -lgtest -lpthread

all: ncc

ncc: $(OBJS) 
	$(CXX) $(OBJS) -o ncc 

test: $(TEST_OBJS) | build
	$(CXX) $(GTEST_CXXFLAGS) $(TEST_OBJS) -o test_lexer

build/test_lexer.o: test/test_lexer.cpp | build
	$(CXX) $(CXXFLAGS) test/test_lexer.cpp -o build/test_lexer.o

build/main.o: src/main.cpp | build
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

build/lexer.o: src/lexer/lexer.cpp | build
	$(CXX) $(CXXFLAGS) -c src/lexer/lexer.cpp -o build/lexer.o

build/parser.o: src/parser/parser.cpp | build
	$(CXX) $(CXXFLAGS) -c src/parser/parser.cpp -o build/parser.o

build/codegen.o: src/codegen/codegen.cpp | build
	$(CXX) $(CXXFLAGS) -c src/codegen/codegen.cpp -o build/codegen.o

build/token.o: src/lexer/token.cpp | build
	$(CXX) $(CXXFLAGS) -c src/lexer/token.cpp -o build/token.o

build/helpers.o: src/helpers/helpers.cpp | build
	$(CXX) $(CXXFLAGS) -c src/helpers/helpers.cpp -o build/helpers.o

build: 
	mkdir -p build/

clean: 
	rm -rf build ncc test_lexer 
