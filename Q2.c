/* CS261- Assignment 1 - Q.2*/
/* Name:  Jen Anderson
 * Date:  07/01/13
 * Solution description: The values of x, y, and z, the return value of foo(), and the changed values of
    x, y, and z are printed out.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c) // a is a pointer, b is a pointer, c is a variable
{
    /*Set a to double its original value*/
    *a = (*a * 2);

    /*Set b to half its original value*/
    *b = (*b / 2);

    /*Assign a+b to c*/
    c = (*a + *b);

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("\n");
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returnVal = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("The return value of foo() is %d\n", returnVal);

    /*Print the values of x, y and z again*/
    printf("After the call to foo(), the value of x is %d\n", x);
    printf("After the call to foo(), the value of y is %d\n", y);
    printf("After the call to foo(), the value of z is %d\n", z);

    return 0;
    /*Is the return value different than the value of z?  Why?*/

    /* Yes, the return value is different than z, because the third parameter of foo is a variable, not a pointer.  So, in
    *  foo, the value of c is only a copy of the value passed in as a parameter.  When c is changed in the foo program, only the
    *  temporary c value is changed, not the value stored at the z variable.*/
}


