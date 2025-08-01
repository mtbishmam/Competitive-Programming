#include <iostream>

int main() {
#ifdef __clang__
    std::cout << "Compiled with Clang\n";
#elif __GNUC__
    std::cout << "Compiled with GCC\n";
#else
    std::cout << "Other compiler\n";
#endif
    return 0;
}