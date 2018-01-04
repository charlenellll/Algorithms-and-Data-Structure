//
// Created by 廖佳玲 on 1/4/18.
//

#ifndef UNIONFIND_UNIONFIND1_H_H
#define UNIONFIND_UNIONFIND1_H_H

#include <iostream>
#include <cassert>

using namespace std;

// Using a simple look-up array

namespace UF1 {


    class UnionFind {

    private:
        int count;
        int *id;

    public:
        UnionFind(int n) {
            count = n;
            id = new int[n];

            for (int i = 0; i < count; i++)
                id[i] = i;
        }

        ~UnionFind() {
            delete[] id;
        }

        // O(1)
        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        // O(1)
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // O(N)
        void unionElements(int p, int q) {

            int pID = find(p);
            int qID = find(q);

            if (pID == qID)
                return;

            for (int i = 0; i < count; i++)
                if (id[i] == pID)
                    id[i] = qID;
        }
    };

}


#endif //UNIONFIND_UNIONFIND1_H_H
