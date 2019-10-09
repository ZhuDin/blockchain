mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

fn main() {
    pub fn eat_at_restaurant() {
        // Abolute path 
        crate::front_of_house::hosting::add_to_waitlist();

        // Relation path
        front_of_house::hosting::add_to_waitlist();
    }
}