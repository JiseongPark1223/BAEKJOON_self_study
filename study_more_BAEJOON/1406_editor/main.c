#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { //연결리스트의 노드구조체를 선언한다.
    int data;
    struct node *prev;
    struct node *next;
} node;

int main()
{
    node *head = (node*)malloc(sizeof(node)); //헤드노드에 알맞은 크기를 할당 prev와 next포인터를 지정한다.
    head->data = -1;
    head->prev = NULL;
    head->next = NULL;
    node *cur = head; //cur은 커서 역할을 할 노드이다.
    
    int t, len;
    char str[100001], c, word;
    
    scanf("%s", str);
    scanf("%d", &t);
    
    len = strlen(str);
    
    for (int i = 0; i < len; i++) //입력받은 문자열을 이중연결리스트에 저장
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = str[i];
        cur->next = newnode;
        newnode->prev = cur;
        cur = newnode;
    }
    
    for (int i = 0; i < t; i++)
    {
        scanf(" %c", &c);
        
        if (c == 'L')
        {
            if (cur->prev)
            {
                cur = cur->prev;
            }
        }
        else if (c == 'D')
        {
            if (cur->next)
            {
                cur = cur->next;
            }
        }
        else if (c == 'B')
        {
            if (cur->prev) //이전의 문자가 존재해야 삭제 가능
            {
                node *del = cur; //삭제할 문제를 del에 저장
                cur = cur->prev; //기존 cur의 위치 cur->prev로 이동한다
                if (del->next)
                {
                    cur->next = del->next;
                    del->next->prev = cur;
                }
                else
                {
                    cur->next = NULL;
                }
                del->prev = NULL;
                del->next = NULL;
                
                free(del);
            }
        }
        else
        {
            scanf(" %c", &word);
            
            node *newnode = (node*)malloc(sizeof(node));
            newnode->data = word;
            
            if (cur->next)
            {
                cur->next->prev = newnode;
                newnode->next = cur->next;
            }
            else
            {
                newnode->next = NULL;
            }
            cur->next = newnode;
            newnode->prev = cur;
            cur = newnode;
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