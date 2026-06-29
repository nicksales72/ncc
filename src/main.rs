use std::{env, fs, io, path::Path, process};

pub struct Lox {
    //interpreter: Interpreter,
    had_error: bool,
    had_runtime_error: bool,
}

impl Lox {
    fn run_file(&mut self, path: &str) {
        let path_from_string: &Path = Path::new(path);
        println!("{:?}", path_from_string);

        let bytes: io::Result<Vec<u8>> = fs::read(path_from_string);
        println!("{:?}", bytes);
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let mut lox = Lox {
        had_error: false,
        had_runtime_error: false,
    };
    if args.len() > 2 {
        println!("Usage: jlox [script]");
        process::exit(64);
    } else if args.len() == 2 {
        println!("runFile step");
        lox.run_file(&args[1]);
    } else {
        println!("runFile step");
        // runPrompt();
    }
}
