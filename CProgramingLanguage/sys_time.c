#include <stdio.h>
#include <time.h>
#include "sys_time.h"

int main(int argc, char const *argv[])
{
	struct timespec time1 = {0,0};
	clock_gettime(CLOCK_REALTIME,&time1);
	printf("clock_realtime %d,%d \n",(int)time1.tv_sec,(int)time1.tv_nsec );

	printf("clock_realtime %ld microseconds\n", microseconds(time1));
	return 0;
}

long microseconds(struct timespec ti){
		return 1000000*(ti.tv_sec)+(ti.tv_nsec)/1000;
}
