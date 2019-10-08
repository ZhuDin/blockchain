fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn main() {
    let my_string = String::from("hello world");
    let word = first_word(&my_string[..]);
    println!("first_word of my_string is {}", word);

    let my_string_literal = "hello world";
    let word = first_word(&my_string_literal[..]);
    println!("first_word of my_string_literal is {}", word);

    let word = first_word(my_string_literal);
    println!("first_word of my_string_literal is {}", word);
}