#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *v, int tam);
void insertionSort(int *v, int tam);
void selectionSort(int *v, int tam);
void mergeSort(int *v, int ini, int fim);
void quickSort(int *v, int ini, int fim);
void shellSort(int *vet, int size);

int main() {
    
    printf("Metodos de Ordenacao\n");
    
    return 0;
}

void bubbleSort(int *v, int tam) {
    for(int i=0;i<tam;i++)
        for(int j=0, aux;j<tam;j++)
            if(v[j+1]<v[j]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}

void insertionSort(int *v, int tam) {
    for(int i=1;i<tam;i++)
        for(int j=i-1,aux=v[i];j>=0 && aux<v[j];j--) {
            aux=v[j+1];
			v[j+1] = v[j];
			v[j]=aux;
        }
}

void selectionSort(int *v, int tam) {
    for(int i=0,aux,aux2,aux3;i<tam;i++) {
        aux = v[i];
        aux2 = i;
        for(int j=i;j<tam;j++) {
            if(v[j]<aux) {
                aux = v[j];
                aux2 = j;
            }
        }
        aux3 = v[i];
        v[i] = aux;
        v[aux2] = aux3;
    }
}

void mergeSort(int *v, int ini, int fim) {
    if(ini<fim-1) {
        int meio = (ini + fim) / 2;
        mergeSort(v,ini,meio);
        mergeSort(v,meio,fim);

        int *w, i = ini, j = meio, k = 0;
        w = (int*)malloc((fim-ini)*sizeof(int));
        while (i < meio && j < fim) {
            if (v[i] <= v[j])  w[k++] = v[i++];
            else  w[k++] = v[j++];
        }             
        while (i < meio)  w[k++] = v[i++];
        while (j < fim)  w[k++] = v[j++];
        for (i = ini; i < fim; ++i)  v[i] = w[i-ini];
        free (w); 
    }
}

void quickSort(int *v, int ini, int fim) {
    int pivo = v[ini], i = ini, j = fim, aux;
    while(i<=j) {
        while(v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
		 	aux = v[j];
	     	v[j--] = v[i];
	     	v[i++] = aux;
		}
    }
    if(ini<j) quickSort(v,ini,j);
	if(i<fim) quickSort(v,i,fim);
}

void shellSort(int *vet, int tam) {
    int i, j, valor, h = (tam) / 2;
    // for(h=1;h<tam;h=3*h+1);
    for(;h>0;h=h/2)
        for(i=h;i<tam;i++) {
            valor = vet[i];
            j = i;
            while(j>h-1 && valor<=vet[j-h]) {
                vet[j] = vet[j-h];
                j = j - h;
            }
            vet[j] = valor;
        }
}
