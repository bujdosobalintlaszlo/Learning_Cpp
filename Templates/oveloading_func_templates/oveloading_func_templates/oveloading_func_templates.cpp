#include <iostream>
using namespace std;

template <typename T>
T Sum(T a, T b) {
    cout << "template sum" << endl;
    return a + b;
}
template<typename T>
T Sum(T a, T b, T c) {
    return a + b + c;
}

double Sum(double a, double b) {
    cout << "non-template sum" << endl;
    return a + b;
}

/*
* we need to be considerate about imbigouty when we have overloaded templates as well
template<typename T>
T Sum(T a, int b) {
    return a + b + c;
}

template<typename T>
T Sum(int a, T b) {
    return a + b + c;
}
*/


int main()
{
    //If there is imbiguity beteewn a template and a non-template function the non-template will take presitence
    cout << Sum(2.0, 3.56) << endl;
    cout << Sum(2.0, 3.56,8493.4343) << endl;
    cout << Sum(2, 3) << endl;
    cout << Sum(1, 3, 5) << endl;

    return 0;
}
