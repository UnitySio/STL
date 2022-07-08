//
// Created by Woojin Choi on 2022/07/07.
//

#ifndef STL_STLVECTOR_H
#define STL_STLVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class Iterator {
private:
    T *ptr;
public:
    Iterator(T *ptr) : ptr(ptr) {
    }

    Iterator &operator++() {
        *ptr++;
        return *this;
    }

    Iterator &operator+=(int value) {
        *ptr += value;
        return *this;
    }

    Iterator &operator-=(int value) {
        *ptr -= value;
        return *this;
    }

    T &operator[](int index) {
        return ptr[index];
    }

    T &operator*() {
        return *ptr;
    }

    bool operator==(const Iterator &iterator) {
        return ptr == iterator.ptr;
    }

    bool operator!=(const Iterator &iterator) {
        return ptr != iterator.ptr;
    }
};

template <typename T>
class STLVector {
private:
    T *array;
    int size;
    int capacity;
public:
    typedef Iterator<T> iterator;

    STLVector() {
        size = 0;
        capacity = 0;
        array = new T[capacity];
    }

    STLVector(int size) {
        this->size = size;
        capacity = size;
        array = new T[size];

        for (int i = 0; i < size; i++) {
            array[i] = T();
        }
    }

    STLVector(int size, T value) {
        this->size = size;
        capacity = size;
        array = new T[size];

        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
    }

    ~STLVector() {
        delete[] array;
    }

    STLVector &operator=(const STLVector &stlVector) {
        T *temp = new T[stlVector.size];

        for (int i = 0; i < stlVector.size; i++) {
            temp[i] = stlVector.array[i];
        }

        delete[] array;

        size = stlVector.size;
        capacity = stlVector.size;
        array = temp;

        return *this;
    }

    bool operator==(const STLVector &stlVector) {
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

    bool operator!=(const STLVector &stlVector) {
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

    bool operator>(const STLVector &stlVector) {
        if (size < stlVector.size) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const STLVector &stlVector) {
        if (size > stlVector.size) {
            return true;
        } else {
            return false;
        }
    }

    T &operator[](int index) {
        return array[index];
    }

    void PushBack(T value) {
        if (size + 1 >= capacity) {
            if (capacity == 0) capacity++;
            else capacity *= 2;

            T *temp = new T[capacity];

            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
        }

        array[size++] = value;
    }

    void PopBack() {
        array[--size] = T();
    }

    void Assign(int size, T value) {
        delete[] array;

        this->size = size;
        capacity = size;
        array = new T[size];

        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
    }

    T &At(int index) {
        if (index <= size - 1) {
            return array[index];
        } else {
            throw out_of_range("vector"); /// 예외 발생
        }
    }

    T &Front() {
        return array[0];
    }

    T &Back() {
        return array[size - 1];
    }

    void Swap(STLVector &stlVector) {
        T *temp_array = array;
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

    void Reserve(int capacity) {
        this->capacity = capacity;
        T *temp = new T[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        delete[] array;
        array = temp;
    }

    void Resize(int size) {
        T *temp = new T[size];

        if (size > this->size) {
            for (int i = 0; i < size; i++) {
                if (i > this->size - 1) {
                    temp[i] = T();
                } else {
                    temp[i] = array[i];
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
        }

        delete[] array;

        this->size = size;
        capacity = size;
        array = temp;
    }

    void Resize(int size, int value) {
        T *temp = new T[size];

        if (size > this->size) {
            for (int i = 0; i < size; i++) {
                if (i > this->size - 1) {
                    temp[i] = value;
                } else {
                    temp[i] = array[i];
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
        }

        delete[] array;

        this->size = size;
        capacity = size;
        array = temp;
    }

    bool Empty() {
        if (size <= 0) {
            return true;
        } else {
            return false;
        }
    }

    void Clear() {
        for (int i = 0; i < size; i++) {
            array[i] = T();
        }

        size = 0;
    }

    int Size() {
        return size;
    }

    int Capacity() {
        return capacity;
    }

    iterator Begin() {
        return iterator(array);
    }

    iterator End() {
        return iterator(array + size);
    }
};

#endif //STL_STLVECTOR_H
