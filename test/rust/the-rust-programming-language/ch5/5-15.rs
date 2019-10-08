#![allow(unused_variables)]
fn main() {
    #[derive(Debug)]
    struct Rectangle {
        width: u32, 
        height: u32,
    }

    impl Rectangle {
        fn square(size: u32) -> Rectangle {
            Rectangle { width: size, height: size }
        }
    }

    let sq = Rectangle::square(3);
}