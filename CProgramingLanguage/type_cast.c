#include <stdio.h>

//https://www.runoob.com/cprogramming/c-type-casting.html
int main(int argc, char const *argv[])
{
	// 显示指定 转换为 double
	int a = 17, b = 5;
	double mean = (double)a/b;
	printf("%d/%d = %f \n",a,b,mean );
	// 整数提升是指把小于 int 或 unsigned int 的整数类型转换为 int 或 unsigned int 的过程
	char c = 'c'; /* ascii 值是 99 */
	int sum = a+c;
	printf("%d+%d = %d\n",a,c,sum );
	// 转换到高的 float
	float sum2 = a+c;
	printf("%d+%d = %f\n",a,c,sum2 );
	return 0;
}