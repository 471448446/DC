#include <stdio.h>

void justPrint(int number){
	if (number){
		printf("%d is true\n",number);
	}else{
		printf("%d is false\n",number);
	}
}

/**
* if 语句 条件是 boolean 值，可以用int值判断，0 是false ，其他的是 true
*/
int main(int argc, char const *argv[])
{

	justPrint(-2);
	justPrint(-1);
	justPrint(0);
	justPrint(1);
	justPrint(2);
	// if (1){
	// 	printf("1 is true\n");
	// }else{
	// 	printf("1 is false\n");
	// }

	// if (0){
	// 	printf("0 is true\n");
	// }else{
	// 	printf("0 is false\n");
	// }

	// if (2){
	// 	printf("2 is true\n");
	// }else{
	// 	printf("2 is false\n");
	// }


	// if (-1){
	// 	printf("-1 is true\n");
	// }else{
	// 	printf("-1 is false\n");
	// }
	return 0;
}

