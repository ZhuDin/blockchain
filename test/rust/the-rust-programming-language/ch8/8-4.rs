#![allow(unused_variables)]
fn main() {
    {
        let v = vec![1, 2, 3, 4];
        // do stuff with v
    } // <- goes out of scope and is freed here
}