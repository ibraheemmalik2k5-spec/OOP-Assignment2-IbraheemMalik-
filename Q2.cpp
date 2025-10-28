#include <iostream>
#include <string>
using namespace std;

class Feature {
public:
    string Name;
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n) { Name = n; }
    void analyze() { cout << "Land Feature Detected: " << Name << endl; }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) { Name = n; }
    void analyze() { cout << "Water Feature Detected: " << Name << endl; }
};

class Node {
public:
    int FeatureID;
    Feature* F;
    Node* next;
    Node(int id, Feature* f) {
        FeatureID = id;
        F = f;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() { head = NULL; }

    void insertAtEnd(int id, Feature* f) {
        Node* n = new Node(id, f);
        if (head == NULL) { head = n; return; }
        Node* t = head;
        while (t->next != NULL) t = t->next;
        t->next = n;
    }

    void deleteByID(int id) {
        if (head == NULL) return;
        if (head->FeatureID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* t = head;
        while (t->next != NULL && t->next->FeatureID != id)
            t = t->next;
        if (t->next == NULL) return;
        Node* temp = t->next;
        t->next = temp->next;
        delete temp;
    }

    void displayAll() {
        Node* t = head;
        while (t != NULL) {
            t->F->analyze();
            t = t->next;
        }
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    ~SinglyLinkedList() {
        Node* t = head;
        while (t != NULL) {
            Node* next = t->next;
            delete t;
            t = next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));

    cout << "All Features:\n";
    list.displayAll();

    cout << "\nAfter deleting ID 2:\n";
    list.deleteByID(2);
    list.displayAll();

    cout << "\nAfter reversing:\n";
    list.reverseList();
    list.displayAll();

    return 0;
}

