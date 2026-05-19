#include <iostream>
#include <algorithm>
#pragma once

template<typename I> 
class unidirected_edge {
    int v1;
    int v2;

    public:
    unidirected_edge(int a, int b) {
        if (a<b) {
            v1 = a;
            v2 = b;
        } else {
            v1 = b;
            v2 = a;
        }        
    }
    int from() const {return v1;}
    int to() const {return v2;}

    bool operator<(const unidirected_edge& other) const {
        if (from() < other.from()) return true;
        if (from() > other.from()) return false;
        return to() < other.to();
    }

    bool operator==(const unidirected_edge& other) const {
        return from() == other.from() && to() == other.to();
    }
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<I>& e) {
    return os << "(" << e.from() << "," << e.to() << ")";
}