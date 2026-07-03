#ifndef COMPILER_H
#define COMPILER_H

#include <string>

class Compiler {
    public:
        Compiler();
        ~Compiler() = default;
        void runFile(std::string path);
        void error(std::string line, std::string message);
    private:
        bool had_error;
        void run(std::string source);
        void report(std::string line, std::string where, std::string message);
};

#endif
