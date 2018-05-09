#include <cstddef>
//#include <bits/valarray_after.h>
#include "exceptions.h"

template <typename T, size_t N>
class fixedvector {
private:
    T *data = new T[N];
public:
    constexpr fixedvector(T init_value) {
        static_assert(N > 0, "Vector size must be greater than 0.");
        fill(init_value);
    }

    constexpr fixedvector() : fixedvector(0){}

    // destructor
    ~fixedvector() { delete[] data; }

    // getters
    constexpr inline size_t getSize() const { return N; };
    constexpr inline T *getData() const { return data;};

    // methods
    constexpr void fill(T value){
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

    constexpr const T &at(size_t index) const;
    constexpr T &at(size_t index);

    constexpr T &operator[](size_t index);
    constexpr const T &operator[](size_t index) const;

    constexpr const T &front() const;

private:

};

template<typename T, size_t N>
constexpr const T &fixedvector<T, N>::at(size_t index) const {
    if (index >= 0 && index < N) {
        return data[index];
    }

    throw OutOfBoundException();
}

template<typename T, size_t N>
constexpr T &fixedvector<T, N>::at(size_t index) {
    if (index >= 0 && index < N) {
        return data[index];
    }

    throw OutOfBoundException();
}

template<typename T, size_t N>
constexpr T &fixedvector<T, N>::operator[](size_t index) {
    return data[index];
}

template<typename T, size_t N>
constexpr const T &fixedvector<T, N>::operator[](size_t index) const {
    return data[index];
}

template<typename T, size_t N>
constexpr const T &fixedvector<T, N>::front() const {
    return at(N-1);
}
