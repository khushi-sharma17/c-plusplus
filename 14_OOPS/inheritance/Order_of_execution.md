
# suppose we are multilevel inheriting, in what order the constructors and the destructors be called in their order of the execution ?


Great question! In **multilevel inheritance** (e.g., `A -> B -> C`), **constructors and destructors are called in opposite orders**.

---

## **Order of Constructor Calls**

* **Base class constructors are called first**, then derived class constructors.
* Execution order: **Top to Bottom** (parent → child).

### Example:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor A\n"; }
    ~A() { cout << "Destructor A\n"; }
};

class B : public A {
public:
    B() { cout << "Constructor B\n"; }
    ~B() { cout << "Destructor B\n"; }
};

class C : public B {
public:
    C() { cout << "Constructor C\n"; }
    ~C() { cout << "Destructor C\n"; }
};

int main() {
    C obj;
}
```

---

### **Output**

```
Constructor A
Constructor B
Constructor C
Destructor C
Destructor B
Destructor A
```

---

## **Order of Destructor Calls**

* **Derived class destructors are called first**, then base class destructors.
* Execution order: **Bottom to Top** (child → parent).

---

## **Reason for This Order**

1. **Construction:**

   * Derived class depends on base class.
   * Base must be **fully constructed first** so derived can safely use it.

2. **Destruction:**

   * Derived class destructor runs first to clean up **its own resources**.
   * Then base destructor runs to clean up **base resources**.

---

## **With Virtual Destructors**

* If you delete an object via a **base class pointer**, **virtual destructor** ensures **correct bottom-to-top order** of destruction.

Example:

```cpp
A* ptr = new C(); 
delete ptr; // Calls C -> B -> A destructors (if A's destructor is virtual)
```

Without `virtual`, only `A`'s destructor would run → resource leak.

---

## **In Multilevel Inheritance with Parameters**

* If constructors take parameters:

  * **Base class constructor** must be called explicitly in initializer list of derived class.
* Example:

```cpp
class A {
public:
    A(int x) { cout << "A: " << x << endl; }
};

class B : public A {
public:
    B(int x, int y) : A(x) { cout << "B: " << y << endl; }
};

class C : public B {
public:
    C(int x, int y, int z) : B(x, y) { cout << "C: " << z << endl; }
};

int main() {
    C obj(1, 2, 3);
}
```

**Output:**

```
A: 1
B: 2
C: 3
```

---
