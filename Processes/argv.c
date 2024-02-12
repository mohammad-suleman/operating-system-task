#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) { // argc −− number of arguments 
    int i;
    for ( i =0; i <argc ; i ++){ 
        printf("The argument at %d index is %s\n",i , argv[i]);
    }
    return 0;
}