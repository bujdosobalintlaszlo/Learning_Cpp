// insertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
void insertionSort(std::vector<int> *a) {
    for (int i = 1; i < (*a).size(); ++i) {
        if ((*a)[i - 1] > (*a)[i]) {
            int x = (*a)[i];
            (*a)[i] = (*a)[i - 1];
            int j = i - 1;
            while (j >= 0 && (*a)[j] > x) {
                (*a)[j + 1] = (*a)[j];
                j -= 1;
            }
            (*a)[j + 1] = x;
        }
    }
}

int main()
{
    std::vector<int> a{ 4,3,1,3,5,2,6,4 };
    insertionSort(&a);
    std::for_each(a.begin(), a.end(), [](int x) {
        std::cout << x << " ";
    });
}

