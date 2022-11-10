#include <stdio.h>
#include <stdlib.h>

typedef int* item;

typedef struct {
    int tamanho;
    int capacidade;
    item elemento;
}heap;

void troca(heap * H, int i, int j){
    int aux;
    aux=H->elemento[i];
    H->elemento[i]=H->elemento[j];
    H->elemento[j]=aux;
}

void CorrigeHeapDescendo(heap * H, int i){
    int maior=i;
    /*Caso o elemento na posição 2i tenha prioridade maior que o elemento na posição i */
    if(2*i<=H->tamanho && H->elemento[2*i] > H->elemento[maior]){
        maior=2*i;
    }
    /*Caso o elemento na posição 2i+1 tenha prioridade maior que o elemento na posição i */
    if(2*i+1<=H->tamanho && H->elemento[2*i+1] > H->elemento[maior]) {
        maior=2*i+1;
    }
    if(maior != i) {
        /*Troca o indice filho de maior valor com o índice pai de menor valor  */
        troca(H, i, maior);
        /*Troca o elemento filho de maior valor com o elemento pai de menor valor  */
        /*É possível que a troca tenha bagunçado o heap, por isso chamamos a função novamente para corrigir*/
        CorrigeHeapDescendo(H,maior);
    }
}

void CorrigeHeapSubindo(heap * H, int i) {
    int pai=i/2;
    if(i>=2 && H->elemento[i] > H->elemento[pai]){
        troca(H,i,pai);
        CorrigeHeapSubindo(H,pai);
    }
}

void ConstroiHeap(heap *H, int i){
    H->tamanho=i;
    for(i=H->tamanho/2;i>0;i--){
        CorrigeHeapDescendo(H,i);
    }

}

void InsereHeap(heap * H, int x){
    if(H->tamanho < H->capacidade) {
        H->tamanho=H->tamanho+1;
        H->elemento[H->tamanho]=x;
        CorrigeHeapSubindo(H,H->tamanho);
    }
}

int RemoveHeap(heap * H){
    int i=H->elemento[1];
    if(H->tamanho>=1){
        H->elemento[1]=H->elemento[H->tamanho];
        H->tamanho=H->tamanho-1;
        CorrigeHeapDescendo(H,1);
    }
    return i;
}

int main(){
    int i, x;
    heap * H;
    
    H=malloc(sizeof(heap));

    H->tamanho=7;
    H->capacidade=20;
    H->elemento=malloc(H->capacidade*sizeof(item));

    H->elemento[1]=10;
    H->elemento[2]=50;
    H->elemento[3]=3;
    H->elemento[4]=13;
    H->elemento[5]=15;
    H->elemento[6]=1;
    H->elemento[7]=20;

    ConstroiHeap(H,H->tamanho); 

    for(i=1;i<H->tamanho+1;i++){
        printf(" %d ", H->elemento[i]);
    }

    printf("\n");
    x=70;
    InsereHeap(H,x);

    for(i=1;i<H->tamanho+1;i++){
        printf(" %d ", H->elemento[i]);
    }
    printf("\n");

    i=RemoveHeap(H);
    printf("O elemento removido foi %d \n", i);

    for(i=1;i<H->tamanho+1;i++){
        printf(" %d ", H->elemento[i]);
    }

    printf("\n");

    free(H);
    free(H->elemento);

    return 0;    
}
