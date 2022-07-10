//
// Created by Woojin Choi on 2022/07/07.
//

#ifndef STL_STLVECTOR_H
#define STL_STLVECTOR_H

#include <iostream>
using namespace std;

/**
 * @brief 반복자
 * @details
 */
template <typename T>
class Iterator {
private:
    T *array_;
public:
    Iterator(T *array = nullptr) : array_(array) { /// 객체 생성과 동시에 멤버 변수를 초기화
    }

    Iterator &operator++() {
        ++array_;
        return *this;
    }

    Iterator &operator++(int) {
        array_++;
        return *this;
    }

    Iterator &operator--() {
        --array_;
        return *this;
    }

    Iterator operator--(int) {
        return *this;
    }

    Iterator &operator+=(int value) {
        array_ += value;
        return *this;
    }

    Iterator &operator-=(int value) {
        array_ -= value;
        return *this;
    }

    T &operator[](int index) {
        return array_[index];
    }

    T &operator*() {
        return *array_;
    }

    Iterator operator+(int value) {
        return array_ + value;
    }

    Iterator operator-(int value) {
        return array_ - value;
    }

    int operator-(const Iterator &kIterator) { /// 상대적 거리를 계산하기 위해 -연산자 재할당
        return array_ - kIterator.array_;
    }

    bool operator==(const Iterator &kIterator) {
        return array_ == kIterator.array_;
    }

    bool operator!=(const Iterator &kIterator) {
        return array_ != kIterator.array_;
    }
};

/**
 * @brief 역반복자
 * @details
 */
template <typename T>
class ReverseIterator {
private:
    T *array_;
public:
    ReverseIterator(T *array = nullptr) : array_(array) { /// 객체 생성과 동시에 멤버 변수를 초기화
    }

    ReverseIterator &operator++() {
        --array_;
        return *this;
    }

    ReverseIterator &operator++(int) {
        array_--;
        return *this;
    }

    ReverseIterator &operator--() {
        ++array_;
        return *this;
    }

    ReverseIterator &operator--(int) {
        array_++;
        return *this;
    }

    ReverseIterator &operator+=(int value) {
        array_ -= value;
        return *this;
    }

    ReverseIterator &operator-=(int value) {
        array_ += value;
        return *this;
    }

    T &operator[](int index) {
        return array_[index];
    }

    T &operator*() {
        return *array_;
    }

    ReverseIterator operator+(int value) {
        return array_ - value;
    }

    ReverseIterator operator-(int value) {
        return array_ + value;
    }

    bool operator==(const ReverseIterator &kReverseIterator) {
        return array_ == kReverseIterator.array_;
    }

    bool operator!=(const ReverseIterator &kReverseIterator) {
        return array_ != kReverseIterator.array_;
    }
};

template <typename T>
class STLVector {
private:
    T *array_;
    int size_;
    int capacity_;
public:
    typedef Iterator<T> Iterator;
    typedef ReverseIterator<T> ReverseIterator;

    STLVector() {
        size_ = 0;
        capacity_ = 0;
        array_ = new T[capacity_];
    }

    STLVector(int size) {
        size_ = size;
        capacity_ = size;
        array_ = new T[size];

        for (int i = 0; i < size; i++) {
            array_[i] = T();
        }
    }

    STLVector(int size, T value) {
        size_ = size;
        capacity_ = size;
        array_ = new T[size];

        for (int i = 0; i < size; i++) {
            array_[i] = value;
        }
    }

    ~STLVector() {
        delete[] array_;
    }

    STLVector &operator=(const STLVector &stlVector) {
        T *temp = new T[stlVector.size_];

        for (int i = 0; i < stlVector.size_; i++) {
            temp[i] = stlVector.array_[i];
        }

        delete[] array_;

        size_ = stlVector.size_;
        capacity_ = stlVector.size_;
        array_ = temp;

        return *this;
    }

    bool operator==(const STLVector &stlVector) {
        if (size_ != stlVector.size_) {
            return false;
        }

        for (int i = 0; i < size_; i++) {
            if (array_[i] != stlVector.array_[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const STLVector &stlVector) {
        if (size_ == stlVector.size_) {
            return false;
        }

        for (int i = 0; i < size_; i++) {
            if (array_[i] == stlVector.array_[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator>(const STLVector &stlVector) {
        return size_ < stlVector.size_;
    }

    bool operator<(const STLVector &stlVector) {
        return size_ > stlVector.size_;
    }

    T &operator[](int index) {
        return array_[index];
    }

    void PushBack(T value) {
        if (size_ + 1 >= capacity_) {
            if (capacity_ == 0) {
                Reserve(capacity_ + 1);
            } else {
                Reserve(capacity_ * 2);
            }
        }

        array_[size_++] = value;
    }

    void PopBack() {
        size_--;
    }

    void Assign(int size, T value) {
        delete[] array_;

        size_ = size;
        capacity_ = size;
        array_ = new T[size];

        for (int i = 0; i < size; i++) {
            array_[i] = value;
        }
    }

    T &At(int index) {
        if (index <= size_ - 1) {
            return array_[index];
        } else {
            throw out_of_range("vector"); /// 예외 발생
        }
    }

    T &Front() {
        return array_[0];
    }

    T &Back() {
        return array_[size_ - 1];
    }

    void Swap(STLVector &stlVector) {
        T *temp_array = array_;
        int temp_size = size_;
        int temp_capacity = capacity_;

        delete[] array_;

        array_ = stlVector.array_;
        size_ = stlVector.size_;
        capacity_ = stlVector.capacity_;

        delete[] stlVector.array_;

        stlVector.array_ = temp_array;
        stlVector.size_ = temp_size;
        stlVector.capacity_ = temp_capacity;
    }

    void Reserve(int capacity) {
        capacity_ = capacity;
        T *temp = new T[capacity];

        for (int i = 0; i < size_; i++) {
            temp[i] = array_[i];
        }

        delete[] array_;
        array_ = temp;
    }

    void Resize(int size) {
        T *temp = new T[size];

        if (size > size_) {
            for (int i = 0; i < size; i++) {
                temp[i] = array_[i];
            }
        } else {
            for (int i = 0; i < size; i++) {
                temp[i] = array_[i];
            }
        }

        delete[] array_;

        size_ = size;
        capacity_ = size;
        array_ = temp;
    }

    void Resize(int size, int value) {
        T *temp = new T[size];

        if (size > size_) {
            for (int i = 0; i < size; i++) {
                if (i > size_ - 1) {
                    temp[i] = value;
                } else {
                    temp[i] = array_[i];
                }
            }
        } else {
            for (int i = 0; i < size; i++) {
                temp[i] = array_[i];
            }
        }

        delete[] array_;

        size_ = size;
        capacity_ = size;
        array_ = temp;
    }

    bool Empty() {
        return size_ <= 0;
    }

    void Clear() {
        size_ = 0;
    }

    int Size() {
        return size_;
    }

    int Capacity() {
        return capacity_;
    }

    Iterator Begin() {
        return Iterator(array_);
    }

    Iterator End() {
        return Iterator(array_ + size_);
    }

    ReverseIterator RBegin() {
        return ReverseIterator(array_ + (size_ - 1));
    }

    ReverseIterator REnd() {
        return ReverseIterator(array_ - 1);
    }

    Iterator Insert(Iterator position, T value) {
        int index = position - array_;

        if (size_ + 1 >= capacity_) {
            Reserve(capacity_ * 2);
        }

        for (int i = size_; i > index; i--) {
            array_[i] = array_[i - 1];
        }

        array_[index] = value;
        size_++;

        return Iterator(array_ + index);
    }

    Iterator Insert(Iterator position, int size, T value) {
        int index = position - array_;

        if (size_ + size >= capacity_) {
            if (size_ + size > capacity_ * 2) {
                Reserve(size_ + size);
            } else {
                Reserve(capacity_ * 2);
            }
        }

        for (int i = size_ + size; i > index; i--) {
            array_[i] = array_[i - size];
        }

        for (int i = 0; i < size; i++) {
            array_[index + i] = value;
        }

        size_ += size;

        return Iterator(array_ + index);
    }

    Iterator Insert(Iterator position, Iterator start, Iterator end) {
        int index = position - array_;
        int size = end - start;

        if (size_ + size >= capacity_) {
            if (size_ + size > capacity_ * 2) {
                Reserve(size_ + size);
            } else {
                Reserve(capacity_ * 2);
            }
        }

        for (int i = size_ + size; i > index; i--) {
            array_[i] = array_[i - size];
        }

        for (int i = 0; i < size; i++) {
            array_[index + i] = *start;
            start++;
        }

        size_ += size;
        return Iterator(array_ + index);
    }

    void Erase(Iterator position) {
        int index = position - array_;

        for (int i = index + 1; i < size_; i++) {
            array_[i - 1] = array_[i];
        }

        size_--;
    }

    void Erase(Iterator start, Iterator end) {
        int start_index = start - array_;
        int end_index = end - array_;
        int distance = end_index - start_index;

        for (int i = end_index; i < size_; i++) {
            array_[i - distance] = array_[i];
        }

        size_ -= distance;
    }
};

#endif //STL_STLVECTOR_H
