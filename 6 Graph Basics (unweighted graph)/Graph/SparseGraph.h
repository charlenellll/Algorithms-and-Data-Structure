//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Sparse Graph - use Adjacency Lists

class SparseGraph{

private:
    int n,m;
    bool directed;
    vector<vector<int>> g; // g[i] stores the list of adjacent nodes of i (Adjacency List)

public:
    SparseGraph(int n, bool directed){
        this->n = n;
        this->directed = directed;
        this->m = 0;

        for(int i = 0; i < n; i++)
            g.push_back( vector<int>() );
    }

    ~SparseGraph(){

    }

    int V(){ return n; }
    int E(){ return m; }

    void addEdge( int v, int w){

        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        // Disadvantage of Adjacency Lists:
        // If I were to use this to eliminate the parallel edges, the worst time complexity can be O(N)
//        if( hasEdge(v,w) )
//            return;

        g[v].push_back(w);
        if( v != w && !directed )
            g[w].push_back(v);

        m++;
    }

    // Worst case scenario: O(N)
    bool hasEdge(int v, int w){

        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        for(int i = 0; i < g[v].size(); i++ )
            if( g[v][i] == w )
                return true;

        return false;
    }

    // print the whole Sparse Graph
    void show(){

        for(int i = 0; i < n; i++){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0; j < g[i].size(); j++)
                cout << g[i][j] << "\t";
            cout << endl;

        }
    }

    // each iterator is the adjacency list of vertex v in the graph
    class adjIterator{

    private:
        SparseGraph &G;
        int v;
        int index; // the place of current iteration

    public:
        adjIterator( SparseGraph &graph, int v): G(graph){
            this->v = v;
            this->index = 0;
        }

        // the first vertex in the adjacency list
        int begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];
            return -1;
        }

        // the next vertex in the adjacency list
        int next(){
            index ++;
            if( index < G.g[v].size() )
                return G.g[v][index];
            return -1;
        }

        bool end(){
            return ( index >= G.g[v].size() );
        }
    };

};


#endif //GRAPH_SPARSEGRAPH_H
