#include <stdio.h>
#include <math.h>

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    double p;
    double q;
    printf("Enter prime numbers p, q:");
    scanf("%lf", &p);
    scanf("%lf", &q);
    double n1 = p * q;
    double n2 = (p - 1) * (q - 1);
    double e;
    printf("Enter public key e:");
    scanf("%lf", &e);
    while (e < n2)
    {
        if (gcd(e, n2) == 1)
            break;
        else
            e++;
    }

    int k = 1;
    double d = (1 + (k * n2)) / e;
    double no;
    printf("Enter message to be sent:");
    scanf("%lf", &no);
    printf("Given data = %lf", no);
    double z = pow(no, e);
    z = fmod(z, n1);
    printf("\nEncrypted data = %lf", z);
    double m = pow(z, d);
    m = fmod(m, n1);
    printf("\nDecrypted data = %lf", m);

    return 0;
}