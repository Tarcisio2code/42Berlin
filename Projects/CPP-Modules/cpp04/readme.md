# 42 Berlin - Projects - CPP Module 04   

## 📖 Overview
This module introduces **Subtype Polymorphism**, **Abstract Classes**, and Interfaces in C++. The project explores how to use virtual functions to achieve dynamic behavior at runtime and emphasizes the critical importance of **Deep Copies** when dealing with classes that contain pointer members (like a Brain).

## ✨ Key Features Learned
- **Subtype Polymorphism**: Using base class pointers to refer to derived class objects and achieving runtime binding.  
- **Virtual Destructors**: Ensuring proper cleanup of derived classes when deleted through a base class pointer to prevent memory leaks.  
- **Abstract Classes & Interfaces**: Defining "Contract" classes using pure virtual functions (virtual void func() = 0;).  
- **Deep vs. Shallow Copies**: Implementing Copy Constructors and Assignment Operators that duplicate actual data rather than just pointer addresses.  
- **The "Brain" Concept**: Managing complex compositions where one class contains a pointer to another allocated object.  

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
- [Polymorphism in C++](https://www.geeksforgeeks.org/inheritance-in-c/)
- [Virtual Destructors](https://www.geeksforgeeks.org/cpp/virtual-destructor/)
- [Deep Copy vs. Shallow Copy](https://www.geeksforgeeks.org/cpp/shallow-copy-and-deep-copy-in-c/)
- [C++98 Standard (ISO/IEC 14882:1998)](https://en.wikipedia.org/wiki/C%2B%2B98)

## 📸 Featured Exercise: [ex02](https://github.com/Tarcisio2code/42Berlin/tree/master/Projects/CPP-Modules/cpp04/ex02)

> **Implementation Highlights:**
> - **Pure Virtual Functions**: Transformed the Animal class into an Abstract Class by declaring makeSound() as a pure virtual function (= 0), ensuring it cannot be instantiated.
> - **Interface Contract**: Forced all derived classes (Dog and Cat) to implement their own specific makeSound() logic, guaranteeing polymorphic behavior.
> - **Memory Integrity**: Maintained the use of Virtual Destructors to ensure that even when using Abstract Class pointers, the full object (including the Brain) is correctly deallocated.
> - **Object Composition**: Integrated the Brain class through private pointers to demonstrate that abstract hierarchies can still manage complex data structures.

![Implementation of ex02](https://github.com/Tarcisio2code/42Berlin/tree/master/Projects/CPP-Modules/cpp04/screenshot.png)
