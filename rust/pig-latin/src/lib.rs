// Pig-latinize a string of words
pub fn translate(input: &str) -> String {
    input
        .split_whitespace()
        .map(translate_word)
        .collect::<Vec<String>>()
        .join(" ")
}

fn translate_word(word: &str) -> String {

    let idx = find_vowel_idx(word);
    let (consonants, rest) = word.split_at(idx);

    format!("{}{}ay", rest, consonants)
}

fn find_vowel_idx(word: &str) -> usize {
    if word.is_empty()
        || word.starts_with('a')
        || word.starts_with('o')
        || word.starts_with('e')
        || word.starts_with('i')
        || word.starts_with('u')
        || word.starts_with("yt")
        || word.starts_with("xr") {
        0
    } else if word.starts_with("qu") {
        2
    } else if word.chars().nth(1) == Some('y') {
        1
    } else {
        1 + find_vowel_idx(&word[1..])
    }

}
