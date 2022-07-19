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

        Node(T value = T()) : data(value) {
            previous = nullptr;
            next = nullptr;
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
        head_ = new Node();
        tail_ = new Node();

        head_->next = tail_;
        tail_->previous = head_;

        size_ = 0;
    }

    STLList(size_t size) {
        head_ = new Node();
        tail_ = new Node();

        head_->next = tail_;
        tail_->previous = head_;

        size_ = 0;

        for (size_t i = 0; i < size; i++) {
            PushBack(T());
        }
    }

    STLList(size_t size, T value) {
        head_ = new Node();
        tail_ = new Node();

        head_->next = tail_;
        tail_->previous = head_;

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

        delete head_;
        delete tail_;
    }

    void PushBack(T value) {
        Node *temp = tail_->previous;
        temp->next = new Node(value);
        temp->next->previous = temp;
        temp->next->next = tail_;
        tail_->previous = temp->next;

        size_++;
    }

    void PopBack() {
        Node *temp = tail_->previous;

        tail_->previous = temp->previous;
        temp->previous->next = tail_;

        delete temp;

        size_--;
    }

    void PushFront(T value) {
        Node *temp = head_->next;
        temp->previous = new Node(value);
        temp->previous->next = temp;
        temp->previous->previous = head_;
        head_->next = temp->previous;


        size_++;
    }

    void PopFront() {
        Node *temp = head_->next;

        head_->next = temp->next;
        temp->next->previous = head_;

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

    Iterator Erase(Iterator position) {
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

    void Merge() {

    }

    void Splice() {

    }

    void Remove() {

    }

    void RemoveIf() {

    }

    void Unique() {

    }

    void Assign(size_t size, T value) {
        Clear();

        for (size_t i = 0; i < size; i++) {
            PushBack(value);
        }
    }

    void Clear() {
        for (size_t i = 0; i < Size(); i++) {
            PopBack();
        }
    }

    bool Empty() {
        return size_ == 0;
    }

    int Size() {
        return size_;
    }

    T Front() {
        return head_->next->data;
    }

    T Back() {
        return tail_->previous->data;
    }

    Iterator Begin() {
        return Iterator(head_->next);
    }

    Iterator End() {
        return Iterator(tail_);
    }

    ReverseIterator RBegin() {
        return ReverseIterator(tail_);
    }

    ReverseIterator REnd() {
        return ReverseIterator(head_->next);
    }
};


#endif //STL_STL_LIST_H
