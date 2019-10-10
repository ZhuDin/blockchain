fn main() {
    let string1 = String::from("abcd");
    let string2 = "xyz";

    fn longest(x: &str, y: &str) -> &str {
        if x.len() > y.len() {
            x
        } else {
            y
        }
    }

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);
}