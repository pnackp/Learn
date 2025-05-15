// -Pointer with Arrays - Exam by chatgpt -- pnackp solve ;  

// Output Example  
// Enter number of elements: 5  
// Enter 5 integers: 10 20 5 7 30  

// Array values: 10 20 5 7 30  
// Maximum: 30  
// Minimum: 5  
// Average: 14.40 
// Reversed array: 30 7 5 20 10

#include <stdio.h>
#include <stdlib.h>

int findmaxandaverage(int *arrays , int size){
    int max = arrays[0];  // Set max = arrays[0] to compare and replace if arrays[i] > max
    int minimum = arrays[0]; // Set min = arrays[0] to compare and replace if arrays[i] < min
    int nums = 0;

    for (int i = 0 ; i < size ; i++){
        if (arrays[i] > max){
            max = arrays[i];
        }
        else if (arrays[i] < minimum){
            minimum = arrays[i];
        }
        nums += arrays[i];  // Add arrays[i] to nums to calculate the average later
    }

    printf("Maximum: %d", max);
    printf("\nMinimum: %d", minimum);
    printf("\nAverage: %.2f", (float)nums / size);  // use float for 2 decimal places

    return 0;
}

int Reverse(int *arrays , int size){
    int reverse[size];  // Create a new array to store reversed elements
    int i = 0;
    for (int j = size - 1; j >= 0; j--){  // Copy arrays in reverse order // (Why use size - 1?) cause in c arrays start from 0 not 1 if you not -1 == Null ; 
        reverse[i] = arrays[j];
        i++;
    }

    printf("\nReversed array values:");
    for (int i = 0 ; i < size ; i++){
        printf(" %d", reverse[i]);
    }
    return 0;
}

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arrays;
    arrays = (int *)malloc(size * sizeof(int));  // Allocate memory for the array

    for (int i = 0; i < size; i++){  // Input values into arrays[i]
        printf("Enter int at [%d]: ", i);
        scanf("%d", &arrays[i]);
    }

    printf("Array values: ");
    for (int i = 0 ; i < size ; i++){  // Print array values
        printf("%d ", arrays[i]);
    }

    printf("\n");
    findmaxandaverage(arrays , size);
    Reverse(arrays, size);
    free(arrays);  // Free allocated memory
}

// 2025 - 5 - 7;
