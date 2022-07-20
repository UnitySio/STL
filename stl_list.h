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

    STLList &operator=(const STLList &kSTLList) {
        head_ = kSTLList.head_;
        tail_ = kSTLList.tail_;
        size_ = kSTLList.size_;

        return *this;
    }

    bool operator!=(const STLList &kSTLList) {
        if (size_ != kSTLList.size_) {
            return true;
        } else {
            Node *temp = head_->next;
            Node *stl_list_temp = kSTLList.head_->next;

            for (size_t i = 0; i < size_; i++) {
                if (temp->data == stl_list_temp->data) {
                    return false;
                }

                temp = temp->next;
                stl_list_temp = stl_list_temp->next;
            }

            return true;
        }
    }

    bool operator==(const STLList &kSTLList) {
        if (size_ == kSTLList.size_) {
            Node *temp = head_->next;
            Node *stl_list_temp = kSTLList.head_->next;

            for (size_t i = 0; i < size_; i++) {
                if (temp->data != stl_list_temp->data) {
                    return false;
                }

                temp = temp->next;
                stl_list_temp = stl_list_temp->next;
            }

            return true;
        }

        return false;
    }

    bool operator>(const STLList &kSTLList) {
        return head_->next->data > kSTLList.head_->next->data;
    }

    bool operator<(const STLList &kSTLList) {
        return head_->next->data < kSTLList.head_->next->data;
    }

    bool operator>=(const STLList &kSTLList) {
        return head_->next->data >= kSTLList.head_->next->data;
    }

    bool operator<=(const STLList &kSTLList) {
        return head_->next->data <= kSTLList.head_->next->data;
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
        size_t sub;

        if (new_size > size_) {
            sub = new_size - size_;

            for (size_t i = 0; i < sub; i++) {
                PushBack(T());
            }
        } else {
            sub = size_ - new_size;

            for (size_t i = 0; i < sub; i++) {
                PopBack();
            }
        }
    }

    void Resize(size_t new_size, T value) {
        size_t sub;

        if (new_size > size_) {
            sub = new_size - size_;

            for (size_t i = 0; i < sub; i++) {
                PushBack(value);
            }
        } else {
            sub = size_ - new_size;

            for (size_t i = 0; i < sub; i++) {
                PopBack();
            }
        }
    }

    void Insert(Iterator position, T value) {
        Node *temp = &position;
        Node *temp_previous = temp->previous;

        temp->previous = new Node(value);
        temp->previous->next = temp;
        temp->previous->previous = temp_previous;
        temp_previous->next = temp->previous;

        size_++;
    }

    Iterator Erase(Iterator position) {
        Node *temp = &position;
        Node *temp_next = temp->next;

        temp->previous->next = temp_next;
        temp_next->previous = temp->previous;

        delete temp;

        size_--;

        return Iterator(temp_next);
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

    void Remove(T value) {
        Node *temp = head_->next;

        for (size_t i = 0; i < size_; i++) {
            if (temp->data == value) {
                Erase(temp);
            }

            temp = temp->next;
        }
    }

    template<typename Condition>
    void RemoveIf(Condition condition) {
        Node *temp = head_->next;

        for (size_t i = 0; i < size_; i++) {
            if (condition(temp->data)) {
                Erase(temp);
            }

            temp = temp->next;
        }
    }

    void Unique() {
        Node *temp = head_->next;
        Node *temp_next = temp->next;

        for (size_t i = 0; i < size_; i++) {
            while (temp->data == temp_next->data) {
                Erase(temp_next);
                temp_next = temp->next;
            }

            temp = temp->next;
            temp_next = temp->next;
        }
    }

    /// 예외 처리 필요(수정 예정)
    template<typename Condition>
    void Unique(Condition condition) {
        Node *temp = head_->next;
        Node *temp_next = temp->next;

        for (size_t i = 0; i < size_; i++) {
            while (condition(temp->data, temp_next->data)) {
                Erase(temp_next);
                temp_next = temp->next;
            }

            temp = temp->next;
            temp_next = temp->next;
        }
    }

    void Assign(size_t size, T value) {
        Clear();

        for (size_t i = 0; i < size; i++) {
            PushBack(value);
        }
    }

    void Clear() {
        for (size_t i = 0; i < size_; i++) {
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
