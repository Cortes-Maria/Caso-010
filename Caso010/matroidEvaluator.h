//
// Created by María José on 10/28/2019.
//

#ifndef CASO010_MATROIDEVALUATOR_H
#define CASO010_MATROIDEVALUATOR_H

//Function that uses the function provided in the matroid and stores the solution in the I subset.
void processMatroids(struct Matroid matrArray[],int arrSize){
#pragma omp parallel for
    for(int arrayIterator=0; arrayIterator<arrSize; arrayIterator++){
        matrArray[arrayIterator].func(&matrArray[arrayIterator]);
        if(DEBUG){
            int id = omp_get_thread_num();
            printf("M%d is tested...\n",arrayIterator+1);
            printf("Thread %d on matroid number %d.\n", id, arrayIterator+1);
        }
    }

}


#endif //CASO010_MATROIDEVALUATOR_H
