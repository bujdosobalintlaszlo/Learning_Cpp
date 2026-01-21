#include <iostream>
/*
Task: A singleton is a design pattern that restricts the user from creating more
than one instance of said object. This means that it cannot be coppied or moved;

Requirements:
- Implement a class called Singleton where only one instance can be returned trough the
GetInstance() method.
- The singleton should not be movable or copyable. These operations should delete the instance.

The task is from getcracked.io
*/
class Singleton {
public:
    static Singleton* GetInstance() {
        static Singleton instance;
        return &instance;
    }
    //copy
    Singleton(const Singleton&) = delete;
    //could be Singleton& but void is better cause the returntype is not part of the signature
    void operator*(const Singleton&) = delete;
    //move
    //follow up: Why cant I mark Singleton&& as const Singleton&& at move constructor/asignment operator.
    //answ: you could but it would be dumb, since it fails silently and also you cant really take out of the obj. if its const.
    //in short it is counter intuitive for what move does.
    Singleton(Singleton&&) = delete;
    void operator*(Singleton&&) = delete;

private:
    //for create we hide the constructor from the client
    Singleton() = default;
};


int main()
{
    std::cout << "Hello World!\n";
}

