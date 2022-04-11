// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

struct SYM {
    char ch;
    int prior;
};
template<typename T, int size>
class TPQueue {
private:
    T arr[20];
    int first, last;
public:
    TPQueue() :first(0), last(0) { }
    void push(T x) {
        if (last - first >= size) {
            throw std::string("Full!");
        } else {
            int s = last++;
            while ((arr[s % size].prior < x.prior) && (--s >= first)) {
                arr[(s + 1) % size] = arr[s % size];
            }
            arr[(s + 1) % size] = x;
        }     
    }
    T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

#endif  // INCLUDE_TPQUEUE_H_
