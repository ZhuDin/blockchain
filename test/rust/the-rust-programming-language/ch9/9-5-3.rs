/*
 * Another method, expect, which is similar to unwrap, lets us also choose the panic! error
 * message. Using expect instead of unwrap and providing good error messages can convey your 
 * intent and make tracking down the source of a panic easier.
 */
#![allow(unused_variables)]
use std::fs::File;

fn main() {
    let f = File::open("hello.txt").expect("Failed to open hello.txt");
}