#include <stdio.h>
#include <pthread.h>

int increaseNumber;
void justIncreasNumber();

// 三个线程竞争访问全局变量sharedi，并且都没有进行相应的同步。
int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,NULL);
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,NULL);
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	printf("thread no mutex %d\n", increaseNumber);
	return 0;
}

void justIncreasNumber(){
	int tmp;
	for (int i = 0; i < 1000; ++i)
	{
		tmp = increaseNumber;
		tmp = tmp + 1;
		increaseNumber = tmp;	
	}
}