#include <stdio.h>

int main()
{
    int ax, bx, cx, ay, by, cy;
    
    scanf("%d %d", &ax, &ay);
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &cx, &cy);
    
    printf("%d %d", ax^bx^cx, ay^by^cy);
    return 0;
}
//xor 연산자를 이용해 3개의 값 중 다른 하나를 찾을 수 있다.
//a = 2 = 10(2), b = 3 = 11(2), c = 2 = 10(2)
//a^b = 01(2), (a^b)^c = 11(2)