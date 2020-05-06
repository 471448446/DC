#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <time.h>


const int thread_size = 3;
int increaseNumber[thread_size];
int args[thread_size];

void justIncreasNumber(int *name);

unsigned long long time_microseconds() {

    struct timespec ts;
    unsigned long long units;

    clock_gettime(CLOCK_REALTIME, &ts);
    units = (unsigned long long) (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);

    return units;
}

unsigned long long time_microsecond_deltas(unsigned long long ticks_s) {
    unsigned long long ticks_e = time_microseconds();
    return ticks_e - ticks_s;
}


int main(int argc, char const *argv[])
{


    pthread_t thread_id[thread_size];
    for (int i = 0; i < thread_size; ++i) {
        increaseNumber[i] = 0;
        args[i] = i;

        pthread_create(&thread_id[i], NULL, (void *) &justIncreasNumber, (void *) &args[i]);
    }

    for (int i = 0; i < thread_size; ++i)
    {
       pthread_join(thread_id[i],NULL);
    }

    int sum = 0;
    for (int i = 0; i < thread_size; ++i)
    {
        sum += increaseNumber[i];
        printf("thread[%d]:%d\n",i, increaseNumber[i]);
    }
    printf("thread:%d sum:%d\n", thread_size, sum);

	return 0;
}

void justIncreasNumber(int *name) {
    unsigned long long start = time_microseconds();
    int index = *name;
    printf("name:%d\n", index);
    while (1) {
        increaseNumber[index]++;

        if (time_microsecond_deltas(start) > 2000000) {
            break;
        }
    }
}