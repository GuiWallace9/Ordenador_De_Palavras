#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char*string1, char*string2){
    int i=0;

    while(string1[i] != '\0' || string2[i] != '\0'){
        if(string1[i]>string2[i]){
            return 0;
        } else if(string1[i]<string2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

void insertionSort (char **words, int n) {
  int i, k, j, length1, length2;
  char *key;
  key=malloc(10*sizeof(char));
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    length1=strlen(words[i]);
    for(k=0;k<length1+1;k++){
        key[k]=words[i][k];
    }
    j = i - 1;
    /* encontra a posicao correta de chave (A[i])
       no vetor A[0..i-1] */
    while (j >= 0 && compare(key, words[j])) {
        if(strlen(words[j])>strlen(key)) length2=strlen(words[j]);
        else length2=strlen(key);
        for(k=0;k<length2+1;k++){
            words[j+1][k]=words[j][k];
        }       
        j=j-1;
    }
    
    for(k=0;k<length1+1;k++){
        words[j+1][k]=key[k];
    } 
  }
  free(key);
}




int main() {
    int i, n;
    char **words;

    printf("Insert the number of words: \n");
    scanf("%d", &n);

    words=malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
        words[i]=malloc(10*sizeof(char));
    }

    for(i=0;i<n;i++){
        scanf("%s", words[i]);
    }
    insertionSort(words,n);
    printf("\n");
    
    for(i=0;i<n;i++){
        printf("%s", words[i]);
        printf("\n");
    }

    for(i=0;i<n;i++){
        free(words[i]);
    }
    free(words);

  return 0;
}