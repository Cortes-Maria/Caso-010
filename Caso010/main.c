#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Matroid.h"

/*
//Funciones de los matroids separando elementos en cores
void pair(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    #pragma omp parallel
    for(int elem = 0; elem < size; elem++){
        int id = omp_get_thread_num();
        printf("\n Element %d is being tested in thread %d \n",elem+1,id);
        int actual = pMat->S[elem];
        if((actual % 2) == 0){
            pMat->I[pos] = actual;
            pos++;
        }
    }
}

 void XinAWord(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    #pragma omp parallel
    for(int i=0; i<size; i++) {
        int id = omp_get_thread_num();
        printf("\n Element %d is being tested in thread %d \n",elem+1,id);
        char *str;
        str = pMat->S[i];
        int strSize = strlen(str);
        for (int actual = 0; actual < strSize; actual++) {
            if (str[actual] == 'x' || str[actual] == 'X') {
                pMat->I[pos] = str;
                pos++;
                break;
            }
        }
    }
}


void higherTanThousand(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    #pragma omp parallel
    for(int elem=0; elem<size; elem++) {
        int id = omp_get_thread_num();
        printf("\n Element %d is being tested in thread %d \n",elem+1,id);
        int actual = pMat->S[elem];
        if(actual >= 1000){
            pMat->I[pos] = actual;
            pos++;
        }
    }
}


*/
//Funciones de los primeros tres matroids sin separar por elemento en core

void pair(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    //#pragma omp parallel
    for(int elem = 0; elem < size; elem++){
        //int id = omp_get_thread_num();
        //printf("\n Element %d is tested in thread %d \n",elem+1,id);
        int actual = pMat->S[elem];
        if((actual % 2) == 0){
            pMat->I[pos] = actual;
            pos++;
        }
    }
}


void XinAWord(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    for(int i=0; i<size; i++) {
        char *str;
        str = pMat->S[i];
        int strSize = strlen(str);
        for (int actual = 0; actual < strSize; actual++) {
            if (str[actual] == 'x' || str[actual] == 'X') {
                pMat->I[pos] = str;
                pos++;
                break;
            }
        }
    }
}


void higherTanThousand(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    for(int elem=0; elem<size; elem++) {
        int actual = pMat->S[elem];
        if(actual >= 1000){
            pMat->I[pos] = actual;
            pos++;
        }
    }
}

int main(void)
{
    //Matroid definition//
    struct Matroid M1 = {{0,2,3,4,5,6,7,8},{NULL},pair};
    struct Matroid M2 = {{0,2500,55,4,5,6000,1248654},{NULL},higherTanThousand};
    struct Matroid M3 = {{"agua","xilofono","Xoco","pila","noño","yuuoiur","234xiop","Xesar"},{NULL},XinAWord};
    struct Matroid matrArray[] = {M1,M2,M3};

    printf("facebook");
    int size =  (int)( sizeof(matrArray) / sizeof(matrArray[0]));
    processingM(matrArray, size); //Processing the array of matroids
    printf("\n facebook \n");

    //Print separate results
    printResults(matrArray[0].I,4);
    printResults(matrArray[1].I,3);
    printChars(matrArray[2].I,4);

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