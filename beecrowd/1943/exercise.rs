use std::io;


fn main() {
    let thresholds = [1, 3, 5, 10, 25, 50, 100];

    loop {
        let mut input = String::new();

        match io::stdin().read_line(&mut input) {
            Ok(0) => {
                break;
            },
            Ok(_) => {
                match input.trim().parse::<i32>() {
                    Ok(value) => {
                        let mut idx = 0;
                        while idx < thresholds.len() && value > thresholds[idx] {
                            idx += 1;
                        }

                        println!("Top {}", thresholds[idx]);
                    }
                    Err(_) => {}
                }
            },
            Err(_) => {}
        }
    }
}