#include <iostream>
#include <stack>
#include <string>
using namespace std;

string encodeString(const string &s)
{
    stack<char> charStack;
    string encodedString = "";

    for (char c : s)
    {

        if (islower(c))
        {

            char encodedChar = 'a' + (c - 'a' + 3) % 26;
            charStack.push(encodedChar);
        }
        else
        {
            charStack.push(c);
        }
    }

    while (!charStack.empty())
    {
        encodedString += charStack.top();
        charStack.pop();
    }

    return encodedString;
}

int main()
{
    string s;
    cout << "Nhap chuoi s: ";
    getline(cin, s);

    string encodedString = encodeString(s);
    cout << "Chuoi ma hoa: " << encodedString << endl;

    return 0;
}