#include "stdio.h"
#include "stdlib.h"

const int SIZE = 10;

/**
* 返回一个随机数
* 由于 C 中函数中不能生成函数，所以回调函数只有先定义在其他地方。
*/
int getNumber(){
	return rand();
}

/**
* 有一个 函数指针 作为参数，其返回值是 int，接受的参数是void。
*/
void init_array(int *array,int size,int (*pointer)(void)){
	for (int i = 0; i < size; ++i)
	{
		array[i] = pointer();
	}
}

int main(int argc, char const *argv[])
{
	int array[SIZE];
	init_array(array,SIZE,getNumber);
	for (int i = 0; i < SIZE; ++i)
	{
		printf("arrar[%d] = %d \n", i,array[i]);
	}
	return 0;
}