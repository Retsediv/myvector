#include <cstdio>
#include <iostream>

const size_t default_vector_size = 4;

using std::cout;
using std::endl;
using std::copy;

template<typename T>
class myvector {
private:
    size_t size;
    size_t reserved_size;

    T *data;

    void resize(size_t new_size);

public:
    // constructors
    myvector() : reserved_size(default_vector_size), size(0), data(new T[default_vector_size]) {}

    myvector(size_t n) : reserved_size(n), size(0), data(new T[n]) {}

    // destructor
    ~myvector() { delete[] data; }

    // getters
    size_t getSize() const;

    size_t getReserved_size() const;

    T *getData() const;

    // methods
    void push_back(const T &x);

    T at(size_t index);

    // operators
    T& operator[](size_t index);

};

template<typename T>
size_t myvector<T>::getSize() const {
    return size;
}

template<typename T>
size_t myvector<T>::getReserved_size() const {
    return reserved_size;
}

template<typename T>
T *myvector<T>::getData() const {
    return data;
}

template<typename T>
void myvector<T>::push_back(const T &x) {
    if (size == reserved_size) {
        // extend size
        resize(size + default_vector_size);
    }

    data[size] = x;
    size++;
}

template<typename T>
void myvector<T>::resize(size_t new_size) {
    if (new_size > reserved_size) {
        T *new_data = new T[new_size];

        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;

        reserved_size = new_size;
    }
}

template<typename T>
T &myvector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
T myvector<T>::at(size_t index) {
    if(index >= 0 && index <= size){
        return data[index];
    }

    // TODO: make own exception
    throw std::out_of_range("Invalid index for array");
}
