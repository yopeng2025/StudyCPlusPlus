# CPP-Module-01

A comprehensive C++98 learning module covering fundamental object-oriented programming concepts with practical exercises and examples.


## Exercises

### **Ex00: Memory Allocation & Constructors**
- **Focus**: Stack vs. Heap allocation, constructor initialization
- **Concepts**: 
  - Dynamic memory allocation with `new` operator
  - Stack-based object creation
  - Constructor and destructor lifecycle
- **Example**: Create Zombie objects on both stack and heap, observe destruction patterns

### **Ex01: Array Allocation & Destructors**
- **Focus**: Array allocation, bulk object initialization
- **Concepts**:
  - Array allocation with `new[]` and `delete[]`
  - Default constructors and setter methods
  - Proper memory cleanup for arrays
- **Example**: Allocate a horde of zombies and initialize them with names

### **Ex02: References vs. Pointers**
- **Focus**: Understanding fundamental differences between pointers and references
- **Concepts**:
  - Pointer dereferencing (`*ptr`)
  - Reference aliasing (shares same memory address)
  - Memory address introspection
- **Example**: Compare pointer and reference behavior when modifying string values

### **Ex03: References in Classes**
- **Focus**: Using references and pointers as member variables
- **Concepts**:
  - Reference members (must be initialized in constructor)
  - Pointer members (can be NULL, set later)
  - Access operators (`->` for pointers, `.` for references)
  - Const correctness
- **Example**: HumanA uses a reference weapon (always present), HumanB uses a pointer weapon (optional)

### **Ex04: File I/O & String Manipulation**
- **Focus**: File operations and string replacement algorithm
- **Concepts**:
  - Input/output file streams (`ifstream`, `ofstream`)
  - String finding and substring extraction
  - Error handling
- **Example**: Implement a `sed`-like utility that finds and replaces string patterns in files

### **Ex05: Function Pointers & Static Members**
- **Focus**: Advanced pointer usage and static arrays
- **Concepts**:
  - Function pointers and member function pointers
  - Static member variables
  - Switch-case dispatch pattern
- **Example**: Use function pointer arrays to dynamically call different complaint methods based on input

### **Ex06: Switch Statements & Fall-through Logic**
- **Focus**: Switch statement control flow and intentional fall-through
- **Concepts**:
  - Switch case fall-through (cascading execution)
  - Default case handling
  - Conditional flow based on severity levels
- **Example**: Filter complaints by severity level, executing all messages from the selected level downward


- Static members and member function pointers
- Control flow patterns in C++

---

*This module provides hands-on experience with C++ fundamentals essential for building robust applications.*
