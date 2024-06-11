#include <iostream>
#include "Detection.h"

Detection* Detection::mIntance = nullptr;
Detection::Detection() {};
Detection::~Detection() {
    mIntance = nullptr;
}

void Detection::print() {
    std::cout << this << std::endl;
}