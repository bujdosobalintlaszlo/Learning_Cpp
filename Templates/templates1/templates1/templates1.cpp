#include <iostream>
#include <string>

//also can be template<class T>
template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}
int main()
{
    Print(5);
    Print("hello");
    Print(4.353);

    std::cin.get();
}
