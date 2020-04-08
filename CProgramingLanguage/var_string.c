#include <stdio.h>
#include <string.h>
/**
* 直接赋值和使用strcopy区别？？
*/
//https://www.runoob.com/cprogramming/c-strings.html
int main(int argc, char const *argv[])
{
    printf("--------------size of string------------\n");
	/**
	* 申明字符串 指定 char值的时候，必须加 \0
	* 字符串在存储的时候回多一个空字符，长度是+1的
	*/
	char hello1[] = "hello";
    char hello2[] = {'h','e','l','l','o','\0'};
	char name_chinese[] = "张";
    /**
    * hello1 和 hello1 两个内容是一样的，所以长度也是一样的
    */
    printf("%s size = %d \n", hello1,(int)strlen(hello1));
    printf("%s size = %d \n", hello2,(int)strlen(hello2));
    printf("%s size = %d \n", name_chinese,(int)strlen(name_chinese));

    /*--------调用方法-------------*/
    printf("--------------string method------------\n");
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

	/* --------赋值的区别----------- */
    printf("--------------赋值------------\n");
    /**
    * 在学习的过程中经常看到 = 和 strcpy 的方式 对字符串赋值，看下有什么却别
    * ff91、ff92 一个是数组方式存储，一个是指针方式存储
    * 区别：https://www.cnblogs.com/gaochaochao/p/8564988.html
    * --指针存储：常量字符串会保存在程序的常量区，编译时会将该字符串在常量区的起始地址拷贝过来存在指针p中，
    * --数组存储：常量字符串也会保存在程序的常量区，但是在字符数组初始化时，会将字符串拷贝到中，即数组中存储字符串副本
    * 常量字符串： 可以这么理解，就是"" 双引号中的，这种不可更变的字符串。
    * --常量区的不应许修改。运行【修改字符串】查看，尝试修改ff91,ff92中的内容。
    * -->这就是《指向字符串常量的指针和存储字符串常量的数组之间的差异》
    * 文章中更是指出`char * strcpy(char * strDest,const char * strSrc);` 两个参数的区别，第一个参数是可以修改形参的，第二个参数不能修改形参。
    * 如果指向了常量区的指针那么久不能修改，反之，则可以修改。
    *
    * 文章中的结论：
    * 1 char *p="1234";指针p指向常量区，不允许修改内容及p[0]='a'非法
    * 2 char str[5]="abcd"  字符数组str复制了常量区字符串“abcd”的值，而字符数组是在数据段，可以进行修改及str[0]='1'合法
    * 3 对于strcpy函数的第一个形参，是输出型形参，因此只能是数组名，而不能是字符指针变量
    * 4 对strcpy的第二个形参，是输入型形参，可以是数组名或者是字符指针变量，但最好是字符指针变量
    *
    * 这两个有待考证
    * https://www.codeleading.com/article/83291641967/ https://www.cnblogs.com/Stephen-Qin/p/10424618.html
    * 
    * 从目前来看字符串指针的赋值，不能使用 strcpy。可以用= 赋值常量，另外一个指针。
    * 数组就可以在申明的时候赋值 array= "xx",array = {'a','b'} 或者 arrar[0] = 'a' 注意是字符，不是字符串""
    *
    */

    char ff90[] = "Hello Tesla";
    char ff91[] = "Hello Tesla";
    char *ff92 = "Hello Tesla";
    // 这是在声明一个变量,声明变量是不分配内存的 
    char *ff93;
    char ff94[12];
    char *ff95 = "Hello Tesla";
    // 两个指针指向同一块内存，是指针的地址赋值 ，属于浅拷贝 ？？
    ff93 = ff92;
    // 这句会报错的，接受拷贝数据的是ff93指针，指针是不能接受拷贝的。 从后面`memory_mangage.c`看出需要先分配存储才行
    // strcpy(ff93,ff92);
    // 第一个参数只能算是数组？？，第二个参数可以是指针，数组 WTF
    strcpy(ff94,ff92);

    /**
    * 0、1、4 三个字符串，虽然值使用的但是地址都不一样。 
    * 理解：
    * >>>>0、1 是存储的常量字符串的副本。4 是利用strcpy生成的副本,所以他们地址是不一样的。
    * >>>>最后生成了三个副本，内存中就新增了三个这个字符串。
    * 2、3、5 对应的字符串，指针指向的同一个地址
    * 理解：
    * >>>>1、3 是指针直接赋值，执行同一个内存地址，而5是在赋值的时候表明，指向的常量字符串的地址。
    * >>>>最后达到的效果是一样的，都是同一个地址。
    */
    printf("ff90 address = %p, value = %s\n",&ff90,ff90);
    printf("ff91 address = %p, value = %s\n",&ff91,ff91);
    printf("ff92 address = %p, value = %c\n",ff92,*ff92);// 默认指向的第一个元素，可以循环读取，读取到空字符 \0 结束就行。
    printf("ff93 address = %p, value = %c\n",ff93,*ff93);
    printf("ff94 address = %p, value = %s\n",&ff94,ff94);
    printf("ff95 address = %p, value = %c\n",ff95,*ff95);
    /*--【修改字符串】--*/
    // 这个是可以的，修改数据区的内容
    // ff91[0] = 'h';
    // 这个在运行时会报错，因为修改了常量区的内容
    // ff92[0] = 'h';

    return 0;
}