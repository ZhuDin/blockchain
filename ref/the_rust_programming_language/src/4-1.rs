fn main() {
    let mut s = String::from("hello");

    s.push_str(", world!");

    println!("{}", s);

    let s1 = String::from("hello");
    let s2 = s1;
    //println!("{}, world!", s1);
    println!("{}, world!", s2);

    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("s1 = {}, s2 = {}", s1, s2);

    let x = 5;
    let y = x;

    println!("x = {}, y = {}", x, y);
    
    let s = String::from("hello");	// s comes into scope

    takes_ownership(s);			// s's value moves into the function...
					// ... and so is no longer valid here

    let x = 5;				// x comes into scope

    makes_copy(x);			// x would move into the function,
					// but i32 is Copy, so it's okay to still
					// use x afterward
    
    let s1 = gives_ownership();	// gives_ownership moves its return value into s1

    let s2 = String::from("hello");	// sw come into scope

    let s3 = takes_and_gives_back(s2);	// s2 is moved into takes_and_gives_back, which
					                    // also moves its return value into s3
    println!("{}", s1);
    println!("{}", s3);

    let s1 = String::from("hello");

    let (s2, len) = calculate_length(s1);

    println!("The length of '{}' is {}.", s2, len);
}	
    // Here, x goes out of scope, then s. But because s's value was moved, nothing
	// special happens.
    // Here, s3 goes out of scope and is dropped. s2 goes out of scope but was
	// moved, so nothing happens. s1 goes out of scope and is dropped.

fn takes_ownership(some_string: String) {	//some_string comes into scope
    println!("{}", some_string);
}	// Here, some_string goes out of scope and 'drop' is called. The backing
	// memory is freed.

fn makes_copy(some_integer: i32) {	// some_integer comes into scope
    println!("{}", some_integer);
}

fn gives_ownership() -> String {	// gives_ownership will move its return value 
					// into the function that calls it

    let some_string = String::from("hello");	// some_string comes into scope

    some_string					// some_string is return and moves 
						// out to the calling function
}

// takes_and_gives_back will take a String and return one
fn takes_and_gives_back(a_string: String) -> String {	// a_string comes into scope

    a_string	// a_string is returned and moves out to the calling function
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();	// len() returns the length of a String

    (s, length)
}
