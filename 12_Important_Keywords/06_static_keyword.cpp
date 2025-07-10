#include <iostream>

void counter() {
    static int count = 0;  // 'count' retains its value across function calls
    count++;
    std::cout << "Count: " << count << std::endl;
}

int main() {
    counter();  // Output: Count: 1
    counter();  // Output: Count: 2
    counter();  // Output: Count: 3
    return 0;
}
