# change log

## v1.1
FractionalPart function:
Added a check to avoid counting perfect roots and dividing by 0 in the function logic**. (This was causing crashes.)
Added a check for repetitions in the function, meaning that a period that includes only one number is written to the vector as a single number.
(Previously, due to the lack of a check, the following occurred: B = 10 | vec = 6 6 Now the function returns B = 10 | vec = 6.)
This is the number under the square root, and vec is the return vector of the periodic continued fraction.)

Approximation function:
Added a check for perfect squares. This avoids errors similar to FractionalPart.
The approximation logic has been completely redesigned. Now the approximation cycle runs through several periods simultaneously. That is,
if the period "1 2 3 4 5" is passed to the function, the function will construct an approximation based on the period "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5"***.
This fixes the problem of an unfound approximation, where an approximation exists but the function can't find it.

\*\* - don't try to construct a continued fraction for an integer (there's no nontrivial periodic part)

\*\*\* - the period is repeated as many times as it can fit within the matrix length constraint matrix[100][100]
That is, there can't be more than 100 numbers. BUT! We don't require the period to fit completely, which means if there's not enough space to insert it completely,
we insert only the numbers that fit, and don't insert any remaining numbers after the boundary is crossed.