#include <stdio.h>
#include <pthread.h>

// 3. 申明线程调用函数
void just_print_message(void* handle);

// 创建线程
int main(int argc, char const *argv[])
{
	char name_thread1[] = "thread1";
	// 1. 申明线程标识符
	pthread_t thread1;
	// 2. 申明线程属性 没有使用 NULL
	pthread_attr_t thread1_attr;
	// 3. 申明线程调用函数的参数
	char* message1 = "thread1";

	void* ret_thread1;

	printf("thread1 prepare\n");
	// 创建线程，根据结果判断是否成功
	int res = pthread_create(&thread1,NULL,(void*)&just_print_message,(void*)message1);
	if (res!=0){
		printf("fail create %s \n",name_thread1);
	}else{
		// 等待线程执行完成
		int temp = pthread_join(thread1,&ret_thread1);
		printf("%s retval: %d\n", name_thread1,(int)ret_thread1);
		printf("%s join: %d\n", name_thread1,temp);
		if (temp!=0)
		{
			printf("%s cannot join\n",name_thread1);
		}
		printf("%s end\n",name_thread1);
	}
	return 0;
}

void just_print_message(void* handle){
	printf("____i am thread fun run %s\n", (char*)handle);
}