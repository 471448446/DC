#include <stdio.h>
/**
* 定义常量 
* #define 常量名称 常量内容
* 不想Java 需要用 = 号，以及一大堆限定符 static final
* 也没有分号作为结束标志
* 不过形式上差不多，类型 + 名称 + 值 
*/
#define MAX_FAHR 300
#define STEP 20

/**
* 定义函数 在一个地方申明，一个地方实现
* 函数申明：
* 返回值 + 名称 + 参数 + 花括号实体
*/
float mapFahrToCelsius(int fair);

int main(int argc, char const *argv[])
{
	/* code */
	float celius =0;
	for (int i = 0; i < MAX_FAHR; i+=STEP)
	{
		// celius = (i-32)*5.0/9.0;
		celius = mapFahrToCelsius(int);
		printf("%d fair = %6.1f celsius\n", i,celius);
	}
	return 0;
}

float mapFahrToCelsius(int fair){
	return (fair-32)*5.0/9.0;
}