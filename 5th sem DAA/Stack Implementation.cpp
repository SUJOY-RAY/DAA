#include <iostream>
using namespace std;

template <typename T>
class Stack {
    int top;
    int maxSize;
    T* stackArray;

public:
    Stack(int size) : maxSize(size), top(-1) {
        stackArray = new T[maxSize];
    }

    ~Stack() { delete[] stackArray; }

    bool isFull() const { return top == maxSize - 1; }
    bool isEmpty() const { return top == -1; }

    void push(const T& value) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        stackArray[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T(); // Return default-constructed T
        }
        return stackArray[top];
    }
};

int main() {
    Stack<int> intStack(5);
    intStack.peek();
    intStack.push(10);
    intStack.push(20);
    cout << "Top element (int): " << intStack.peek() << "\n";
    intStack.pop();
    cout << "Top element after pop (int): " << intStack.peek() << "\n";

    Stack<string> stringStack(3);
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Top element (string): " << stringStack.peek() << "\n";
    stringStack.pop();
    cout << "Top element after pop (string): " << stringStack.peek() << "\n";

    return 0;
}