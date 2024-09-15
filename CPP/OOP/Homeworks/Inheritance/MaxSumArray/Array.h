#pragma once
#include <memory>

template<typename T>
class Array
{
    std::shared_ptr<T> data;
    size_t size;

public:
    Array(size_t sz) {
        size = sz;
        data.reset(new T[sz]);
    }
    Array(int sz) {
        size = sz;
        data.reset(new T[sz]);
    }

    size_t getSize() { return size; }

    T& operator[] (size_t idx) {
        return data.get()[idx];
    }

    struct iterator {
        T* value;
        iterator(T* ptr) : value(ptr) {};
        iterator& operator++ () { value++; return *this; }
        bool operator!=(const iterator& other) { return other.value != value; }
        T& operator*() const { return *value; }
    };

    iterator begin() { return iterator(data.get()); }
    iterator end() { return iterator(data.get() + size); }
};