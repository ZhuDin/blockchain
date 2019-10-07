fn main() {
    // In general, the `{}` will be automatically replaced with any 
    // argument. These will be stringified.
    println!("{} days", 31);

    // There are various optional pattern this works with. Positional
    // arguments can be used.
    println!("{0}, this is {1}. {1}, this is {0}", "Alice", "Bob");

    // As can named arguments.
    println!("{subject} {verb} {object}", 
            object="the lazy dog", 
            subject="the quick brown fox", 
            verb="jumps over");

    // Special formatting can be specified after a `:`.
    println!("{} of {:b} people know binary, the other half doesn't", 1, 2);

    // You can right-align text with a specified width. This will output
    // "    1". 4 white spaces and a "1".
    println!("{number:>width$}", number=1, width=5);

    // You can pad numbers with extra zeroes. This will output "00001".
    println!("{number:>0width$}", number=1, width=5);

    // Rust even checks to make sure the correct number of arguments are used.

    // Create a structure named `Structure` which contains an `i32`.
    #[allow(dead_code)]
    struct Structure(i32);

    // However, custom types such as this structure require more complicated 
    // handling. This will not work.
    // println!("This struct `{}` won't print...", Structure(3));

}