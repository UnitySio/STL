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

        bool operator==(const ReverseIterator &kIterator) {
            return current == kIterator.current;
        }

        bool operator!=(const ReverseIterator &kIterator) {
            return current != kIterator.current;
        }
    };

    Node *head_;
    Node *tail_;
    int size_;
public:
    typedef Iterator Iterator;
    typedef ReverseIterator ReverseIterator;

    STLList() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    STLList(const STLList<T> &kSTLList) {
        head_ = kSTLList.head_;
        tail_ = kSTLList.tail_;
        size_ = kSTLList.size_;
    }

    ~STLList() {
        Node *temp = head_;

        while (head_ != nullptr) {
            head_ = head_->next;
            delete temp;
            temp = head_;
        }
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

    void Clear() {
        Node *temp = head_;

        while (head_ != nullptr) {
            head_ = head_->next;
            delete temp;
            temp = head_;
        }

        size_ = 0;
    }

    bool Empty() {
        return size_ <= 0;
    }

    int Size() {
        return size_;
    }

    T Front() {
        return head_->data;
    }

    T Back() {
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
