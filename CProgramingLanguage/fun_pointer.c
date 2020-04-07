#include <stdio.h>

int max(int x,int y){
	return x>y?x:y;
}
//https://www.runoob.com/cprogramming/c-fun-pointer-callback.html
int main(int argc, char const *argv[])
{
	int a = 10 ,b = 20;
	// 函数指针，名称：pointer_fun ，值是：max函数的地址
	int (* pointer_fun)(int,int) = &max;
	printf("max : %d %d max = %d \n",a,b,max(a,b));
	printf("funPointer : %d %d max = %d \n",a,b,pointer_fun(a,b));
	return 0;
}