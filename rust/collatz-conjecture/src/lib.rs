fn step(n: u64) -> u64 {
    if n % 2 == 0{
        n/2
    } else {
        n * 3 + 1
    }
}

pub fn collatz(n: u64) -> Option<u64> {
    if n < 1 {
        None
    } else {
        let mut current = n;
        let out = (0..)
            .map(|_| {
                // this is cursed
                let temp = current;
                current = step(current);
                temp
            })
            .take_while(|&n| n != 1)
            .count();
        Some(out as u64)
    }
}
