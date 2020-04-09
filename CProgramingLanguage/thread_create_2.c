#include <stdio.h>
#include <pthread.h>

// 3. 申明线程调用函数
void just_print_message(void* handle);

// 执行完后才执行下一个
void simpleRunThread(char name[]);

int main(int argc, char const *argv[])
{
	
	simpleRunThread("thread1");
	simpleRunThread("thread2");

	return 0;
}

void simpleRunThread(char name[]){

	// 1. 申明线程标识符
	pthread_t thread1;
	// 2. 申明线程属性 没有使用 NULL
	pthread_attr_t thread1_attr;
	// 3. 申明线程调用函数的参数
	char* message1 = name;

	void* ret_thread1;

	printf("%s prepare\n",name);

	// 创建线程，根据结果判断是否成功
	int res = pthread_create(&thread1,NULL,(void*)&just_print_message,(void*)message1);
	if (res!=0){
		printf("%s fail create\n",name);
	}else{
		// 等待线程执行完成
		int temp = pthread_join(thread1,&ret_thread1);
		printf("%s retval: %d\n", name,(int)ret_thread1);
		printf("%s join: %d\n", name,temp);
		if (temp!=0){
			printf("%s fail join\n",name);
		}
		printf("%s end\n",name);
	}
}

void just_print_message(void* handle){
	for (int i = 0; i < 5; ++i)
	{
		printf("__%d__i am thread run fun __%s\n", i,(char*)handle);
	}
}