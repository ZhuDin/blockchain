#![allow(unused_variables)]
fn main() {
    use std::io;
    use std::io::Read;
    use std::fs::File;

    /*
     * The ? placed after a Result value is defined to work in almost th esame way as the match
     * expressions we defined handle the Result values. If the value of the Result is an Ok, the 
     * value inside the Ok will get returned from this expression, and the program will continue.
     * If the value is an Err, the Err will be returned from the whole function as if we had used
     * the return keyword so the error value gets propagated to the calling code.
     */
    fn read_username_from_file() -> Result<String, io::Error> {
        let mut f = File::open("hello.txt")?;
        let mut s = String::new();
        f.read_to_string(&mut s)?;
        Ok(s)
    }
}