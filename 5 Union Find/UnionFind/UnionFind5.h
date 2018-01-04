//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H

#include <cassert>
#include <algorithm>

using namespace std;

// Path Compression
// Optimization: in the find operation

namespace UF5{
    class UnionFind{
    private:
        int* parent;
        int* rank; // rank[i] represents the # of levels in the set rooted by i
        int count;

    public:
        UnionFind(int n){

            parent = new int[n];
            rank = new int[n];
            count = n;
            for(int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete [] parent;
            delete [] rank;
        }


        // find the root of p
        // Optimization here

        // normal Path Compression

//        int find(int p){
//            assert( p >= 0 && p < count);
//            while( parent[p]!=p ) {
//                // Path Compression here
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//
//            return p;
//        }

        // extreme Path Compression that each tree has only two levels: root and leaves
        // TODO: almost O(1)
        int find(int p){
            assert( p >= 0 && p < count);

            // Path Compression here
            if( parent[p]!=p ) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        // check if p and q have the same root
        // O(1)
        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        // TODO : almost O(1)
        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            // union the smaller tree to the larger tree's root to make sure the new tree's height is smaller
            if( rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }
            else if(rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }
            else{ // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }


    };
}

#endif //UNIONFIND_UNIONFIND5_H
