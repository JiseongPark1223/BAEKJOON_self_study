#include <stdio.h>

int main()
{
    int t, cnt, p, max = 0, str[102], front = 0, res = 1;
    
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d %d", &cnt, &p);
        
        front = 0, res = 1;
        
        for (int i = 0; i < cnt; i++)
        {  
            scanf("%d", &str[i]);
        }
        
        while (1)
        {
            max = 0;
            for (int i = 0; i < cnt; i++)
            {
                if (max < str[i])
                {
                    max = str[i];
                }
            }
            
            while (max != str[front])
            {
                front = (front + 1)%cnt; 
            }
            
            if (p == front)
            {
                break;
            }
            
            str[front] = 0;
            front = (front + 1)%cnt;
            res++;
        }
        printf("%d\n", res);
    }
    
    return 0;
}
