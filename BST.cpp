#include <iostream>
using namespace std;

class Veicolo
{
private:
    string marca;
    string modello;
    int anno;
public:
    Veicolo(){}
    Veicolo(string m,string md,int a):marca(m),modello(m),anno(a){}

    string getMarca(){return marca;}
    string getModello(){return modello;}
    int getAnno(){return anno;}

    void Stampa()
    {
        cout<<"Marca->"<<marca<<"\nModello->"<<modello<<"\nAnno->"<<anno<<endl;
    }

    virtual string TipoVeicolo()=0;
};

class Auto : public Veicolo
{
public:
    Auto(string m,string md,int a):Veicolo(m,md,a){}
    string TipoVeicolo(){return "Tipo Auto";}
};

class Moto : public Veicolo
{
public:
    Moto(string m,string md,int a):Veicolo(m,md,a){}
    string TipoVeicolo(){return "Tipo Moto";}
};

template<typename T>
struct Node
{
    Node<T>* sx;
    Node<T>* dx;
    T* dato;
};

template<typename T>
class AlberoBinario
{
private:
    Node<T>* root;
public:
    AlberoBinario(){root=nullptr;}
    //AlberoBinario(Node<T>* r):root(r){}

    Node<T>* getRoot(){return root;}
    Node<T>* Inserisci(Node<T>* root,T* x);
    void Inse(T* x);
    Node<T>* Rimuovi(Node<T>* root,T* x);
    Node<T>* FindMin(Node<T>* root);
    void Rim(T* x);
    Node<T>* FindParent(Node<T>* root,T key,Node<T>* parent=nullptr);
    Node<T>* Front();
    void InOrder(Node<T>* root);
    void PreOrder(Node<T>* root);
    void PostOrder(Node<T>* root);
};

template<typename T>
Node<T>* AlberoBinario<T>::Inserisci(Node<T>* root,T* x)
{
    if(root == nullptr)
    {
        Node<T>* newnode=new Node<T>;
        newnode->dato=x;
        newnode->sx=nullptr;
        newnode->dx=nullptr;
        return newnode;
    }

    if(x < root->dato)
    {
        root->sx=Inserisci(root->sx,x);
    }
    else
    {
        root->dx=Inserisci(root->dx,x);
    }
    return root;
}

template<typename T>
Node<T>* AlberoBinario<T>::FindMin(Node<T>* root)
{
    while(root->sx != nullptr)
    {
        root=root->sx;
    }
    return root;
}

template<typename T>
Node<T>* AlberoBinario<T>::Rimuovi(Node<T>* root,T* x)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(x < root->dato)
    {
        root->sx=Rimuovi(root->sx,x);
    }
    else if(x > root->dato)
    {
        root->dx=Rimuovi(x > root->dx,x);
    }
    else
    {
        if(root->sx == nullptr && root->dx == nullptr)
        {
            delete root;
            return nullptr;
        }
        if(root->dx == nullptr)
        {
            Node<T>* temp=root->dx;
            delete root;
            return temp;
        }
        else if(root->sx == nullptr)
        {
            Node<T>* temp=root->sx;
            delete root;
            return temp;
        }
        else
        {
            Node<T>* temp=FindMin(root->dx);
            temp->dato=root->dato;
            root->dx=Rimuovi(root->dx,x);
        }
    }
}


template<typename T>
void AlberoBinario<T>::Inse(T* x)
{
    root=Inserisci(root,x);
}

template<typename T>
void AlberoBinario<T>::Rim(T* x)
{
    root=Rimuovi(root,x);
}

template<typename T>
void AlberoBinario<T>::InOrder(Node<T>* root)
{
    if(root==nullptr){return;}
    InOrder(root->sx);
    cout<<"Marca->"<<root->dato->getMarca()<<"-Modello->"<<root->dato->getModello()<<"-Anno->"<<root->dato->getAnno()<<endl;
    InOrder(root->dx);
}

template<typename T>
void AlberoBinario<T>::PreOrder(Node<T>* root)
{
    cout<<"Marca->"<<root->dato->getMarca()<<"-Modello->"<<root->dato->getModello()<<"-Anno->"<<root->dato->getAnno()<<endl;
    PreOrder(root->sx);
    PreOrder(root->dx);
}

template<typename T>
void AlberoBinario<T>::PostOrder(Node<T>* root)
{
    PostOrder(root->sx);
    PostOrder(root->dx);
    cout<<"Marca->"<<root->dato->getMarca()<<"-Modello->"<<root->dato->getModello()<<"-Anno->"<<root->dato->getAnno()<<endl;
}

int main()
{
    AlberoBinario<Veicolo> bst;
    Auto auto1("Ford","Fiesta",2003);
    Moto moto1("Nevio","AfricaTwin",2019);
    Auto auto2("Mercedes","Benz",1999);
    Moto moto2("Filippo","Champagne",2222);

    bst.Inse(&auto1);
    bst.Inse(&moto1);
    bst.Inse(&auto2);
    bst.Inse(&moto2);

    cout<<"Stampa InOrder->"<<endl;
    bst.InOrder(bst.getRoot());

    cout<<"\nStampa PreOrder->"<<endl;
    bst.PreOrder(bst.getRoot());

    cout<<"\nStampa PostOrder->"<<endl;
    bst.PostOrder(bst.getRoot());
}
