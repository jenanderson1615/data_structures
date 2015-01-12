/* CS261- Assignment 1 - Q. 0*/
/* Name: Jen Anderson
 * Date: 07/01/13
 * Assignment to explore pointers in C
 * Solution description:
 *      The solution is 5 statements: "x is stored at 0028FF1C" (in my computer), "iptr points at the value of 7", "iptr points
 *      at the address of 0028FF1C", "The address of iptr is 0028FF00", and "x has the value of 7".
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("iptr points at the value of %d\n", *iptr);

     /*Print the address pointed to by iptr*/
    printf("iptr points at the address of %p\n", iptr);

     /*Print the address of iptr itself*/
     printf("The address of iptr is %p\n", (void*) &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 7;

    /*print the address of x*/
    printf("x is stored at %p\n", (void *)&x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("x has the value of %d\n", x);

    return 0;
}


