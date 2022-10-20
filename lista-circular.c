#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int chave;
    struct no *prox;
}TNo;

void insereComeco(TNo **lista, int k);
void insereFinal(TNo **lista, int k);
void mostraLista(TNo *lista);
void removeDoInicio(TNo **lista);
void desalocaLista(TNo **lista);
TNo *encontraElemento(TNo *lista, int k);
void removeElemento(TNo **lista, int k);
void removeDoFinal(TNo **lista);

int main() {
    TNo *lista=NULL;
    for(int i=0;i<10;i++)
       insereComeco(&lista,i);
    desalocaLista(&lista);
    
    return 0;
}

void insereComeco(TNo **lista, int k) {
    TNo *novo=(TNo*)malloc(sizeof(TNo));
    if(!novo) return;
    novo->chave = k;    
    if(!*lista) {
        *lista = novo;
        novo->prox = novo;
        return;
    }
    novo->prox = (*lista)->prox;
    (*lista)->prox = novo;
}

void insereFinal(TNo **lista, int k) {
    TNo *novo=(TNo*)malloc(sizeof(TNo));
    if(!novo) return;
    novo->chave = k;
    if(!*lista) {
        *lista = novo;
        novo->prox = novo;
        return;
    }
    novo->prox = (*lista)->prox;
    (*lista)->prox = novo;
    *lista = novo;
}

void mostraLista(TNo *lista) {
    if(!lista) {
        printf("\nLista Vazia\n");
        return;
    }
    TNo *aux=lista->prox;
    do {
        printf("%d ",aux->chave);
        aux = aux->prox;
    }while(aux!=lista->prox);
    printf("\n");
}

void removeDoInicio(TNo **lista) {
    if(!*lista) return;
    if(*lista == (*lista)->prox) {
        *lista = NULL;
        return;
    }
    TNo *aux = (*lista)->prox;
    (*lista)->prox = (*lista)->prox->prox;
    free(aux);
}

void desalocaLista(TNo **lista) {
    if(*lista) {
        TNo *aux=(*lista)->prox;
        while(1) {
            removeDoInicio(lista);
            aux = aux->prox;
            if(!*lista)
                break;
        }
    }
}

TNo *encontraElemento(TNo *lista, int k) {
    if(!lista) return NULL;
    TNo *aux = lista;
    while(lista!=aux) {
        if(lista->chave==k)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

void removeElemento(TNo **lista, int k) {
    if(!*lista) return;
    TNo *aux1, *aux2;
    for(aux1=(*lista)->prox;aux1!=*lista;aux1=aux1->prox)
        if(aux1->prox->chave == k) {
            if(aux1->prox->chave == (*lista)->chave)
                *lista = aux1->prox->prox;
            aux2 = aux1->prox;
            aux1->prox = aux1->prox->prox;
            free(aux2);
        }
}

void removeDoFinal(TNo **lista) {
    removeElemento(lista, (*lista)->chave);
}
