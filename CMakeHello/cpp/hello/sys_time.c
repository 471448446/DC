#include <stdio.h>
#include <time.h>
#include "sys_time.h"

void test_sys_time() {
    struct timespec time = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time);
    // 直接打印值观看，秒+纳秒
    printf("test_clock_realtime %d,%d \n", (int) time.tv_sec, (int) time.tv_nsec);
    printf("test_clock_realtime %ld microseconds\n", microseconds(time));
    printf("test_clock_realtime %ld milliseconds\n",milliseconds(time));
}

long microseconds(struct timespec ti) {
    // 1,000,000 微妙
    return CLOCKS_PER_SEC * (ti.tv_sec) + (ti.tv_nsec) / 1000;
}

long milliseconds(struct timespec ti){
    return 1000 * (ti.tv_sec) + (ti.tv_nsec) / 1000000;
}
