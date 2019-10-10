#![allow(unused_variables)]
fn main() {
    let mut s1 = String::from("foo");
    let s2 = "bar";
    // The push_str method takes a stirng slice don't want to take ownership of the parameter
    s1.push_str(s2);
    println!("s1 is {}", s1);
    println!("s2 is {}", s2);
}