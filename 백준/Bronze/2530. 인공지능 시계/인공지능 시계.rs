use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).unwrap();

    let mut iter = input.split_whitespace();
    let mut a: i8 = iter.next().unwrap().parse().unwrap();
    let mut b: i8 = iter.next().unwrap().parse().unwrap();
    let mut c: i8 = iter.next().unwrap().parse().unwrap();

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let mut d: i32 = input.trim().parse().unwrap();

    while d > 0 {
        c = (c + 1) % 60;
        b = (b + ((c == 0) as i8)) % 60;
        a = (a + ((b == 0 && c == 0) as i8)) % 24;
        d -= 1;
    }
    println!("{a} {b} {c}")
}