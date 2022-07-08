//
// Created by Woojin Choi on 2022/07/07.
//

#include "STLVector.h"

STLVector::STLVector() {
    size = 0;
    capacity = 0;
    array = new int[capacity];
}

STLVector::STLVector(int size) {
    this->size = size;
    capacity = size;
    array = new int[size];
}

STLVector::STLVector(int size, int value) {
    this->size = size;
    capacity = size;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

STLVector::~STLVector() {
    delete[] array;
}

STLVector &STLVector::operator=(const STLVector &stlVector) {
    return *this;
}

int STLVector::operator[](int index) {
    return array[index];
}

void STLVector::PushBack(int value) {
    if (size + 1 >= capacity) {
        if (capacity == 0) capacity++;
        else capacity *= 2;

        int *temp = new int[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        array = temp;
    }

    array[size++] = value;
}

void STLVector::PopBack() {
    array[--size] = 0;
}

void STLVector::Assign(int size, int value) {
    this->size = size;
    capacity = size;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

int STLVector::At(int index) {
    if (index <= size - 1) {
        return array[index];
    }
    else
    {
        throw out_of_range("vector"); /// 예외 발생
    }
}

int STLVector::Front() {
    return array[0];
}

int STLVector::Back() {
    return array[size - 1];
}

void STLVector::Reserve(int capacity) {
    this->capacity = capacity;
    int *temp = new int[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    array = temp;
}

void STLVector::Resize(int size) {
    int *temp = new int[size];

    for (int i = 0; i < size; i++) {
        temp[i] = 0;
    }

    for (int i = 0; i < this->size; i++) {
        temp[i] = array[i];
    }

    this->size = size;
    capacity = size;
    array = temp;
}

void STLVector::Resize(int size, int value) {
    int *temp = new int[size];

    if (size > this->size) {
        for (int i = 0; i < size; i++) {
            if (i > this->size - 1) {
                temp[i] = value;
            }
            else {
                temp[i] = array[i];
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
    }

    this->size = size;
    capacity = size;
    array = temp;
}

bool STLVector::Empty() {
    if (size <= 0) {
        return true;
    }
    else {
        return false;
    }
}

int STLVector::Clear() {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }

    size = 0;
}

int STLVector::Size() {
    return size;
}

int STLVector::Capacity() {
    return capacity;
}
