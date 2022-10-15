#include<stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *prox;
} No;

void inserirComeco(No **lista, int k);
void inserirFinal(No **lista, int k);
int contadorDeElementos(No *lista);
void inverteLista(No *lista, No **novo);
void mostra(No *lista);
void removeDoInicio(No **lista);
void removeDoFinal(No *lista);
void removeElemento(No *lista, int k);
No *encontraElemento(No *lista, int k);
void desalocaLista(No **Lista);

int main() {
    No *lista = NULL;
    for(int i=0;i<2;i+=2)
       inserirComeco(&lista,i);
    desalocaLista(&lista);
    
    return 0;
}

void inserirComeco(No **lista, int k) {
    No *novo = (No*)malloc(sizeof(No));
    if(novo) {
        novo->chave = k;
        novo->prox = *lista;
        *lista = novo;
    }
}

void inserirFinal(No **lista, int k) {
    No *novo = (No*)malloc(sizeof(No));
    if(novo) {
        novo->chave = k;
        novo->prox = NULL;
        if(!*lista)
            *lista = novo;
        else {
            No *aux=*lista;
            while(aux->prox) 
                aux = aux->prox;
            aux->prox = novo;
        }
    }
}

int contadorDeElementos(No *lista) {
    int i=0;
    while(lista!=NULL) {
        lista = lista->prox;
        i++;
    }
    return i;
}

void inverteLista(No *lista, No **novo) {
    if(*novo)
        free(*novo);
    *novo = (No*)malloc(sizeof(No));
    if(lista) {
        int n = contadorDeElementos(lista);
        for(int i=0;i<n;i++) {
            if(i==0) {
                (*novo)->prox = NULL;
                (*novo)->chave = lista->chave;
            } else
                inserirComeco(novo,lista->chave);
            lista = lista->prox;
        }
    } else *novo = NULL;
}

void mostra(No *lista) {
    while(lista!=NULL) {
        printf("%d\n",lista->chave);
        lista = lista->prox;
    }
}

void removeDoInicio(No **lista) {
    No *aux = NULL;
    if(lista) {
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}

void removeDoFinal(No *lista) {
    No *aux=NULL;
    if(lista) {
        int i, n=contadorDeElementos(lista);
        aux = lista;
        while(aux->prox)
            aux = aux->prox;
        free(aux);
        aux = lista;
        for(i=0;i<n-1;i++) {
            if(i==n-2)
                aux->prox = NULL;
            aux = aux->prox;
        }
    }
}

void removeElemento(No *lista, int k) {
    No *aux1=NULL, *aux2=NULL;
    if(lista) {
        int i;
        aux1 = lista;
        for(i=0;aux1->chave!=k;i++)
            aux1 = aux1->prox;
        aux2 = aux1;
        for(aux1=lista;i>0;i--,aux1 = aux1->prox)
            if(i==1)
                aux1->prox = aux1->prox->prox;
        free(aux2);
    }
}

No *encontraElemento(No *lista, int k) {
    No *elemento = NULL;
    if(lista) {
        No *aux=lista;
        while(aux->chave!=k)
            aux = aux->prox;
        return aux;
    } else return NULL;
}

void desalocaLista(No **lista) {
    while((*lista)->prox!=NULL)
        removeDoFinal(*lista);
    free(*lista);
    *lista = NULL;
}
