#include <iostream>
using namespace std;
int main()
{
    string cipher = "seattle";
    for (int i = 1; i < 26; i++)
    {
        cout << "Key: " << i << endl;
        for (int j = 0; j < cipher.length() - 1; j++)
        {
            cout << char((cipher[j] - 65 - i + 26) % 26 + 65);
        }
        cout << endl;
    }
}