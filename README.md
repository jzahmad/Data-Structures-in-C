# Data Structures in C

This repository contains implementations of several fundamental data structures in C, designed for use in a Linux
environment.

## Summary

The repository contains implementations for:

**Linear Data Structures:**

* **Array List:** A dynamic array implementation that can grow as needed.
* **Linked List:** A linked list implementation with nodes that store data and pointers to the next and previous nodes.
* **Stack:** A LIFO (Last-In, First-Out) data structure implemented using a linked list.
* **Queue:** A FIFO (First-In, First-Out) data structure implemented using a linked list.

**Non-Linear Data Structures:**

* **Binary Tree:** A tree-based data structure with a hierarchical organization.
* **Heap:** A binary tree-based data structure that maintains a heap property (either min-heap or max-heap) for
efficient retrieval of the minimum or maximum element.

**Features:**

* **Generic implementation:** Data structures are designed to work with different data types.
* **Extensive test cases:** Unit tests are provided to verify the correctness of the implementations.
* **Documentation:** Each data structure implementation includes comprehensive comments explaining the code.
* **Bash scripting:** Compilation and testing are automated using Bash scripts.

## Tech Stack

* **Language:** C
* **Operating System:** Linux
* **Framework:** N/A (pure C implementation)

## Installation

1. **Clone the repository:**
```bash
git clone https://github.com/your-username/data-structures-c.git
```

2. **Navigate to the repository directory:**
```bash
cd data-structures-c
```

3. **Install necessary dependencies (if any):**
* This project does not require any external dependencies.

## Running the Project

1. **Compile the code:**
```bash
make
```
This will compile all the source files in the respective directories.

2. **Run the test cases:**
```bash
make test
```
This will execute the unit tests in each data structure directory.

3. **Run specific test cases:**
For example, to run the test cases for the `array_list` implementation:
```bash
make test-array-list
```
You can replace `array-list` with the name of any other data structure.

## Configuration

* The `Makefile` file contains the compilation and testing commands. You can modify it to adjust the compilation flags
or add new targets.

## Testing

* The unit tests are located in the `test` subdirectory of each data structure.
* The `Makefile` provides targets to run the tests for individual data structures or for all data structures.

## Contributing

Contributions are welcome! Please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes with clear and concise commit messages.
4. Push your changes to your fork.
5. Open a pull request against the `main` branch of the original repository.

## Licensing

This project is licensed under the MIT License - see the LICENSE file for details.
