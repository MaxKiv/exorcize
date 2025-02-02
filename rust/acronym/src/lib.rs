// Produces a given words acronym
pub fn acronym(word: &str) -> String {
    // Return the first character the entire word is uppercase
    if word.chars().all(|c| c.is_ascii_uppercase()) {
        return word.chars().next().unwrap().to_string();
    }

    // Return the capitalised first character the entire word is lowercase
    if word.chars().all(|c| c.is_lowercase()) {
        return word.chars().next().unwrap().to_uppercase().to_string();
    }

    // Else return all uppercase characters in the given word
    word.chars().filter(|c| c.is_ascii_uppercase()).collect()
}

// Gets the acronym of all words in the phrase
pub fn abbreviate(phrase: &str) -> String {
    phrase
        .chars()
        .map(|c| if c == '-' { ' ' } else { c }) // Replace dashes with spaces
        .collect::<String>() // Collect into a String for further processing
        .split_whitespace() // Split into words
        .map(|word| {
            word.chars()
                .filter(|c| c.is_alphabetic())
                .collect::<String>()
        }) // Filter out non-alphabetic characters
        .map(|word| acronym(&word)) // Generate acronym for each word
        .collect::<String>() // Collect all acronyms into a single String
}
