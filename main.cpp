#include <iostream>
#include <vector>
#include "STLVector.h"
using namespace std;

int main() {
    STLVector<int> a;

    for (int i = 0; i < 10; i++) {
        a.PushBack(i + 1);
    }

    STLVector<int>::iterator iter = a.Begin();

    iter -= 5;
    cout << iter[0] << endl;

    /*for (; iter != a.End(); ++iter) {
        cout << *iter << endl;
    }*/

    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }

    vector<int>::iterator viter = v.begin();

    viter += 10;

    cout << viter[0] << endl;

    return 0;
}
