/*
 * Packages: A Cargo feature that lets you build, test, and share crates
 * Crates: A tree of modules that products a library or executable
 * Modules and use: let you control the organization, scope, and privacy of paths
 * Paths: A way of naming an item, such as a struct, function, or module
 */

#![allow(unused_variables)]
fn main() {
    mod front_of_house {
        mod hosting {
            fn add_to_waitlist() {}
            fn seat_at_table() {}
        }

        mod serving {
            fn take_order() {}
            fn serve_order() {}
            fn take_payment() {}
        }
    }
}