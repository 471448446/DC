#include "stdio.h"
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// 结论：当达到一定量级的时候，多线程时间会更少就是更快，反之单线程时间更少就是会快
// 线程的创建这些也是耗时操作
const int g_thread = 100;

void simple_task();

long sequential_execution();
long con_execution();

long delta_time(struct timespec* start,struct timespec* end);

// 微妙
long microseconds(struct timespec ti);

/**
* 假设一个任务耗时为T，如果顺序执行N个任务，那么耗时就是 N*T。 如果多线程？？
*/
int main(int argc, char const *argv[])
{

	long seq_time = sequential_execution();
	long con_time = con_execution();

	printf("seq_time: %ld microseconds,con_execution:%ld microseconds \n", seq_time,con_time);
	return 0;
}

void simple_task(int id){

	// printf("%d task start\n", id);
	// sleep 导致打印日志也延时了
	//int usleep(useconds_t microseconds);
	// for (int i = 0; i < 5; ++i)
	// {
	// 	printf("%d task %d time sleep\n", id,i);
	// 	usleep(200000);
	// }
	// sleep(1);

	// 模拟耗时任务
	// 1万次 108 毫秒
	int i =100000;
	while(i>0){
		i--;
	}
	// printf("%d task end\n", id);
}

long sequential_execution(){
	struct timespec time1 = {0,0};
	struct timespec time2 = {0,0};

	clock_gettime(CLOCK_REALTIME,&time1);
	// printf("time start time %ld \n",microseconds(time1));

	pthread_t threads[g_thread];
	int* threads_pa[g_thread];

	for (int i = 0; i < g_thread; ++i)
	{
		simple_task(i);
	}

	clock_gettime(CLOCK_REALTIME,&time2);
	// printf("time end time %ld \n",microseconds(time2));

	long delta = delta_time(&time1,&time2);
	// printf("task consume time %ld s or %ld microseconds\n",delta/1000000,delta);
	return delta;
}

long con_execution(){
	struct timespec time1 = {0,0};
	struct timespec time2 = {0,0};

	clock_gettime(CLOCK_REALTIME,&time1);
	// printf("time start time %ld \n",microseconds(time1));

	pthread_t threads[g_thread];
	int* threads_pa[g_thread];

	for (int i = 0; i < g_thread; ++i)
	{
		*(threads_pa+i) = i;
		pthread_create(&threads[i],NULL,(void*)simple_task,(void*)threads_pa[i]);
	}

	for (int i = 0; i < g_thread; ++i)
	{
		pthread_join(threads[i],NULL);
	}
	// simple_task(0);

	clock_gettime(CLOCK_REALTIME,&time2);
	// printf("time end time %ld \n",microseconds(time2));


	long delta = delta_time(&time1,&time2);
	// printf("task consume time %ld s or %ld microseconds\n",delta/1000000,delta);
	return delta;
}

long microseconds(struct timespec ti){
		return 1000000*(ti.tv_sec)+(ti.tv_nsec)/1000;
}

long delta_time(struct timespec* start,struct timespec* end){
	return 1000000*(end->tv_sec - start->tv_sec)+(end->tv_nsec - start->tv_nsec)/1000;
}