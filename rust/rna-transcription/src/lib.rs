#[derive(Debug, PartialEq, Eq)]
pub struct Dna {
    nucleotides: Vec<Nucleotides>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Rna {
    nucleotides: Vec<Nucleotides>,
}

impl Dna {
    pub fn new(dna: &str) -> Result<Self, usize> {

        let mut nucleotides: Vec<Nucleotides> = Vec::new();

        for (i, c) in dna.chars().enumerate() {
            match (i, c) {
                (_, 'A') => nucleotides.push(Nucleotides::A),
                (_, 'T') => nucleotides.push(Nucleotides::T),
                (_, 'C') => nucleotides.push(Nucleotides::C),
                (_, 'G') => nucleotides.push(Nucleotides::G),
                (i, _) => return Err(i),
            }
        }

        Ok(Dna { nucleotides })

    }

    pub fn into_rna(self) -> Rna {
        Rna {
            nucleotides: self.nucleotides.into_iter().map(|nucleotide| {
                match nucleotide {
                    Nucleotides::G => Nucleotides::C,
                    Nucleotides::C => Nucleotides::G,
                    Nucleotides::T => Nucleotides::A,
                    Nucleotides::A => Nucleotides::U,
                    n => panic!("invalid nucleotide in DNA sequence: {:?}", n),
                }
            })
            .collect()
        }
    }
}

impl Rna {
    pub fn new(rna: &str) -> Result<Rna, usize> {
        let mut nucleotides: Vec<Nucleotides> = Vec::new();

        for (i, c) in rna.chars().enumerate() {
            match (i, c) {
                (_, 'A') => nucleotides.push(Nucleotides::A),
                (_, 'U') => nucleotides.push(Nucleotides::U),
                (_, 'C') => nucleotides.push(Nucleotides::C),
                (_, 'G') => nucleotides.push(Nucleotides::G),
                (i, _) => return Err(i),
            }
        }

        Ok(Rna { nucleotides })
    }
}

#[derive(Debug, PartialEq, Eq)]
enum Nucleotides {
    A,
    U,
    C,
    G,
    T,
}

