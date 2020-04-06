#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[] = {10,20,200};
	int i,*point;
	/**
	* 指针赋值，指向数组中第一个位置的内存地址。
	*/
	point = array;
	for (i = 0; i < 3 ; i++)
	{
		// 这里有个类型转换的警告⚠️
		printf("address: array[%d] = %x\n",i,(unsigned int)point );
		printf("value: array[%d] = %d\n",i,*point );
		point++;
	}
	return 0;
}