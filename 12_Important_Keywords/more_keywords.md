# Are there super, final, abstract and explicit type of keywords in c++ ?

Great question! These keywords behave differently across **C++** and **Java**, and some exist in C++ but with different usage or naming. Let me break them down one by one:

---

## **1. `super` keyword**

* **In Java:**

  * `super` is used to call the **parent class constructor** or **parent class methods**.
  * Example (Java):

    ```java
    class Parent {
        void display() { System.out.println("Parent"); }
    }
    class Child extends Parent {
        void display() {
            super.display(); // Call parent method
            System.out.println("Child");
        }
    }
    ```

* **In C++:**

  * **NO `super` keyword**.
  * Instead, we explicitly call the **base class name** with `::` (scope resolution).
  * Example (C++):

    ```cpp

    class Parent {
    public:
        void display() { cout << "Parent\n"; }
    };

    class Child : public Parent {
    public:
        void display() {
            Parent::display(); // Equivalent to super in Java
            cout << "Child\n";
        }
    };
    ```

---



## **2. `final` keyword**

* **In Java:**

  * Prevents inheritance of a class or overriding of a method.

* **In C++ (since C++11):**

  * Used in two contexts:

    1. **To prevent class inheritance:**

       ```cpp
       class A final { };  // No class can inherit from A
       ```
       
    2. **To prevent method overriding:**

       ```cpp
       class Base {
           virtual void show() final;  // Cannot be overridden in derived class
       };
       ```

---




## **3. `abstract` keyword**

* **In Java:**

  * Marks a class as abstract or declares abstract methods.

* **In C++:**

  * **NO `abstract` keyword**.
  * Achieved using **pure virtual functions**:

    ```cpp
    class Shape {
    public:
        virtual void draw() = 0;  // Pure virtual function -> Abstract class
    };
    ```

---

## **4. `explicit` keyword**

* **Only in C++** (Java does not have this keyword).
* Used to **prevent implicit conversions** on constructors or conversion operators.
* Example:

```cpp
class A {
public:
    explicit A(int x) { }  // Prevent implicit conversion
};

void func(A obj) { }

int main() {
    func(5);   // ❌ Error (implicit conversion not allowed)
    func(A(5)); // ✅ Explicit conversion
}
```

---

# **Summary**

| Keyword    | In Java                       | In C++                                |
| ---------- | ----------------------------- | ------------------------------------- |
| `super`    | Used for parent class call    | No keyword; use `Base::`              |
| `final`    | Prevents inheritance/override | Prevents inheritance/override (C++11) |
| `abstract` | Marks abstract class/method   | No keyword; use pure virtual `=0`     |
| `explicit` | Not present                   | Prevents implicit conversions         |

---

Do you want me to **list all keywords that are in Java but not in C++ and vice versa** (like a full comparison table)?
Shall I also **explain `explicit` in detail with conversion examples** (this is often asked in interviews)?
