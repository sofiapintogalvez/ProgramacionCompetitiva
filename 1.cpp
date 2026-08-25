#include <iostream>
using namespace std;

int rpta(int v, int t)
{
    return 2 * (v * t);
}

int main()
{
    int v, t;
    while (cin >> v >> t)
    {
        cout << rpta(v, t);
        cout << endl;
    }

    return 0;
}