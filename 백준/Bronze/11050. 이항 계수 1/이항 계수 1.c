#include <stdio.h>

int main()
{
    int n, k, deno = 1, num = 1;
    
    scanf("%d %d", &n, &k);
    
    for (int i = n; i > 0; i--)
    {
        deno *= i;
    }
    
    for (int i = n - k; i > 0; i--)
    {
        num *= i;
    }
    
    for (int i = k; i > 0; i--)
    {
        num *= i;
    }
    
    printf("%d", deno/num);
    return 0;
}