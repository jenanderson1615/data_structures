/* CS261- Assignment 1 - Q.3*/
/* Name: Jen Anderson
 * Date: 7/1/13
 * Solution description: This program prints out an unsorted array of 20 values and a sorted array of 20 values.
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n) //Sorts the given array using a bubble sort.
{
     int progress = 0;

     do
     {
        int i;
        progress = 0;

        for (i = 0; i < (n - 1); i++)
        {
            if (number[i] > number[i + 1])
            {
                int temp = number[i];
                number[i] = number[i + 1];
                number[i + 1] = temp;

                progress = 1;
            }
        }
     }
                while (progress);
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i = 0;

    /*Allocate memory for an array of n integers using malloc.*/
    int *ptr = malloc(n); //array starts at address ptr points to.

    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++)
    {
        *(ptr + i) = rand();
    }

    /*Print the contents of the array.*/
    printf("My unsorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("\tThe value at position %d is: %d\n", (i + 1), *(ptr + i));
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(ptr, n);

    /*Print the contents of the array.*/
    printf("\n\nMy sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("\tThe value at position %d is: %d\n", (i + 1), *(ptr + i));
    }

    return 0;
    exit;
}

