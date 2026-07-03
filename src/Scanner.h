#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

#include "Token.h"

class Scanner {
    public: 
        Scanner(std::string source);
        std::vector<Token> scanTokens();
};

#endif
