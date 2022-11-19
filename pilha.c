#include<stdio.h>
#include<stdlib.h>

typedef struct Tno {
    int chave;
    struct Tno *prox;
}Tno;

void insereNo(Tno **pilha, int k);
void removeNo(Tno **pilha);
void desalocaPilha(Tno **pilha);
void mostraPilha(Tno *pilha);

int main() {
    Tno *pilha = NULL;
    for(int i=0;i<10;i++)
        insereNo(&pilha, i);
    mostraPilha(pilha);
    for(int i=0;i<4;i++)
        removeNo(&pilha);
    mostraPilha(pilha);
    desalocaPilha(&pilha);
    mostraPilha(pilha);
    for(int i=0;i<10;i++)
        insereNo(&pilha, i);
    mostraPilha(pilha);
    for(int i=0;i<4;i++)
        removeNo(&pilha);
    mostraPilha(pilha);
    desalocaPilha(&pilha);

    return 0;
}

void insereNo(Tno **pilha, int k) {
    Tno *novo = (Tno*)malloc(sizeof(Tno));
    if(!novo) return;
    novo->chave = k;
    novo->prox = *pilha;
    *pilha = novo;
}

void removeNo(Tno **pilha) {
    Tno *aux = *pilha;
    (*pilha) = (*pilha)->prox;
    free(aux);
}

void desalocaPilha(Tno **pilha) {
    while(*pilha)
        removeNo(pilha);
}

void mostraPilha(Tno *pilha) {
    for(;pilha;pilha=pilha->prox)
        printf("%d ",pilha->chave);
    printf("\n");
}
