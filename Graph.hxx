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
template <class T, class C>
int Graph<T, C>::gradeByVertex(T vertex)
{
    int pos = this->getPositionByVertex(vertex), rt = 0;
    //Check if the vertex exists
    if (pos != -1)
    {
        //*go through all columns
        for (int i = 0; i < this->count_vertex(); i++)
            if (this->cost_matrix[pos][i] != 0)
                rt++;
    }
    else
        rt = -1;
    return rt;
}
template <class T, class C>
void Graph<T, C>::DFShelper(T v, bool *visited)
{
    std::cout << v << " ";
    visited[this->getPositionByVertex(v)] = true;
    for (int i = 0; i < this->count_vertex(); i++)
    {
        if (this->search_edge(v, this->vertex[i]) && !visited[i])
            this->DFShelper(this->vertex[i], visited);
    }
}
template <class T, class C>
void Graph<T, C>::DFS(T begin)
{
    if (this->search_vertex(begin))
    {
        bool visited[this->count_vertex()];
        for (int i = 0; i < this->count_vertex(); i++)
            visited[i] = 0;
        this->DFShelper(begin, visited);
    }
    else
        std::cout << "Vertex not found" << std::endl;
    std::cout << std::endl;
}
template <class T, class C>
void Graph<T, C>::BFS(T vec)
{

    if (this->search_vertex(vec))
    {
        bool visited[this->count_vertex()];
        for (int i = 0; i < this->count_vertex(); i++)
            visited[i] = 0;
        std::queue<T> q;
        q.push(vec);
        while (!q.empty())
        {
            T v = q.front();
            q.pop();
            if (!visited[this->getPositionByVertex(v)])
            {
                visited[this->getPositionByVertex(v)] = true;
                std::cout << v << " ";
                for (int i = 0; i < this->count_vertex(); i++)
                    if (this->search_edge(v, this->vertex[i]) && !visited[i])
                        q.push(this->vertex[i]);
            }
        }
    }
    else
        std::cout << "Vertex not found" << std::endl;
    std::cout << std::endl;
}
template <class T, class C>
std::vector<std::pair<T, C>> Graph<T, C>::getAdjacentByVertex(T vertex)
{
    std::vector<std::pair<T, C>> rt;
    if (this->search_vertex(vertex))
    {
        for (int j = 0; j < this->count_vertex(); j++)
        {
            if (this->cost_matrix[getPositionByVertex(vertex)][j] != 0)
            {
                std::pair<T, C> pair = std::make_pair(this->vertex[j], getCostByEdge(vertex, this->vertex[j]));
                rt.push_back(pair);
            }
        }
    }
    return rt;
}
//T graph type and C means cost type
template <class T, class C>
C Graph<T, C>::dijkstra(T origin, T dest)
{
    //Distance cost
    C dist[this->count_vertex()];
    bool visited[this->count_vertex()];
    std::priority_queue<std::pair<C, T>, std::vector<std::pair<C, T>>, std::greater<std::pair<C, T>>> pq;
    if (this->search_vertex(origin))
    {
        for (int i = 0; i < this->count_vertex(); i++)
        {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[getPositionByVertex(origin)] = 0;
        pq.push(std::make_pair(dist[getPositionByVertex(origin)], origin));
        //std::cout << dist[getPositionByVertex(origin)] << std::endl;
        while (!pq.empty())
        {
            std::pair<C, T> p = pq.top();
            T u = p.second;
            pq.pop();
            if (visited[getPositionByVertex(u)] == false)
            {
                visited[getPositionByVertex(u)] == true;
                typename std::vector<std::pair<T, C>>::iterator it;
                for (it = this->getAdjacentByVertex(u).begin(); it != this->getAdjacentByVertex(u).end(); it++)
                {
                    T v = it->first;
                    C cost = it->second;
                    if (dist[getPositionByVertex(v)] > (dist[getPositionByVertex(u)] + cost))
                    {
                        dist[getPositionByVertex(v)] = dist[getPositionByVertex(u)] + cost;
                        pq.push(std::make_pair(dist[getPositionByVertex(v)], v));
                    }
                }
            }
        }
    }
    std::cout << dist[this->getPositionByVertex(dest)] << std::endl;
    return dist[this->getPositionByVertex(dest)];
}