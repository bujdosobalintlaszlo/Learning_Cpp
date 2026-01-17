#include <iostream>

class Stack {
public:
    static const int maxSize = 50;

    Stack() : m_top(0) {}

    bool push(int value) {
        if (m_top >= maxSize) {
            std::cout << "Stack overflow!\n";
            return false;
        }
        m_stack[m_top++] = value;
        return true;
    }
    int pop() {
        if (m_top == 0) return -99999;
        return m_stack[--m_top];
    }
    void print() const {
        if (m_top == 0) {
            std::cout << "Empty stack!\n";
            return;
        }

        for (int i = m_top - 1; i >= 0; --i) {
            std::cout << m_stack[i] << '\n';
        }
    }

private:
    int m_top;
    int m_stack[maxSize];
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.print();
    myStack.pop();
    myStack.print();
    return 0;
}

