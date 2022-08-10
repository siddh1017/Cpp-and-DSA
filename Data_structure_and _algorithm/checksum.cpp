#include <iostream>
#include <cstring>
using namespace std;

int check_digit(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        else 
        {
            if (is_binary (str))
                str++;
            else
                return 0;
        }
    }
    return 1;
}

int is_binary(char *s)
{
    if (*s=='0' || *s=='1')
        return 1;
    else
        return 0;
}

string add(string a, string b)
{
    string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;
    while (size_a >= 0 || size_b >= 0 || temp == 1)
    {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);

        if (result.size() > a.size() - 1)
        {
            string temp_s = "";
            temp_s = temp_s + char(temp + '0');
            result = add(result, temp_s);
        }
        else
        {
            result = char(temp % 2 + '0') + result;
        }
        temp /= 2;
        size_a--;
        size_b--;
    }
    return result;
}

void sum(char m[])
{
    char *token;
    char *token1;
    token = strtok(m, " ");
    token1 = strtok(token, " ");
    if (check_digit(token) && check_digit(token1))
    {
        string sum = add(token, token1);
        while (token1 != NULL)
        {
            token1 = strtok(NULL, " ");
            if (check_digit(token1))
            {
                sum = add(sum, token1);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
    }
    cout << sum;
}

int main()
{
    int n;
    cout << "Enter the no. of numbers: ";
    cin >> n;

    char message[(n * 4) + (n - 1)];
    for (int i = 0; i < ((n * 4) + (n - 1)); i++)
    {
        cin >> message[i];
    }

    sum(message);
    return 0;
}