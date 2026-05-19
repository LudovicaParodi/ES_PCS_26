#pragma once
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits>
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
 
template<typename I>
unidirected_graph<I> dijkstra(const unidirected_graph<I>& G, I source) {
 
    using dist_node = std::pair<int, I>;
    std::priority_queue<dist_node, std::vector<dist_node>, std::greater<dist_node>> pq;
 
    std::map<I, int> dist;   // distanza minima dal sorgente
    std::map<I, I>   pred;   // predecessore nel cammino minimo
    std::set<I>      visited;
 
    // Inizializzazione
    dist[source] = 0;
    pred[source] = source;
    pq.push({0, source});
 
    while (!pq.empty()) {
        I u = pq.top().second;
        pq.pop();
 
        // Evito doppie visite dello stesso nodo
        if (visited.count(u))
            continue;
        visited.insert(u);
 
        // Tutti gli archi hanno peso 1
        for (I v : G.neighbours(u)) {
            int new_dist = dist[u] + 1;
            // Aggiorno se v non ha ancora una distanza o ho trovato un cammino migliore
            if (!dist.count(v) || new_dist < dist[v]) {
                dist[v] = new_dist;
                pred[v] = u;
                pq.push({new_dist, v});
            }
        }
    }
 
    // Costruisce l'albero dei cammini minimi tramite pred
    unidirected_graph<I> tree;
    for (auto const& [node, par] : pred) {
        if (node != source)
            tree.add_edge(unidirected_edge<I>(par, node));
    }
 
    return tree;
}