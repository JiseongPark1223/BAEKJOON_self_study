#include <stdio.h>

void reverse(char arr[])
{
    char temp;
    temp = arr[0];
    arr[0] = arr[2];
    arr[2] = temp;
}

int main()
{
    char arr1[3], arr2[3];
    
    scanf("%s %s", arr1, arr2);
    
    reverse(arr1);
    reverse(arr2);
    
    if (arr1 > arr2)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%c", arr1[i]);
        }
    }
    else
    {
         for (int i = 0; i < 3; i++)
        {
            printf("%c", arr2[i]);
        }
    }

    return 0;
}