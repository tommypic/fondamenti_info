#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next; 
} nodo;


void stampalista(nodo *lista);
int lunghezzalista(nodo *lista);
void inseriscielemento(nodo *lista, int elemento, int posizione);
void sommalista (nodo *lista);
void eliminaripetizioni(nodo *lista);
void eliminanodo(nodo *lista, nodo *nododaelim);


int main(){
    nodo *lista, *temp, *nodocorr;
    for(int i = 0; i < 7; i++){
        nodocorr = (nodo *)malloc(sizeof(nodo));
        
        nodocorr->dato = i;
        

        if (i == 0){
            lista = temp = nodocorr;
        }

        else{
            temp->next = nodocorr;   //temp e' il nodo precedente a nodocorr
            temp = nodocorr;
        }
    }

    temp->next = NULL;


    stampalista(lista);
    printf("\n\n");
    stampalista(lista);
    eliminaripetizioni(lista);
    printf("\n\n");
    stampalista(lista);
}

void stampalista(nodo *lista){

    nodo *temp = lista;
    while(temp != NULL){
        printf("%d \n",temp->dato);
        temp = temp->next;
    }
}

int lunghezzalista(nodo *lista){
    nodo *temp = lista;
    int contatore = 0;
    while(temp != NULL){
        temp = temp->next;
        contatore++;

    }
    return contatore;
}

void inseriscielemento(nodo *lista, int elemento, int posizione){
    nodo *temp1, *temp2;
    temp1 = lista;                         // inizializzo il puntatore sulla testa della lista
    for(int i = 1; i < posizione-1; i++){  //mi sposto sull'elemento alla posizione prima di quello che voglio inserire 
        temp1 = temp1->next;
    }
    temp2 = temp1->next;              //salvo un altro puntatore successivo a quello che voglio inserire
    nodo *nuovopunt = (nodo*) malloc(sizeof(nodo));        //creo il nuovo nodo 
    nuovopunt->dato = elemento; 
    temp1->next = nuovopunt;
    nuovopunt->next = temp2;

}

void sommalista(nodo *lista){
    nodo *temp, *temp1;
    temp1 = lista;
    int contatore;
    int lunghezza = lunghezzalista(lista);
    for(int i = 0; i < lunghezza; i++){
        temp = temp1;
        for(int j = i; j < lunghezza; j++){
            contatore += temp->dato;
            temp = temp->next;
        }
        temp1->dato = contatore;
        temp1 = temp1->next;
        contatore = 0; 
    }
}

void eliminanodo(nodo *lista, nodo *nododaelim){
    nodo *temp;
    temp = lista;
    if(lista == nododaelim){             //se mi trovo in testa alla lista elimino il nodo e basta
        free(nododaelim);

    }
    else {
        while(temp->next != nododaelim){
            temp = temp->next;
        }
        temp->next = nododaelim->next;
        free(nododaelim);
    }
}

void eliminaripetizioni(nodo *lista){
    nodo *temp1, *temp2;                //dichiaro i due nodi che mi servono per scorrere la lista
    temp1 = lista;
    while(temp1 != NULL){               //creo due cicli, il nodo del secondo parte dal nodo successivo al primo per evitare di controllare due volte
        temp2 = temp1;
        while(temp2->next != NULL){      
            if(temp1->dato == temp2->next->dato){
                eliminanodo(lista, temp2->next);
            }
            temp2 = temp2->next;       // in questo modo scorro senza errori se eliminavo temp2 non sarei potuto passare al nodo successivo 
        }
        temp1 = temp1->next;
    }

}
