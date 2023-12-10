use std::io;

fn main() {
    let mut input = String::new();

    let _ = io::stdin().read_line(&mut input);

    match input.trim().parse::<f64>() {
        Ok(r) => {
            println!("A={:.4}", r * r * 3.14159);
        }
        Err(_) => {}
    };
}
