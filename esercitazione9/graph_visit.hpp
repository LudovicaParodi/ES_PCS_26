#include <iostream>
#include <set>
#include "unidirected_graph.hpp"
#include "FIFO.hpp"   
#include "LIFO.hpp"   

template<typename I, typename Container>
unidirected_graph<I> graph_visit(const unidirected_graph<I>& G, I source, Container& container) {
    
    unidirected_graph<I> tree;          // albero risultante dalla visita
    std::set<I> visited;                // nodi già visitati

    container.put(source);
    visited.insert(source);

    while (!container.empty()) {
        I current = container.get();    // FIFO → BFS,  LIFO → DFS

        for (I neighbor : G.neighbours(current)) {
            if (visited.count(neighbor) == 0) {     // se non ancora visitato
                visited.insert(neighbor);
                container.put(neighbor);
                tree.add_edge(unidirected_edge<I>(current, neighbor));  // aggiungo arco all'albero
            }
        }
    }
    return tree;
}