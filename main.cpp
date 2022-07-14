#include <iostream>
#include "stl_vector.h"
#include "stl_pair.h"
#include "stl_list.h"
#include <list>
using namespace std;

int main() {
    STLList<int> l;

    for (int i = 0; i < 10; i++) {
        l.PushBack(10);
    }

    cout << l.Size() << endl;

    if (l.Empty()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    l.Clear();

    cout << l.Size() << endl;

    if (l.Empty()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
