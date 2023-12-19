use std::io;

fn main() {
    let mut input = String::new();

    let _ = io::stdin().read_line(&mut input);
    let _ = match input.trim().parse::<i32>() {
        Ok(input) => {
            println!("{}", input * 4);
         },
        Err(_) => {}
    };
}
