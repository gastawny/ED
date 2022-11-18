#include<stdio.h>
#include<stdlib.h>

typedef struct Tno {
    int chave;
    struct Tno *ant;
    struct Tno *prox;
} Tno;

void inserirComeco(Tno **lista, int k);
void inserirFinal(Tno **lista, int k);
int contadorDeElementos(Tno *lista);
void mostraLista(Tno *lista);
void removeDoInicio(Tno **lista);
void removeDoFinal(Tno **lista);
void removeElemento(Tno **lista, int k);
Tno *encontraElemento(Tno *lista, int k);
void desalocaLista(Tno **lista);

int main() {
    Tno *lista=NULL;
    for(int i=0;i<10;i++)
       insereComeco(&lista,i);
    desalocaLista(&lista);
    return 0;
}

void inserirComeco(Tno **lista, int k) {
    Tno *novo = (Tno*)malloc(sizeof(Tno));
    if(!novo) return;
    novo->chave = k;
    if(!*lista) {
        novo->prox = novo->ant = NULL;
        *lista = novo;
        return;
    }
    novo->ant = NULL;
    (*lista)->ant = novo;
    novo->prox = *lista;
    *lista = novo;
}

void inserirFinal(Tno **lista, int k) {
    Tno *novo = (Tno*)malloc(sizeof(Tno)), *aux;
    if(!novo) return;
    novo->chave = k;
    if(!*lista) {
        novo->prox = novo->ant = NULL;
        *lista = novo;
        return;
    }
    for(aux = *lista;aux->prox;aux = aux->prox);
    aux->prox = novo;
    novo->ant = aux;
    novo->prox = NULL;
}

int contadorDeElementos(Tno *lista) {
    int i;
    for(i=0;lista;lista = lista->prox, i++);
    return i;
}

void mostraLista(Tno *lista) {
    for(;lista;lista = lista->prox)
        printf("%d ",lista->chave);
    printf("\n");
}

void removeDoInicio(Tno **lista) {
    Tno *aux = *lista;
    if(!*lista) return;
    if(!(*lista)->prox) {
        free(*lista);
        *lista = NULL;
        return;
    }
    (*lista)->prox->ant = NULL;
    (*lista) = (*lista)->prox;
    free(aux);
}

void removeDoFinal(Tno **lista) {
    Tno *aux1, *aux2;
    if(!*lista) return;
    if(!(*lista)->prox) {
        free(*lista);
        *lista = NULL;
        return;
    }
    for(aux1 = *lista;aux1->prox;aux1 = aux1->prox);
    aux2 = aux1;
    aux1->ant->prox = NULL;
    free(aux2);
}

void removeElemento(Tno **lista, int k) {
    int FLAG;
    Tno *aux1, *aux2;
    if(!*lista) return;
    if(!(*lista)->prox) {
        free(*lista);
        *lista = NULL;
        return;
    }
    if((*lista)->chave == k) {
        removeDoInicio(lista);
        return;
    }
    for(aux1 = *lista, FLAG = 0;aux1->chave!=k;aux1 = aux1->prox)
        if(aux1->chave != k && !aux1->prox)
            FLAG = 1;
    if(FLAG) return;
    if(!aux1->prox) {
        removeDoFinal(lista);
        return;
    }
    aux2 = aux1;
    aux1->ant->prox = aux1->prox;
    aux1->ant->prox->ant = aux1->ant;
    free(aux2);
}

Tno *encontraElemento(Tno *lista, int k) {
    for(;lista;lista = lista->prox)
        if(lista->chave == k)
            return lista;
    return NULL;
}

void desalocaLista(Tno **lista) {
    while(*lista)
        removeDoInicio(lista);
}
