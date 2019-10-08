fn main() {
    /*
     * Because if is an expression, we can use it 
     * on the right of a let
     */
     let condition = true;
     let number = if condition {
         5
     } else {
         6
     };

     println!("The value of number is {}", number);
}