#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_digit(char *ip)
{
    while (*ip)
    {
        if (!isdigit(*ip))
        {
            return 0;
        }
        ip++;
    }
    return 1;
}

int check_range(int x)
{
    if (x >= 0 && x <= 255)
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
                token = strtok(NULL, ".");
                dots++;
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

void net_host(char ip[], char x)
{
    char net[15], host[15];
    if (x == 'a')
    {
        int i = 0, j = 0;
        while (ip[j] != '.'){
            net[i++] = ip[j++];
        }
        i = 0;
        j++;
        while (ip[j] != '\0'){
            host[i++] = ip[j++];
        }
        printf("network ID is %s\n", net);
        printf("Host ID is %s\n", host);
    }
    else if (x == 'b')
    {
        int i = 0, j = 0, dotCount = 0;
        while (dotCount < 2)
        {
            net[i++] = ip[j++];
            if (ip[j] == '.'){
                dotCount++;
            }
        }
        i = 0;
        j++;

        while (ip[j] != '\0'){
            host[i++] = ip[j++];
        }
        printf("network ID is %s\n", net);
        printf("Host ID is %s\n", host);
    }
    else if (x == 'c')
    {
        int i = 0, j = 0, dotCount = 0;
        while (dotCount < 3)
        {
            net[i++] = ip[j++];
            if (ip[j] == '.'){
                dotCount++;
            }    
        }

        i = 0;
        j++;

        while (ip[j] != '\0'){
            host[i++] = ip[j++];
        }
        printf("network ID is %s\n", net);
        printf("Host ID is %s\n", host);
    }
    else
    {
        printf("No Network or Host Id\n");
    }
}

void check_grp(char ip[])
{
    char *token;
    token = strtok(ip, ".");
    int num = atoi(token);
    if (num >= 240 && num < 255)
    {
        printf("IP_address falls in grp E\n");
        net_host (ip, 'e');
    }
    else if (num >= 224 && num <= 139)
    {
        printf("IP_address falls in grp D\n");
        net_host (ip, 'd');
    }
    else if (num >= 192 && num <= 223)
    {
        printf("IP_address falls in grp C\n");
        net_host (ip, 'c');
    }
    else if (num >= 128 && num <= 191)
    {
        printf("IP_address falls in grp B\n");
        net_host (ip, 'b');
    }
    else if (num >= 1 && num <= 127)
    {
        printf("IP_address falls in grp A\n");
        net_host (ip, 'a');
    }
    else
    {
        printf("No grp assigned");
    }
}

int main()
{
    char ip[15];
    fgets(ip, sizeof(ip), stdin);
    if (check_ip(ip))
    {
        printf("Valid IP_address and ");
        check_grp(ip);
    }
    else
    {
        printf("NOT valid IP_address");
    }

    return 0;
}
