//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Dense Graph - use Adjacency Matrix

class DenseGraph{
private:
    int n,m;
    bool directed;
    vector<vector<bool>> g; // Adjacency Matrix

public:
    DenseGraph(int n, bool directed){
        this->n = n;
        this->directed = directed;
        this->m = 0;

        for(int i = 0; i < n; i++)
            g.push_back( vector<bool>(n, false) );
    }

    ~DenseGraph(){

    }

    int V(){ return n; }
    int E(){ return m; }

    void addEdge(int v, int w){

        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        if( hasEdge(v,w) )
            return;

        g[v][w] = true;
        if( !directed )
            g[w][v] = true;

        m++;
    }

    bool hasEdge(int v, int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        return g[v][w];
    }

    // print the whole Dense Graph
    void show(){

        for(int i = 0; i < n; i++){
            for( int j = 0; j < n ; j++)
                cout << g[i][j] << "\t";
            cout << endl;

        }
    }

    // the iterator of adjacency lists in the dense graph
    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = 0;
        }
        ~adjIterator(){

        }

        int begin(){
            index = -1;
            return next();
        }

        int next(){
            for( index += 1; index < G.V(); index ++)
                if( G.g[v][index] )
                    return index;
            return -1;
        }

        bool end(){
            return( index >= G.V() );
        }

    };
};

#endif //GRAPH_DENSEGRAPH_H
