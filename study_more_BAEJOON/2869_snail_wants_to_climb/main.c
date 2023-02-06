#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, v; //낮에 올라가는 거리 a, 밤에 올라가는 거리 b, 올라가야할 길이 v
    double n;
    
    scanf("%d %d %d", &a, &b, &v);
    
    n = (double)(v - b) / (a - b);
    
    n = ceil(n);
    
    printf("%.0f", n);
    
    return 0;
}
//문제의 핵심은 아래의 식을 세우는 것이다.
//n일에 올라갈 수 있는 최대 거리는 n * a - (n - 1) * b이다. (밤에는 도로 내려오기떄문에 n - 1)
//n*a - (n-1)*b >= v, 정리하면 n >= (v-b)/(a-b)
//n이 소숫점이 나오면 그 다음날에 v에 도달하는 것이기에 ceil로 올림을 한다.