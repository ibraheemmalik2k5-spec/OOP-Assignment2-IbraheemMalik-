#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;
    Node(int id, string t, string a) {
        BookID = id;
        Title = t;
        Author = a;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = NULL; }

    void addAtBeginning(int id, string t, string a) {
        Node* n = new Node(id, t, a);
        n->next = head;
        if (head != NULL) head->prev = n;
        head = n;
    }

    void addAtEnd(int id, string t, string a) {
        Node* n = new Node(id, t, a);
        if (head == NULL) { head = n; return; }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void addAtPosition(int pos, int id, string t, string a) {
        if (pos <= 1 || head == NULL) {
            addAtBeginning(id, t, a);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next != NULL && i < pos - 1; i++)
            temp = temp->next;
        Node* n = new Node(id, t, a);
        n->next = temp->next;
        if (temp->next != NULL) temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void deleteByID(int id) {
        Node* temp = head;
        while (temp != NULL && temp->BookID != id)
            temp = temp->next;
        if (temp == NULL) return;
        if (temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;
        delete temp;
    }

    void displayForward() {
        Node* t = head;
        while (t != NULL) {
            cout << t->BookID << " - " << t->Title << " by " << t->Author << endl;
            t = t->next;
        }
    }

    void displayBackward() {
        if (head == NULL) return;
        Node* t = head;
        while (t->next != NULL) t = t->next;
        while (t != NULL) {
            cout << t->BookID << " - " << t->Title << " by " << t->Author << endl;
            t = t->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.addAtEnd(1, "C++ Programming", "Bjarne Stroustrup");
    list.addAtEnd(2, "Data Structures", "Mark Weiss");
    list.addAtEnd(3, "Algorithms", "CLRS");

    cout << "Library (forward):\n";
    list.displayForward();

    cout << "\nAfter deleting book ID 2:\n";
    list.deleteByID(2);
    list.displayForward();

    cout << "\nReverse order:\n";
    list.displayBackward();

    return 0;
}

