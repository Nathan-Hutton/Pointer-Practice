#include <stdio.h>
#include <stdlib.h>

int reduceFraction(int *numerator, int *denominator);
int gcd(int m, int n);

int main()
{
    int numerator, denominator;
    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    if(numerator == 0 || denominator == 0)
    {
        printf("Cannot use 0\n");
        return 0;
    }
    reduceFraction(&numerator, &denominator);
    printf("In lowest terms, that fraction is %d/%d\n", numerator, denominator);
    return 0;
}

int gcd(int m, int n)
{
    if (m < 0)
        return gcd(-m, n);
    else if (n < 0)
        return gcd(m, -n);
    else if (m % n != 0)
        return gcd(n, m % n);
    else
        return n;
}

int reduceFraction(int *numerator, int *denominator)
{
    int common_factor = gcd(*numerator, *denominator);
    *numerator = *numerator / common_factor;
    *denominator = *denominator / common_factor;
    return 0;
}
