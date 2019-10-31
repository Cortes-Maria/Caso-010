//
// Created by María José on 10/28/2019.
//

#ifndef CASO010_MATROID_H
#define CASO010_MATROID_H

#define M_SIZE 7
#define MATROID_INTERSECT_SIZE 7
#define DEBUG 1

struct Matroid
{
    void *S[M_SIZE];   //Pointer to S in the matroid.
    void *I[M_SIZE];   //Pointer to I in the matroid.
    void (*func)(struct Matroid*);    //Pointer to the function.
};

// Function that uses the function given to evaluate de matroid //
void processingM(struct Matroid matrArray[],int arrSize){
#pragma omp parallel for
    for(int elemntInArray = 0; elemntInArray < arrSize; elemntInArray++ ){
        int id = omp_get_thread_num();
        printf("\n Matroid %d is tested in thread %d \n",elemntInArray+1,id);
        matrArray[elemntInArray].func(&matrArray[elemntInArray]);
    }
}


//https://www.cs.cmu.edu/~guna/15-123S11/Lectures/PPT/Lecture16.pdf



#endif //CASO010_MATROID_H
