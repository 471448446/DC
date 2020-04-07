#include <stdio.h>

/**
* 传值调用
* 不影响原来的值。
*/
void swip(int x,int y){
	int temp =x;
	x = y;
	y = temp;
}

/**
* 引用调用
* 可能会影响原来的值。
*/
void swip2(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

// https://www.runoob.com/cprogramming/c-functions.html
int main(int argc, char const *argv[])
{
	int a = 100, b = 200;
	printf("传值参数\n");
	printf("befor swip a = %d,b = %d  \n",a,b );
	swip(a,b);
	printf("after swip a = %d,b = %d  \n",a,b );

	int c = 100, d = 200;
	printf("引用参数\n");
	printf("befor swip a = %d,b = %d  \n",c,d );
	swip2(&c,&d);
	printf("after swip a = %d,b = %d  \n",c,d );
	return 0;
}