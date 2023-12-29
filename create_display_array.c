#include<stdio.h>
#include<stdlib.h>
#define MAX 10
char tree[MAX];
/*
void root(char);
void left(char, int);
void right(char, int);
void display();
*/


void root(char c)
{
    if (tree[0] != '\0')
        printf("Root already exists \n");
    else
        tree[0] = c;
}

void left(char c, int parent)
{
    if (tree[parent] == '\0')
        printf("Can't insert %c. Parent doesn't exist \n");
    else
        tree[(2 * parent) + 1] = c;
}

void right(char c, int parent)
{
    if (tree[parent] == '\0')
        printf("Can't insert %c. Parent doesn't exist \n");
    else
        tree[(2 * parent) + 2] = c;
}

void display()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (tree[i] == '\0')
            printf("NULL ");
        else
            printf("%c ", tree[i]); 
    }
    printf("\n");
}

int main()
{
    root('A');
    left('B', 0);
    right('C', 0);
    right('D', 1); // Changed the parent index for 'D' to 1
    display();
    return 0;
}
