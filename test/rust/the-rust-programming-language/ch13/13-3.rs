#![allow(unused_variables)]
fn main() {
    use std::thread;
    use std::time::Duration;

    fn simulated_expensive_calculation(num: u32) -> u32 {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    }

    fn generate_workout(intensity: u32, random_number: u32) {
        if intensity < 25 {
            println!(
                "Today, do {} situps!",
                simulated_expensive_calculation(intensity)
            );
            println!(
                "Next, do {} situps!",
                simulated_expensive_calculation(intensity)
            );
        } else {
            if random_number == 3 {
                println!("Take a break today! Remember to stay hydrated!");
            } else {
                println!(
                    "Today, run for {} minutes!",
                    simulated_expensive_calculation(intensity)
                );
            }
        }
    }
}