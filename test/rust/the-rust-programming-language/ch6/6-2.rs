#![allow(unused_variables)]
fn main() {
    enum Message {
        Quit, // has no data associated with it at all
        Move { x: i32, y: i32 }, // includes an anonymous struct inside it
        Write(String), // includes a single String
        ChangeColor(i32, i32, i32), // includes three i32 values
    }
}