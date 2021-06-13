#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <set>
#include <map>
using namespace std;

template <class T>
struct Graph
{
    set<T> *node_set;
    map<T, set<T>> *adj_list;

    Graph()
    {
        node_set = new set<T>;
        adj_list = new map<T, set<T>>;
    }

    ~Graph()
    {
        if (node_set != nullptr)
        {
            delete node_set;
            node_set = nullptr;
        }
        if (adj_list != nullptr)
        {
            delete adj_list;
            adj_list = nullptr;
        }
    }

    void add_edge(const T &a, const T &b)
    {
        node_set->insert(a);
        node_set->insert(b);
        (*adj_list)[a].insert(b);
        (*adj_list)[b].insert(a);
    }

    void printGraph() const
    {
        for (auto &x : *adj_list)
        {
            cout << x.first << ": ";
            for (auto &y : x.second)
                cout << y << ", ";
            cout << "end" << endl;
        }
        cout << endl;
    }
};

// int main()
// {
//     Graph<int> g;
//     g.add_edge(1, 2);
//     g.add_edge(1, 3);
//     g.add_edge(3, 2);
//     g.add_edge(3, 4);

//     g.printGraph();
// }

#endif