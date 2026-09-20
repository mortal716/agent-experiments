#include <iostream>

int main() {
    const int result = 20 + 22;
    std::cout << "sandbox-test: " << result << '\n';
    return result == 42 ? 0 : 1;
}