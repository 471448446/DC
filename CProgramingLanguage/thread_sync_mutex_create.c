#include <stdio.h>
#include <stdlib.h> // 引用所需要的常量 EXIT_FAILURE
#include <pthread.h>

const char* name_thread1 = "thread1";
const char* name_thread2 = "thread2";
const char* name_thread3 = "thread3";

int increaseNumber;

pthread_mutex_t mutex ;

void justIncreasNumber(char *name);

/**
* https://www.cnblogs.com/fuyunbiyi/p/3475602.html
* 1. 锁保护的并不是我们的共享变量（或者说是共享内存），对于共享的内存而言，用户是无法直接对其保护的，因为那是物理内存，无法阻止其他程序的代码访问。
* 	 事实上，锁之所以对关键区域进行了保护，在本例中，是因为所有线程都遵循了一个规则，那就是在进入关键区域钱加同一把锁，在退出关键区域钱释放同一把锁
* 3. 我们从上述运行结果中可以看到，加锁是会带来额外的开销的，加锁的代码其运行速度，明显比不加锁的要慢一些，所以，在使用锁的时候，要合理，
*	 在不需要对关键区域进行保护的场景下，我们便不要画蛇添足，为其加锁了
* 锁有一个很明显的缺点，那就是它只有两种状态：锁定与不锁定。
*/
int main(int argc, char const *argv[])
{
	// 初始化锁 锁对象，锁的配置，没有穿NULL
	pthread_mutex_init(&mutex,NULL);

	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,(void*)name_thread1);
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,(void*)name_thread2);
	pthread_create(&thread1,NULL,(void*)&justIncreasNumber,(void*)name_thread3);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	printf("thread no mutex %d\n", increaseNumber);
	// 销毁锁
	pthread_mutex_destroy(&mutex);
	return 0;
}

void justIncreasNumber(char *name){
	int tmp;
	for (int i = 0; i < 1000; ++i)
	{
		// 加锁
		if (pthread_mutex_lock(&mutex)!=0)
		{
			printf("%s lock fail %d \n",name,i);
			// 还是会存在 ！= 3000 的情况，可能获取不到锁
			exit(EXIT_FAILURE);
		}

		tmp = increaseNumber;
		tmp = tmp + 1;
		increaseNumber = tmp;	

		// 解锁
		if (pthread_mutex_unlock(&mutex)!=0)
		{
			printf("%s unlock fail %d \n",name,i);
			exit(EXIT_FAILURE);
		}
	}
}