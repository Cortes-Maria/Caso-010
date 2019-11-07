//
// Created by María José on 10/28/2019.
//

#ifndef CASO010_MATROID_H
#define CASO010_MATROID_H

#define M_SIZE 7
#define DEBUG 1

struct Matroid
{
    void *S[M_SIZE];   //Pointer to S in the matroid.
    void *I[M_SIZE];   //Pointer to I in the matroid.
    void (*func)(struct Matroid*);    //Pointer to the function.
    int Isize;
};

// Function that uses the function given to evaluate the matroid //
void processingM(struct Matroid matrArray[],int arrSize){
#pragma omp parallel for // NOLINT(openmp-use-default-none)
    for(int elemntInArray = 0; elemntInArray < arrSize; elemntInArray++ ){
        int id = omp_get_thread_num();
      //  printf("\n Matroid %d is tested in thread %d \n",elemntInArray+1,id);
        matrArray[elemntInArray].func(&matrArray[elemntInArray]);
    }
}

void printResults(void *array[], int arrSize){
    printf("Printing resutlts in I:\n");
    for(int inArray = 0; inArray < arrSize; inArray++){
        char *test = (char*)array[inArray];
        printf("%d\n", test);
    }
    printf("\n");
}

void printChars(void *array[], int arrSize){
    printf("Printing resutlts in M3:\n");
    for(int inArray = 0; inArray < arrSize; inArray++){
        char *test = (char*)array[inArray];
        printf("%s\n", test);
    }
    printf("\n");
}
//busca un elemento en un arreglo (en este caso en el subset I)
bool elementExists(void *array[],int arrSize, int pElement){
    for(int arrayPos=0; arrayPos<arrSize; arrayPos++){
        if((int) array[arrayPos] == pElement){
            return true;
        }
    }
    return false;
}

//searchs the current item in the matroid array (Paralelismo aquí)
bool isIntersection(struct Matroid matrArray[],int arrSize,int pElement){
    bool result = true;
#pragma omp parallel for // NOLINT(openmp-use-default-none)
    for(int matrArrayPos=0; matrArrayPos<arrSize;matrArrayPos++){

       // int id = omp_get_thread_num();
       // printf("\n Matroid %d is tested in thread %d \n",matrArrayPos+1,id);

        int size =  matrArray[matrArrayPos].Isize;
        if(!elementExists(matrArray[matrArrayPos].I,size,pElement)){
            result = false;
        }
    }
    return result;
}

void CalculateIntersection(struct Matroid matrArray[],int arrSize){
    int size =  matrArray[0].Isize;
    printf("Intersection is:\n");
    for(int matrArrayI=0; matrArrayI<size;matrArrayI++){
        int actualNumber = (int) matrArray[0].I[matrArrayI];
        if(isIntersection(matrArray, arrSize, actualNumber)){
            printf("%i \n", actualNumber);
        }
    }
}







//https://www.cs.cmu.edu/~guna/15-123S11/Lectures/PPT/Lecture16.pdf



#endif //CASO010_MATROID_H
