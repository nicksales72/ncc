use core::num;
use std::{cmp, io::{self, Read}};

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

#[derive(Debug)]
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
                last_char = '\0';
            }
        }

        // println!("{}", last_char);

        if last_char.is_alphabetic() {
            self.identifier_str = Some(last_char.to_string());
            // println!("{:?}", self.identifier_str);

            while let Some(my_char) = get_char() && my_char.is_alphanumeric() {
                self.identifier_str.get_or_insert(String::new()).push(my_char);
            }

            if self.identifier_str == Some("def".to_string()) {
                println!("def!");
                return Token::TokDef;
            }
            if self.identifier_str == Some("extern".to_string()) {
                println!("extern!");
                return Token::TokExtern;
            }

            return Token::TokIdentifier;
        }

        if last_char.is_ascii_digit() || last_char == '.' {
            let mut num_str: String = String::new();
            while last_char.is_ascii_digit() || last_char == '.' {
                num_str.push(last_char);
                match get_char() {
                    Some(c) => last_char = c,
                    None => break,
                }
            }

            if let Ok(num) = num_str.parse::<f64>() {
                self.num_val = Some(num);
            }
        }

        return Token::TokNumber;
    }
}


fn main() {
    let mut lexer: Lexer = Lexer {identifier_str: None, num_val: None};
    // println!("{:?}", lexer.identifier_str);
    let test = lexer.get_tok();
    // println!("{:?}", lexer.identifier_str);
    println!("{:?}", lexer);
}
