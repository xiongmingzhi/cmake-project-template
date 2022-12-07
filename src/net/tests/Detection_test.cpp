#include <src/net/Detection.h>
int main(){
    Detection* p1 = Detection::intance();
    Detection* p2 = Detection::intance();
    p1->print();
    p2->print();
    delete p1, p2;
}
