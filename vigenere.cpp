#include <iostream>
using namespace std;

string finalkey(string pt, string k)
{
    if (k.length() >= pt.length())
        return k;
    else
    {
        int plen = pt.length() - k.length();
        int klen = k.length();
        while (plen >= klen)
        {
            k += k;
            plen -= klen;
        }
        k += k.substr(0, plen);
        return k;
    }
}
string encrypt(string pt, string k)
{

    string ct = "";
    for (int i = 0; i < pt.length(); i++)
    {
        ct += (char)(((int)pt[i] - 'A' + (int)k[i] - 'A') % 26) + 'A';
    }
    return ct;
}
string decrypt(string ct, string k)
{

    string pt = "";
    for (int i = 0; i < ct.length(); i++)
        pt += (char)((((int)ct[i] - 'A' - (k[i] - 'A')) + 26) % 26) + 'A';

    return pt;
}

int main()
{
    string pt;
    string key = "HELO";
    cout << "Enter text in capital letters: ";
    cin >> pt;
    key = finalkey(pt, key);
    cout << "\nPlaintext: " << pt << endl;
    string ct = encrypt(pt, key);
    cout << "Ciphertext: " << ct << endl;
    pt = decrypt(ct, key);
    cout << "Decoded Plaintext: " << pt << endl;
    return 1;
}