#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    while(cin >> n && n != 0)
    {
        vector<int> carros(n);
        vector<int> posicion(n, 0);
        bool posible = true;

        for(int i = 0; i < n; i++)
        {
            int c, p;
            cin >> c >> p;

            int pos = i + p;

            if(pos < 0 || pos >= n || posicion[pos] != 0)
                posible = false;
            
            else
                posicion[pos] = c;
        }

        if(!posible)
            cout << -1 << endl;
        
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(i > 0)
                    cout << " ";

                cout << posicion[i];
            }

            cout << endl;
        }
    }

    return 0;
}