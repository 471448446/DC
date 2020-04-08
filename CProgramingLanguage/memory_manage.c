#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://www.runoob.com/cprogramming/c-memory-management.html
int main(int argc, char const *argv[])
{
	// 申明长度为200
	char name[200];
	// 长度未知
	char *largeName;
	
	strcpy(name,"Tony Telsa");

	/*------动态申请内存-------*/
	// malloc函数返回的是 void * 类型的指针，这里强制转换为 char *指针
	// 在堆内存中申请了 200 个 char 长度的字节
	largeName = (char *)malloc(100 * sizeof(char)); // calloc(200, sizeof(char));
	if (largeName != NULL){
		/**
		* 之前在字符串的`var_string.c`地方指是无法操作的。 但是这里分配的内存那就可以操作
		* 所以指针只有在分配的内存时，才能使用strcpy
		*/
		strcpy(largeName, "I am BBBBBBBBBBBBBBB Telsa");
		printf("malloc 分配的对内存保存的数据 : %s\n", largeName);
	}else {
		printf("malloc 分配堆内存失败 无法保存 largeName\n");
	}

	/*----调整大小-----*/
	largeName = (char *)realloc(largeName,200* sizeof(char));
	if( largeName == NULL ){
	    fprintf(stderr, "Error - unable to allocate required memory\n");
	}else{
	    strcat( largeName, ",She is in class 10th ");
	}
	printf("name size = %d , content = %s\n",(int)strlen(name),name);
	printf("largeName size = %d , content = %s\n",(int)strlen(largeName),largeName);

	/*------释放内存-------*/ 
	// 当程序退出时，操作系统会自动释放所有分配给程序的内存，但是，建议您在不需要内存时，都应该调用函数 free() 来释放内存。
	free(largeName);
	return 0;
}