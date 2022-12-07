#ifndef CMAKE_PROJECT_TEMPLATE_DETECTION_H
#define CMAKE_PROJECT_TEMPLATE_DETECTION_H


class Detection {
public:
    Detection();
    ~Detection();
    static Detection* intance() {
        if(mIntance == nullptr){
            mIntance = new Detection;
        }
        return mIntance;
    }
    void print();

private:
    static Detection* mIntance;
};


#endif //CMAKE_PROJECT_TEMPLATE_DETECTION_H
