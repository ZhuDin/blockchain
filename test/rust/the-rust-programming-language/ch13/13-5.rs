#![allow(unused_variables)]
fn main() {
    use std::thread;
    use std::time::Duration;

    let expensive_closure = |num| {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    };
    expensive_closure(5);
}