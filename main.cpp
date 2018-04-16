#include <iostream>
#include <vector>
#include "myvector.cpp"

int main() {
    myvector<int> v;
    std::vector<int> orig;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    v[0] = 12;
    v[1] = 144;
    v[2] = 13;
    v[3] = 169;

    myvector<int> v2{v};

    cout << v2.getReserved_size() << endl;
    cout << v2.getSize() << endl;

    for (int i = 0; i < v2.getSize(); ++i) {
        cout << v2[i] << endl;
    }

    return 0;
}