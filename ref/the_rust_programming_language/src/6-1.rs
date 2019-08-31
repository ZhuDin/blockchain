fn main() {
    #[derive(Debug)]
    enum IpAddrKind {
        V4,
        V6,
    }

    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    println!("{:#?}", four);
    println!("{:?}", six);

    fn route(_ip_kind: IpAddrKind) { }
    
    route(IpAddrKind::V4);
    route(IpAddrKind::V6);
    
    /*#[derive(Debug)]
    struct IpAddr {
        kind: IpAddrKind,
        address: String,
    }*/
    /*
    #[derive(Debug)]
    enum IpAddr {
        V4(String),
        V6(String),
    }
    */

    #[derive(Debug)]
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }

    /*let home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1"),
    };
   
    let loopback = IpAddr {
        kind: IpAddrKind::V6,
        address: String::from("::1"),
    };*/
    /*
    let home = IpAddr::V4(String::from("127.0.0.1"));
    let loopback = IpAddr::V6(String::from("::1"));
    */

    let home = IpAddr::V4(127, 0, 0, 1);
    let loopback = IpAddr::V6(String::from("::1"));

    println!("{:?}", home);
    println!("{:#?}", loopback);
}

