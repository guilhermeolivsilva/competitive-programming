use std::io;

fn main() {
    let mut input_1 = String::new();
    let mut input_2 = String::new();

    let _ = io::stdin().read_line(&mut input_1);
    let _ = io::stdin().read_line(&mut input_2);

    let _ = match input_1.trim().parse::<f64>() {
        Ok(left) => {
            let _ = match input_2.trim().parse::<f64>() {
                Ok(right) => {
                    println!("X = {}", left + right);
                },
                Err(_) => {}
            };
        },
        Err(_) => {}
    };
}
