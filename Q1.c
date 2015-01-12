/* CS261- Assignment 1 - Q.1*/
/* Name: Jen Anderson
 * Date: 7/1/13
 * Solution description: The output is a list of 10 random and unique student ids from 1-10 and 10 random student scores from 0 to
    100.  The program then prints out the minimum, maximum, and average test score values.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     /*Allocate memory for ten students*/
    struct student *s = malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return s;
}

void generate(struct student* students)
{
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int i = 0;
    int j = 0;
    srand(time(NULL ));

    for (i = 0; i < 10; i++)
    {
        students[i].id = (rand() % 10) + 1;
        for(j = 0; j < i; j++)
        {
            if(students[i].id == students[j].id)
            {
                students[i].id = (rand() % 10) + 1;
                j = -1;
            }

        }
        students[i].score = (rand() % 101);
    }
}

void output(struct student* students)
{
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int x;
    for(x = 0; x < 10; x++)
    {
        printf("%d: %d\n", students[x].id, students[x].score);
    }
}

void summary(struct student* students)
{
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int minimum;
     int maximum;
     int scoreTotal = 0;
     int average;
     int currentStudent;

     minimum = students[0].score;
     maximum = students[0].score;

     for(currentStudent = 0; currentStudent < 10; currentStudent++)
     {
         if (students[currentStudent].score < minimum)
            minimum = students[currentStudent].score;
         if (students[currentStudent].score > maximum)
            maximum = students[currentStudent].score;

         scoreTotal += students[currentStudent].score;
     }

    average = scoreTotal/10;

    printf("The minimum score was: %d\n", minimum);
    printf("The maximum score was: %d\n", maximum);
    printf("The average score was: %d\n", average);

}

void deallocate(struct student* stud)
{
     /*Deallocate memory from stud*/
     free(stud);
}


int main()
{
    struct student* stud = NULL;

    /*call allocate*/
    struct student *myStudentGroup = allocate();

    /*call generate*/
    generate(myStudentGroup);

    /*call output*/
    output(myStudentGroup);

    /*call summary*/
    summary(myStudentGroup);

    /*call deallocate*/
    deallocate(myStudentGroup);

    return 0;
}


