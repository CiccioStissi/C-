#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool search(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int val) {
        Node* temp = head;

        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        if (temp == head) {
            head = temp->next;
        } else {
            temp->prev->next = temp->next;
        }

        if (temp == tail) {
            tail = temp->prev;
        } else {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    cout << "Lista in avanti: ";
    myList.printForward();

    cout << "Lista all'indietro: ";
    myList.printBackward();

    int searchVal = 10;
    if (myList.search(searchVal)) {
        cout << searchVal << " trovato nella lista." << endl;
    } else {
        cout << searchVal << " non trovato nella lista." << endl;
    }

    myList.remove(15);
    cout << "Lista in avanti dopo la rimozione di 15: ";
    myList.printForward();

    return 0;
}
