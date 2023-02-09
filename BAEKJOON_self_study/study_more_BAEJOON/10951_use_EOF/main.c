#include <stdio.h>

int main()
{
    int a, b;
    
    while (scanf("%d %d", &a, &b) != EOF) //EOF란 end of file의 약자로 파일의 끝에 도달했을때 나오는 값, -1
    {                                     //문제에서 입력 최대갯수에 제한이 없었기에 EOF를 사용해 while문을 종료한다.
        printf("%d\n", a + b);            //scanf함수는 받아온 수를 return하는데 에러가 발생하거나 EOF면 -1을 return
    }                                     //따라서 while 조건문은 위 코드와 같다.
    return 0;
}