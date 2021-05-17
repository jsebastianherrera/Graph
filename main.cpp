#include <iostream>
#include "Graph.h"
int main(void)
{
    Graph<int, int> g;
    g.insert_vertex(1);
    g.insert_vertex(2);
    g.insert_vertex(3);
    g.insert_vertex(4);
    g.insert_edge(1, 2, 2);
    g.insert_edge(1, 4, 3);
    g.insert_edge(2, 1, 6);
    g.insert_edge(2, 3, 5);
    g.insert_edge(2, 4, 2);
    g.insert_edge(3, 1, 3);
    g.insert_edge(4, 2, 5);
    g.insert_edge(4, 3, 6);
    g.print_cost_matrix();
    g.remove_vertex(4);
    g.remove_edge(3, 1);
    g.print_cost_matrix();
}
