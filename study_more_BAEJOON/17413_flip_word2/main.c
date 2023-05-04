#include <stdio.h>
#include <string.h>

int top = -1;
char stack[100003];//fgets은 개행문자를 받고 경우에 따라 NULL을 추가하기 때문에 정해진 배열의 크기보다 2에서 3정도 크게 잡는 것이 좋다.

void push(char x)
{
    stack[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    int len;
    char s[100003];
    
    fgets(s, 100003, stdin); //띄어쓰기가 있기 때문에 fgets로 문자열을 입력받는다.
    
    len = strlen(s);
    
    if (s[len - 1] == '\n') //개행문자가 입력되기 때문에 그것을 NULL로 바꾸어준다.
    {
        s[len - 1] = 0;
    }
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '<')
        {
            if (top != -1) //<가 나오기 전에 스택에 있던 문자들은 뒤집어 출력한다.
            {
                while (top != -1)
                {
                    printf("%c", stack[top]);
                    pop();
                }
            }
            while (s[i] != '>') //괄호내 문자들은 순서가 뒤집히지 않으므로 그대로 출력한다.
            {
                printf("%c", s[i]);
                i++;
            }
            printf("%c", s[i]);
        }
        else if (s[i] == ' ' || s[i] == '\0') //띄어쓰기가 나오거나 문자열 마지막에 오는 NULL을 만나면 뒤집어 출력한다.
        {
            while (top != -1)
            {
                printf("%c", stack[top]);
                pop(); //스택에 있는 문자열을 출력한다.
            }
            printf(" "); //공백을 출력해 띄어쓰기를 출력한다.
        }
        else
        {
            push(s[i]); //나머지 문자는 스택에 넣어준다.
        }
    }
    return 0;
}
