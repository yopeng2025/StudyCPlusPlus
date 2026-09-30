# CPP Module 04


This module covers various advanced object-oriented programming concepts in C++. The topics addressed include virtual functions, polymorphism, deep copy, abstract classes, and interfaces.

## Exercises

### Exercise 00: Virtual Functions
**Concept:** Virtual functions allow you to override functions in derived classes.

**Example:**
```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base class show function called." << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function called." << std::endl;
    }
};

// Usage
Base *bptr;
Derived d;
bptr = &d;
bptr->show();  // Calls Derived's show function
```

### Exercise 01: Polymorphism
**Concept:** Polymorphism enables objects of different classes to be treated as objects of a common superclass.

**Example:**
```cpp
void display(Base &b) {
    b.show();
}

// Usage
Derived d;
display(d);  // Calls Derived's show
```

### Exercise 02: Deep Copy
**Concept:** A deep copy creates a new instance of an object and copies all fields to the new instance, allocating new memory for dynamic resources.

**Example:**
```cpp
class MyClass {
public:
    int *data;
    MyClass(int value) {
        data = new int(value);
    }
    // Implementing copy constructor for deep copy
    MyClass(const MyClass &obj) {
        data = new int(*(obj.data));
    }
    ~MyClass() { delete data; }
};
```

### Exercise 03: Abstract Classes
**Concept:** An abstract class cannot be instantiated and is designed to be inherited by subclasses.

**Example:**
```cpp
class AbstractBase {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function
};

class ConcreteClass : public AbstractBase {
public:
    void pureVirtualFunction() override {
        std::cout << "Implemented pure virtual function." << std::endl;
    }
};
```

