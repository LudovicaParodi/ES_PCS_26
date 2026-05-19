#include <iostream>
#include <set>
#include "unidirected_graph.hpp"

template<typename I>
void recursive_dfs_helper(const unidirected_graph<I>& G, I current,
                           std::set<I>& visited, unidirected_graph<I>& tree) {
    visited.insert(current);
 
    for (I neighbor : G.neighbours(current)) {
        if (visited.count(neighbor) == 0) {
            tree.add_edge(unidirected_edge<I>(current, neighbor));
            recursive_dfs_helper(G, neighbor, visited, tree);
        }
    }
}
 
// Visita DFS ricorsiva
template<typename I>
unidirected_graph<I> recursive_dfs(const unidirected_graph<I>& G, I source) {
    unidirected_graph<I> tree;
    std::set<I> visited;
    recursive_dfs_helper(G, source, visited, tree);
    return tree;
}