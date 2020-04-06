//
//  main.c
//  HelloC
//
//  Created by 杨川 on 2020/4/6.
//  Copyright © 2020 Better. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char name[] = "Tom";
    printf("%s size = %d \n",name,(int)strlen(name));
    return 0;
}
