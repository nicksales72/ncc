use std::io::{self, Read};

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
    identifier_str: String,
    num_val: f64,
}

impl Lexer {
    fn get_tok() {
        let mut last_char: char = ' ';

        while last_char == ' ' {
            if let Some(my_char) = get_char() {
                last_char = my_char;
            } else {
                last_char = ' ';
            }
        }

        println!("{}", last_char);

        if last_char.is_alphabetic() {
            println!("works");
        }
    }
}


fn main() {
    println!("Hello0 world ");
    Lexer::get_tok();
}
