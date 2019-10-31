#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Matroid.h"

// No entiendo los matroids con void *
// Ya la palmé anoche y no aguanto la cabeza


//Funcion y arreglos de los primeros tres matroids


bool pair(int pNumber){
    if ((pNumber % 2) == 0){
        return true;
    }else{
        return false;
    }
}

bool inAWord(const char *input, const char *contains){
    bool check[256] = { false };
    while(*input){
        check[(unsigned char)*input++] = true;
    }
    while(*contains){
        if(!check[(unsigned char)*contains++])
            return false;
    }
    return true;
}

bool palindrome(char * pMyString) {
    int space = strlen(pMyString);
    if (space <= 1) return 1;
    int beg = 0, end = space - 1;
    while (pMyString[beg] == pMyString[end]){
        if (beg >= end) return true; // when gets to the center of the word it says it's palindrome
        beg ++;
        end--;
    }
    return false;//If it gets here the word is not palindrome
}

//Funcion y arreglos de los otros


/*int main() {

    int tamano = 5;
    struct element A[tamano];
    int I[tamano];
    for (int number = 0; number < tamano; number++) {
        A[number].x = number+100;
        A[number].passed = false;
        I[number] = -1;
    }

    #pragma omp parallel num_threads(sizeof(A)/sizeof(A[0]))
    {
        printf("ENTRA  al proceso %d \n", omp_get_thread_num());
        tested(&A[omp_get_thread_num()]);
    }

    for (int i = 0; i < tamano; i++) {
        if(A[i].passed == true){
            I[i] = A[i].x;
        }
    }

    printf("\n------------Resultado------------\n");
    for (int i = 0; i < tamano; i++){
        if(I[i] != -1)
            printf("numero %d, ",I[i]);
    }


    return 0;
}

int main(){

    //Se crean 3 matroids con funciones distintas y se ejecutan


    //Se crean 5 matroids con la misma funcion y se ejecutan


}

int main() {

    #pragma omp parallel
    {
        printf("Hello, World!\n");
    }

    printf("termino prro");
}*/