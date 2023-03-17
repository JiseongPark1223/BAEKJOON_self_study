#include <stdio.h>
#include <stdlib.h>

int card[500001] = {0}, res[500001] = {0};

int compare(const void *arr1, const void *arr2)
{
    if (*(int *)arr1 > *(int *)arr2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int lower_bound(int start, int end, int key, int *card)
{
    while (start < end)
    {
        int mid = start + (end - start)/2;
        
        if (card[mid] < key)
        {
            start = mid + 1;
        }
        else if (key < card[mid])
        {
            end = mid - 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

int upper_bound(int start, int end, int key, int *card)
{
    while (start < end)
    {
        int mid = start + (end - start)/2;
        
        if (card[mid] < key)
        {
            start = mid + 1;
        }
        else if (key < card[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int main()
{
    int m, n, num, lb, ub;
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &card[i]);
    }
    qsort(card, m, sizeof(int), compare);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        
        lb = lower_bound(0, m - 1, num, card);
        ub = upper_bound(0, m - 1, num, card);
        
        res[i] = ub - lb + 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}