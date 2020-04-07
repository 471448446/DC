#include <stdio.h>
// https://www.runoob.com/cprogramming/c-structures.html

/*----------定义结构体----------*/
// 直接用struct定义类型
// 没有指定struct名称，指定包含的数据类型，以及定义结构体变量
struct 
{
	int x;
	int y;	
} struct1;

// 指定了struct 名称，包含的数据类型，没有定义结构体变量
struct SIMPLE
{
	int x;
	int y;	
};

// 定义结构体的变量
struct SIMPLE t1, t2[20], *t3;

// 直接用typedef + struct定义类型
//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c; 
} Simple2;

//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;

/*----------结构体成员包含其他结构体----------*/
struct COMPLEX
{
	char name[50];
	Simple2 ss;
};

//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};

/*----------初始化----------*/
struct SIMPLE simple1 = {1,2};
Simple2 simple2_1 = {1,'a',1.0};


/*---------结构作为函数参数-------------*/
// 如果相关函数名称一样，会报错。不能函数重载 ？？
void printSimple(struct SIMPLE sp);
// void printSimple(struct SIMPLE sp, int size);
void printSimple2(struct SIMPLE *sp);

int main(int argc, char const *argv[])
{
	/*----------访问结构体----------*/
	int bb = simple1.x;
	printSimple(simple1);
	printSimple2(&simple1);
	return 0;
}

/*----------结构体参数----------*/
// 使用 . 访问属性
void printSimple(struct SIMPLE sp){
	printf("SIMPLE{x = %d,y = %d}\n",sp.x,sp.y );
}
/*----------结构体指针参数----------*/
// 使用 -> 访问属性
void printSimple2(struct SIMPLE *sp){
	printf("SIMPLE{x = %d,y = %d}\n",sp->x,sp->y );
}