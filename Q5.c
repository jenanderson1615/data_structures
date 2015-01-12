/* CS261- Assignment 1 - Q.5*/
/* Name: Jen Anderson
 * Date: 7/04/13
 * Solution description: Output asks the user for a word, then prints the word in sticky caps.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word)
{
     /*Convert to sticky caps*/
     int x;
    for (x = 0; x < strlen(word); x++)
    {
         if(x % 2 == 0)
         {
            if (word[x] >= 'a' && word[x] <= 'z')
            {
                word[x] = toUpperCase(word[x]);
            }
         }
         else
         {
            if (word[x] >= 'A' && word[x] <= 'Z')
            {
                word[x] = toLowerCase(word[x]);
            }
         }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
   char word[256];
   char *input;

   input = word;
   printf("Please type one word: \n");
   scanf("%s", input);

    /*Call sticky*/
    sticky(input);

    /*Print the new word*/
    printf("%s\n", input);

    int i;
    for (i = 0; i < sizeof(input); i++)
    {
        if(input[i] == '\n')
        {
            input[i] = '\0';
            break;
        }
    }

    return 0;
}


