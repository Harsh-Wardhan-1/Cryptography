#include <iostream>
#include <cstring>
#define SIZE 30
using namespace std;

void converttouppercase(char letter[], int ps)
{
    int i;
    for (i = 0; i < ps; i++)
    {
        if (letter[i] > 96 && letter[i] < 123)
            letter[i] -= 32;
    }
}
int removeallspaces(char *letter, int ps)
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (letter[i] != ' ')
            letter[count++] = letter[i];
    letter[count] = '\0';
    return count;
}

void keytable(char key[], int ks, char keyT[5][5])
{
    int i, j, k, flag = 0, *dicty;

    dicty = (int *)calloc(26, sizeof(int));
    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'J')
            dicty[key[i] - 65] = 2;
    }

    dicty['J' - 65] = 1;

    i = 0;
    j = 0;

    for (k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 65] == 2)
        {
            dicty[key[k] - 65] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 65);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[])
{
    int i, j;

    if (a == 'J')
        a = 'I';
    else if (b == 'J')
        b = 'I';

    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 5; j++)
        {

            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
int mod5(int a)
{
    return (a % 5);
}
int prepare(char str[], int ptrs)
{
    if (ptrs % 2 != 0)
    {
        str[ptrs++] = 'Z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];

    for (i = 0; i < ps; i += 2)
    {

        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void playfaircipherencryption(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    ks = strlen(key);
    ks = removeallspaces(key, ks);
    converttouppercase(key, ks);

    ps = strlen(str);
    converttouppercase(str, ps);
    ps = removeallspaces(str, ps);

    ps = prepare(str, ps);

    keytable(key, ks, keyT);

    encrypt(str, keyT, ps);
}
void decrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];
    for (i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] - 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void playfaircipherdecryption(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    ks = strlen(key);
    ks = removeallspaces(key, ks);
    converttouppercase(key, ks);

    ps = strlen(str);
    converttouppercase(str, ps);
    ps = removeallspaces(str, ps);

    keytable(key, ks, keyT);

    decrypt(str, keyT, ps);
}
int main()
{
    char str[SIZE], key[SIZE];
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter message to be encrypted: ";
    cin >> str;
    playfaircipherencryption(str, key);
    cout << "\nEncrypted code: " << str << endl;
    playfaircipherdecryption(str, key);
    cout << "Decrypted code: " << str << endl;
    return 0;
}