#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int t, n;
    string let;
    vector<char> xx;
    vector<char>::iterator it;
    scanf_s("%d", &t);
    while (t--)
    {
        scanf_s("%d\n", &n);
        cin >> let;
        for (int i=0; i < n ; i++)
        {
            switch (let[i])
            {
            case 'L':
                xx.push_back('L');
                break;

            case 'R':
                xx.push_back('R');
                break;

            case 'U':
                xx.push_back('D');
                break;

            case 'D':
                xx.push_back('U');
                break;

            default:
                break;
            }
        }
    for (it = xx.begin(); it != xx.end(); it++)
        cout << *it;
    xx.clear();
    cout << endl;
}
    return 0;
}