#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

void leftRotateFirstHalfBy2(std::vector<int>& v)
{
    int half = v.size() / 2;
    std::reverse(v.begin(), v.begin() + 1);
    std::reverse(v.begin() + 1, v.begin() + half);
    std::reverse(v.begin(), v.begin() + half);
}

void rightRotateFirstHalfBy2(std::vector<int>& v)
{
    int half = v.size() / 2;
    std::reverse(v.begin(), v.begin() - 1);
    std::reverse(v.begin() - 1, v.begin() + half);
    std::reverse(v.begin(), v.begin() + half);
}

std::vector<int> processData()
{
    std::vector<int> v;
    std::string line;

    std::getline(std::cin, line);
    std::stringstream ss(line);

    int x;
    while (ss >> x)
        v.push_back(x);

    return v;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        std::vector<int> v = processData();
        rightRotateFirstHalfBy2(v);

        for (int x : v)
            std::cout << x << ' ';
        std::cout << '\n';
    }
}
