#include <iostream>

inline void print(const std::string &s){
    std::cout << s << std::endl;
}

int main(int argc, char *argv[]) {
    std::string s = "Welcome using test!";
    print(s);
}
