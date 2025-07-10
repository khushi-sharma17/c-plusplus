
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















## What is the difference between endl and '\n' in C++ ?

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