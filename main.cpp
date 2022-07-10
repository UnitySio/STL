#include <iostream>
#include <vector>
#include "stl_vector.h"
using namespace std;

int main() {
    STLVector<string> vec;

    for (int i = 0; i < 10; i++) {
        vec.PushBack("N : " + to_string(i + 1));
    }

    STLVector<string> t_vec;

    for (int i = 0; i < 5; i++) {
        t_vec.PushBack("Temp N : " + to_string(i + 1));
    }

    STLVector<string>::Iterator it;

    vec.Insert(vec.Begin() + 3, t_vec.Begin() + 2, t_vec.End());

    for (it = vec.Begin(); it != vec.End(); ++it) {
        cout << *it << endl;
    }

    STLVector<string>::ReverseIterator rit;

    for (rit = vec.RBegin(); rit != vec.REnd(); ++rit) {
        cout << *rit << endl;
    }

    return 0;
}
