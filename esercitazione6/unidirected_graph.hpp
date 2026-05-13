#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include "unidirected_edge.hpp"

template<typename I> 

class unidirected_graph {
private:
    // Mappa: Nodo -> Set di vicini
    std::map<I, std::set<I>> adj_list;
    
    // Mappa per associare a ogni arco un numero progressivo
    std::map<unidirected_edge<I>, int> edge_to_id;
    
    // Vector per recuperare l'arco dato l'ID (indice del vector = ID)
    std::vector<unidirected_edge<I>> id_to_edge;

public:
    unidirected_graph() = default;
    unidirected_graph(const unidirected_graph& other) = default;  //costruttore di copia

    void add_edge(const unidirected_edge<I>& e) {
        I u = e.from();
        I v = e.to();

        adj_list[u].insert(v);
        adj_list[v].insert(u);

        //se l'arco non esiste già
        if (edge_to_id.count(e) == 0) {
            int new_id = id_to_edge.size();

            edge_to_id[e] = new_id;

            id_to_edge.push_back(e);
        }
    }

    std::set<I> neighbours(I node) const {
        return adj_list.at(node);   //data una chiave restituisce valore associato
    }

    std::vector<unidirected_edge<I>> all_edges() const {
        return id_to_edge;
    }

    std::set<I> all_nodes() const {
        std::set<I> nodes;
        for (auto const& [node, neighbors] : adj_list) {
            nodes.insert(node);
        }
        return nodes;
    }

    int edge_number(const unidirected_edge<I>& e) const {
        auto it = edge_to_id.find(e);

        if (it != edge_to_id.end()) {
            return it->second; // Arco trovato: restituisco l'ID
        } else {
            return -1;         // Arco non trovato: restituisco -1
        }
            }

    unidirected_edge<I> edge_at(int id) const {
        return id_to_edge.at(id); 
    }

    // Operatore differenza: G3 = G1 - G2 (archi in G1 non in G2)
    unidirected_graph operator-(const unidirected_graph<int>& other) const {

        unidirected_graph<I> result;

        for (const auto& e : id_to_edge) {
            // Se l'arco e non è presente nel grafo 'other'
            if (other.edge_to_id.count(e) == 0) {
                result.add_edge(e);
            }
        }
        return result;
    }
};
