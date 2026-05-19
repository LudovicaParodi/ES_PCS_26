#include <iostream>
#include <queue>
#pragma once

template<typename T> 

class fifo {
private:

    std::queue<T> q;

public:

    fifo() = default;   //costruttore di default

    void put(const T& x) {
        q.push(x);         // inserisce in cima
    }

    T get() {               //legge con top e rimuove con pop dalla cima
        T x = q.front(); 
        q.pop();
        return x;
    }

    bool empty() { return q.empty(); }  //verifica se è vuoto
};