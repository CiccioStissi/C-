#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
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
        Node<T>* prev = nullptr;

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
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList<int> myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    std::cout << "Lista: ";
    myList.printList();

    int searchVal = 10;
    if (myList.search(searchVal)) {
        std::cout << searchVal << " trovato nella lista." << std::endl;
    } else {
        std::cout << searchVal << " non trovato nella lista." << std::endl;
    }

    myList.remove(15);
    std::cout << "Lista dopo la rimozione di 15: ";
    myList.printList();

    return 0;
}
