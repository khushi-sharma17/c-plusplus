
## Flowchart
- start/end - Terminator
- input/output
- process
- decision making block
- arrows
- connector


## Pseudocode
- generic way of representing the code.


## Programming Language
- What is a programming language ?
A programming language is a set of instructions and syntax used to communicate with and control a computer's behavior, allowing programmers to write code that can be executed by the machine.

- Why do we need it ?
Computers don't understand human languages like English or Hindi. They understand binary code (1s and 0s). Programming languages translate human-readable instructions into this binary code, allowing us to control and manipulate computers. 


## Compiler
- handles translation
- find errors


## Data types and Variables
- char     -    1 byte
- bool      -   1 byte
- int   -   4 byte
- unsigned int      -      4 byte
- float     -   4 byte
- double    -   8 byte


## How negative numbers are stored ?
- +ve --> first bit 0
- -ve --> first bit 1

Steps
- first ignore the negative signs
- convert into binary repr.
- take 2's comp and store it.


## Shift Operator
* in left shift and right shift operator the padding depends on the sign of the numbers, if the numbers are positive, the padded numbers are 0, while for the negative numbers, it is compiler dependent.




## Time Complexity
- It is the amount of time taken by an algorithm to run as a function of length of the input.

### WHy ?
- For making better programs.
- Comparision of algo


-> Big O Notation (Upper Bound, worst case)  
-> Theta 0  (for avg case complexity)  
-> Omega (lower bound, best case)  


-> constant time -> O(1)  
-> Linear time -> O(n)  
-> Logarithmic time -> O(logn)  
-> Quadratic time -> O(n square)   
-> cubic time -> O(n cube)  


-> Complexity scale
O(1) -> O(logn) -> O(n) -> O(n logn) -> O(n square) -> O(n cube) -> O(2 power n) -> O(n factorial)


- Stuck in TLE (Time Limit Exceeded)
10**8 operation rule -> Most of the modern machine can perform 10 ** 8 operation/second.



![alt text](image.png)



## Binary search
- Condition - element should be in monotonic function















# What is the difference between endl and '\n' in C++ ?

Both `endl` and `'\n'` in C++ are used to create a **new line**, but there are **important differences** between them. Let's break it down:

---

### 🔸 `'\n'` – Newline Character

* `'\n'` is a character literal that inserts a newline into the output stream.
* It does **not** flush the output buffer automatically.
* Faster than `endl` in terms of performance.

**Example:**

```cpp
cout << "Hello\nWorld";
```

**Output:**

```
Hello
World
```

---

### 🔸 `endl` – End Line Manipulator

* `endl` inserts a newline (`\n`) **and** **flushes the output buffer**.
* Flushing means forcing the output to be written to the console or file immediately.
* Slightly **slower**, but useful when you want to ensure output is shown immediately (e.g., in logging or debugging).

**Example:**

```cpp
cout << "Hello" << endl;
cout << "World";
```

**Output:**

```
Hello
World
```

(Here, "Hello" is printed and flushed before moving on.)

---

### 🔍 When to Use What?

| Situation                                   | Use    |
| ------------------------------------------- | ------ |
| Fast output (e.g., competitive programming) | `'\n'` |
| Immediate output (e.g., logs, debugging)    | `endl` |

---

### 🧠 Bonus Tip

You can manually flush after `'\n'` if needed:

```cpp
cout << "Hello\n" << flush;
```

---


















## what is the difference between nullptr and NULL in C++ ?


In C++, both `NULL` and `nullptr` are used to represent a null pointer, but there are important differences between them, especially in modern C++:

---

### 🔹 `NULL`

* **Type**: It is typically defined as `#define NULL 0` or `#define NULL ((void*)0)` in C/C++ headers.
* **Problem**: `NULL` is just an integer literal (`0`), so it can cause ambiguity when overloaded functions exist.

#### 🔸 Example of ambiguity:


```cpp
void func(int);
void func(char*);

func(NULL);  // Calls func(int), not func(char*)
```



This happens because `NULL` is just `0`, an `int`.

---

### 🔹 `nullptr` (introduced in C++11)

* **Type**: It is a keyword of its own type: `std::nullptr_t`.
* **Purpose**: Meant specifically to represent a null pointer constant.
* **Advantage**: Removes ambiguity in overload resolution.


#### 🔸 Example:

```cpp
void func(int);
void func(char*);

func(nullptr);  // Calls func(char*), because nullptr is not an int
```

---

### ✅ Summary:

| Feature            | `NULL`                | `nullptr`            |
| ------------------ | --------------------- | -------------------- |
| Introduced in      | C / C++               | C++11                |
| Type               | Integer literal (`0`) | `std::nullptr_t`     |
| Overload ambiguity | Yes                   | No                   |
| Recommended        | ❌ Not in C++         | ✅ Yes, from C++11+ |

---

### 🔧 Best Practice:

Use `nullptr` instead of `NULL` in modern C++ (C++11 and later) to avoid type confusion and improve code safety and clarity.






































# What are the different concepts in OOPS in C++ and in Java ?

---

## **Core OOP Concepts (Common to Both C++ and Java)**

1. **Class and Object**

   * **Class**: Blueprint of an object (defines properties and behaviors).
   * **Object**: Instance of a class.

2. **Encapsulation**

   * Bundling data (variables) and methods (functions) together.
   * Controlled access using **access specifiers** (`private`, `protected`, `public`).

3. **Abstraction**

   * Hiding internal implementation details and exposing only necessary parts.
   * Achieved via **abstract classes** and **interfaces**.

4. **Inheritance**

   * Deriving a new class from an existing class to reuse or extend functionality.
   * Promotes **code reuse**.

5. **Polymorphism**

   * Ability of a single function, operator, or method to behave differently based on context.
   * Two types:

     * **Compile-time (Static)**: Function overloading, operator overloading.
     * **Run-time (Dynamic)**: Achieved using **virtual functions** (C++) or **method overriding** (Java).

---

## **OOP Concepts in C++**

C++ is **multi-paradigm** (supports both procedural and OOP).
Extra concepts supported in C++:

1. **Multiple Inheritance**

   * A class can inherit from multiple base classes.
   * Can cause the "Diamond Problem," solved by **virtual inheritance**.

2. **Operator Overloading**

   * Allows redefining operators (`+`, `-`, `==`) for user-defined classes.

3. **Virtual Functions and Pure Virtual Functions**

   * Used for **runtime polymorphism** and **abstract classes**.

4. **Templates (Generic Programming)**

   * Similar to generics in Java but more powerful (works for functions and classes).

5. **Memory Management**

   * Manual (`new`/`delete`) or smart pointers (`std::shared_ptr`, `std::unique_ptr`).

6. **Access Specifiers for Inheritance**

   * `public`, `protected`, `private` inheritance modes.

---

## **OOP Concepts in Java**

Java is **purely object-oriented (except primitives)**, so almost everything is an object.

Key OOP features in Java:

1. **Single Inheritance (Class) + Multiple Inheritance (Interface)**

   * A class can inherit only one parent class (to avoid diamond problem).
   * Multiple inheritance is achieved using **interfaces**.

2. **Interfaces and Abstract Classes**

   * Interfaces define contracts (similar to pure virtual classes in C++).
   * Abstract classes allow partial implementation.

3. **Garbage Collection**

   * Automatic memory management (no `delete` keyword like in C++).

4. **No Operator Overloading**

   * Operators cannot be overloaded (e.g., `+` works only for numbers and strings).

5. **Packages and Access Modifiers**

   * Four access levels: `public`, `protected`, `default`, `private`.

6. **Generics**

   * Type-safe collections and methods (similar to templates, but restricted).

---

## **Key Differences in OOP between C++ and Java**

| Feature                   | C++                                                                              | Java                                                    |
| ------------------------- | -------------------------------------------------------------------------------- | ------------------------------------------------------- |
| **Multiple Inheritance**  | Supported (with `virtual` keyword to avoid ambiguity)                            | Not supported (only via interfaces)                     |
| **Memory Management**     | Manual (`new`/`delete`) and smart pointers                                       | Automatic garbage collection                            |
| **Operator Overloading**  | Supported                                                                        | Not supported                                           |
| **Polymorphism**          | Compile-time (overloading, operator overloading) and runtime (virtual functions) | Compile-time (overloading) and runtime (overriding)     |
| **Templates vs Generics** | Templates for functions/classes                                                  | Generics (type-erased at runtime)                       |
| **Access Specifiers**     | `public`, `protected`, `private`                                                 | `public`, `protected`, `default`, `private`             |
| **Inheritance Type**      | Multiple inheritance of classes                                                  | Single inheritance of classes (multiple via interfaces) |
| **Execution Model**       | Compiled to machine code                                                         | Compiled to bytecode (JVM)                              |

---































# which operators cannot be overloaded in C++ ?

---

## **Operators that cannot be overloaded**

1. **Scope resolution operator `::`**

   * Used to define members outside a class or access global variables.
   * Example:

     ```cpp
     int x;
     class A { public: static int x; };
     int A::x = 5;  // Scope resolution
     ```
   * Cannot be overloaded because it’s fundamental to resolving names at compile time.

---

2. **Member access (dot) operator `.`**

   * Used to access members of an object.
   * Example:

     ```cpp
     obj.member;
     ```
   * Overloading this would break basic syntax and semantics.

---

3. **Member pointer access operator `.*`**

   * Used with pointers to members.
   * Example:

     ```cpp
     class A { public: int x; };
     int A::*ptr = &A::x;
     A obj;
     obj.*ptr = 10;
     ```
   * Cannot be overloaded for similar reasons as `.` operator.

---

4. **Ternary conditional operator `?:`**

   * Conditional operator:

     ```cpp
     condition ? expr1 : expr2;
     ```
   * Cannot be overloaded because it requires three operands and overloading could make code ambiguous.

---

5. **`sizeof` operator**

   * Returns size of a type or object at compile time:

     ```cpp
     sizeof(int);  // returns 4 (on 32-bit)
     ```
   * Must remain compile-time and cannot be changed by user code.

---

6. **`typeid` operator**

   * Used in RTTI (Run-Time Type Information) to get type info:

     ```cpp
     typeid(obj).name();
     ```
   * Cannot be overloaded as it’s tied to compiler’s type system.

---

7. **`alignof` operator (since C++11)**

   * Returns the alignment requirement of a type:

     ```cpp
     alignof(int);
     ```
   * Compile-time operator, cannot be overloaded.

---

8. **`decltype` operator (since C++11)**

   * Used to query the type of an expression:

     ```cpp
     decltype(x) y;
     ```
   * Cannot be overloaded as it’s purely compile-time.

---

9. **`new` and `delete` in global scope (special case)**

   * You **can** overload `operator new` and `operator delete` (for memory allocation), but **not** the syntax of `new` or `delete` themselves.

---

## **Why these operators cannot be overloaded?**

* They are **compile-time operators** or affect **core language semantics**.
* Overloading them would **break code readability** and **compiler guarantees**.
* For example, if `sizeof` was overloaded, you could make `sizeof(int)` return `100`, which is nonsensical for memory management.

---

### **Operators That CAN Be Overloaded**

* Arithmetic: `+`, `-`, `*`, `/`, `%`
* Relational: `<`, `>`, `<=`, `>=`, `==`, `!=`
* Logical: `&&`, `||`, `!`
* Bitwise: `&`, `|`, `^`, `~`, `<<`, `>>`
* Assignment: `=`, `+=`, `-=`, `*=`, `/=`, etc.
* Increment/Decrement: `++`, `--`
* Subscript: `[]`
* Function call: `()`
* Pointer dereference: `->` (but not `.`)

---








































# what are the various uses of scope resolution operator ?


The **scope resolution operator (`::`)** in C++ is a very powerful operator used to **define and access entities in specific scopes**. Its main job is to **remove ambiguity** and **access correct members or global variables/functions**.

Here are its **various uses** (works):

---

## **1. To Define Class Member Functions Outside the Class**

* Allows defining a member function **outside the class** after declaring it inside the class.

### Example:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void display();  // Declaration
};

// Definition outside class using ::
void A::display() {
    cout << "Member function defined outside the class" << endl;
}

int main() {
    A obj;
    obj.display();
}
```

---

## **2. To Access Global Variables When Local Variable Has Same Name**

* When a **local variable** shadows a **global variable**, `::` helps access the global one.

### Example:

```cpp
#include <iostream>
using namespace std;

int x = 10;  // Global variable

int main() {
    int x = 20;  // Local variable
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl;  // Access global variable
}
```

**Output:**

```
Local x: 20
Global x: 10
```

---

## **3. To Access Static Members of a Class**

* Static members are **shared among all objects**. They are accessed using `ClassName::member`.

### Example:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    static int count;
};

int A::count = 5;  // Initialization outside class

int main() {
    cout << "Static count: " << A::count << endl;
}
```

---

## **4. To Define Static Data Members Outside Class**

* Static data members must be **initialized outside** the class using `::`.

(Already shown in previous example.)

---

## **5. To Access Class Members When Using Inheritance (Remove Ambiguity)**

* When **multiple base classes** have members with the **same name**, `::` is used to specify which base class’s member to access.

### Example:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void show() { cout << "Class A" << endl; }
};

class B {
public:
    void show() { cout << "Class B" << endl; }
};

class C : public A, public B {
public:
    void display() {
        A::show();  // Access A’s show()
        B::show();  // Access B’s show()
    }
};

int main() {
    C obj;
    obj.display();
}
```

---

## **6. To Access Namespaces**

* Used to access members of a specific namespace.

### Example:

```cpp
#include <iostream>
namespace first {
    int value = 10;
}
namespace second {
    int value = 20;
}
int main() {
    std::cout << first::value << "\n";
    std::cout << second::value << "\n";
}
```

---

## **7. To Access Enclosing Class Members in Nested Classes**

* Used to **define or access** members of outer class from inner (nested) class.

### Example:

```cpp
#include <iostream>
using namespace std;

class Outer {
public:
    class Inner {
    public:
        static void show();
    };
};

void Outer::Inner::show() {
    cout << "Nested class function definition" << endl;
}

int main() {
    Outer::Inner::show();
}
```

---

## **8. To Call Constructor of Base Class in Derived Class**

* Used to **initialize base class constructor explicitly**.

### Example:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) { cout << "Base constructor: " << x << endl; }
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) { cout << "Derived constructor" << endl; }
};

int main() {
    Derived obj(10);
}
```

---

## **Summary of Uses**

1. Define member functions outside class.
2. Access global variables hidden by local variables.
3. Initialize and access static members.
4. Resolve ambiguity in multiple inheritance.
5. Access members of namespaces.
6. Access nested class members.
7. Call base class constructors in derived classes.

---












































