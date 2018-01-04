//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>

// Using a tree

namespace UF2{
    class UnionFind{
    private:
        int* parent;
        int count;

    public:
        UnionFind(int n){

            parent = new int[n];
            count = n;
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        ~UnionFind(){
            delete [] parent;
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

            parent[pRoot] = qRoot;
        }

    };
}

#endif //UNIONFIND_UNIONFIND2_H
