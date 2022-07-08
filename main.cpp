#include <iostream>
#include <vector>
#include "STLVector.h"
using namespace std;

int main() {
    STLVector v;

    for (int i = 0; i < 5; i++) {
        v.PushBack(i + 1);
    }

    v.Resize(10);

    for (int i = 0; i < v.Size(); i++) {
        cout << v.At(i) << endl;
    }

    cout << "----------" << endl;

    cout << v.Size() << endl;
    cout << v.Capacity() << endl;

    cout << "----------" << endl;
    return 0;
}
