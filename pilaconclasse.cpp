#include <iostream>
#include <string>

using namespace std;

class Veicolo{
    private:
        string targa;
        int anno;
        string modello;
    public:
        Veicolo(){
            targa = "";
            anno = 0;
            modello = "";
        }

        Veicolo(string t, int a, string m){
            targa = t;
            anno = a;
            modello = m;
        }

        string GetTarga(){
            return targa;
        }

        int GetAnno(){
            return anno;
        }

        string GetModello(){
            return modello;
        }

        virtual ostream& write(ostream& os){
            os<<"Targa: "<< GetTarga() << " Anno immatricolazione: " << GetAnno() << " Modello: " << GetModello() << endl;
            return os;
        }
};

        ostream& operator<<(ostream& os, Veicolo& v){
            return v.write(os);
        }

class Auto:public Veicolo{
    public:
        Auto(string t,int a, string m):Veicolo(t,a,m){}

        ostream& operator<<(ostream& os){
            os<<"Targa: "<< GetTarga() << " Anno immatricolazione: " << GetAnno() << " Modello: " << GetModello() << endl;
            return os;
        }   
};

class Moto:public Veicolo{
    public:
        Moto(string t,int a, string m):Veicolo(t,a,m){}

        ostream& operator<<(ostream& os){
            os<<"Targa: "<< GetTarga() << " Anno immatricolazione: " << GetAnno() << " Modello: " << GetModello() << endl;
            return os;
        }   
};

class Nodo{
    public:
        Veicolo *dato;
        Nodo *next;
    
        Nodo(){
            this->dato = 0;
            this->next = nullptr;
        }

        Nodo(Veicolo *data){
            this->dato = data;
            this->next = nullptr;
        }
};

class Pila{
    private:
        Nodo *dato;
        Nodo *head;
    public:
        Pila(){
            head = nullptr;
            dato = nullptr;
        }

        Pila(Nodo *data){
            head = nullptr;
            dato = data;
        }

        void push(Veicolo *tmp){
            Nodo *newnodo = new Nodo(tmp);
            newnodo->next = head;
            head = newnodo;
        }

        Veicolo *pop(){
            if(head == nullptr){
                return nullptr;
            }

            Nodo *tmp = head;
            head = head->next;
            Veicolo *temp = tmp->dato;
            delete tmp;
            return temp;
        }

        void top(){
            if(head == nullptr){
                return;
            }

            cout<<*(head->dato)<<endl;
        }

        void stampa(){
            Nodo *tmp = head;
            while(tmp){
                cout<<*(tmp->dato)<<endl;
                tmp = tmp->next;
            }
           
        }
};

int main(){
    // Create instances of Veicolo, Auto, and Moto
    Veicolo veicolo1("ABC123", 2020, "Sedan");
    Auto auto1("XYZ789", 2022, "SUV");
    Moto moto1("DEF456", 2021, "Sport");

    // Display information using the overloaded << operator
    /*cout << "Veicolo 1:\n" << veicolo1 << endl;
    cout << "Auto 1:\n" << auto1 << endl;
    cout << "Moto 1:\n" << moto1 << endl;*/

    // Example of using Pila (Stack)
    Pila pila;

    // Push instances onto the stack
    pila.push(&veicolo1);
    pila.push(&auto1);
    pila.push(&moto1);
    pila.stampa();

    cout<<"Eliminazione effettuata: "<<endl;
    pila.pop();
    cout<<endl;
    pila.stampa();
    cout<<endl;
    pila.top();



    // Note: Make sure to handle memory deallocation appropriately based on your design

    return 0;

}