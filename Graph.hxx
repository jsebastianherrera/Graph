#include "Graph.h"
template <class T, class C>
std::vector<T> Graph<T, C>::getVertex()
{
    return this->vertex;
}
template <class T, class C>
std::vector<std::vector<C>> Graph<T, C>::getCost_matrix()
{
    return this->cost_matrix;
}
template <class T, class C>
int Graph<T, C>::count_vertex()
{
    return this->vertex.size();
}
template <class T, class C>
int Graph<T, C>::count_edges()
{
    int cont = 0;
    for (int i = 0; i < this->count_vertex(); i++)
    {
        for (int j = 0; j < this->count_vertex(); j++)
        {
            if (this->cost_matrix[i][j] != 0)
                cont += this->cost_matrix[i][j];
        }
    }
    return cont;
}
template <class T, class C>
bool Graph<T, C>::insert_vertex(T vertex)
{
    if (!this->search_vertex(vertex))
    {
        this->vertex.push_back(vertex);
        std::vector<C> col;
        for (int i = 0; i < this->count_vertex(); i++)
            col.push_back(0);
        this->cost_matrix.push_back(col);
        for (int i = 0; i < this->count_vertex(); i++)
        {
            if (this->cost_matrix[i].size() < this->count_vertex())
                for (int j = count_vertex() - 1; j < this->count_vertex(); ++j)
                    this->cost_matrix[i].push_back(0);
        }
        return true;
    }
    return false;
}
template <class T, class C>
bool Graph<T, C>::search_vertex(T vertex)
{
    typename std::vector<T>::iterator it;
    for (it = this->vertex.begin(); it != this->vertex.end(); it++)
    {
        if (*it == vertex)
            return true;
    }
    return false;
}
template <class T, class C>
int Graph<T, C>::getPositionByVertex(T vertex)
{
    for (int i = 0; i < this->count_vertex(); i++)
    {
        if (this->vertex[i] == vertex)
            return i;
    }
    return -1;
}
template <class T, class C>
bool Graph<T, C>::search_edge(T origin, T destination)
{
    if (this->search_vertex(origin) && this->search_vertex(destination))
    {
        int i = this->getPositionByVertex(origin);
        int j = this->getPositionByVertex(destination);
        if (this->cost_matrix[i][j] != 0)
            return true;
    }
    return false;
}
template <class T, class C>
C Graph<T, C>::getCostByEdge(T origin, T destination)
{
    if (this->search_edge(origin, destination))
    {
        int i = this->getPositionByVertex(origin);
        int j = this->getPositionByVertex(destination);
        return this->cost_matrix[i][j];
    }
    return 0;
}
template <class T, class C>
bool Graph<T, C>::insert_edge(T origin, T destination, C cost)
{
    if (this->search_vertex(origin) && this->search_vertex(destination))
    {
        int i = this->getPositionByVertex(origin);
        int j = this->getPositionByVertex(destination);
        if (this->cost_matrix[i][j] == 0)
        {
            this->cost_matrix[i][j] = cost;
            return true;
        }
        else
            return false;
    }
    return false;
}
template <class T, class C>
void Graph<T, C>::print_cost_matrix()
{
    std::cout << std::endl;
    for (int i = 0; i < this->cost_matrix.size(); i++)
    {
        for (int j = 0; j < this->cost_matrix[i].size(); j++)
            std::cout << "\t" << this->cost_matrix[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
template <class T, class C>
bool Graph<T, C>::remove_vertex(T vertex)
{
    int pos = this->getPositionByVertex(vertex);
    if (pos != -1)
    {
        //remove rows
        this->cost_matrix.erase(this->cost_matrix.begin() + pos);
        //remove columns
        for (int i = 0; i < this->cost_matrix.size(); i++)
            this->cost_matrix[i].erase(this->cost_matrix[i].begin() + pos);
        this->vertex.erase(this->vertex.begin() + pos);
        return true;
    }
    return false;
}
template <class T, class C>
bool Graph<T, C>::remove_edge(T origin, T destination)
{
    if (search_edge(origin, destination))
    {
        int i = this->getPositionByVertex(origin);
        int j = this->getPositionByVertex(destination);
        this->cost_matrix[i][j] = 0;
        return true;
    }
    return false;
}
template <class T, class C>
void Graph<T, C>::planar_path()
{
    for (int j = 0; j < this->count_vertex() - 1; j++)
        std::cout << this->vertex[j] << ",";
    std::cout << this->vertex[this->count_vertex() - 1] << std::endl;
}