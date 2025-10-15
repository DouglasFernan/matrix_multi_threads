# Multithreaded Matrix Multiplication in C++

A simple C++ program that multiplies two matrices read from a text file, using `std::thread` to parallelize the computation. Each row of the resulting matrix is calculated on a separate thread.

## Project Structure

The input file (`matrizes.txt`) should be placed inside the `/output` directory, alongside the compiled executable.

```
project-root/
├── output/
│   ├── matrix_multi_threads  <-- Executable goes here
│   └── matrizes.txt          <-- Input file goes here
└── matrix_multi_threads.cpp
```

## Getting Started

Follow these instructions to compile and run the project on your local machine.

### Prerequisites

You will need a C++ compiler that supports C++11 or newer and POSIX threads (pthreads).

* **For Windows:** [MinGW-w64](https://www.mingw-w64.org/) (GCC for Windows) is recommended.
* **For Linux/macOS:** A modern version of GCC or Clang should work out of the box.

### Compilation

From the **project's root directory**, run the following command. It will compile the source file and place the executable inside the `/output` folder.

```bash
g++ matrix_multi_threads.cpp -o output/matrix_multi_threads -std=c++17 -pthread
```

### Execution

After compiling, you must first navigate into the `output` directory to run the program.

1.  **Change into the output directory:**
    ```bash
    cd output
    ```
2.  **Run the executable:**
    ```bash
    ./matrix_multi_threads
    ```

The program will then prompt you to enter the name of your input file (e.g., `matrizes.txt`).

## Example Usage

This shows the complete workflow in the terminal.

```bash
# From the project root, compile the code
$ g++ matrix_multi_threads.cpp -o output/matrix_multi_threads -std=c++17 -pthread

# Navigate into the output folder
$ cd output

# Run the program
$ ./matrix_multi_threads
Enter input filename: matrizes.txt
58 64
139 154
```
