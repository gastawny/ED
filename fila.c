#include<stdio.h>
#include<stdlib.h>

typedef struct Tno {
    int chave;
    struct Tno *prox;
}Tno;

void insereNo(Tno **fila, int k);
void removeNo(Tno **fila);
void desalocaFila(Tno **fila);
void mostraFila(Tno *fila);

int main() {
    Tno *fila = NULL;
    for(int i=0;i<10;i++)
        insereNo(&fila, i);
    mostraFila(fila);
    for(int i=0;i<4;i++)
        removeNo(&fila);
    mostraFila(fila);
    desalocaFila(&fila);
    mostraFila(fila);
    for(int i=0;i<10;i++)
        insereNo(&fila, i);
    mostraFila(fila);
    for(int i=0;i<4;i++)
        removeNo(&fila);
    mostraFila(fila);
    desalocaFila(&fila);

    return 0;
}

void insereNo(Tno **fila, int k) {
    Tno *novo = (Tno*)malloc(sizeof(Tno)), *aux = *fila;
    if(!novo) return;
    novo->chave = k;
    novo->prox = NULL;
    if(!*fila) {
        (*fila) = novo;
        return;
    }
    while(aux->prox)
        aux = aux->prox;
    aux->prox = novo;
}

void removeNo(Tno **fila) {
    Tno *aux = *fila;
    (*fila) = (*fila)->prox;
    free(aux);
}

void desalocaFila(Tno **fila) {
    while(*fila)
        removeNo(fila);
}

void mostraFila(Tno *fila) {
    for(;fila;fila=fila->prox)
        printf("%d ",fila->chave);
    printf("\n");
}
