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
        int actual = (int) pMat->S[elem];
        if((actual % 2) == 0){
            pMat->I[pos] = (void *) actual;
            pMat->Isize++;
            pos++;
        }
    }
}


void XinAWord(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    for(int i=0; i<size; i++) {
        char *str;
        str = pMat->S[i];
        int strSize = (int) strlen(str);
        for (int actual = 0; actual < strSize; actual++) {
            if (str[actual] == 'x' || str[actual] == 'X') {
                pMat->I[pos] = str;
                pMat->Isize++;
                pos++;
                break;
            }
        }
    }
}


void higherTanThousand(struct Matroid* pMat){
    int pos = 0,  size = sizeof (pMat->S)/sizeof (pMat->S[0]);
    for(int elem=0; elem<size; elem++) {
        int actual = (int) pMat->S[elem];
        if(actual >= 1000){
            pMat->I[pos] = (void *) actual;
            pMat->Isize++;
            pos++;
        }
    }
}

int main(void)
{
    //Matroid definition//
    struct Matroid M1 = {{0, (void *) 2, (void *) 3, (void *) 4, (void *) 5, (void *) 6, (void *) 7}, {NULL}, pair};
    struct Matroid M2 = {{0, (void *) 2500, (void *) 55, (void *) 4, (void *) 5, (void *) 6000, (void *) 1248654}, {NULL}, higherTanThousand};
    struct Matroid M3 = {{"agua","xilofono","Xoco","pila","noño","yuuoiur","234xiop"},{NULL},XinAWord};
    struct Matroid matrArray[] = {M1,M2,M3};

    printf("facebook");
    int size =  (int)( sizeof(matrArray) / sizeof(matrArray[0]));
    processingM(matrArray, size); //Processing the array of matroids
    printf("\n facebook \n");

    //Print separate results
    printResults(matrArray[0].I,4);
    printResults(matrArray[1].I,3);
    printChars(matrArray[2].I,4);

    printf("Parte B\n");
    struct Matroid M01 = {{(void*) 16, (void *) 2, (void *) 3, (void *) 4, (void *) 5, (void *) 6, (void *) 7}, {NULL}, pair};
    struct Matroid M02 = {{(void*) 16, (void *) 2, (void *) 3, (void *) 10, (void *) 4, (void *) 12, (void *) 13}, {NULL}, pair};
    struct Matroid M03 = {{(void*) 16, (void *) 2, (void *) 3, (void *) 4, (void *) 53, (void *) 68, (void *) 71}, {NULL}, pair};
    struct Matroid M04 = {{(void*) 16, (void *) 2, (void *) 3, (void *) 4, (void *) 85, (void *) 65, (void *) 73}, {NULL}, pair};
    struct Matroid M05 = {{(void*) 16, (void *) 2, (void *) 3, (void *) 4, (void *) 59, (void *) 64, (void *) 79}, {NULL}, pair};
    struct Matroid matrArrayB[] = {M01,M02,M03,M04,M05};

    int sizeB =  (int)( sizeof(matrArrayB) / sizeof(matrArrayB[0]));
    processingM(matrArrayB, sizeB); //Processing the array of matroids
    CalculateIntersection(matrArrayB,sizeB);

    return 0;
}

