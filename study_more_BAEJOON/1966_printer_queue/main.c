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
                if (max < str[i]) //큐에서 최댓값을 찾아 다음순번을 찾는다
                {
                    max = str[i];
                }
            }
            
            while (max != str[front])
            {
                front = (front + 1)%cnt; //회전큐의 특성을 이용하여 정해진 배열만 돌도록 한다.
            }
            
            if (p == front) //만약 찾던 수에 도달하면 중단하고 순번을 출력시킨다.
            {
                break;
            }
            
            str[front] = 0; //방문한 큐는 0으로 설정하여 최댓값을 구할 때 못 구하도록 한다.
            front = (front + 1)%cnt;
            res++;
        }
        printf("%d\n", res);
    }
    
    return 0;
}
