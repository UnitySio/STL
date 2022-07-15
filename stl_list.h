//
// Created by Woojin Choi on 2022/07/13.
//

#ifndef STL_STL_LIST_H
#define STL_STL_LIST_H


template <typename T>
class STLList {
private:
    struct Node {
        T data;
        Node *previous;
        Node *next;

        Node(T value = T(), Node *previous = nullptr, Node *next = nullptr) : data(value), previous(previous), next(next) {
        }
    };

    class Iterator {
    private:
        Node *current;
    public:
        Iterator(Node *current = nullptr) : current(current) {
        }

        Iterator &operator++() {
            current = current->next;
            return *this;
        }

        Iterator &operator++(int) {
            current = current->next;
            return *this;
        }

        Iterator &operator--() {
            current = current->previous;
            return *this;
        }

        Iterator &operator--(int) {
            current = current->previous;
            return *this;
        }

        T &operator*() {
            return current->data;
        }

        Node *operator&() {
            return current;
        }

        bool operator==(const Iterator &kIterator) {
            return current == kIterator.current;
        }

        bool operator!=(const Iterator &kIterator) {
            return current != kIterator.current;
        }
    };

    class ReverseIterator {
    private:
        Node *current;
    public:
        ReverseIterator(Node *current = nullptr) : current(current) {
        }

        ReverseIterator &operator++() {
            current = current->previous;
            return *this;
        }

        ReverseIterator &operator++(int) {
            current = current->previous;
            return *this;
        }

        ReverseIterator &operator--() {
            current = current->next;
            return *this;
        }

        ReverseIterator &operator--(int) {
            current = current->next;
            return *this;
        }

        T &operator*() {
            return current->data;
        }

        Node *operator&() {
            return current;
        }

        bool operator==(const ReverseIterator &kIterator) {
            return current == kIterator.current;
        }

        bool operator!=(const ReverseIterator &kIterator) {
            return current != kIterator.current;
        }
    };

    Node *head_;
    Node *tail_;
    size_t size_;
public:
    typedef Iterator Iterator;
    typedef ReverseIterator ReverseIterator;

    STLList() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    STLList(size_t size) {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;

        for (size_t i = 0; i < size; i++) {
            PushBack(T());
        }
    }

    STLList(size_t size, T value) {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;

        for (size_t i = 0; i < size; i++){
            PushBack(value);
        }
    }

    STLList(const STLList<T> &kSTLList) {
        head_ = kSTLList.head_;
        tail_ = kSTLList.tail_;
        size_ = kSTLList.size_;
    }

    ~STLList() {
        Clear();
    }

    void PushBack(T value) {
        if (size_ == 0) {
            head_ = new Node(value);
            tail_ = head_;
        } else {
            tail_->next = new Node(value, tail_);
            tail_ = tail_->next;
        }

        size_++;
    }

    void PopBack() {
        Node *temp = tail_;
        tail_ = tail_->previous;

        delete temp;

        size_--;
    }

    void PushFront(T value) {
        if (size_ == 0) {
            head_ = new Node(value);
            tail_ = head_;
        } else {
            head_->previous = new Node(value, nullptr, head_);
            head_ = head_->previous;
        }

        size_++;
    }

    void PopFront() {
        Node *temp = head_;
        head_ = head_->next;

        delete temp;

        size_--;
    }

    void Resize(size_t new_size) {

    }

    void Resize(size_t new_size, T value) {

    }

    void Insert(Iterator position, T value) {
        Node *temp = &position;
    }

    void Erase(Iterator position) {

    }

    void Swap(STLList<T> stl_list) {
        Node *temp_head = head_;
        Node *temp_tail = tail_;
        size_t temp_size = size_;

        head_ = stl_list.head_;
        tail_ = stl_list.tail_;
        size_ = stl_list.size_;

        stl_list.head_ = temp_head;
        stl_list.tail_ = temp_tail;
        stl_list.size_ = temp_size;
    }

    void Assign(size_t size, T value) {
        Clear();

        for (int i = 0; i < size; i++) {
            PushBack(value);
        }
    }

    void Clear() {
        Node *temp = head_;

        while (head_ != nullptr) {
            head_ = head_->next;
            delete temp;
            temp = head_;
        }

        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    bool Empty() {
        return size_ <= 0;
    }

    int Size() {
        return size_;
    }

    T Front() {
        if (size_ == 0) {
            return T();
        }

        return head_->data;
    }

    T Back() {
        if (size_ == 0) {
            return T();
        }

        return tail_->data;
    }

    Iterator Begin() {
        return Iterator(head_);
    }

    Iterator End() {
        return Iterator(nullptr);
    }

    ReverseIterator RBegin() {
        return ReverseIterator(nullptr);
    }

    ReverseIterator REnd() {
        return ReverseIterator(head_);
    }
};


#endif //STL_STL_LIST_H
