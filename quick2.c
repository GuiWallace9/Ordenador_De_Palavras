#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void troca (char **words, int i, int j){
    int k, length;
    char *aux;
    aux=malloc(sizeof(char));
    length=strlen(words[j]);
    for(k=0;k<length+1;k++){
        aux[k]=words[j][k];
    }
    length=strlen(words[i]);
    for(k=0;k<length+1;k++){
        words[j][k]=words[i][k];
    }
    length=strlen(aux);
    for(k=0;k<length+1;k++){
        words[i][k]=aux[k];
    }
    free(aux);
}

int compare(char*string1, char*string2){
    int i=0;

    while(string1[i] != '\0' && string2[i] != '\0'){
        if(string1[i]>string2[i]){
            return +1;
        } else if(string1[i]<string2[i]){
            return -1;
        }
        i++;
    }
    return 0;
}



int particiona (char **words, int ini, int fim) {
  int i, j;
  char *pivo;

  pivo = words[fim];
  i = ini;
  for (j = ini; j < fim; j++){
    if (compare(words[j],pivo)<=0){
      troca(words, i, j);
      i++;
    } 
  }
  troca(words, i, fim);

  return i;
}

void quicksort (char **words, int ini, int fim) {
  int x;

  if (ini < fim){
    x = particiona(words, ini, fim);
    quicksort(words, ini, x - 1);
    quicksort(words, x + 1, fim);
  }
}




int main() {
    int i, n;
    char **words;

    printf("Digite a quantidade de palavras: \n");
    scanf("%d", &n);

    words=malloc(n*sizeof(char *));

    for(i=0;i<n;i++){
        words[i]=malloc(10*sizeof(char));
    }

    printf("Digite as %d palavras \n", n);

    for(i=0;i<n;i++){
        scanf("%s", words[i]);
    }

    quicksort(words, 0, n - 1);



    printf("\n");
    for(i=0;i<n;i++){
        printf("%s \n", words[i]);
    }
  
  for(i=0;i<n;i++){
    free(words[i]);
  }
  free(words);
  return 0;
}