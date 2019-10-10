/*
 * Using match works well enough, but it can be a bit verbose and doesn't always communicate intent
 * well. The Result<T, E> type has many helper methods defined on it to do various tasks. One of 
 * those method, called unwrap, is a shortcut method that is implemented just like the match 
 * expression we wrote. If the Result values is Ok variant, unwrap will return the value inside 
 * the Ok. If the Result is the Err variant, unwrap will call the panic! macro for us.
 */
#![allow(unused_variables)]
use std::fs::File;

fn main() {
    let f = File::open("hello.txt").unwrap();
}