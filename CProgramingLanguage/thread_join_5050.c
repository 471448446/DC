#include <stdio.h>
#include <pthread.h>
  
#define TOTAL 10
int sumarray[TOTAL];
 
 
void *PartSum(void* param) {
    int index = (int)param;
    int sum = 0;
 
    for(int i=1; i<=10; ++i){
        sum += (index*10 + i);
    }
 
    sumarray[index] = sum;
    pthread_exit(NULL);
}
 
int main()
{
    int sumall=0;
 
    pthread_t threads[TOTAL];
    for(int i=0;i<TOTAL;i++){
        pthread_create(&threads[i], NULL, PartSum, (void *)i);
    }
 
    // for(int i=0; i<TOTAL; i++){
    //    pthread_join(threads[i], NULL);
    // }
 
    for(int i=0;i<TOTAL;i++)
        sumall += sumarray[i];
 
    printf("sumall: %d\n", sumall);
    return 0;
}