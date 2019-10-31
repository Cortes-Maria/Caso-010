#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Matroid.h"


//Funciones de los primeros tres matroids

void pair(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    for(int elem = 0; elem < size; elem++){
        int actual = pMat->S[elem];
        if((actual % 2) == 0){
            pMat->I[pos] = actual;
            pos++;
        }
    }
    for(int i = 0; i<pos; i++){
        printf("Numero %d", pMat->I[i]);
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

bool higherTanThousand(int pNumber){
    int count = 0;
    while(pNumber != 0){
        count++;
        pNumber /= 10;
    }
    if(count >= 4){
        return true;
    }else{
        return false;
    }
}

int main(void)
{
    struct Matroid M1 = {{0,2,3,4,5,6,7},{NULL},pair};
    struct Matroid M2 = {{0,2,55,4,5,6,12},{NULL},pair};
    struct Matroid matrArray[] = {M1,M2};

    int size =  (int)( sizeof(matrArray) / sizeof(matrArray[0]));
    //void* returnVal;
    printf("facebook");
    processingM(matrArray, size);
    printf("\n facebook \n");
    //printResults(matrArray[0].I,5);
    printf("Termino prro!");
    return 0;
}


/*
struct element{
    int x;
    bool passed;
};

int main() {

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

int main() {

    #pragma omp parallel
    {
        printf("Hello, World!\n");
    }

    printf("termino prro");
}*/