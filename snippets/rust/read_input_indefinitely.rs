use std::io;

fn main() {
    loop {
        let mut input = String::new();

        match io::stdin().read_line(&mut input) {
            Ok(0) => { break; },
            Ok(_) => {},
            Err(_) => {}
        }
    }
}