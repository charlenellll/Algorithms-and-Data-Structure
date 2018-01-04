//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

template <typename Graph>
class Path{

private:
    Graph &G;
    int s;
    bool* visited;
    int * from;

    // Time Complexity of DFS:
    // Sparse Graph (Adjacency lists): O(V+E) (usually O(E) if E is bigger)
    // Dense Graph (Adjacency matrix): O(V^2)
    void DFS(int v){

        visited[v] = true;

        // a trap in C++ compiler: it doesn't know if adjIterator is a typename or a member variable
        typename Graph::adjIterator adj(G, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next())
            if( !visited[w] ){
                from[w] = v;
                DFS(w);
        }
    }
    // TODO: in directed graph, do cycle detection in DFS.

public:
    Path(Graph &graph, int s):G(graph){

        assert( s >= 0 && s < G.V());

        visited = new bool[G.V()];
        from = new int[G.V()];
        this->s = s;
        for(int i = 0; i < G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }

        // find the path
        DFS(s);

    }

    ~Path(){
        delete [] visited;
        delete [] from;
    }

    bool hasPath(int w){
        assert( w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec){

        stack<int> s;

        int p = w;
        while(p != -1){
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while( !s.empty() ){
            vec.push_back( s.top() );
            s.pop();
        }
    }

    void showPath(int w){

        vector<int> vec;
        path(w, vec);
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i];
            if( i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> " ;
        }
    }

};

#endif //GRAPH_PATH_H
