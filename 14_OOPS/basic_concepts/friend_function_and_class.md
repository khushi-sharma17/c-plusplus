
# what is the friend function in C++ ?

A **friend function** in C++ is a **non-member function** (not part of the class) that is **granted special access** to the private and protected members of the class.

Normally, **private/protected members** cannot be accessed outside the class, but friend functions break this restriction for specific functions.

---

## **Syntax**

```cpp
class ClassName {
    friend returnType functionName(arguments);
};
```

---

## **Key Points about Friend Functions**

1. **Declared inside class** using `friend` keyword, but **defined outside** like a normal function.
2. **Not a member** of the class, so it:

   * Does **not use `this` pointer**.
   * Must explicitly use object name to access members.
3. Can access **private and protected data** of the class.
4. **Can be standalone functions** or **member functions of another class** (friend class).
5. **Friendship is not mutual**:

   * If `A` is friend of `B`, `B` is not automatically friend of `A`.
6. **Friendship is not inherited**:

   * If `B` is derived from `A`, `B` doesn’t automatically inherit friendship.

---

## **Example of Friend Function**

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    Box(int l) : length(l) {}

    // Friend function declaration
    friend void printLength(Box b);
};

// Friend function definition
void printLength(Box b) {
    cout << "Length: " << b.length << endl; // Accessing private member
}

int main() {
    Box b1(10);
    printLength(b1);
}
```

**Output:**

```
Length: 10
```

---

## **Friend Function as Member of Another Class**

```cpp
class A;  // Forward declaration

class B {
public:
    void showA(A& obj);
};

class A {
private:
    int x = 5;
public:
    friend void B::showA(A& obj); // Friend member function of class B
};

void B::showA(A& obj) {
    cout << "Value of x: " << obj.x << endl;
}

int main() {
    A a;
    B b;
    b.showA(a);
}
```

---

## **Friend Class**

* A class can make another class its friend, giving **all member functions** of the friend class access to its private/protected members.

```cpp
class A {
private:
    int data = 42;
    friend class B;  // B is a friend class
};

class B {
public:
    void display(A& obj) {
        cout << obj.data << endl; // Access private member of A
    }
};
```

---

## **Advantages of Friend Functions**

* Allows **controlled access** to private/protected members.
* Useful for **operator overloading** (e.g., `<<`, `>>` operators).

---

## **Disadvantages**

* Breaks **encapsulation** (private members become accessible).
* Friendship is **not inherited** and **not reciprocal** (must be explicitly declared each time).

---
