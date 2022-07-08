//
// Created by Woojin Choi on 2022/07/07.
//

#ifndef STL_STLVECTOR_H
#define STL_STLVECTOR_H

#include <iostream>
using namespace std;

class STLVector {
private:
    int *array;
    int size;
    int capacity;
public:
    STLVector();
    STLVector(int size);
    STLVector(int size, int value);
    ~STLVector();

    STLVector &operator=(const STLVector &stlVector);
    int operator[](int index);

    void PushBack(int value);
    void PopBack();
    void Assign(int size, int value);
    int At(int index);
    int Front();
    int Back();
    void Reserve(int capacity);
    void Resize(int size);
    void Resize(int size, int value);
    bool Empty();
    int Clear();
    int Size();
    int Capacity();
};


#endif //STL_STLVECTOR_H
