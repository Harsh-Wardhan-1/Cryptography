#include <iostream>
using namespace std;

int main()
{
    int i, j;
    string pt;
    cout << "Enter the text: ";
    cin >> pt;
    string key = "Hello";
    int mod = key.length();
    j = 0;
    for (i = key.length(); i < pt.length(); i++)
    {
        key += key[j % mod];
        j++;
    }
    string ct = "";
    for (i = 0; i < pt.length(); i++)
    {
        ct += (key[i] - 'A' + pt[i] - 'A') % 26 + 'A';
    }
    cout << "\nPlaintext: " << pt << endl;
    cout << "Ciphertext: " << ct << endl;
    string dpt = "";
    for (i = 0; i < ct.size(); i++)
    {
        dpt += (ct[i] - key[i] + 26) % 26 + 'A';
    }
    cout << "Decoded Plaintext: " << dpt << endl;
    return 0;
}
