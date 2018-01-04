//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

// Connected Components

template <typename Graph>
class Component{

private:
    Graph &G;
    bool *visited;
    int ccount;
    // See if two vertex are connected
    int *id;

    void DFS(int v){

        visited[v] = true;
        // use this single line to maintain the connected property for reference
        id[v] = ccount;

        // a trap in C++ compiler: it doesn't know if adjIterator is a typename or a member variable
        typename Graph::adjIterator adj(G, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next()){
            if( !visited[w] )
                DFS(w);
        }
    }

public:
    Component(Graph &graph):G(graph){

        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for(int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }



        for(int i = 0; i < G.V(); i++)
            if( !visited[i] ) {
                DFS(i);
                ccount ++;
            }

    }

    ~Component(){
        delete [] visited;
        delete [] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected(int v, int w){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }

};

#endif //GRAPH_COMPONENT_H
