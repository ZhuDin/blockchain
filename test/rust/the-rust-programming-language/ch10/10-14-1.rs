#![allow(unused_variables)]
fn main() {
    pub trait Summary {
        fn summarize_author(&self) -> String;
        fn summarize(&self) -> String {
            format!("(Read more from {}...)", self.summarize_author())
        }
    }

    pub struct Tweet {
        pub username: String,
        pub content: String,
        pub reply: bool,
        pub retweet: bool,
    }

    impl Summary for Tweet {
        fn summarize_author(&self) -> String {
            format!("@{}", self.username)
        }
    }

    let tweet = Tweet {
        username: String::from("horse_ebook"), 
        content: String::from("of course, as you probably already know, people"),
        reply: false, 
        retweet: false,
    };
    println!("1 new tweet: {}", tweet.summarize());

    pub fn notify(item: impl Summary) {
        println!("Breaking news! {}", item.summarize());
    }

}