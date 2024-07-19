pub fn raindrops(n: u32) -> String {
    let mut out = String::with_capacity(16);

    if n % 3 == 0 {
        out.push_str("Pling");
    }
    if n % 5 == 0 {
        out.push_str("Plang");
    }
    if n % 7 == 0 {
        out.push_str("Plong");
    }
    if out.is_empty() {
        out = n.to_string();
    }

    out
}
