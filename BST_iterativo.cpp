#include <iostream>
using namespace std;

class nodo{        
    public : 
        nodo * sx;
        nodo * dx;
        int dato ;
        nodo * parente;
        nodo(){
            sx = nullptr;
            dx = nullptr;
            parente = nullptr;
            dato = 0;
        }
        nodo(int num){
            dato = num;
            sx = nullptr;
            dx = nullptr;
            parente = nullptr;
        }
};

class bst{
    private : 
        nodo * root;
    public : 
        bst(){
            root = nullptr;
        }
        bst(nodo * nodino){
            root = nodino;
        }
// inserimento sempre e dico sempre iterativo. Non si perde il parent
        void inserimento_interno(int value){
            nodo * newnodo = new nodo(value);
            if(root == nullptr){
                root = newnodo;
                return ;
            }
            nodo * tmp = root;
            nodo * tmp2 = nullptr;
            while(tmp != nullptr){
                tmp2 = tmp;
                if(value < tmp->dato){
                    tmp = tmp->sx;
                }else{
                    tmp = tmp->dx;
                }
            }
            if(value < tmp2->dato){
                tmp2->sx = newnodo;
                newnodo->parente = tmp2;
            }else{
                tmp2->dx = newnodo;
                newnodo->parente = tmp2;
            }
        }

        void pre_order(nodo * root){
            if(root){
                cout<<root->dato<<endl;
                pre_order(root->sx);
                pre_order(root->dx);
            }
        }
        void pre_order(){
            cout<<"Stampa pre_order"<<endl;
            pre_order(root);
        }

        void in_order(nodo * root){
            if(root){
                in_order(root->sx);
                cout<<root->dato<<endl;
                in_order(root->dx);
            }
        }
        void in_order(){
            cout<<"Stampa in_order"<<endl;
            in_order(root);
        }

        void post_order(nodo * root){
            if(root){
                post_order(root->sx);
                post_order(root->dx);
                cout<<root->dato<<endl;
            }
        }
        void post_order(){
            cout<<"Stampa post_order"<<endl;
            post_order(root);
        }

        void stampa_parente(nodo * nodino){
            cout<<"Parente di : "<< nodino->dato<<endl;
            cout<< nodino->parente->dato <<endl;
        }

        nodo * min(nodo* root){
            if(root == nullptr){
                cout<<"L'albero non esiste."<<endl;
                return nullptr;
            }
            nodo * tmp = root;
            while(tmp->sx != nullptr){
                tmp = tmp->sx;
            }
                return tmp;
        }

        nodo * min(){
            cout<<"Ricerca minimo BST" << endl;
            nodo * minimo = min(root);
            cout << minimo->dato<<endl;
            return minimo;
        }

        nodo * max(nodo * root){
            if(root == nullptr){
                cout<<"L'albero non esiste."<<endl;
                return nullptr;
            }
            while(root->dx){
                root = root->dx;
            }
                return root;
        }

        nodo * max(){
            cout<<"Ricerca massimo BST" <<endl;
            nodo * massimo = max(root);
            cout<<massimo->dato<<endl;
            return massimo;
        }

        /*nodo * successore(){
            cout << "Ricerca successore"<<endl;
            nodo * suc = min(root->dx);
            cout << suc->dato << endl;
            return suc;
        }*/

        nodo * successore(int value){
            cout<<"Successore di : ";
            nodo * to_reach = ricerca_interna(value);
            //cout<<to_reach->dato<<endl;
            nodo * tmp = min(to_reach->dx);
            cout<<tmp->dato<<endl;
            return tmp;
        }

        nodo * ricerca_interna(int value_to_found/*,nodo root*/){
            if(root == nullptr){
                return nullptr;
            }
            nodo * tmp = root;
            nodo * nodo_to_AP = nullptr;
            while(value_to_found != tmp->dato){
                if(value_to_found < tmp->dato){
                    tmp = tmp->sx;
                    if(tmp == nullptr){
                        cout<<"Valore non trovato"<<endl;
                    return nullptr;
                    }
                }else{
                    tmp = tmp->dx;
                    if(tmp == nullptr){
                    cout<<"Valore non trovato"<<endl;
                    return nullptr;
                    }
                }
            }
            nodo_to_AP = tmp;
            cout<<nodo_to_AP->dato<<endl;
            return nodo_to_AP;
        }


        void delete_nodo(nodo * tmp){
            //caso foglia 
            if(tmp->sx == nullptr && tmp ->dx == nullptr){
                if(tmp->parente->sx == tmp){
                    tmp->parente->sx = nullptr;
                }else{
                    tmp->parente->dx = nullptr;
                }
                delete tmp;
                return;
            }else 
            //caso figlio sx
            if(tmp->sx != nullptr && tmp->dx == nullptr){
                tmp->sx->parente = tmp->parente;
                if(tmp == tmp->parente->sx){
                    tmp->parente->sx = tmp->sx;
                }else{
                    tmp->parente->dx = tmp->sx;
                }
                delete tmp;
                return;
            }
            //caso figlio dx
            if(tmp->dx != nullptr && tmp->sx == nullptr){
                tmp->dx->parente = tmp->parente;
                if(tmp == tmp->parente->sx){
                    tmp->parente->sx = tmp->dx;
                }else{
                    tmp->parente->dx = tmp->dx;
                }
            }
            nodo * succ = min(tmp->dx);   //Nodo con due figli
            int swap = tmp->dato;
            tmp->dato = succ->dato;
            succ->dato= swap;
            delete_nodo(succ); 
        }

        void delete_nodo(int num){
            if(root == nullptr){
                cout<<"L'albero non esiste"<<endl;
                return ;
            }
            nodo * to_delete = ricerca_interna(num);
            if(to_delete == nullptr){
                cout<<"Il valore non è stato trovato"<<endl;
                return;
            }
            delete_nodo(to_delete);            
        }

        /*nodo * padre(int n){
            nodo * tmp = ricerca_interna(n);
            cout<<tmp->parente->dato;
            return tmp->parente;
        }*/

};

int main(){
    bst albero;
    albero.inserimento_interno(16);
    albero.inserimento_interno(14);
    albero.inserimento_interno(18);
    albero.inserimento_interno(13);
    albero.inserimento_interno(15);
    albero.inserimento_interno(17);
    albero.inserimento_interno(19);
    albero.inserimento_interno(12);
    albero.pre_order();
    albero.in_order();
    albero.post_order();
    //albero.stampa_parente();
    albero.min();
    albero.max();
    //albero.successore(16);
    albero.ricerca_interna(17);
    albero.successore(16);
    cout<<endl<<endl;
    albero.delete_nodo(16);
    albero.pre_order();
    albero.in_order();
    albero.post_order();
    //albero.padre(18);
}
