#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
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
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == val) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    cout << "Lista: ";
    myList.printList();

    int searchVal = 10;
    if (myList.search(searchVal)) {
        cout << searchVal << " trovato nella lista." << endl;
    } else {
        cout << searchVal << " non trovato nella lista." << endl;
    }

    myList.remove(15);
    cout << "Lista dopo la rimozione di 15: ";
    myList.printList();

    return 0;
}
