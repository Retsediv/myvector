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
    v[100] = 12;

    for (int i = 0; i < 10; ++i) {
        cout << v[i] << endl;
    }

    return 0;
}