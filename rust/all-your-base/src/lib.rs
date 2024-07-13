// Playin with ideas stolen from
// https://exercism.org/tracks/rust/exercises/all-your-base/solutions/dangets

#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    InvalidInputBase,
    InvalidOutputBase,
    InvalidDigit(u32),
}

#[rustfmt::skip]
fn require<T>(predicate: bool, error: T) -> Result<(), T> {
    if predicate { Ok(()) } else { Err(error) }
}

///
/// Convert a number between two bases.
///
/// A number is any slice of digits.
/// A digit is any unsigned integer (e.g. u8, u16, u32, u64, or usize).
/// Bases are specified as unsigned integers.
///
/// Return the corresponding Error enum if the conversion is impossible.
///
///
/// You are allowed to change the function signature as long as all test still pass.
///
///
/// Example:
/// Input
///   number: &[4, 2]
///   from_base: 10
///   to_base: 2
/// Result
///   Ok(vec![1, 0, 1, 0, 1, 0])
///
/// The example corresponds to converting the number 42 from decimal
/// which is equivalent to 101010 in binary.
///
///
/// Notes:
///  * The empty slice ( "[]" ) is equal to the number 0.
///  * Never output leading 0 digits, unless the input number is 0, in which the output must be `[0]`.
///    However, your function must be able to process input with leading 0 digits.
///
pub fn convert(number: &[u32], from_base: u32, to_base: u32) -> Result<Vec<u32>, Error> {
    to_decimal(number, from_base).and_then(|n| to_base_n(n, to_base))
}

fn to_decimal(number: &[u32], from_base: u32) -> Result<u32, Error> {
    require(from_base >= 2, Error::InvalidInputBase)?;

    number.iter().try_fold(0u32, |acc, &digit| {
        require(digit < from_base, Error::InvalidDigit(digit))?;

        acc.checked_mul(from_base)
            .and_then(|result| result.checked_add(digit))
            .ok_or(Error::InvalidDigit(digit))
    })
}

fn to_base_n(decimal: u32, to_base: u32) -> Result<Vec<u32>, Error> {
    require(to_base >= 2, Error::InvalidOutputBase)?;

    if decimal == 0 {
        return Ok(vec![0]);
    }

    let mut out = Vec::with_capacity(16);
    let mut number = decimal;

    while number > 0 {
        out.push(number % to_base);
        number /= to_base;
    }

    out.reverse();
    Ok(out)
}
