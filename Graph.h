#ifndef _GRAPH_H_
#define _GRAPH_H_
#define INF 10000000
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <utility>
#include <list>
#include <map>
template <class T, class C>
class Graph
{
private:
    std::vector<T> vertex;
    std::vector<std::vector<C>> cost_matrix;

protected:
    ;
    void DFShelper(T, bool *);
    void relajacion(T, T, C);

public:
    //Graph();
    std::vector<T>
    getVertex();
    std::vector<std::pair<T, C>> getAdjacentByVertex(T);
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
    int gradeByVertex(T);
    //**Path
    void DFS(T);
    void BFS(T);
    void planar_path();
    void print_cost_matrix();
    //TODO prim,kruskal && dijkstra
    //*prim get the minimum possible value
    //Shortes way in the graph
    C dijkstra(T, T);
};
#include "Graph.hxx"
#endif