#include <iostream>
#include "Graph.h"
int main(void)
{
    Graph<int> g;
    /*int **mat;
    std::cout << "Count vertex:" << g.count_vertex() << std::endl;
    std::cout << "Count edges:" << g.count_edges() << std::endl;
    mat = g.geyAdjacency_matrix();
    std::cout << "Insert:" << g.insert_vertex(1) << std::endl;
    std::cout << "Insert:" << g.insert_vertex(2) << std::endl;
    //Try to insert repeated value
    std::cout << "Insert:" << g.insert_vertex(1) << std::endl;
    std::cout << "Insert edge:" << g.insert_edge(1, 2) << std::endl;
    g.insert_edge(1, 1);
    std::cout << "Print matrix" << std::endl;
    */
    g.insert_vertex(1);
    g.insert_vertex(2);
    g.insert_vertex(3);
    g.insert_vertex(4);
    g.insert_edge(1, 2);
    g.insert_edge(1, 2);
    g.insert_edge(1, 4);
    g.insert_edge(1, 4);
    g.insert_edge(1, 4);
    g.insert_edge(2, 1);
    g.insert_edge(2, 1);
    g.insert_edge(2, 1);
    g.insert_edge(2, 1);
    g.insert_edge(2, 1);
    g.insert_edge(2, 1);
    g.insert_edge(2, 3);
    g.insert_edge(2, 3);
    g.insert_edge(2, 3);
    g.insert_edge(2, 3);
    g.insert_edge(2, 3);
    g.insert_edge(2, 4);
    g.insert_edge(2, 4);
    g.insert_edge(3, 1);
    g.insert_edge(3, 1);
    g.insert_edge(3, 1);
    g.insert_edge(4, 2);
    g.insert_edge(4, 2);
    g.insert_edge(4, 2);
    g.insert_edge(4, 2);
    g.insert_edge(4, 2);
    g.insert_edge(4, 3);
    g.insert_edge(4, 3);
    g.insert_edge(4, 3);
    g.insert_edge(4, 3);
    g.insert_edge(4, 3);
    g.insert_edge(4, 3);
    g.print_adjacency_matrix();
}
