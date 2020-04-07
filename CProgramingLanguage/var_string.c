#include <stdio.h>
#include <string.h>

//https://www.runoob.com/cprogramming/c-strings.html
int main(int argc, char const *argv[])
{
	/**
	* 申明字符串 指定 char值的时候，必须加 \0
	* 字符串在存储的时候回多一个空字符，长度是+1的
	*/
	char hello1[] = "hello";
    char hello2[] = {'h','e','l','l','o','\0'};
	char name_chinese[] = "张";
    printf("%s size = %d \n", hello1,(int)strlen(hello1));
    printf("%s size = %d \n", hello2,(int)strlen(hello2));
    printf("%s size = %d \n", name_chinese,(int)strlen(name_chinese));

	/* code */
	return 0;
}