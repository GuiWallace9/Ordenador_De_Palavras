#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int i;
    char *word1, *word2;

    word1=malloc(10*sizeof(char));
    word2=malloc(10*sizeof(char));

    printf("Digite as duas palavra \n");
    scanf("%s %s", word1, word2);

    i=compare(word1,word2);
    printf("\n\n");
    if(i) printf("%s \n%s \n", word1, word2);
    else printf("%s \n%s \n", word2, word1);

    return 0;
}
