fn main() {
    {
        let r; // 'a
        {
            let x = 5; // 'b
            r = &x;
        } // 'b
        println!("r: {}", r);
    }
} // 'a