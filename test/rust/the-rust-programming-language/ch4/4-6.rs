fn main() {
    let s1 = String::from("hello");
    let len = calculate_length(&s1);
    println!("The length of '{}' is {}.", s1, len);

    let mut s2 = String::from("hello");
    change(&mut s2);
    println!("The s2 is : {}", s2);
}

fn calculate_length(s: &String) -> usize {
    /*
     * We call having references as funciton parameters borrowing.
     * We can't modify something we're borrowing. Just as variables
     * are immutable by default, so are references. We're not allowed
     * to modify something we have a reference to.
     */
    s.len()
}

fn change(some_string: &mut String) {
    /*
     * If a string is mutable. Then we can create a mutable reference
     * with &mut s and accept a mutable reference. But mutable reference
     * have one big restriction: you can have only one mutable reference
     * to a particular piece of data in a particular scope.
     */
    some_string.push_str(", world");
}