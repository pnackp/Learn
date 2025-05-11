#include <stdio.h>
#include <stdlib.h>

struct structer
{
    int x;
};

int struc(struct structer *x){
    x->x = 10;
}

int main(){
    struct structer test;
    test.x = 1;
    printf("%d",test.x);
    struc(&test);
    printf("\n%d",test.x);
}