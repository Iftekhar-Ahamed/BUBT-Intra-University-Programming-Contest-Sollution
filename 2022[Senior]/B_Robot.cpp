#include <stdio.h>

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    char str[105];
    scanf("%s", str);

    int gg, tt;
    int i;
    for (i = 0; i < n; i++)
    {
        if (str[i] == 'R')
            gg = i;
        if (str[i] == 'B')
            tt = i;
    }
    int flag = 0;
    if (tt < gg)
    {
        for (i = tt; i <= gg; i += k)
        {
            if (str[i] == 'R')
            {
                flag = 1;
                break;
            }
            if (str[i] == '#')
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        for (i = gg; i <= tt; i += k)
        {
            if (str[i] == 'B')
            {
                flag = 1;
                break;
            }
            if (str[i] == '#')
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
        printf("Yeah!!\n");
    else
        printf("Oppss!!\n");
    return 0;
}
