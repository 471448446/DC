#include <stdio.h>

void oldWay(){
	int n = 20;
	for(int i = 0; i < n; i--){
		printf("-");
	}
}
void fixWay1(){
	int n = 20;
	for(int i = 0; -i < n; i--){
		printf("-");
	}
}

//https://coolshell.cn/articles/3961.html
int main(int argc, char const *argv[])
{
	
	// oldWay();
	fixWay1();
	return 0;
}