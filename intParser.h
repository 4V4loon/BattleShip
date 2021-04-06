#pragma once
#include<iostream>

int& powInt(int& x, int& y)
{
    for (int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}
int& parseInt(char* chars)
{
    int sum = 0;
    int len = strlen(chars);
    for (int x = 0; x < len; x++)
    {
        int n = chars[len - (x + 1)] - '0';
        sum = sum + powInt(n, x);
    }
    return sum;
}

