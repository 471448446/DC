#include <stdio.h>

//https://stackoverflow.com/questions/8208021/how-to-increment-a-pointer-address-and-pointers-value
int main(int argc, char const *argv[])
{
	int array[] = {10,20,200};
	int i,*point;
	/**
	* 指针赋值，指向数组中第一个位置的内存地址。
	* point+1 指向下一个地址 
	*/
	point = array;
	printf("------use point++ -----\n");
	for (i = 0; i < 3 ; i++)
	{
		// 这里有个类型转换的警告⚠️  %x
		printf("array[%d] = %d , %p\n",i,*point,point );
		point++;
	}
	printf("------use point+1 -----\n");
	point = &array[0];
	for (int i = 0; i < 3; ++i)
	{
		printf("point[%d] = %d , %p\n", i,point[i],point+i);
	}
	return 0;
}