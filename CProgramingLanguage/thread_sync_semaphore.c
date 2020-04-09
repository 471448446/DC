#include <stdio.h>
#include <stdlib.h> // 引用所需要的常量 EXIT_FAILURE
#include <pthread.h>
#include <semaphore.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int size = 0;
sem_t sem;

// 生产者
void provide_data(void) {
    int i;
    for (i=0; i< MAXSIZE; i++) {
        stack[i] = i;

		/**
		* 为信号量加1
		* 成功返回0，失败返回-1
		* 参数
		* sem：指向信号量的一个指针
		*/
        sem_post(&sem);
    }
}

// 消费者
void handle_data(void) {
    int i;
    while((i = size++) < MAXSIZE) {
		/**
		* 为信号量减1
		* 成功返回0，失败返回-1
		* 参数
		* sem：指向信号量的一个指针
		*/
        sem_wait(&sem);
        printf("%d X %d = %d\n", stack[i], stack[i], stack[i]*stack[i]);
        // sleep(1);
    }
}

// 信号量更新是一个 生产、消费的同步问题，一次只能访问某个资源，而锁解决了多个人同时访问一段代码。
int main(void) {

    pthread_t provider, handler;

	/**
	* 信号量初始化
	* 成功返回0，失败返回-1
	* 参数
	* sem：指向信号量结构的一个指针
	* pshared： 不是0的时候，该信号量在进程间共享，否则只能为当前进程的所有线程们共享
	* value：信号量的初始值
	*/
    sem_init(&sem, 0, 0);
    pthread_create(&provider, NULL, (void *)handle_data, NULL);
    pthread_create(&handler, NULL, (void *)provide_data, NULL);
    pthread_join(provider, NULL);
    pthread_join(handler, NULL);


	/**
	* 销毁信号量
	* 成功返回0，失败返回-1
	* 参数
	* sem：指向信号量的一个指针
	*/
    sem_destroy(&sem);

    return 0;
}