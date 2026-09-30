# C++98 Learning Exercises

This repository contains my complete set of exercises for learning **C++98**, based on 42's C++ Modules 00 to 09.

These exercises document my progression from C fundamentals to object-oriented programming, resource management, inheritance, polymorphism, templates, STL containers, and algorithms. Each module contains independent exercise directories such as `ex00` and `ex01`, which can be compiled and run separately.

## Learning Path

| Module | Main Topic | Exercise Topics |
| --- | --- | --- |
| [CPP-Module-00](./CPP-Module-00/) | C++ Fundamentals and Classes | Namespaces, I/O, classes, encapsulation, static members, string manipulation |
| [CPP-Module-01](./CPP-Module-01/) | Memory and References | `new`/`delete`, stack and heap, pointers, references, file operations, function pointers |
| [CPP-Module-02](./CPP-Module-02/) | Operator Overloading and Type Conversion | Orthodox Canonical Form, fixed-point numbers, operator overloading, geometric tests |
| [CPP-Module-03](./CPP-Module-03/) | Inheritance | Base and derived classes, construction and destruction, inheritance hierarchies, the diamond problem |
| [CPP-Module-04](./CPP-Module-04/) | Polymorphism | Virtual functions, runtime polymorphism, deep copies, abstract classes, interfaces |
| [CPP-Module-05](./CPP-Module-05/) | Exceptions | `try`, `catch`, `throw`, custom exceptions, exception safety |
| [CPP-Module-06](./CPP-Module-06/) | Type Casting | `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`, scalar conversions |
| [CPP-Module-07](./CPP-Module-07/) | Templates | Function templates, class templates, template instantiation, generic programming |
| [CPP-Module-08](./CPP-Module-08/) | STL Fundamentals | Containers, iterators, algorithms, stacks, and container adapters |
| [CPP-Module-09](./CPP-Module-09/) | STL and Practical Problems | `std::map`, RPN, Ford-Johnson sorting, Jacobsthal numbers |


Each exercise directory usually contains a `Makefile`. The README files inside the modules describe their key topics, implementation ideas, and related concepts.

## Build and Run

Enter an exercise directory and run `make`:

```bash
cd CPP-Module-00/ex01
make
./phonebook
```

The executable name may differ between exercises; check the `Makefile` in the corresponding directory. Common commands include:

```bash
make        # Build
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Clean and rebuild
```

These exercises target the C++98 standard. Typical compiler flags include:

```bash
-c++ -Wall -Wextra -Werror -std=c++98
```

## Key Concepts

- Use `std::string`, `std::iostream`, and the standard library instead of C-style interfaces
- Understand constructors, destructors, copy constructors, and assignment operators
- Distinguish stack objects, heap objects, pointers, and references
- Prevent memory leaks by correctly matching `new`/`delete` and `new[]`/`delete[]`
- Use inheritance, virtual functions, and abstract classes to implement polymorphism
- Write and use exception classes for error handling
- Understand explicit C++ type casts
- Use function templates, class templates, and STL containers to solve generic problems
- Organize data processing with iterators and STL algorithms

## Note

This is a personal repository documenting my learning process. The code focuses on understanding C++98 syntax, design practices, and underlying behavior. The README files in each module may contain notes, examples, and implementation ideas; the actual code is available in the corresponding exercise directories.
