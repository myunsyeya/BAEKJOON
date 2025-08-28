use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).unwrap();

    let mut t: i8 = input.trim().parse().unwrap();
    input.clear();
    while t > 0 {
        t -= 1;
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let n: i8 = iter.next().unwrap().parse().unwrap();
        let k: i8 = iter.next().unwrap().parse().unwrap();
        input.clear();

        io::stdin().read_line(&mut input).unwrap();
        iter = input.split_whitespace();
        let mut candy: i8;
        let mut answer: i16 = 0;
        for _ in 0..n {
            candy = iter.next().unwrap().parse().unwrap();
            answer += (candy / k) as i16;
        }
        input.clear();
        println!("{answer}");
    }
}