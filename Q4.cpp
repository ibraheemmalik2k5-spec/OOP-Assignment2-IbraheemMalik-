#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    int id;
    string name;
    int tickets;
    Customer* next;
    Customer(int i, string n, int t) {
        id = i;
        name = n;
        tickets = t;
        next = NULL;
    }
};

class Queue {
public:
    Customer* front;
    Customer* rear;
    Queue() { front = rear = NULL; }

    void enqueue(int i, string n, int t) {
        Customer* c = new Customer(i, n, t);
        if (rear == NULL) {
            front = rear = c;
            return;
        }
        rear->next = c;
        rear = c;
    }

    void dequeue() {
        if (front == NULL) return;
        Customer* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void display() {
        Customer* t = front;
        while (t != NULL) {
            cout << t->id << " - " << t->name << " (" << t->tickets << " tickets)" << endl;
            t = t->next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Ahmed", 1);

    cout << "Current Queue:\n";
    q.display();

    cout << "\nAfter serving first customer:\n";
    q.dequeue();
    q.display();

    return 0;
}

