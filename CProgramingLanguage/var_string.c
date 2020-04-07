#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/**
	* 申明字符串 指定 char值的时候，必须加\0
	*/
    char hello2[] = {'h','e','l','l','o','\0'};
	char hello1[] = "hello";
    printf("%s size = %d \n", hello1,strlen(hello1));
    printf("%s size = %d \n", hello2,strlen(hello2));
	/* code */
	return 0;
}