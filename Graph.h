#ifndef _GRAPH_H_
#define _GRAPH_H_
#define MAX_VERTEX 1024
#include <list>
#include <vector>
#include <iostream>
template <class T, class C>
class Graph
{
private:
    std::vector<T> vertex;
    std::vector<std::vector<T>> cost_matrix;
    // int **adjacency_matrix;

public:
    //Graph();
    std::vector<T> getVertex();
    std::vector<std::vector<C>> getCost_matrix();
    int count_vertex();
    int count_edges();
    bool insert_vertex(T);
    bool search_vertex(T);
    bool search_edge(T, T);
    bool remove_edge(T, T);
    C getCostByEdge(T, T);
    int getPositionByVertex(T);
    bool insert_edge(T, T, C);
    bool remove_vertex(T);
    void planar_path();
    void print_cost_matrix();
};
#include "Graph.hxx"
#endif