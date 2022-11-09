
typedef int* item;

typedef struct {
    int tamanho;
    int capacidade;
    item elemento;
}heap;


int CorrigeHeapDescendo(heap H, int i){
    int maior=i;
    /*Caso o elemento na posição 2i tenha prioridade maior que o elemento na posição i */
    if(2*i<=H.tamanho && H.elemento[2*i] > H.elemento[maior]){
        maior=2*i;
    }
    /*Caso o elemento na posição 2i+1 tenha prioridade maior que o elemento na posição i */
    if(2*i+1<=H.tamanho && H.elemento[2*i+1] > H.elemento[maior]) {
        maior=2*i+1;
    }
    if(maior != i) {
        /*Troca o indice filho de maior valor com o índice pai de menor valor  */
        troca(H.elemento[i], H.elemento[maior]);
        /*Troca o elemento filho de maior valor com o elemento pai de menor valor  */
        troca(H.elemento[i], H.elemento[maior]);
        /*É possível que a troca tenha bagunçado o heap, por isso chamamos a função novamente para corrigir*/
        CorrigeHeapDescendo(H,maior);
    }
}

int CorrigeHeapSubindo(heap H, int i) {
    int pai=i/2;
    if(i>=2 && H.elemento[i] > H.elemento[pai]){
        troca(H.elemento[i], H.elemento[pai]);
        troca(H.elemento[i], H.elemento[pai]);
        CorrigeHeapSubindo(H,pai);
    }
}