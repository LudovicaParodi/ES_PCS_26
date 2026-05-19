#pragma once
#include <fstream>
#include <string>
#include "unidirected_graph.hpp"
 
template<typename I>
void to_dot(const unidirected_graph<I>& G, const std::string& filename) {
    std::ofstream file(filename);
    file << "graph G {\n";
    for (const auto& e : G.all_edges()) {
        file << "    " << e.from() << " -- " << e.to()
             << "\n";
    }
    file << "}\n";
}