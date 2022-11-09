#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(strlen(string1)==strlen(string2)) return 0;
    else if(strlen(string1)>strlen(string2)) return 1;
    else return -1;
    
}

void  intercala (int p, int q, int r, char **words)  {
  int n1, n2;
  char **A, **B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (char));  
  for(i=0;i<n1;i++){
    A[i]=malloc(10*sizeof(char));
  }    
  B = malloc (n2 * sizeof (char)); 
  for(i=0;i<n2;i++){
    B[i]=malloc(10*sizeof(char));
  }   


  for (i = 0; i < n1; i++) {
    A[i]=words[p+i];
  }

  for (i = 0; i < n2; i++){
    B[i] = words[q+1 + i];
  }


  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {                
    if (compare(A[i],B[j])<=0){
        words[k]=A[i++];
    }
    else {
        words[k]=B[j++];
    }
    k++;
  }

  while (i < n1)
    words[k++] = A[i++];         
  while (j < n2)
    words[k++] = B[j++];
/*
  free(A);
  free(B); */
}



void mergeSort (int p, int r, char **words) {
  int q;
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, words);       
    mergeSort(q+1, r, words);       
    intercala(p, q, r, words);    
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

    mergeSort(0, n-1, words);



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