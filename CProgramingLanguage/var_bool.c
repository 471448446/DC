#include <stdio.h>
#include <stdbool.h>
//https://stackoverflow.com/questions/5369770/bool-to-int-conversion
// the value false is converted to zero and the value true is converted to one.
int main(int argc, char const *argv[])
{
	bool x = false;
	// bool 就是 0或者1
	// false = 0
	// true = 1
	printf("x = %d or = %s\n", x,x?"true":"false");
	return 0;
}