#include <iostream>
#include <stack>
#pragma once

template<typename T> 

class lifo {
private:

    std::stack<T> s;

public:

    lifo() = default;   //costruttore di default

    void put(const T& x) {
        s.push(x);         // inserisce in cima
    }

    T get() {               //legge con top e rimuove con pop dalla cima
        T x = s.top();
        s.pop();
        return x;
    }

    bool empty() { return s.empty(); }  //verifica se è vuoto
};