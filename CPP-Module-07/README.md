# CPP-Module-07

C++ template programming and STL containers learning module.

## Tech Stack

- **Language**: C++
- **Topics**: Templates, STL Containers, Iterators, Function Templates, Class Templates

## Compilation

```bash
cd exXX  # Navigate to exercise directory
make    # Compile the project
```

## Exercises

### ex00: Function Templates

Function templates allow you to write generic functions that work with any data type.

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Works with int, double, etc.
int result = add(5, 10);
double sum = add(1.5, 2.5);
```

**Key Points:**
- Type deduction happens at compile time
- Compiler generates separate code for each type used
- Template specialization allows custom implementations for specific types

### ex01: STL Containers & Iterators

Learn how to use standard containers like vector, list, and map to store and manipulate data.

```cpp
// Vector - dynamic array
std::vector<int> vec = {1, 2, 3};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
}

// Map - key-value pairs
std::map<std::string, int> ages;
ages["Alice"] = 30;
for (auto& pair : ages) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
```

**Key Points:**
- Vector: O(1) random access, efficient at end operations
- List: O(1) insertion/deletion anywhere, no random access
- Map: O(log n) operations, automatically sorted by key
- Iterators provide uniform access across different containers

### ex02: Class Templates & Advanced Algorithms

Create generic data structures using class templates and apply STL algorithms.

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(T value) { data.push_back(value); }
    T pop() { 
        T value = data.back();
        data.pop_back();
        return value;
    }
};

// STL algorithms
std::vector<int> vec = {3, 1, 4, 1, 5};
std::sort(vec.begin(), vec.end());
auto it = std::find(vec.begin(), vec.end(), 4);
```

**Key Points:**
- Class templates create generic data structures
- STL algorithms work with any container via iterators
- Template instantiation generates code for each type at compile time