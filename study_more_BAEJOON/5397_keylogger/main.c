#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { //노드를 담을 구조체를 선언
    char data;
    struct node *prev;
    struct node *next;
} node;

int main()
{
    int t, len;
    char str[1000001];
    
    scanf("%d ", &t);
    
    while (t--)
    {
        node *head = (node *)malloc(sizeof(node)); //헤드 노드를 선언
        head->prev = NULL;
        head->next = NULL;
        head->data = -1;
        node *cur = head;
        
        scanf("%s ", str);
        
        len = strlen(str);
        
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '<')
            {
                if (cur->prev) //<이면 왼쪽에 노드가 존재해야 한다.
                {
                    cur = cur->prev;
                }
            }
            else if (str[i] == '>')
            {
                if (cur->next) //>이면 오른쪽에 노드가 존재해야 한다.
                {
                    cur = cur->next;
                }
            }
            else if (str[i] == '-')
            {
                if (cur->prev) //문자를 지우려면 왼쪽에 노드가 존재해야 한다.
                {
                    node *del = cur;
                    cur = cur->prev;
                    
                    if (del->next)
                    {
                        del->next->prev = cur;
                        cur->next = del->next;
                    }
                    else
                    {
                        cur->next = NULL;
                    }
                    del->next = NULL;
                    del->prev = NULL;
                    free(del);
                }
            }
            else
            {
                node *newnode = (node *)malloc(sizeof(node));
                newnode->data = str[i];
                
                if (cur->next) //문자열의 넣는 위치에 다음문자열이 있으면 다음 문자열 전에 newnode를 넣는다.
                {
                    cur->next->prev = newnode;
                    newnode->next = cur->next;
                    newnode->prev = cur;
                    cur->next = newnode;
                }
                else
                {
                    newnode->prev = cur;
                    cur->next = newnode;
                    newnode->next = NULL;
                }
                cur = newnode;
            }
        }
        head = head->next;
        
        while (head) 
        {
            printf("%c", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}