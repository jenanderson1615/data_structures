/* CS261- Assignment 1 - Q.4*/
/* Name: Jen Anderson
 * Date: 7/7/13
 * Solution description: This program outputs a list of ten random student ids and scores and
    then outputs the same list sorted by score.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n) //Sorts the student structure by their scores
{
     int progress = 0;

     do
     {
        int i;
        progress = 0;

        for (i = 0; i < (n - 1); i++)
        {
            if (students[i].score > students[i+1].score)
            {
                struct student temp = students[i];
                students[i] = students[i+1];
                students[i+1] = temp;

                progress = 1;
            }
        }
     }
     while(progress);
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *myStudentGroup = malloc(10 * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    int i = 0;
    int j = 0;
    srand(time(NULL ));

    for (i = 0; i < 10; i++)
    {
        myStudentGroup[i].id = (rand() % 10) + 1;
        for(j = 0; j < i; j++)
        {
            if(myStudentGroup[i].id == myStudentGroup[j].id)
            {
                myStudentGroup[i].id = (rand() % 10) + 1;
                j = -1;
            }

        }
        myStudentGroup[i].score = (rand() % 101);
    }

    /*Print the contents of the array of n students.*/
    printf("The unsorted list of students: \n");
    int y;
    for(y = 0; y < 10; y++)
    {
        printf("\t%d: %d\n", myStudentGroup[y].id, myStudentGroup[y].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(myStudentGroup, n);

    /*Print the contents of the array of n students.*/
    printf("The list of students sorted by their scores: \n");
    int z;
    for(z = 0; z < 10; z++)
    {
        printf("\t%d: %d\n", myStudentGroup[z].id, myStudentGroup[z].score);
    }


    return 0;
    exit;
}


