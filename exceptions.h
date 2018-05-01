#include <exception>

#ifndef MYVECTOR_EXCEPTIONS_H
#define MYVECTOR_EXCEPTIONS_H

class MyVectorException : public std::exception {
public:
    const char *what() const throw() {
        return "Error while working with `myvector`";
    }
};

class OutOfBoundException : public MyVectorException {
public:
    const char *what() const throw() {
        return "Invalid index for array";
    }
};

class IsEmptyException : public MyVectorException {
public:
    const char *what() const throw() {
        return "myvector is empty to get data from it";
    }
};

#endif //MYVECTOR_EXCEPTIONS_H
