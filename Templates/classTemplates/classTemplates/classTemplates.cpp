#include <iostream>
using namespace std;

template <typename T, int length>
class Array {
public:
    T array[length];

    void fillArray(T value) {
        for (int i = 0; i < length; ++i) {
            array[i] = value;
        }
    }

    T& at(int index) {
        return array[index];
    }
};

int main()
{
    Array<int, 31> intArr;
    intArr.fillArray(2);
    cout << "intArr[4] = " << intArr.at(4) << endl;

    Array<string, 6> stringArray;
    stringArray.fillArray("udwi");
    cout << "stringArray[4] = " << stringArray.at(4) << endl;
    stringArray.array[4] = "123";  

    for (int i = 0; i < 6; ++i) {        
        cout << "stringArray[" << i << "]: " << stringArray.at(i) << endl;
    }
}
