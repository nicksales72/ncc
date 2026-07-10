CXX = g++
OBJS  = main.o compiler.o tokenizer.o helpers.o
TEST_OBJS  = test_tokenizer.o 
CXXFLAGS = -g -c -Wall -Wextra -Wpedantic -Werror -std=c++20
TEST_CXXFLAGS = -lgtest_main -lgtest -lpthread

ncc: $(OBJS) 
	$(CXX) $(OBJS) -o ncc 

test: test_tokenizer.o tokenizer.o helpers.o
	$(CXX) $(TEST_CXXFLAGS) test_tokenizer.o tokenizer.o helpers.o -o test_tokenizer

test_tokenizer.o: test/test_tokenizer.cpp
	$(CXX) $(CXXFLAGS) test/test_tokenizer.cpp -o test_tokenizer.o

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o main.o

compiler.o: src/compiler/compiler.cpp
	$(CXX) $(CXXFLAGS) src/compiler/compiler.cpp -o compiler.o

tokenizer.o: src/tokenizer/tokenizer.cpp 
	$(CXX) $(CXXFLAGS) src/tokenizer/tokenizer.cpp -o tokenizer.o

helpers.o: src/helpers/helpers.cpp 
	$(CXX) $(CXXFLAGS) src/helpers/helpers.cpp -o helpers.o

clean: 
	rm $(OBJS) $(TEST_OBJS) ncc test_tokenizer
