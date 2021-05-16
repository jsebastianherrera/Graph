#include "Graph.h"
template <class T>
Graph<T>::Graph()
{
    //Reserve memory for rows
    this->adjacency_matrix = new int *[MAX_VERTEX];
    //Reserve memory for columns
    for (int i = 0; i < MAX_VERTEX; i++)
        *(adjacency_matrix + i) = new int[MAX_VERTEX];
}
template <class T>
std::vector<T> Graph<T>::getVertex()
{
    return this->vertex;
}
template <class T>
int **Graph<T>::getAdjacency_matrix()
{
    return this->adjacency_matrix;
}
template <class T>
int Graph<T>::count_vertex()
{
    return this->vertex.size();
}
template <class T>
int Graph<T>::count_edges()
{
    int cont = 0;
    for (int i = 0; i < this->count_vertex(); i++)
    {
        for (int j = 0; j < this->count_vertex(); j++)
        {
            if (*(*(adjacency_matrix + i) + j) != 0)
                cont += *(*(adjacency_matrix + i) + j);
        }
    }
    return cont;
}
template <class T>
bool Graph<T>::insert_vertex(T vertex)
{
    if (this->search_vertex(vertex))
    {
        this->vertex.push_back(vertex);
        for (int j = 0; j < this->count_vertex(); j++)
            *(*(this->adjacency_matrix + (this->count_vertex() - 1)) + j) = 0;
        return true;
    }
    return false;
}
template <class T>
bool Graph<T>::search_vertex(T vertex)
{
    typename std::vector<T>::iterator it;
    for (it = this->vertex.begin(); it != this->vertex.end(); it++)
    {
        if (*it == vertex)
            return false;
    }
    return true;
}
template <class T>
int Graph<T>::getPositionByVertex(T vertex)
{
    for (int i = 0; i < this->count_vertex(); i++)
    {
        if (this->vertex[i] == vertex)
            return i;
    }
    return -1;
}
template <class T>
bool Graph<T>::insert_edge(T origin, T destination)
{
    if (this->search_vertex(origin) == 0 && this->search_vertex(destination) == 0)
    {
        int i = this->getPositionByVertex(origin);
        int j = this->getPositionByVertex(destination);
        (*(*(this->adjacency_matrix + i) + j))++;
        return true;
    }
    return false;
}
template <class T>
void Graph<T>::print_adjacency_matrix()
{
    std::cout << std::endl;
    for (int i = 0; i < this->count_vertex(); i++)
    {
        for (int j = 0; j < this->count_vertex(); j++)
            std::cout << "\t" << *(*(this->adjacency_matrix + i) + j);
        std::cout << std::endl;
    }
}