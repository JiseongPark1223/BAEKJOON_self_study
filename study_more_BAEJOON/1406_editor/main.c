#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}node;



int main()
{
    node *head = (node*)malloc(sizeof(node));
    head->data = -1;
    head->prev = NULL;
    head->next = NULL;
    node *cur = head;
    
    int t, len;
    char str[100001], input, word;
    
    scanf("%s", str);
    scanf("%d", &t);
    
    len = strlen(str);
    
    for (int i = 0; i < len; i++)
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = str[i];
        cur->next = newnode;
        newnode->prev = cur;
        newnode->next = NULL;
        cur = newnode;
    }
    
    for (int i = 0; i < t; i++)
    {
        scanf(" %c", &input);
        
        if (input == 'L')
        {
            if (cur->prev != NULL)
            {
                cur = cur->prev;
            }
        }
        else if (input == 'D')
        {
            if (cur->next != NULL)
            {
                cur = cur->next;
            }
        }
        else if (input == 'B')
        {
            if (cur->prev != NULL)
            {
                node *del = (node*)malloc(sizeof(node));
                del = cur;
                cur = cur->prev;
                
                if (del->next)
                {
                    cur->next = del->next;
                    del->next->prev = cur;
                    del->prev = NULL;
                }
                else
                {
                    cur->next = NULL;
                    del->prev = NULL;
                }
                free(del);
            }
        }
        else
        {
            scanf(" %c", &word);
            node *newnode = (node*)malloc(sizeof(node));
            
            newnode->data = word;
            newnode->prev = cur;
            
            if (cur->next)
            {
                cur->next->prev = newnode;
                newnode->next = cur->next;
                cur->next = newnode;
                cur = newnode;
            }
            else
            {
                cur->next = newnode;
                newnode->next = NULL;
                cur = newnode;
            }
        }
    }
    
    head = head->next;
    
    while (head)
    {
        printf("%c", head->data);
        head = head->next;
    }
    return 0;
}