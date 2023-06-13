#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ip[16];
    int y[4];
    printf("Enter the ip address\n");
    scanf("%s", ip);
    int dot = 0,i = 0, j = 0,x = 0;
    while (ip[i] != '\0')
    {
        if (ip[i] == '.')
        {
            if (dot == 3)
            {
                printf("Invalid IP address");
                return 0;
            }
            y[j] = x;
            x = 0;
            j++;
        }
        else
        {
            x = x * 10;
            x = x + ip[i] - '0';
        }
        i++;
    }
    y[3] = x;
    x = y[0];

    if (y[0] < 0 || y[0] > 255 || y[1] < 0 || y[1] > 255 || y[2] < 0 || y[2] > 255 || y[3] < 0 || y[3] > 255)
    {
        printf("Invalid ip address");
        return 0;
    }
    if (x >= 0 && x <= 127)
    {
        printf("class : A  netid : %d  hostid :%d.%d.%d", y[0], y[1], y[2], y[3]);
    }
    else if (x >= 128 && x <= 191)
    {
        printf("class : B  netid : %d.%d  hostid :%d.%d", y[0], y[1], y[2], y[3]);
    }
    else if (x >= 192 && x <= 223)
    {
        printf("class : C  netid : %d.%d.%d  hostid :%d", y[0], y[1], y[2], y[3]);
    }
    else if (x >= 224 && x <= 240)
    {
        printf("Class D adresses are not divided");
    }
    else if (x <= 255)
    {
        printf("Class E adresses are not divided");
    }
    return 0;
}