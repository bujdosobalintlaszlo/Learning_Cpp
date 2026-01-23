#include<iostream>
#include<vector>
/*
Könyvazonosító számok ellenõrzése
Az ISBN (International Standard Book Number) azonosítók olyan tízjegyû számok, amelyeket könyvek azonosítására használnak. A szám tizedik számjegye lehet X karakterrel leírt 10-es is. A könnyebb olvashatóság végett a szám leírásában kötõjelek és szóközök szerepelhetnek, lényegi jelentõségük nincsen.

Valójában az elsõ kilenc számjegy azonosítja a könyvet. A tizedik számjegy validálja, hogy az elsõ kilenc számjegy helyes-e. Mivel a checksum algoritmus 11-gyel vett oszthatóságot vizsgál, szükséges lehet a 10-es ellenõrzõ számjegy, amit X jelöl az ISBN számban.

Az ISBN számok ellenõrzésére az alábbi checksum algoritmus használható: két részletösszeg számítandó az ISBN számból: s1 és s2. Az s1 az ISBN számjegyeinek részletösszegei, míg s2 az s1 részletösszege. Az ISBN érvényes, ha az utolsó s2 részletösszeg osztható 11-gyel.

Példa: 0-13-162959-X (Tanenbaum: Computer Networks)

0 1 3 1  6  2  9  5  9   10  (Az ISBN számjegyei)
0 1 4 5  11 13 22 27 36  46  (s1 részletösszegek)
0 1 5 10 21 34 56 83 119 165 (s2 részletösszegek)

Mivel a 165 osztható 11-gyel, az azonosító érvényes.

Feladat: a standard inputról beolvasott azonosítókról eldönteni, hogy a fenti algoritmus alapján érvényes azonosító-e. Minden sorban pontosan egy azonosító szerepel. A standard output-on "Valid" jelenti az érvényes azonosítót, "Invalid" jelenti az érvénytelen azonosítót. A standard input-on az eof jelzi, hogy nincs több ellenõrizendõ azonosító.


Példa Input:
0-13-162959-X
1-234-5678-90


Példa Output:
Valid
Invalid
*/

/*
Magyarazatok: azert irtam const std::vector<int> &v ket, mivel nem akarom modositani,sem masolni annyiszor ahanyszor dolgozom vele es atadom parameterkent igy ezzel memoriat es idot sporolok.
*/
int calcS2(const std::vector<int> &v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	return sum;
}

std::vector<int> calcS1(const std::vector<int> &v) {
	std::vector<int> steps;
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
		steps.push_back(sum);
	}
	return steps;
}

std::vector<int> processData(const std::string& inp) {
	std::vector<int> v;
	for (int i = 0; i < inp.size(); ++i) {
		if (inp[i] == 'X') {
			v.push_back(10);
		}
		else if (isdigit(inp[i])) {
			v.push_back(inp[i] - '0');
		}
	}
	return v;
}
bool checkIfValid(const std::vector<int>& v) {
	if (v.size() != 10) return false;

	std::vector<int> s1 = calcS1(v);
	int s2 = calcS2(s1);

	return (s2 % 11 == 0);
}

int main() {
	std::string inp;
	while (std::cin >> inp) {
		std::vector<int> v = processData(inp);

		if (checkIfValid(v)) {
			std::cout << "Valid" << std::endl;
		}
		else {
			std::cout << "Invalid" << std::endl;
		}
	}
	return 0;
}

