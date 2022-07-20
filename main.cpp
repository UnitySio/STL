#include <iostream>
#include <stdlib.h>
#include "stl_vector.h"
#include "stl_pair.h"
#include "stl_list.h"
#include <list>
using namespace std;

/*bool Condition(int i) {
    return ((i % 2) == 0);
}*/

int main() {
    STLList<int> l;

    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    l.PushBack(4);
    l.PushBack(1);

    l.Unique([](int a, int b) {
        return a != b;
    });

    /*l.RemoveIf([](int i) {
        return ((i % 2) == 0);
    });*/

    //l.RemoveIf(Condition);

    STLList<int>::Iterator it;

    for (it = l.Begin(); it != l.End(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
