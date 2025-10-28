#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class StackLinked {
public:
    Node* top;
    StackLinked() { top = NULL; }

    void push(int d) {
        Node* n = new Node(d);
        n->next = top;
        top = n;
    }

    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) return -1;
        return top->data;
    }

    bool empty() { return top == NULL; }
};

class StackArray {
public:
    int *arr;
    int top, size;
    StackArray(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int d) {
        if (top == size - 1) return;
        top++;
        arr[top] = d;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool empty() { return top == -1; }

    ~StackArray() { delete[] arr; }
};

int main() {
    cout << "Linked List Stack:\n";
    StackLinked s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    while (!s1.empty()) {
        cout << s1.peek() << " ";
        s1.pop();
    }

    cout << "\n\nArray Stack:\n";
    StackArray s2(10);
    s2.push(5);
    s2.push(15);
    s2.push(25);
    while (!s2.empty()) {
        cout << s2.peek() << " ";
        s2.pop();
    }

    cout << "\n\nBoth stacks have O(1) push and pop operations.\n";
    return 0;
}

