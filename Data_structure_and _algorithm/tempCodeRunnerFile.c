#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_digit(char *str)
{
    int i=0;
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }    
        str++;
    }
    return 1;
}

int check_range(int x)
{
    if (x>=0 && x<=255)
        return 1;
    else
        return 0;
}

int check_ip(char str[])
{
    char *token;
    token = strtok(str, ".");
    int dots = 0;
    while (token != NULL)
    {
        if (check_digit(token))
        {
            int num = atoi(token);
            if (check_range(num))
            {
                token = strtok (NULL ,".");
                dots ++;
            }
            else
            {
                break;   
            }
        }
        else 
        {
            break;
        }
    }
    if (dots == 3)
        return 1;
    else 
        return 0;
}

void check_grp(char ip[])
{
    char * token;
    token = strtok (ip, ".");
    int num = atoi(token);
    if (num >= 240 && num <255)
    {
        printf("IP_address falls in grp E");
    }
    else if(num >= 224 && num <=139)
    {
        printf("IP_address falls in grp D");
    }
    else if (num>=192 && num <=223)
    { 
        printf ("IP_address falls in grp C");
    }
    else if (num>=128 && num <=191)
    { 
        printf ("IP_address falls in grp B");
    }
    else if (num>=1 && num <=127)
    { 
        printf ("IP_address falls in grp A");
    }
    else {
        printf ("No grp assigned");
    }
}

int main()
{
    char ip[15];
    fgets (ip, sizeof(ip), stdin);
    if (check_ip(ip))
    {
        printf ("Valid IP_address and ");
        check_grp(ip);
    }
    else 
    {
        printf ("NOT valid IP_address");
    }

    return 0;
}


