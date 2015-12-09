#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
void iswap(char *a, char *b)
{
    char temp = *b;
    *b = *a;
    *a = temp;
}

int findCeil(char str[], char first, int start, int end)
{
    int index = start;
    for(int i = start + 1; i <= end; ++i)
    {
        if(str[i] > first && str[i] < str[index])
        {
            index = i;
        }
    }
    return index;
}

void sortedPermutation(char str[])
{
    qsort(str, strlen(str), sizeof(str[0]), compare);
    bool isFinished = false;

    while(!isFinished)
    {
        cout << str << endl;
        int i;
        for(i = strlen(str) - 2; i >= 0; --i)
        {
            if(str[i] < str[i + 1])
            break;
        }
        if(i == -1)
            isFinished = true;
        else
        {
            int index = findCeil(str, str[i], i + 1, strlen(str) - 1);
            iswap(&str[i], &str[index]);
            qsort(str + i + 1, strlen(str) - i- 1, sizeof(str[0]), compare);
        }

    }
}
int main()
{
    char str[] = "ABCD";
    sortedPermutation(str);
    return 0;
}
