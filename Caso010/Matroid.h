//
// Created by María José on 10/28/2019.
//

#ifndef CASO010_MATROID_H
#define CASO010_MATROID_H

#define M_SIZE 7
#define MATROID_INTERSECT_SIZE 7
#define DEBUG 1

void *results[M_SIZE] = {NULL};

struct Matroid
{
    void *S[M_SIZE];   //Pointer to S in the matroid.
    void *I[M_SIZE];   //Pointer to I in the matroid.
    void (*func)(struct Matroid*);    //Pointer to the function.
};
//https://www.cs.cmu.edu/~guna/15-123S11/Lectures/PPT/Lecture16.pdf



#endif //CASO010_MATROID_H
