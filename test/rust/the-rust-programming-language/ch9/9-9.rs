#![allow(unused_variables)]
fn main() {
    use std::io;
    use std::fs;

    fn read_username_from_file() -> Result<String, io::Error> {
        fs::read_to_string("hello.txt")
    }
}