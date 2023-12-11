use std::io;

fn main() {
    let mut input = String::new();

    let _ = io::stdin().read_line(&mut input);

    // Adjust the type (`i32`) accordingly.
    let _ = match input.trim().parse::<i32>() {
        Ok(input) => { /* Do stuff here */ },
        Err(_) => {}
    };
}
