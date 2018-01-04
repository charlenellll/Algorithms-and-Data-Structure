//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

// BFS on unweighted graph
// find the Shortest Path

// Time Complexity of BFS:
// Sparse Graph (Adjacency lists): O(V+E) (usually O(E) if E is bigger)
// Dense Graph (Adjacency matrix): O(V^2)
template <typename Graph>
class ShortestPath{

private:
    Graph &G;
    int s;
    bool* visited;
    int * from;
    // order: record the length of shortest path from the source s to each vertex
    int * ord;

public:
    ShortestPath(Graph &graph, int s):G(graph){

        assert( s >= 0 && s < G.V());

        visited = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        this->s = s;
        for(int i = 0; i < G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        queue<int> q;

        // BFS
        // find the Shortest Path of the unweighted graph
        q.push(s);
        visited[s] = true;
        ord[s] = 0;

        while( !q.empty() ) {

            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, v);
            for (int w = adj.begin(); !adj.end(); w = adj.next())
                if( !visited[w]) {
                    q.push(w);
                    visited[w] = true;
                    from[w] = v;
                    ord[w] = ord[v] + 1;
                }
        }
    }

    ~ShortestPath(){
        delete [] visited;
        delete [] from;
        delete [] ord;
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

    int length(int w){
        assert( w >= 0 && w < G.V() );
        return ord[w];
    }

};

#endif //GRAPH_SHORTESTPATH_H
