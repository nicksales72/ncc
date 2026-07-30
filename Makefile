CXX = g++
OBJS  = build/main.o build/tokenizer.o build/helpers.o
TEST_OBJS  = build/test_tokenizer.o build/tokenizer.o build/helpers.o
CXXFLAGS = -g -c -Wall -Wextra -Wpedantic -Werror -std=c++20
GTEST_CXXFLAGS = -lgtest_main -lgtest -lpthread

all: ncc

ncc: $(OBJS) 
	$(CXX) $(OBJS) -o ncc 

test: $(TEST_OBJS) | build
	$(CXX) $(GTEST_CXXFLAGS) $(TEST_OBJS) -o test_tokenizer

build/test_tokenizer.o: test/test_tokenizer.cpp | build
	$(CXX) $(CXXFLAGS) test/test_tokenizer.cpp -o build/test_tokenizer.o

build/main.o: src/main.cpp | build
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

build/tokenizer.o: src/tokenizer/tokenizer.cpp | build
	$(CXX) $(CXXFLAGS) -c src/tokenizer/tokenizer.cpp -o build/tokenizer.o

build/helpers.o: src/helpers/helpers.cpp | build
	$(CXX) $(CXXFLAGS) -c src/helpers/helpers.cpp -o build/helpers.o

build: 
	mkdir -p build/

clean: 
	rm -rf build ncc test_tokenizer
