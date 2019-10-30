#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

struct element{
    int x;
    bool passed;
};

void tested(struct element* thisone){
    if ((thisone->x % 2) == 0){
        printf("testeo %d, \n",(thisone->x % 2));
        thisone->passed = true;
    }else{
        printf("tesjfasdfteo %d, \n",(thisone->x % 2));
        thisone->passed = false;
    }
}

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
/*
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