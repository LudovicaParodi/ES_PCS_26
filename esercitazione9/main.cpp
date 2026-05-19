#include <iostream>
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "FIFO.hpp"
#include "LIFO.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "to_dot.hpp"

int main() {
    unidirected_graph<int> G;
    G.add_edge(unidirected_edge<int>(1, 2));
    G.add_edge(unidirected_edge<int>(1, 3));
    G.add_edge(unidirected_edge<int>(2, 3));
    G.add_edge(unidirected_edge<int>(2, 4));
    G.add_edge(unidirected_edge<int>(3, 5));
    G.add_edge(unidirected_edge<int>(4, 5));
    G.add_edge(unidirected_edge<int>(4, 6));
    G.add_edge(unidirected_edge<int>(5, 7));
    G.add_edge(unidirected_edge<int>(6, 7));
    G.add_edge(unidirected_edge<int>(6, 8));
    G.add_edge(unidirected_edge<int>(7, 8));

    // --- DFS iterativo ---
    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    to_dot(dfsG, "dfs_tree.dot");   // genera il file .dot
    std::cout << "DFS iterativo completato -> dfs_tree.dot\n";

    // --- DFS ricorsivo ---
    auto rdfsG = recursive_dfs(G, 1);
    to_dot(rdfsG, "recursive_dfs_tree.dot");
    std::cout << "DFS ricorsivo completato -> recursive_dfs_tree.dot\n";

    // --- BFS ---
    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    to_dot(bfsG, "bfs_tree.dot");   // genera il file .dot
    std::cout << "BFS completato -> bfs_tree.dot\n";

    return 0;
}