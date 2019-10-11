#![allow(unused_variables)]
fn main() {
    struct Cacher<T>
        where T: Fn(u32) -> u32 {
            calculation: T,
            value: Option<u32>,
        }
}