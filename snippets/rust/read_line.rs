use std::io;


fn read_line_as_i64() -> Result<i64, std::num::ParseIntError> {
    let mut input = String::new();
    io::stdin().read_line(&mut input);

    input.trim().parse()
}


fn main() {
    while let Ok(input) = read_line_as_i64() {
        // Do stuff here.
    }
}