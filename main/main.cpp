//#include <iostream>
//#include <src/base/division.h>
//
//using namespace std;
//
//static const char *const HEADER = "\nDivider © 2018 Monkey Claps Inc.\n\n";
//static const char *const USAGE = "Usage:\n\tdivider <numerator> <denominator>\n\nDescription:\n\tComputes the result of a fractional division,\n\tand reports both the result and the remainder.\n";
//
//int main(int argc, const char *argv[]) {
//    Fraction f;
//    cout << HEADER;
//
//    // ensure the correct number of parameters are used.
//    if (argc < 3) {
//        cout << USAGE;
//        return 1;
//    }
//
//    f.numerator = atoll(argv[1]);
//    f.denominator = atoll(argv[2]);
//
//    Division d = Division(f);
//    try {
//        DivisionResult r = d.divide();
//
//        cout << "Division : " << f.numerator << " / " << f.denominator << " = " << r.division << "\n";
//        cout << "Remainder: " << f.numerator << " % " << f.denominator << " = " << r.remainder << "\n";
//    } catch (DivisionByZero) {
//        cout << "Can not divide by zero, Homer. Sober up!\n";
//    }
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>

inline void bubble_sort(int arr[], int size)
{
    for (int i =0 ; i < size; ++i)
    {
        for (int j = 0; j < size-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void container_test()
{
    int arrary[] = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    int size = sizeof(arrary)/ sizeof(arrary[0]);
    int* arr= new int[size];
    memset(arr, 0, sizeof(arrary));
    memcpy(arr, arrary, size* sizeof(int));
    bubble_sort(arr, size);
    delete[] arr;

    std::vector<double>vec(arrary, arrary+size);
    double uname_array[10];
    memcpy(uname_array, vec.data(), vec.size());
    double max = *std::max_element(vec.begin(),vec.end());
    int max_index = std::max_element(vec.begin(),vec.end())-vec.begin();
    double min = *std::min_element(vec.begin(), vec.end());
    double min_index = std::min_element(vec.begin(), vec.end())-vec.begin();
    std::cout << "vec max is: " << max << ", max index is: " << max_index << "; vec min is: "<<min
              <<", min index is: " << min_index << std::endl;

    double target = 5;
    int target_index = std::find(vec.begin(), vec.end(), target)-vec.begin();
    target += 0.6;
    double closesValue = *std::min_element(vec.begin(), vec.end(), [=](double a, double b){
        return std::abs(a-target) < std::abs(b-target);
    });
    double clossValueIndex = std::min_element(vec.begin(), vec.end(), [=](double a, double b){
        return std::abs(a-target)<std::abs(b-target);
    })- vec.begin();
    std::cout << "closses target value is " << closesValue << ", index is " << clossValueIndex << std::endl;

    vec.insert(vec.begin()+1, 5);
    vec.push_back(10);
    vec.erase(vec.begin()+1, vec.begin()+3);//范围性的删除元素
    vec.pop_back();
    std::cout <<"front and back is: "<<  vec.front() << ", " << vec.back() << std::endl;

    //list
    std::list<double>ls = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    ls.push_back(10);
    ls.push_front(0);
    ls.pop_front();
    ls.pop_back();
    ls.insert(ls.begin(), 0);
    ls.erase(ls.begin());
    std::cout <<"ls is : ";
    for(std::list<double>::iterator it=ls.begin(); it != ls.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;


    //queue
    std::queue<double> q = std::queue<double>({2, 5, 7, 8, 6, 9, 1, 4, 3, 0});
    q.push(10);
    q.pop();
    std::cout <<"front and back is: "<< q.front() << ", " << q.back() << std::endl;
    std::cout << "queue is: ";
    while (!q.empty()){
        std::cout << q.front() << ",";
        q.pop();
    }
    std::cout << std::endl;

    //pair
    std::pair<int, std::string>p1(1, "Bob");
    std::pair<int, std::string> p2 = std::make_pair(2, "Tom");
    if (p1>p2){
        std::cout << "This is " << p1.second << std::endl;
    } else{
        std::cout << "This is " << p2.second << std::endl;
    }

    //set
    std::set<double> s = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    std::cout << "s is : ";
    s.insert(10);
    s.erase(10);
    for(std::set<double>::iterator it=s.begin(); it != s.end(); it++)
    {
        std::cout << * it << ", ";
    }
    std::cout << std::endl;

    //map
    std::map<int, std::string>m =  {{4, "Lucy"}, {1, "Tom"}, {3, "Alice"}, {2, "Bob"}};
    std::map<int, std::string, std::greater<int>>m2(m.begin(), m.end());
    std::vector<std::pair<int, std::string>>m3(m.begin(), m.end());
    std::sort(m3.begin(), m3.end(), [](const std::pair<int, std::string>&p1, const std::pair<int, std::string>&p2){
        return p1.second < p2.second;
    });

    std::cout << "map is: ";
    for(const auto &p: m2)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }

}
inline void ptrUse()
{
    std::vector<double> vec = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    std::shared_ptr<std::vector<double>>sharedPtr = std::make_shared<std::vector<double>>(vec);
    std::cout << "sharePtr cout is " << sharedPtr.use_count() << std::endl;
    std::vector<double>*p = sharedPtr.get();
    for(int i=0; i<p->size();i++){
        std::cout << (*p)[i] << ", ";
    }
    std::cout << std::endl;
    sharedPtr.reset();

    size_t size = vec.size()* sizeof(vec[0]);
    double* p1 = static_cast<double*>(malloc(size));
    memcpy(p1, vec.data(), size);
    free(p1);

    double* p2 = new double[vec.size()];
    memcpy(p1, vec.data(), size);
    delete[] p2;

    double* p3 = static_cast<double*>(calloc(vec.size(), size));
    memcpy(p3, vec.data(), size);
    free(p3);

    std::allocator<double>alloc;
    double* p4 = alloc.allocate(vec.size());
    for(int i = 0; i<size; ++i)
    {
        alloc.construct(p4+i, vec[i]);
    }
    for (int i = 0; i < size; ++i) {
        alloc.destroy(p4+i);
    }
    alloc.deallocate(p4, vec.size());

}
//int main(int argc, const char* argv[])
//{
//    //container_test();
//    //ptrUse();
//}

#include <iostream>
#include <thread>
#include <future>

// 函数用于在一个线程中计算某个数的平方，并将结果设置到 promise 中
void calculate_square(int x, std::promise<int>& prom) {
    int result = x * x;
    prom.set_value(result); // 将结果设置到 promise 中
}

int main() {
    // 创建一个 promise 对象，用于在一个线程中设置计算结果
    std::promise<int> prom;

    // 获取与 promise 关联的 future 对象，用于在另一个线程中获取计算结果
    std::future<int> fut = prom.get_future();

    // 启动一个新线程来计算数字的平方
    int num = 5;
    //std::thread t(calculate_square, num, std::ref(prom));
    std::thread t(calculate_square, num, std::ref(prom));
    // 在主线程中等待计算完成并获取结果
    int result = fut.get();
    std::cout << "Square of " << num << " is: " << result << std::endl;

    // 等待并加入计算线程
    t.join();

    return 0;
}


