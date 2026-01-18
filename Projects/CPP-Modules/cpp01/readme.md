# 42 Berlin - Projects - CPP Module 01   

## 📖 Overview
This module explores memory allocation, references, and pointers to members in C++. It focuses on understanding the critical differences between Stack and Heap allocation, the safe use of references, and the implementation of efficient control flow using pointers to functions.   

## ✨ Key Features Learned
- **Memory Management**: Practical application of new and delete for dynamic memory handling.   
- **Stack vs Heap**: Deciding when to allocate objects on the stack or the heap based on scope and size requirements.   
- **References**: Utilizing references to pass objects efficiently without the overhead or risks of raw pointers.   
- **File Manipulation**: Using std::ifstream and std::ofstream for reading and writing files (the "Sed is for losers" exercise).   
- **Pointers to Members**: Executing class methods dynamically using an array of pointers to member functions.   

## Usage
1. Clone the repository:

2. Navigate to the exercise folder:
   ```sh
   cd ex00/
   ```

3. Build the project:
   ```sh
   make
   ```

4. Run the program:
   ```sh
   ./[executable_name]
   ```

## References
- [C++ Dynamic Memory Management](https://en.cppreference.com/w/cpp/memory)
- [Pointers to Member Functions](https://isocpp.org/wiki/faq/pointers-to-members)
- [C++ References vs Pointers](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)
- [Input/output with files (fstream)](https://cplusplus.com/doc/tutorial/files/)

## 📸 Featured Exercise: [ex05](https://github.com/Tarcisio2code/42Berlin/tree/master/Projects/CPP-Modules/cpp01/ex05)

> **Implementation Highlights:**
> - **Efficiency**: Replaced complex if/else or switch structures with an array of pointers to member functions for $O(1)$ command lookup.
> - **Robustness**: Implemented a system that maps log levels (DEBUG, INFO, WARNING, ERROR) directly to their respective private methods.
> - **Memory Safety**: Ensures clean object life cycles and proper resource management without memory leaks.

![Implementation of ex05](https://github.com/Tarcisio2code/42Berlin/tree/master/Projects/CPP-Modules/cpp01/screenshot.png)
