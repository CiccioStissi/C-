#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool search(T val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(T val) {
        Node<T>* temp = head;

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
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    std::cout << "Lista in avanti: ";
    myList.printForward();

    std::cout << "Lista all'indietro: ";
    myList.printBackward();

    int searchVal = 10;
    if (myList.search(searchVal)) {
        std::cout << searchVal << " trovato nella lista." << std::endl;
    } else {
        std::cout << searchVal << " non trovato nella lista." << std::endl;
    }

    myList.remove(15);
    std::cout << "Lista in avanti dopo la rimozione di 15: ";
    myList.printForward();

    return 0;
}
