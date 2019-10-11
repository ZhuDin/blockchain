#![allow(unused_variables)]
#[cfg(test)]
mod tests_1 {
    #[test]
    fn it_works() {
        assert_eq!(2+2, 4);
    }
}

#[cfg(test)]
mod test_2 {
    #[test]
    fn exploration() {
        assert_eq!(2+2, 4);
    }
}

#[cfg(test)]
mod test_3 {
    #[test]
    fn another() {
        // panic!("Make this test fail");
    }
}

// listing 11-5
#[derive(Debug)]
struct Rectangle {
    width: u32, 
    height: u32,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height 
    }
}

#[cfg(test)]
mod tests_6 {
    use super::*;

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle { width: 8, height: 7 };
        let smaller = Rectangle { width: 5, height: 1 };

        assert!(larger.can_hold(&smaller));
    }
    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = Rectangle { width: 8, height: 7 };
        let smaller = Rectangle { width: 5, height: 1 };

        assert!(!smaller.can_hold(&larger));
    }
}

// listing 11-7
pub fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests_7 {
    use super::*;
    #[test]
    fn it_adds_two() {
        assert_eq!(4, add_two(2));
    }
}

// listing 11-8
pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 || value > 100 {
            panic!("Guess value must be between 1 and 100, got {}.", value);
        }

        Guess {
            value 
        }
    }
}

#[cfg(test)]
mod tests_8 {
    use super::*;
    #[test]
    #[should_panic]
    fn greater_than_100() {
        Guess::new(200);
    }
}

#[cfg(test)]
mod tests_11 {
    use super::*;

    #[test]
    fn add_two_and_two() {
        assert_eq!(4, add_two(2));
    }

    #[test]
    fn add_three_and_two() {
        assert_eq!(5, add_two(3));
    }

    #[test]
    fn one_hundred() {
        assert_eq!(102, add_two(100));
    }

    #[test]
    #[ignore]
    fn expensive_test() {
        // code that takes an hour to run
    }
}