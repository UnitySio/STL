#include <iostream>
#include <stdlib.h>
#include "stl_vector.h"
#include "stl_pair.h"
#include "stl_list.h"
#include <list>
using namespace std;

int main() {
    STLList<int> l;

    for (size_t i = 0; i < 10; i++) {
        l.PushFront(i + 1);
    }

    for (size_t i = 0; i < 10; i++) {
        l.PopBack();
    }

    l.Clear();

    cout << l.Front() << endl;
    cout << l.Back() << endl;

    return 0;
}
