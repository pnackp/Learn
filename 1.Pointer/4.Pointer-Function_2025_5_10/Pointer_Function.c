//Problem by gpt - nack slove 
//Enter two numbers: 5 10  
//Before Swap: a = 5, b = 10  
//After Swap:  a = 10, b = 5  

//Enter a number to square: 4  
//Squared number is: 16  

//Enter size of array: 4  
//Enter 4 numbers: 1 2 3 4  
//Average is: 2.50  

// cant use array[i]


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b){
    printf("Before Swap: %d %d", *a , *b);
    int temp = *a;
    *a = *b; 
    *b = temp;
    printf("\nAfter Swap: %d %d", *a , *b);
    return;
}

void square(int *num){
    printf("Input: %d\n", *num);
    double result = pow(*num, 2);
    printf("Power Result: %.1lf\n", result);
    return;
}

float average(int *arr, int size){
    int l = 0 ; 
    float x = 0 ; 
    while (l < size)
    {
        x += *(arr + l);
        l++;
    }
    return x/size;
}

int main(){
    int a ; int b; int c;
    printf("Enter 2 Number :");
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("\nEnter a number to square:");
    scanf("%d",&c);
    square(&c);

    int size , l = 0; 
    printf("Enter Size of Arrays:");
    scanf("%d",&size);
    int *arr = (int*)malloc(size * sizeof(int));

    while (l < size)
    {
        printf("Enter int at [%d]: ", l);
        scanf("%d", arr + l);
        l++;
    }
    
    float x = average(arr,size);
    printf("%0.2f",x);
    return 0 ;
}