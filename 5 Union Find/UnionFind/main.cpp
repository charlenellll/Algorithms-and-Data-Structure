#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;


int main() {

    int n = 1000000;

    // O(N^2)
    // UF1, 200000ops, 21.4045 s
    // UnionFindTestHelper::testUF1(n);

    //UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);

    // TODO: N * almost O(1)
    UnionFindTestHelper::testUF5(n);

//    Optimization in union operation
//    UF1, 200000ops, 21.7179 s
//    UF2, 200000ops, 14.0398 s
//    UF3, 200000ops, 0.012246 s

//    Optimization in find operation
//    After Path Compression in UF5
//    UF3, 2000000ops, 0.375938 s
//    UF4, 2000000ops, 0.192713 s
//    UF5, 2000000ops, 0.190201 s

//    After extreme Path Compression in UF5
//    In theory it is the best optimiztion but in reality it is not as good as normal Path Compression
//    UF3, 2000000ops, 0.387336 s
//    UF4, 2000000ops, 0.271284 s
//    UF5, 2000000ops, 0.421619 s

    return 0;

}