#include <stdio.h>
#include <string.h>
/**
* 直接赋值和使用strcopy区别？？
*/
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

    // 申明长度是12 实际上只有5
    char str1[12] = "Hello";
    char str2[12] = "World";
    // 我只是申明 字符串 但是必须指定长度
    char str3[12];

    /* 复制 str1 到 str3 */
    strcpy(str3,str1);
    printf("strcpy( str3, str1) :  %s \n", str3);
    /* 连接 str1 和 str2 */
    strcat( str1, str2);
    printf("strcat( str1, str2):   %s\n", str1 );
       /* 连接后，str1 的总长度 */
    int len = strlen(str1);
    printf("strlen(str1) :  %d\n", len );

	/* code */
	return 0;
}