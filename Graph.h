#ifndef _GRAPH_H_
#define _GRAPH_H_
#define MAX_VERTEX 1024
#include <list>
#include <vector>
#include <iostream>
template <class T>
class Graph
{
private:
    std::vector<T> vertex;
    int **adjacency_matrix;

public:
    Graph();
    std::vector<T> getVertex();
    int **getAdjacency_matrix();
    //Retorn count vertex
    int count_vertex();
    //Retorn count edges
    int count_edges();
    //Insert vertex
    bool insert_vertex(T);
    bool search_vertex(T);
    int getPositionByVertex(T);
    bool insert_edge(T, T);
    void print_adjacency_matrix();
};
#include "Graph.hxx"
#endif