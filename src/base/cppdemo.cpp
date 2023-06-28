#include "cppdemo.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <memory>
#include <fstream>
#include <sstream>

namespace xzy{
//快排
inline void bubble_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0;j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                int tempt = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tempt;
            }
        }
    }

}

inline void convert(){
    //char 操作
    char arr1[20] = "hello";
    char arr2[] = ", world";
    std::cout <<"sizeof is: "<< sizeof(arr2)<< ", strlen is: " << strlen(arr2) <<std::endl;
    strcat(arr1, arr2); //拼接的时候主要内存是否溢出
    char arr11[20];
    strcpy(arr11, arr1);
    char* ret= strstr(arr1, ",");
    const char delimiter = ',';
    char* arr12 = strrchr(arr11, delimiter);
    printf("%s\n",arr12);
    //std::string 操作
    std::string alphaString = ", world";
    std::cout << "length is: " << alphaString.length() <<", size is: "<<alphaString.size()<< std::endl;//容器，sizeof不可以使用
    std::string alphaString2 =  alphaString.substr(2, 5);

    //类型转换
    char ch[10] = "123.45";
    char* s1 = ch;//ch转char*
    std::string s2 = ch;
    double a1 = strtod(ch, NULL);

    char ch2[10];
    strcpy(ch2, s1);
    std::string s22 = s1;
    double a2 = strtod(s1, NULL);

    char ch3[10];
    for(int i=0; i<s2.length(); i++){
        ch3[i] = s2[i];
    }
    ch3[s2.length()] = '\0';
    const char*s11 = s2.c_str();
    double a3 = std::stod(s2);

    char ch4[10];
    int ret1 = snprintf(ch4, sizeof(ch4), "%f", a1); //ch4为123.45000
    char* s12 = ch4;
    std::string s222 = std::to_string(a1);

}



//容器测试
inline void container_test(){
    //C++ arr
    int arrary[] = {2, 3, 1, 4, 6, 8, 9, 7, 5, 0};
    int size = sizeof(arrary)/ sizeof(arrary[0]);
    bubble_sort(arrary, size);
    int *arr = new int[size];
    memset(arr, 0, sizeof(int)*size);
    memcpy(arr, arrary, sizeof(arrary));
    for(int i = 0; i<size; i++){
        std::cout << *(arr+i) << ", ";
    }
    std::cout << std::endl;
    delete arr;

    //vector
    std::vector<double>vec(arrary, arrary+size);
    double arrary2[10];
    memcpy(arrary2, vec.data(), sizeof(vec));
    int max = *std::max_element(std::begin(vec), std::end(vec));
    int max_index = std::max_element(std::begin(vec), std::end(vec)) - std::begin(vec);
    int min = *std::min_element(std::begin(vec), std::end(vec));
    int min_index = std::min_element(std::begin(vec), std::end(vec)) - std::begin(vec);
    double target = 5;
    std::vector<double>::iterator iter = std::find(std::begin(vec), std::end(vec), target);
    if(iter == vec.end()){
        std::cout << "not find the number" << std::endl;
    } else{
        std::cout << "the number is: " << std::distance(std::begin(vec), iter) << std::endl;
    }
    target += 0.6;
    std::vector<double>::iterator it = std::min_element(vec.begin(), vec.end(), [target](int a, int b){
        return std::abs(a-target) < std::abs(b-target);});
    double closeValue = *it;
    int closeValueindex = std::distance(vec.begin(), it);
    std::cout << "the close number is: " << closeValue << ", index is: " << closeValueindex << std::endl;

    std::vector<double>vec2;
    vec2.assign(vec.begin(), vec.end());
    vec2.insert(vec2.begin()+1, 0.1);
    double firstValue = vec2.front();
    vec2.erase(vec2.begin()+1, vec2.begin()+5);
    vec2.pop_back();
    std::cout << "laster element is " << vec2.back() << std::endl;

  //C++ list
   std::list<double> ls = {1,2 ,3};
   ls.push_back(4);
   ls.push_front(0);
   ls.insert(std::next(ls.begin(), 2), 1.5);
   for(std::list<double>::iterator it = ls.begin(); it != ls.end(); it++){
       std::cout << *it << ", ";
   }
   std::cout << std::endl;
   ls.erase(std::next(ls.begin(), 2));
   for(std::list<double>::iterator it = ls.begin(); it != ls.end(); it++){
      std::cout << *it << ", ";
   }
   std::cout << std::endl;

   //pair
   std::pair<double, std::string> pair1(1, "The pair number is 1");
   std::pair<double, std::string> pair2 = std::make_pair(2, "The pair number is 2");
    if (pair1 < pair2){
        std::cout << pair2.second << std::endl;
    } else{
        std::cout << pair1.second << std::endl;
    }
    //queue
    std::queue<double>q;
    q.push(0);
    q.push(1);
    for(int i = 0; i<q.size(); i++){
        double temp = q.front();//获取第一个元素
        std::cout <<"queue first value is: " << temp << ", ";
        q.pop();//删除首个元素，vector 没有pop函数，但是有pop_back,list有pop_front,也有pop_back函数，queue只有pop先进先出；
    }

    //set函数
    std::set<double> s = {20, 10, 40, 30};//默认从小到大排序
    std::cout << "the set is: ";
    for(std::set<double>::iterator it = s.begin();it != s.end(); it++){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    s.erase(20);
    int cout = s.count(20);

    //map 的三种排序方法
    std::map<int, std::string>myMap = {{4, "Bob"}, {1, "Alice"}, {3, "Charlie"}, {2, "David"}};
    //遍历,按key升序排列
    std::cout << "map 默认按key排序如下: "<< std::endl; ;
    for(const auto& p: myMap){
        std::cout << p.first << ": " << p.second << std::endl;
    }
    //遍历，按key降序排列
    std::map<int, std::string, std::greater<int>>myMap2(myMap.begin(), myMap.end());
    std::cout << "map 按key从大到小排序如下: "<< std::endl; ;
    for(const auto& p: myMap2){
        std::cout << p.first << ": " << p.second << std::endl;
    }

    std::vector<std::pair<int, std::string>>tempVec(myMap.begin(), myMap.end());
    std::sort(tempVec.begin(), tempVec.end(), [](const std::pair<int, std::string>pair1, const std::pair<int, std::string>pair2){
        return pair1.second > pair2.second;
    });
    std::cout << "map 按value排序： " << std::endl;
    for(const auto& p: myMap){
        std::cout << p.first << ": " << p.second << std::endl;
    }

    myMap.insert({5, "Emma"});
    myMap.erase(5);
    std::string name = myMap[2];//获取一个value
    std::vector<std::string> names;//获取所有names
    for(const auto& p: myMap){
        names.push_back(p.second);
    }

}

inline void ptrUse(){
    std::vector<double> vec = {2, 3, 1, 4, 6, 8, 9, 7, 5, 0};
    std::shared_ptr<std::vector<double>>sharePtr = std::make_shared<std::vector<double>>(vec);
    std::cout << "use_count is: " << sharePtr.use_count() << std::endl;
    std::vector<double> *ptr = sharePtr.get();
    for(int i = 0; i<ptr->size(); i++){
        std::cout << (*ptr)[i] << ", ";
    }
    std::cout << std::endl;

    //动态内存分配
    size_t size = vec.size()* sizeof(vec[0]);
    double* p1 = static_cast<double*>(malloc(size));
    memcpy(p1, vec.data(), size);
    free(p1);

    double* p2 = new double[vec.size()];
    memcpy(p2, vec.data(), size);
    delete[] p2;

    double* p3 = static_cast<double*>(calloc(vec.size(), sizeof(double)));
    memcpy(p3, vec.data(), size);
    free(p3);

    std::allocator<double> alloc;
    double* p4 = alloc.allocate(vec.size());
    for(size_t i =0; i<size; i++){
        alloc.construct(p4+i, vec[i]);
    }
    for(size_t i = 0; i<vec.size();i++){
        alloc.destroy(p4+i);
    }
    alloc.deallocate(p4, size);

}
//函数封装
inline void func(){
    int arrary[] = {2, 3, 1, 4, 6, 8, 9, 7, 5, 0};
    int size = sizeof(arrary)/ sizeof(arrary[0]);
    void (*pfunc1)(int arr[], int size);
    void (*pfunc2)(int arr[], int size);
    pfunc1 = bubble_sort;
    pfunc2 = &bubble_sort;
    pfunc1(arrary, size);
    (*pfunc2)(arrary, size);//解指针穿参数

    int a = 1, b= 2;
    auto func1 = [](int x, int y)->int{return x+y;};
    auto func2 = [=]()->int{return a+b;};
    std::function<int(int, int)>func3;
    func3 = func1;
    auto func4 = std::bind(func1, std::placeholders::_1, 5);
    std::cout << func1(a, b) << ", " << func2() << ", " << func3(a, b) <<", " << func4(a) << std::endl;
}

//文件操作
inline void fileFunc(){
    std::vector<int> column1 = {1, 2, 3, 4, 5};
    std::vector<double>column2 = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::ofstream file("data.txt");
    if(!file.is_open()){
        return;
    }

    for(size_t i = 0; i<column1.size(); i++){
        file << column1[i] << ", " << column2[i] << std::endl;
    }
    file.close();

    std::vector<int>vec1;
    std::vector<double>vec2;
    std::ifstream fin("data.txt");
    if(!fin.is_open()){
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
    file.close();
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
    std::cout << " C++ demo programmer spend time is: " << (double)(finish - start)/ CLOCKS_PER_SEC << std::endl;
}

}




