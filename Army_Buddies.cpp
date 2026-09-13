#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s, b;

    while(cin >> s >> b && s != 0 && b != 0)
    {
        vector<int> izquierda(s + 1);
        vector<int> derecha(s + 1);

        for(int i = 1; i <= s; i++)
        {
            izquierda[i] = i - 1;
            derecha[i] = i + 1;
        }

        for(int i = 0; i < b; i++)
        {
            int l, r;
            cin >> l >> r;

            int izq = izquierda[l];
            int der = derecha[r];

            if(izq >= 1)
                derecha[izq] = der;

            if(der <= s)
                izquierda[der] = izq;

            if(izq >= 1)
                cout << izq << " ";
            else
                cout << "* ";

            if(der <= s)
                cout << der << endl;
            else
                cout << "*" << endl;
        }

        cout << "-" << endl;
    }

    return 0;
}