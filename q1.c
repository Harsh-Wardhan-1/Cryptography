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
    double p = 11;
    double q = 3;
    double n = p * q;

    // Finding other part of public key.
    // e stands for encrypt
    double e = 3;
    double phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int k;
    for (int i = 2; i < phi; i++)
    {
        if (gcd(i, phi) == 1)
        {
            k = i;
            break;
        }
    }
    double d = (1 + (k * phi)) / e;
    // Message to be encrypted
    double msg = 13;

    printf("Message data = %lf", msg);

    // Encryption c = (msg ^ e) % n
    double c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %lf", c);

    // Decryption m = (c ^ d) % n
    double m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message Sent = %lf", m);

    return 0;
}