#include <iostream>
using namespace std;

class albero    //Inizializzare una classe albero
{
    private:
    struct alb
    {
        int value;  //dato
        alb* dx;    //puntatore destro
        alb* sx;    //puntatore sinistro
    };
    alb* root;  //puntatore col nome della struct, rappresenta la radice
    public:
    
    albero(){}  //Inizializzazione costruttore
    
    alb* getRoot(){return root;}    //Funzione che ritorna radice
    
    void inse(int x)            /*funzione per l'inserimento dei nodi, dentro di questa funzione si trova 
                                anche un altra funzione "Inserisci" che semplifica il passaggio dei parametri nella funzione
                                una volta richiamata nel main*/
    {
        root=inserisci(root, x);
    }

    alb* inserisci(struct alb* root, int x);    //prototipo della funzione(si trova dentro "inse")
    alb* rimuovi(struct alb* root, int x)       //Funzione per rimuovere un nodo
    {
        if (root == nullptr)                    //controllo per verificare se l'albero è vuoto
        {
            return root;                        //ritorna la radice
        }
        if(x > root->value)                     //verifica che il valore inserito sia maggiore della radice
        {
            root->dx=rimuovi(root->dx,x);       //se così dovesse essere root punterà a destra e sarà uguale al valore dentro la funzione rimuovi
        }
        else if(x < root->value)            //Un ulteriore if che controlla che il valore inserito sia minore della radice  
        {
            root->sx=rimuovi(root->sx,x);       //nel caso in cui dovesse essere minore si andrà a sostituire il nodo di sinistra
        }
        else
        {
            if(root->dx==nullptr && root->sx==nullptr)  //ulteriore controllo verificando che a sinistra e a destra della radice ci siano nodi
            {
                delete root;                            //se non dovessero esserci nodi la radice verrebbe eliminata
                return nullptr;                         //ritornerà semplicemente un puntatore a null
            }
            if(root->dx=nullptr)                        //controllo che a destra della radice non sia vuoto
            {
                alb* temp= root->sx;                    //una variabile dello stesso tipo di struttura dati ma temporanea che 
                                                        //andrà ad acquisire il valore del nodo a sinistra della radice
                
                delete root;                            //la radice viene così eliminata
                return temp;                            //ritorna la variabile temporanea
            }
            if(root->sx=nullptr)                        //controllo  come in precedenza ma a sinistra della radice
            {
                alb* temp= root->dx;                    //stesso metodo utilizzato prima ma al posto del nodo sx useremo quello di dx
                delete root;
                return temp;
            }
            else                                        //altrimenti ricerca il nodo più piccolo a destra della radice
            {
                alb* temp=findmin(root->dx);            //utilizzando sempre una variabile temporanea richiamiamo la funzione
                                                        //"findmin" facendo puntare la radice a destra
                
                root->value=temp->value;                //la variabile temporanea che punta al valore del nodo sarà uguale alla radice che punta al valore del nodo
                root->dx=rimuovi(root->dx, temp->value);//il nodo di destra andrà rimosso e al suo posto verrà inserito il valore temporaneo
            }
        }
        return root;                                    //al termine della funzione verrà ritornata la radice
    }
    void rim(int x)                                     //funzione al cui interno troviamo la funzione "rimuovi", nella funzione rim verrà 
                                                        //passato solamente il valore che decidiamo di rimuovere tenendo conto della funzione "rimuovi"
                                                        //al cui interno troviamo la radice ed il valore inserito 
    {
        rimuovi(root, x);
    }
    void stampa(alb* root)                               //funzione per la stampa dell'albero, il parametro inserito è la radice
    {
        if(root==nullptr)                                //controllo per verificare che non sia vuoto
        {
            return;
        }
        cout<<root->value<<endl;                        //stampa del valore 
        stampa(root->sx);                       
        stampa(root->dx);                               //passaggio effettuato anche a sinistra e destra della radice
    }
    
    alb* findmin(alb* node)                           //funzione con tipo dellla struttura dati, cercherà il nodo più piccolo
    {
        while(node->sx!=nullptr)                        //ciclo che si ripete fin quando non terminano i nodi
        {
            node=node->sx;                          //nodo avrà lo stesso valore del nodo alla sua destra
        }
        return node;                        //ritornerà il nodo
    }

    albero::alb* albero::inserisci(struct alb* root, int x) /*albero::alb*: Questa parte indica il tipo di ritorno della funzione inserisci. 
                                                        In questo caso, la funzione restituirà un puntatore a un oggetto di tipo albero::alb,
                                                        che è un tipo definito all'interno della classe albero.Questo tipo è usato per rappresentare i nodi dell'albero binario di ricerca.
                                                        
                                                        albero::inserisci: Questa parte specifica il nome della funzione, che è inserisci. 
                                                        La notazione albero:: indica che questa funzione è un membro della classe albero.*/
    {
        
        if(root==nullptr)                               //Controllo radice non vuota
        {
            alb* temp= new alb;                         //locazione dinamica puntatore di tipo struttura dati temporanea
            temp->dx=nullptr;                           
            temp->sx=nullptr;
            temp->value=x;                      //temp che guarda al valore sarà uguale al parametro inserito ("x")
            return temp;                        //ritorna temp
        }
        if(x>root->value)                   //se il nodo è più grande della radice andrà a destra
        {
            root->dx=inserisci(root->dx, x);        //inserisce il nodo a destra
        }
        if(x<root->value)                   //se il nodo è minore della radice andrà a sinistra
        {
            root->sx=inserisci(root->sx, x);        //inserisce il nodo a sinistra
        }
        return root;                               //ritorna la radice
    }


};


int main()
{
    albero fro;                                    //creazione oggetto
    fro.inse(9);
    fro.inse(12);
    fro.inse(8);
    fro.inse(11);
    fro.inse(10);
    fro.inse(13);                                //fin qui inserimento dei nodi
    fro.rim(13);                                //rimozione nodo specificato
    fro.stampa(fro.getRoot());                  //stampa albero
}