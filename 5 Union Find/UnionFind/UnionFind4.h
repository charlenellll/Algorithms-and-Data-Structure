//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <cassert>
#include <algorithm>

using namespace std;

// tree
// Optimization: based on the rank of the set (in the union operation)

namespace UF4{
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
        int find(int p){
            assert( p >= 0 && p < count);
            while( parent[p]!=p )
                p = parent[p];
            return p;
        }

        // check if p and q have the same root
        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

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

#endif //UNIONFIND_UNIONFIND4_H
