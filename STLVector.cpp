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
    int *temp = new int[stlVector.size];

    for (int i = 0; i < stlVector.size; i++) {
        temp[i] = stlVector.array[i];
    }

    delete[] array;

    size = stlVector.size;
    capacity = stlVector.size;
    array = temp;

    return *this;
}

bool STLVector::operator==(const STLVector &stlVector) {
    if (size != stlVector.size) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] != stlVector.array[i]) {
            return false;
        }
    }

    return true;
}

bool STLVector::operator!=(const STLVector &stlVector) {
    if (size == stlVector.size) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] == stlVector.array[i]) {
            return false;
        }
    }

    return true;
}

bool STLVector::operator<(const STLVector &stlVector) {
    if (size < stlVector.size) {
        return true;
    }
    else {
        return false;
    }
}

bool STLVector::operator>(const STLVector &stlVector) {
    if (size > stlVector.size) {
        return true;
    }
    else {
        return false;
    }
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

        delete[] array;
        array = temp;
    }

    array[size++] = value;
}

void STLVector::PopBack() {
    array[--size] = 0;
}

void STLVector::Assign(int size, int value) {
    delete[] array;

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

void STLVector::Swap(STLVector &stlVector) {
    int *temp_array = array;
    int temp_size = size;
    int temp_capacity = capacity;

    delete[] array;

    array = stlVector.array;
    size = stlVector.size;
    capacity = stlVector.capacity;

    delete[] stlVector.array;

    stlVector.array = temp_array;
    stlVector.size = temp_size;
    stlVector.capacity = temp_capacity;
}

void STLVector::Reserve(int capacity) {
    this->capacity = capacity;
    int *temp = new int[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

void STLVector::Resize(int size) {
    int *temp = new int[size];

    if (size > this->size) {
        for (int i = 0; i < size; i++) {
            if (i > this->size - 1) {
                temp[i] = 0;
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

    delete[] array;

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

    delete[] array;

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

void STLVector::Clear() {
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
