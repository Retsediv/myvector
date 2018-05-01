#include <cstdio>
#include <iostream>
#include "exceptions.h"

const size_t default_vector_size = 4;

template<typename T>
class myvector {
private:
    size_t reserved_size;
    size_t size;
    T *data;

public:
    typedef T *iterator;

    // constructors
    myvector() : reserved_size(default_vector_size), size(0), data(new T[default_vector_size]) {}

    explicit myvector(size_t n) : reserved_size(n), size(0), data(new T[n]) {}

    myvector(size_t n, T init_value) : reserved_size(n + default_vector_size), size(n), data(new T[n]) {
        for (size_t i = 0; i < n; ++i) {
            data[i] = init_value;
        }
    }

    myvector(const myvector<T> &v) : reserved_size(v.getReserved_size()), size(v.getSize()),
                                     data(new T[v.getReserved_size()]) {
        for (size_t i = 0; i < v.getSize(); ++i) {
            data[i] = v.at(i);
        }
    }

    // destructor
    ~myvector() { delete[] data; }

    // getters
    inline size_t getSize() const { return size; };

    inline size_t getReserved_size() const { return reserved_size; };

    inline T *getData() const { return data;};

    // methods
    void push_back(const T &x);

    void pop_back();

    T &front() const;

    const T &at(size_t index) const;
    T &at(size_t index);
    bool empty() const;

    void clear();

    // operators
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    void resize(size_t new_size);

    iterator begin() { return data; };
    iterator end() { return data + size; };
};

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

        for (size_t i = 0; i < size; ++i) {
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
const T &myvector<T>::operator[](size_t index) const {
    return data[index];
}

template<typename T>
T &myvector<T>::at(size_t index) {
    if (index < size) {
        return data[index];
    }

    throw OutOfBoundException();
}

template<typename T>
const T &myvector<T>::at(size_t index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }

    throw OutOfBoundException();
}

template<typename T>
T &myvector<T>::front() const {
    if (!empty()) {
        return data[size - 1];
    }

    throw IsEmptyException();
}

template<typename T>
void myvector<T>::pop_back(){
    if (empty()) {
        throw IsEmptyException();
    }

    // TODO: Call the destructor of last element
    // (data[size - 1]).~T();

    --size;
}

template<typename T>
void myvector<T>::clear() {
    if (!empty()) {
        // TODO: use pop to call destructors of all objects
//        for (size_t i = 0; i < size; ++i) {
//            pop();
//        }

        size = 0;
        reserved_size = default_vector_size;
        data = new T[reserved_size];
    }
}

template<typename T>
bool myvector<T>::empty() const {
    return size == 0;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::begin() {
    return data;
}

template<typename T>
typename myvector<T>::iterator myvector<T>::end() {
    return data + size;
}