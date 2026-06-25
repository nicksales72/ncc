use std::io::{self, Read};

#[derive(Debug)]
enum Token {
    TokEof = -1,

    // commands
    TokDef = -2, 
    TokExtern = -3,

    // primary 
    TokIdentifier = -4, 
    TokNumber = -5,
}

fn get_char() -> Option<char> {
    // Attempt to read next byte
    match io::stdin().bytes().next() {
        Some(Ok(byte)) => Some(byte as char),
        _ => None,
    }
}

struct Lexer { 
    identifier_str: Option<String>,
    num_val: Option<f64>,
}

impl Lexer {
    fn get_tok(&mut self) -> Token {
        let mut last_char: char = ' ';

        while last_char == ' ' {
            if let Some(my_char) = get_char() {
                last_char = my_char;
            } else {
                last_char = ' ';
            }
        }

        // println!("{}", last_char);

        if last_char.is_alphabetic() {
            self.identifier_str = Some(last_char.to_string());
            // println!("{:?}", self.identifier_str);

            if self.identifier_str == Some("def".to_string()) {
                return Token::TokDef;
            }
            if self.identifier_str == Some("extern".to_string()) {
                return Token::TokExtern;
            }
            return Token::TokIdentifier;
        }

        return Token::TokNumber;
    }
}


fn main() {
    let mut lexer: Lexer = Lexer {identifier_str: None, num_val: None};
    println!("{:?}", lexer.identifier_str);
    lexer.get_tok();
    println!("{:?}", lexer.identifier_str);
}
