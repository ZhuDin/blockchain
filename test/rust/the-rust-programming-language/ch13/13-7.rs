#![allow(unused_variables)]
fn main() {
    use std::thread;
    use std::time::Duration;

    let expensive_closure = |num: u32| -> u32 {
        println!("calculating slow...");
        thread::sleep(Duration::from_secs(2));
        num
    };

    fn  add_one_v1   (x: u32) -> u32 { x + 1 }
    let add_one_v2 = |x: u32| -> u32 { x + 1 };
    // let add_one_v3 = |x| { x + 1 };
    // let add_one_v4 = |x|               x + 1  ; 
}