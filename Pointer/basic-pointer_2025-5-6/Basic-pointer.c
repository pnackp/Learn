#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 2; 
    int *p = &x; // pointer x by p by *
    printf("Nums pointer by p : %d" , *p);
    printf("\naddress is :%p" , p);
}
