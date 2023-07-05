#include <iostream>
#include <src/base/cppdemo.h>
#include <time.h>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
namespace xzy{

inline void bubble_sort(int arr[], int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if(arr[j] > arr[j+1]){
                int tempt = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempt;
            }
        }
    }
}

inline void ptrUse(){
    std::vector<double> vec = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    std::shared_ptr<std::vector<double>>sharePtr = std::make_shared<std::vector<double>>(vec);
    std::cout <<"sharePtr cout is " << sharePtr.use_count() << std::endl;
    std::vector<double>*p = sharePtr.get();
    for(int i=0; i<p->size();i++){
        std::cout << (*p)[i] << ", ";
    }
    std::cout << std::endl;

    size_t size = vec.size()* sizeof(vec[0]);
    double *p1 = static_cast<double *>(malloc(size));
    memcpy(p1,vec.data(),size);
    free(p1);
    double *p2 = new double [vec.size()];
    memcpy(p2, vec.data(), size);
    delete[] p2;
    double *p3 = static_cast<double*>(calloc(vec.size(), size));
    memcpy(p3, vec.data(), size);
    free(p3);

    std::allocator<double> alloc;
    double* p4 = alloc.allocate(vec.size());
    for (int i = 0; i < size; ++i) {
        alloc.construct(p4+i, vec[i]);
    }
    for (int i = 0; i < size; ++i) {
        alloc.destroy(p4+i);
    }
    alloc.deallocate(p4, vec.size());
}


inline void convert(){
    char ch1[20] = "hello";
    char ch2[] = ", world";
    std::cout << "sizeof is: " << sizeof(ch2) <<"; len is: " <<  strlen(ch2) << std::endl;
    strcat(ch1, ch2);
    char ch3[20];
    strcpy(ch3, ch2);
    char*ret1 = strstr(ch1, ",");
    char*ret2 = strrchr(ch1, ',');

    std::string s = ch3;
    std::cout << "size is: " << s.size() << "; length is: " << s.length() << std::endl;
    std::string ss = s.substr(0, 5);

    //类型转换
    char a1[] = "123.45";
    char* s1 = a1;
    std::string s11 = a1;
    double a11 = strtod(a1, NULL);
    printf("%s, %s, %f\n", s1, s11.c_str(), a11);

    const char* s2 = "123.45";
    char a2[10];
    strcpy(a2, s2);
    std::string s22 = s2;
    double a22 = strtod(s2, NULL);
    printf("%s, %s, %f\n", a2, s22.c_str(), a22);

    std::string s3 = "123.45";
    char a3[10];
    strcpy(a3,s3.c_str());
    const char* s33 = s3.c_str(); //一定要加const
    double a33 = std::stod(s3);
    printf("%s, %s, %f\n", a3, s33, a33);

    double a4 = 123.45;
    char a44[10];
    snprintf(a44, sizeof(a44), "%2f", a4);
    char* s4 = a44;
    std::string s44 = std::to_string(a4);
    printf("%s, %s, %s\n", a44, s4, s44.c_str());


}


void container_test(){
    int arrary[] = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    int size = sizeof(arrary)/ sizeof(arrary[0]);
    int* arr= new int[size];
    memset(arr, 0, sizeof(arrary));
    memcpy(arr, arrary, size* sizeof(arrary[0]));
    bubble_sort(arr, size);
    delete[] arr;

    std::vector<double>vec(arrary, arrary+size);
    double uname_array[10];
    memcpy(uname_array, vec.data(), vec.size());
    double max = *std::max_element(vec.begin(), vec.end());
    int max_index = std::max_element(vec.begin(), vec.end()) - vec.begin();
    double min = *std::min_element(vec.begin(), vec.end());
    int min_index = std::min_element(vec.begin(), vec.end()) - vec.begin();
    std::cout << "vec max is: " << max << ", max index is: " << max_index << "; vec min is: "<<min
    <<", min index is: " << min_index << std::endl;
    double target = 5;
    int target_index = std::find(vec.begin(), vec.end(),target)-vec.begin();
    std::cout << "target index is " << target_index << std::endl;
    target += 0.6;
    double closesValue = *std::min_element(vec.begin(), vec.end(), [=](double a, double b){
        return std::abs(a-target)<std::abs(b-target);
    });
    double clossValueIndex = std::min_element(vec.begin(), vec.end(), [=](double a, double b){
        return std::abs(a-target)<std::abs(b-target);
    })- vec.begin();
    std::cout << "closses target value is " << closesValue << ", index is " << clossValueIndex << std::endl;

    vec.insert(vec.begin()+1, 5);
    vec.push_back(10);
    vec.erase(vec.begin()+1);
    vec.pop_back();
    std::cout <<"front and back is: "<<  vec.front() << ", " << vec.back() << std::endl;

    //list
    std::list<double> ls = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    ls.push_front(0);
    ls.push_back(10);
    ls.pop_front();
    ls.pop_back();
    ls.insert(std::next(ls.begin(), 2), 0);
    ls.erase(std::next(ls.begin(), 2));
    std::cout << "ls is: ";
    for(std::list<double>::iterator it = ls.begin(); it != ls.end();it++){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    //queue
    std::queue<double>q = std::queue<double>({2, 5, 7, 8, 6, 9, 1, 4, 3, 0});
    q.push(10);
    q.pop();
    std::cout <<"front and back is: "<< q.front() << ", " << q.back() << std::endl;
    std::cout << "queue is: ";
    while (!q.empty()){
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << std::endl;

    //pair
    std::pair<int, std::string> p1(1, "Bob");
    std::pair<int, std::string> p2 = std::make_pair(2, "Tom");
    if (p1>p2){
        std::cout << "This is " << p1.second << std::endl;
    } else{
        std::cout << "This is " << p2.second << std::endl;
    }

    //set
    std::set<double> s = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    s.insert(10);
    s.erase(10);
    int n = s.count(0);
    std::cout << "set is ";
    for(std::set<double>::iterator it=s.begin(); it!=s.end();it++){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    //map,三种排序
    std::map<int, std::string> m = {{4, "Lucy"}, {1, "Tom"}, {3, "Alice"}, {2, "Bob"}};
    std::map<int, std::string, std::greater<int>>m2(m.begin(), m.end());//key降序
    std::vector<std::pair<int, std::string>>m3(m.begin(), m.end());
    std::sort(m3.begin(), m3.end(), [](const std::pair<int, std::string>&p1, const std::pair<int, std::string>&p2){
        return p1.second <p2.second;
    });//按value排序

    m.insert({5, "Emma"});
    m.erase(5);
    m[3] = "Emma";
    std::cout << "map is: "<<std::endl ;
    for(const auto &p: m){
        std::cout << p.first << ": " << p.second << std::endl;
    }

}

inline void func(){
    int arrary[] = {2, 5, 7, 8, 6, 9, 1, 4, 3, 0};
    int size = sizeof(arrary)/ sizeof(arrary[0]);
    void (*pfunc1)(int arr[], int size);
    void (*pfunc2)(int arr[], int size);
    pfunc1 = bubble_sort;
    pfunc2 = &bubble_sort;
    pfunc1(arrary, size);
    (*pfunc2)(arrary, size);

    int a = 1, b= 2;
    auto func1 = [](int x, int y){return x+y;};
    auto func2 = [&]()->int{return a+b;};
    std::function<int(int, int)>func3 = func1;
    auto func4 = std::bind(func1, std::placeholders::_1, 5);
    std::cout <<"func1,func2,func3,func4: "<< func1(a,b)<<", "
    << func2() <<", " << func3(a,b)<<", " << func4(a) <<std::endl;

}

inline void fileFunc(){
    std::vector<int>vec1 = {1, 2, 3, 4, 5};
    std::vector<double> vec2 = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::ofstream file("data.txt");
    if(!file.is_open()){
        return;
    }
    for (int i = 0; i < vec1.size(); ++i) {
        file << vec1[i] << ", " << vec2[i] << std::endl;
    }
    file.close();
    std::vector<int>vec11;
    std::vector<double>vec22;
    std::ifstream fin("data.txt");
    if (!fin.is_open()){
        return;
    }
    std::string line, value;
    while (std::getline(fin, line)){
        std::istringstream iss(line);
        std::getline(iss, value, ',');
        vec1.push_back(std::stoi(value));
        std::getline(iss, value, ',');
        vec2.push_back(std::stod(value));
    }
    fin.close();

}

void cpptest(){
    clock_t start, finish;
    start = clock();
    //container_test();
    //convert();
    //ptrUse();
    //func();
    fileFunc();
    finish = clock();
    std::cout << "C++ demo spend time is: " << (double)(finish-start)/CLOCKS_PER_SEC << std::endl;
}
}






