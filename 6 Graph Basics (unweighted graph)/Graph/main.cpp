#include <iostream>
#include <vector>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

int main() {

//    // 1. Test on printing a vector
//    vector<int> arr({1,2,3,4,5});
//    vector<int>::iterator iter;
//    for(iter = arr.begin(); iter != arr.end(); iter++)
//        cout << *iter << endl;

//    // 2. Test on implementation of Sparse Graph and Dense Graph
//
//    int N = 20;
//    int M = 100;
//
//    srand( time(NULL) );
//
//    cout << "Sparse Graph: " << endl;
//    // Sparse Graph
//    SparseGraph g1(N, false);
//    for(int i = 0; i < M; i++){
//        int a = rand()%N;
//        int b = rand()%N;
//        g1.addEdge(a,b);
//    }
//
//    // O(E)
//    for(int v = 0; v < N; v++){
//        cout << v <<  ": "  ;
//        // each iterator is the adjacency list of vertex v
//        SparseGraph::adjIterator adj(g1, v);
//        for( int w = adj.begin(); !adj.end(); w = adj.next())
//            cout<< w << " ";
//        cout << endl;
//    }
//    cout << endl;
//
//
//    cout<<"Dense Graph: " << endl;
//    // Dense Graph
//    DenseGraph g2(N, false);
//    for(int i = 0; i < M; i++){
//        int a = rand()%N;
//        int b = rand()%N;
//        g2.addEdge(a,b);
//    }
//
//    // O(V^2) = O(V) * O(V)
//    for(int v = 0; v < N; v++){
//        cout << v <<  ": "  ;
//        // each iterator is the adjacency list of vertex v
//        DenseGraph::adjIterator adj(g2, v);
//        for( int w = adj.begin(); !adj.end(); w = adj.next())
//            cout<< w << " ";
//        cout << endl;
//    }
//    cout << endl;


//    // 3. Read Graph from file
//
//    string filename = "testG1.txt";
//
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename);
//    g1.show();
//
//    cout << endl;
//
//    DenseGraph g2(13, false);
//    ReadGraph<DenseGraph> readGrap2(g2, filename);
//    g2.show();

//    // 4. Finding Components
//    // testG1.txt
//    string filename1 = "testG1.txt";
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph1(g1, filename1);
//    Component<SparseGraph> component1(g1);
//    cout<<"testG1.txt, Component count is : "<<component1.count()<<endl;
//
//    cout << endl;
//
//    string filename2 = "testG2.txt";
//    SparseGraph g2(7, false);
//    ReadGraph<SparseGraph> readGraph2(g2, filename2);
//    Component<SparseGraph> component2(g2);
//    cout<<"testG2.txt, Component count is : "<<component2.count()<<endl;


//    // 5. DFS and find a path
//    string filename = "testG2.txt";
//    SparseGraph g(7, false);
//    ReadGraph<SparseGraph> readGraph(g, filename);
//    g.show();
//    cout << endl;
//
//    Path<SparseGraph> dfs(g, 0);
//    cout<<"DFS : ";
//    dfs.showPath(6);

    // 6. BFS and find the shortest path (in unweighted graph)
    string filename = "testG2.txt";
    SparseGraph g(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> dfs(g, 0);
    cout<<"DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout<<"BFS : ";
    bfs.showPath(6);

    return 0;
}