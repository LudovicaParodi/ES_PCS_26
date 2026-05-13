#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main() {

    unidirected_graph<int> g;

    g.add_edge({3,5});
    g.add_edge({1,2});
    g.add_edge({2,4});

    //Stampo gli archi
    std::cout << "Archi del grafo:\n";

    for (const auto& e : g.all_edges()) {

        std::cout << e << "\n";
    }


    //Stampo i nodi del grafo
    std::cout << "\nNodi del grafo:\n";

    for (const auto& key : g.all_nodes()) {

        std::cout << key << " ";
    }

    std::cout << "\n";


    //Stampo i vicini del nodo 2
    std::cout << "\nVicini del nodo 2:\n";

    for (const auto& x : g.neighbours(2)) {

        std::cout << x << " ";
    }

    std::cout << "\n";


    //Stampo l'ID dell'arco (2,4)
    std::cout << "\nID dell'arco (2,4): ";

    std::cout << g.edge_number({2,4}) << "\n";


    //Stampo l'arco con ID 1
    std::cout << "\nArco con ID 1: ";

    std::cout << g.edge_at(1) << "\n";


    //Differenza tra due grafi
    unidirected_graph<int> g2;

    g2.add_edge({1,2});

    auto diff = g - g2;

    std::cout << "\nDifferenza g - g2:\n";

    for (const auto& e : diff.all_edges()) {

        std::cout << e << "\n";
    }

    return 0;
}