/*
Aknakeresõ
Adott egy m*n-es Microsoft ® Aknakeresõ pálya, ahol *-gal jelöltek az aknák pozíciói, és a . karakter jelzi az aknák hiányát.
Feladat: Határozzuk meg, hogy az akna nélküli mezõknél a 8 szomszédos mezõbõl hányon van akna.

A standard input elején 2 egész érték van: az elsõ az aknakeresõ tábla sorainak száma, a második az aknakeresõ tábla oszlopainak a száma. Ezután jön a tábla leírása, melyben sorvége jelek szerepelhetnek. Feltehetõ, hogy összesen pontosan m*n db. * illetve . érkezik.

Példa Input:
3 5
.*...
...*.
....*

Példa Output:
1*211
112*2
0012*
A feladat megoldásához csak a szabványos C++ eszközei használhatóak!
*/
#include <iostream>
#include <string>
#include <vector>
std::vector<std::vector<char>> readMap() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> map(n, std::vector<char>(m, '.'));
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < m; ++j) {
            map[i][j] = line[j];
        }
    }
    return map;
}
void printMap(std::vector<std::vector<char>> map) {
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '*') {
                std::cout << "*";
            }
            else {
                std::cout << map[i][j];
            }
        }
        std::cout << '\n';
    }
}
int checkNeighbours(const std::vector<std::vector<char>>& map, int posX, int posY) {
    int count = 0;
    int n = map.size();
    int m = map[0].size();

    for (int i = posX - 1; i <= posX + 1; ++i) {
        for (int j = posY - 1; j <= posY + 1; ++j) {
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (i == posX && j == posY) continue;
            if (map[i][j] == '*') ++count;
        }
    }
    return count;
}

void printCountMap(const std::vector<std::vector<char>>& map) {
    int n = map.size();
    int m = map[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '*') {
                std::cout << '*';
            }
            else {
                std::cout << checkNeighbours(map, i, j);
            }
        }
        std::cout << '\n';
    }
}



int main() {
    std::vector<std::vector<char>> map = readMap();
   // printMap(map);
    printCountMap(map);

}


