#include <iostream>
using namespace std;


template<typename T>

T findMax(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template <typename T1,typename T2>
int findMaxSize(T1 a, T2 b) {
    uint16_t aSize = sizeof(a);
    uint16_t bSize = sizeof(b);
    if (aSize > bSize) {
        return aSize;
    }
    return bSize;
}
int main()
{
    double x = 10.45;
    double y = 10.55;
    int z = 43;
    double b_max = findMax<double>(x, y);
    cout << b_max << "is the bigger out of " << x << " and " << y << endl;
    int sizeMax = findMaxSize<int, double>(x, z);
    cout << sizeMax << endl;
}
