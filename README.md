# Multithreaded Matrix Multiplication in C++

A simple C++ program that multiplies two matrices read from a text file, using `std::thread` to parallelize the computation. Each row of the resulting matrix is calculated on a separate thread.

## Getting Started

Follow these instructions to compile and run the project on your local machine.

### Prerequisites

You will need a C++ compiler that supports C++11 or newer and POSIX threads (pthreads).

- **For Windows:** [MinGW-w64](https://www.mingw-w64.org/) (GCC for Windows) is recommended.
- **For Linux/macOS:** A modern version of GCC or Clang should work out of the box.

### Compilation

Open your terminal, navigate to the project directory, and compile the source code using the following command. The `-pthread` flag is essential for enabling thread support.

```bash
g++ matrix_multi_threads.cpp -o matrix_multiplier -std=c++17 -pthread
```

### Execution

Run the compiled program from the terminal:

```bash
./matrix_multiplier
```

The program will then prompt you to enter the name of the input file.

## Input File Format

The program expects a single text file containing two matrices. The format for each matrix is as follows:

1.  A line `L=` followed by the number of rows.
2.  A line `C=` followed by the number of columns.
3.  The matrix data, with numbers separated by spaces and each row on a new line.

### Example (`input.txt`)

This file contains a 2x3 matrix followed by a 3x2 matrix.

```
L=2
C=3
1 2 3
4 5 6
L=3
C=2
7 8
9 10
11 12
```

## Example Usage

This shows how to run the program and the expected output for the example file above.

```bash
$ ./matrix_multiplier
Enter input filename: input.txt
58 64
139 154
```
