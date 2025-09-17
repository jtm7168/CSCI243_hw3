CSCI243 – Homework 3

1. Compilation:

The program was compiled in the act2 directory using:
    gmakemake > Makefile
    make

Compilation produced no errors. All warnings from the original code were fixed
by correcting assignments, unused variables, and string/char comparisons.

2. Running the Program:
Usage:
    ./good-life <num_organisms>

Example:
    ./good-life 40

This initializes a 20x20 board with <num_organisms> randomly placed organisms
('*') and runs Conway's Game of Life for 50 generations.

3. Differences from Expected Output
The expected output file shows a specific pattern of organisms.
My output differs because the program uses the rand() function to seed
organisms. With srand(31), the pattern is reproducible but does not match
the output exactly. The rules of the Game of Life are
applied correctly, I believe, but the visual board contents differ due to randomness.

4. Fixes and Improvement:
- Fixed misuse of '==' vs '='.
- Replaced string literal comparisons with single-character comparisons.
- Removed unused variables and parameters.
- Changed printing format specifiers from %s to %c.
- Limited execution to 50 generations instead of infinite loop.
- Cleaned up formatting to follow course style (consistent spacing, braces).

