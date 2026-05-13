#include <iostream>
#include "unidirected_edge.hpp"

int main() {

    unidirected_edge<int> e1(5,2);
    unidirected_edge<int> e2(2,5);
    unidirected_edge<int> e3(1,7);

    //Testo se mi riordina automaticamente scrivendo (2,5)
    std::cout << "Arco e1: " << e1 << "\n";

    //Testo from() e to()
    std::cout << "from(): " << e1.from() << "\n";
    std::cout << "to(): " << e1.to() << "\n";

    //Testo l'operator ==

    if (e1 == e2) {
        std::cout << "e1 ed e2 sono uguali\n";
    }
    else {
        std::cout << "e1 ed e2 NON sono uguali\n";
    }

    if (e1 == e3) {
        std::cout << "e1 ed e3 sono uguali\n";
    }
    else {
        std::cout << "e1 ed e3 NON sono uguali\n";
    }

    //Testo l'operator < in due casi

    if (e3 < e1) {
        std::cout << e3 << " viene prima di " << e1 << "\n";
    }
    else {
        std::cout << e3 << " viene dopo di " << e1 << "\n";
    }


    if (e2 < e3) {
        std::cout << e2 << " viene prima di " << e3 << "\n";
    }
    else {
        std::cout << e2 << " viene dopo di " << e3 << "\n";
    }


    return 0;
}