#![allow(unused_variables)]
fn main() {
    let word = first_word(&String::from("hello, world!"));
    println!("the index of the end of first_word is: {}", word);
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}