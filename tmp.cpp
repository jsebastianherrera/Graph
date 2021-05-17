#include <iostream>
#include <vector>
int main(void)
{
    std::vector<std::vector<int>> m;
    std::vector<int> c;
    std::vector<int> x;
    std::vector<int> d;
    c.push_back(0);
    c.push_back(1);
    c.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    m.push_back(c);
    m.push_back(x);
    m.push_back(d);
    //delete rows
    m.erase(m.begin() + 2);
    //delete columns
    for (int i = 0; i < m.size(); ++i)
        m[i].erase(m[i].begin() + 2);
    //Print
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
            std::cout << "\t" << m[i][j];
        std::cout << std::endl;
    }
}