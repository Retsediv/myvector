#include <iostream>
#include <vector>
#include "myvector.h"

using std::cout;
using std::endl;
using std::copy;
using std::vector;

int main() {
//    vector<vector<int>> i;
//    vector<int> a{1};
//    vector<int> a1{100, 4};
//    vector<int> a2{};
//    a2.push_back(1);
//    a2.push_back(1);
//    a2.push_back(1);
//    a2.push_back(1);
//
//    i.push_back(a);
//    i.push_back(a1);
//    i.push_back(a2);
//
//    i.pop_back();
//    cout << i.size() << endl;
//    cout << i[2].size() << endl;

    vector<int> a;

    myvector<int> v;

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

    for (size_t i = 0; i < v2.getSize(); ++i) {
        cout << v2[i] << endl;
    }

    cout << v2.front() << endl;
    v2.pop();
    cout << v2.getReserved_size() << endl;
    cout << v2.getSize() << endl;

    cout << "START ITERATOR!!!" << endl;
    myvector<int>::iterator it;
    for(it = v2.begin(); it != v2.end(); it++)    {
        cout<< *it << endl;
    }

    cout << "START FOREACH!!!" << endl;
    for(auto x: v2){
        cout << x << endl;
    }


    cout << "CLEAR" << endl;
    v2.clear();
    cout << v2.getReserved_size() << endl;
    cout << v2.getSize() << endl;

    return 0;
}