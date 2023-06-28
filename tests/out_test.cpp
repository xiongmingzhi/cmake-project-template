#include <iostream>

int main() {
    std::string s = "";

    if (s.empty()) {
        std::cout << "字符串为空";
    }
    else {
        std::cout << "字符串不为空";
    }
}