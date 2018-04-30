#include <cstdio>
#include <iostream>

const size_t default_vector_size = 4;

template<typename T>
class myvector {
private:
    size_t reserved_size;
    size_t size;
    T *data;

    void resize(size_t new_size);

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
    size_t getSize() const;

    size_t getReserved_size() const;

    T *getData() const;

    // methods
    void push_back(const T &x);

    void pop();

    T &front() const;

    const T &at(size_t index) const;

    iterator begin();

    iterator end();

    bool empty() const;

    void clear();

    // operators
    T &operator[](size_t index);

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
const T &myvector<T>::at(size_t index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }

    // TODO: make own exception
    throw std::out_of_range("Invalid index for array");
}

template<typename T>
T &myvector<T>::front() const {
    if (!empty()) {
        return data[size - 1];
    }

    // TODO: make own exception and refactor it
    throw std::out_of_range("No items for front()");
}

template<typename T>
void myvector<T>::pop() {
    if (!empty()) {
        // Call the destructor of last element
//        (data[size - 1]).~T();

        --size;
    }
}

template<typename T>
void myvector<T>::clear() {
    if (!empty()) {
        // use pop to call destructors of all objects
        size_t n = size;
        for (size_t i = 0; i < n; ++i) {
            pop();
        }

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