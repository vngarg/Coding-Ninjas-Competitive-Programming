// Range of second number is upto pow(10,250)

#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(b > a)
        return GCD(b, a);
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        string b;
        cin >> b;

        if(a == 0) {
            cout<<b<<endl;
            continue;
        }

        int num = 0;
        for (int i = 0; b[i] != '\0'; ++i)
            num = ((num * 10) + (int)b[i] - 48) % a;
        
            cout << GCD(a, num) << endl;
    }
    return 0;
}