use std::{
    env, fs,
    io::{self, BufRead, Write},
    path::Path,
    process,
};

pub struct Lox {
    //interpreter: Interpreter,
    had_error: bool,
    had_runtime_error: bool,
}

impl Lox {
    fn run_file(&mut self, path: &str) {
        let path_from_string: &Path = Path::new(path);
        //println!("{:?}", path_from_string);

        match fs::read(path_from_string) {
            Ok(bytes) => println!("{:?}", String::from_utf8(bytes)), // self.run(String::from_utf8(bytes));
            Err(e) => eprintln!("coudlnt read file: {}", e),
        }
    }

    fn run_prompt(&mut self) {
        let stdin = io::stdin();

        loop {
            print!("> ");
            io::stdout().flush().unwrap(); // to make > appear first time

            let mut line = String::new();
            match stdin.lock().read_line(&mut line) {
                Ok(0) => break,                             // EOF (Ctrl-D)
                Ok(_) => println!("{:?}", line.trim_end()), // self.run(line);
                Err(e) => {
                    eprintln!("error reading input: {}", e);
                    break;
                }
            }
        }
    }

    fn run(&mut self, source: &str) {
        /* Java impl
            Scanner scanner = new Scanner(source);
            List<Token> tokens = scanner.scanTokens();

            // For now, just print the tokens.
            for (Token token : tokens) {
              System.out.println(token);
            }
        */
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
        println!("runPrompt step");
        lox.run_prompt();
    }
}
