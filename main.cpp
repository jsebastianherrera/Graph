#include <iostream>
#include <stdio.h>
#include "Graph.h"
int main(void)
{
    Graph<int, int> g;
    g.insert_vertex(0);
    g.insert_vertex(1);
    g.insert_vertex(2);
    g.insert_vertex(3);
    g.insert_vertex(4);
    g.insert_edge(0, 1, 4);
    g.insert_edge(0, 2, 2);
    g.insert_edge(0, 3, 5);
    g.insert_edge(1, 4, 1);
    g.insert_edge(2, 1, 1);
    g.insert_edge(2, 3, 2);
    g.insert_edge(2, 4, 1);
    g.insert_edge(3, 4, 1);
    g.print_cost_matrix();
    //g.planar_path();
    //g.DFS('A');
    //g.BFS('A');
    std::cout << "Grade '0': " << g.gradeByVertex(0) << std::endl;
    std::vector<std::pair<int, int>> vec = g.getAdjacentByVertex(0);
    typename std::vector<std::pair<int, int>>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
        printf("(%d,%d) ", it->first, it->second);
    int cost = g.dijkstra(0, 4);
    printf("\nMinimum cost 0 to 4:%d\n", cost);
}
