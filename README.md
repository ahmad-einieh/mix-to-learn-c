# C Lab Exercises

A collection of independent C coursework exercises covering console I/O, arrays, matrices, strings, structures, binary image handling, and linked lists.

## Organization

- `Lab01/`, `lab02/`, `lab03/`: introductory standalone programs.
- `lab04/`: matrix helpers and transpose exercises.
- `lab05/`: string helpers and exercises.
- `lab06/`: student structures and helper-library exercises.
- `lab07/`, `lab08/`: additional modules, including BMP-related code in `lab08`.
- `lab10/`: linked-list module and exercises.
- `quiz 2/`: a separate quiz exercise.

Directory names are case-sensitive on Linux. There is no single application or repository-wide build command; several files define their own `main` function.

## Build examples

Install GCC or another C compiler. From the repository directory, build one exercise at a time:

```bash
gcc -std=c99 -Wall -Wextra Lab01/hello.c -o hello
./hello
```

For the matrix test, compile its helper implementation too:

```bash
gcc -std=c99 -Wall -Wextra lab04/tset.c lab04/mat.c -o matrix-test
./matrix-test
```

Other multi-file exercises likewise need their matching `.c` helper files. Do not link every source file together, because the independent entry points will conflict.

## Notes

These are historical learning exercises, not a validated utility library. Input handling, memory safety, and compiler compatibility vary by file. Review an exercise before running it, use small test inputs, and keep any file-writing experiments away from important data.
