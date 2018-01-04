//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>

// tree
// Optimization: based on the size of set (in the union operation)

namespace UF3{
    class UnionFind{
    private:
        int* parent;
        int* sz; // sz[i] represents the # of elements in the set rooted by i
        int count;

    public:
        UnionFind(int n){

            parent = new int[n];
            sz = new int[n];
            count = n;
            for(int i = 0; i < n; i++){
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind(){
            delete [] parent;
            delete [] sz;
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
            if( sz[pRoot] < sz[qRoot]){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }


    };
}

#endif //UNIONFIND_UNIONFIND3_H
