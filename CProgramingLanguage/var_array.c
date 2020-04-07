#include <stdio.h>
// 引入这个包，只是为了计算数组大小
#include <stdlib.h>

#define count(x) (sizeof(x) / sizeof((x)[0]))

/**
* 
* 1.定义数组  https://www.runoob.com/cprogramming/c-arrays.html
* 	type arrayName [arraySize];
* 	第一个元素 从 0 开始。
* 2.多维数组 https://www.runoob.com/cprogramming/c-multi-dimensional-arrays.html
* 	type name[size1][size2]...[sizeN];
* 3.数组作为参数 https://www.runoob.com/cprogramming/c-passing-arrays-to-functions.html
* 	如果您想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数，这三种声明方式的结果是一样的
* 	a. *type
* 	b.type[size]
* 	c. type[]
* 4.数组作为函数返回值 https://www.runoob.com/cprogramming/c-return-arrays-from-function.html
* 	a. C 语言不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针
*   b. 另外，C 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
* 5.指向数组的指针 https://www.runoob.com/cprogramming/c-pointer-to-an-array.html
* 	a. 数组名是一个指向数组中第一个元素的常量指针
* 	b. 使用数组名作为常量指针是合法的，反之亦然。
*	怪不得数组和指针经常一起说，原来他们是可以互相表示对方。
*/

/**
* 在 main 之前 需要申明要调用的函数
*/
double getArrayAverage(int *array,int size);

int * getRandomArray();

int main(int argc, char const *argv[])
{
	// 申明数组
	int array[2];
	/** 
	* 申明并初始化 ,并没有 new int
	* 指令指定了大小 为2
	*/
	int array2[2] = {10,20};
	/**
	* 申明并初始化
	* 这里不指定大小，大小后后面 {} 中元素个数确定
	* 大小也为2
	*/
	int array3[] = {10,20};
	/**
	* 多维数组
	*/
	int array4[2][2] = {
		{10,20},
		{40,50}
	};
	printf("_____________array paremeter_______________\n");
	/**
	* 数组作为参数
	*/
	double avg = getArrayAverage(array2,2);
	// 输出 小数 1位。
	printf("array2 avg = %.1f\n",avg);
	printf("_____________return array_______________\n");
	/**
	* 数组作为返回值,只能返回指针，那么如果如何知道长度呢??
	* https://stackoverflow.com/questions/492384/how-to-find-the-sizeof-a-pointer-pointing-to-an-array
	* 无解，将长度放在第一个元素中
	* 还可以越界
	*/
	int *point_array5 = getRandomArray();
	for (int i = 0; i < 3; ++i)
	{
		printf("array5[i] = %d \n",*(point_array5+i)); 
	}
	printf("_____________array and point_______________\n");
	int array6[] = {10,20,30};
	int *point_array6 = array6;
	// 通过指针访问数组
	printf("array6[1] = %d\n", *(point_array6+1));
	// 数组名是一个指向数组中第一个元素的常量指针。 那么按照上面指针访问数组形式
	printf("array6[1] = %d\n", *(array6+1));
	// 使用指针作为数组名
	printf("array6[1] = %d\n", point_array6[1]);
	return 0;
}

double getArrayAverage(int *array,int size)
{
	double sum;
	for (int i = 0; i < size; ++i){
		sum+=array[i];
	}
	/**
	* 求数组元素个数： https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	* 分三步执行 count(x)
	*/
	// 先看数组占对象多少字节
	size_t n = sizeof(array);
	// 由于数组数 int 类型的，那么求一个int 占多少字节
	// 或者 sizeof(array[0]) 是一个意思
	size_t n_i = sizeof(int);
	// 最后求出数组的 元素个数
	int count  = n/n_i;
	printf("getArrayAverage() paremeter array size =  %d\n", count);
	return sum/size;
}

int * getRandomArray(){
	const int count = 2;
	static int array[count];
	for (int i = 0; i < count; ++i)
	{
		array[i] = rand();
		printf("cook array5[i] = %d \n",array[i]); 
	}
	return array;
}