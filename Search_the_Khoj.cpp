#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int caso = 1; caso <= t; caso++)
    {
        int n;
        cin >> n;

        vector<string> numeros;

        for(int i = 0; i < n; i++)
        {
            string numero;
            cin >> numero;
            numeros.push_back(numero);
        }

        string recuerdo;
        cin >> recuerdo;

        cout << "Case " << caso << ":" << endl;

        for(string numero : numeros)
        {
            int diferentes = 0;

            for(int i = 0; i < numero.length(); i++)
            {
                if(numero[i] != recuerdo[i])
                {
                    diferentes++;
                }
            }

            if(diferentes <= 1)
            {
                cout << numero << endl;
            }
        }
    }

    return 0;
}