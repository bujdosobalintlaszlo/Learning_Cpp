//Feladat: Olvassunk be a konzolrol egy egesz szamot, hibas bemenetet kezeljuk! Az adott n szamnak adjuk meg az elso olyan
//tobbszoroset melynek binaris reprezentacioja csupa 1 bol all.

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	long long x = 1;

	while (true) {
		if (x % n == 0) {
			std::cout << x << std::endl;
			break;
		}
		x = x * 10 + 1; 
	}
}

