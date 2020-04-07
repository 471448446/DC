#include <stdio.h>
// 这个头文件处理 多个参数
#include <stdarg.h>

// 居然要分四步，才能读取多参数 vararg，那我何必这么申请呢？不累么
double average(int count,...){
	// 这里有个很申请的现象，如果这里不初始化值 为0 ，在第二次调用的时候，求平均值会有问题。
	double sum =0.0;

	/*申明 多参数List*/	
	va_list vlist;
	/*初始化 多参数个数*/
	va_start(vlist,count);
	/*访问 每个参数*/
	for (int i = 0; i < count; ++i)
	{
		int temp = va_arg(vlist,int);
		sum += temp;
		printf("read vararg %d , sum = %f\n", temp,sum);

	}
	/*最后 清理多参数数据*/
	va_end(vlist);

	return sum/count;
}
// https://www.runoob.com/cprogramming/c-variable-arguments.html
int main(int argc, char const *argv[])
{
	printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));

	return 0;
}