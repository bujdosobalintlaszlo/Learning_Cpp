// mergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

void merge(std::vector<int>* a, int u, int m, int v)
{
    std::vector<int> temp;
    temp.reserve(v - u + 1);

    int i = u;      // bal rész [u, m]
    int j = m + 1;  // jobb rész [m+1, v]

    while (i <= m && j <= v)
    {
        if ((*a)[i] <= (*a)[j])
            temp.push_back((*a)[i++]);
        else
            temp.push_back((*a)[j++]);
    }

    while (i <= m)
        temp.push_back((*a)[i++]);

    while (j <= v)
        temp.push_back((*a)[j++]);

    for (int k = 0; k < temp.size(); ++k)
        (*a)[u + k] = temp[k];
}


void ms(std::vector<int>* a, int u, int v) {
    if (u < v) {
        int m = (u + v) / 2;
        ms(a, u, m);
        ms(a, m+1, v);
        merge(a, u, m, v);
    }
}

void mergeSort(std::vector<int> *a) {
    ms(a, 0, (*a).size()-1);
}
int main()
{
    std::vector<int> a{ 4, 3, 1, 3, 5, 2, 6, 4 };
    mergeSort(&a);

    for (int x : a)
        std::cout << x << " ";
}
