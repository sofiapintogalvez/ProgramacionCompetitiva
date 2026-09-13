#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;

    while(cin >> n && n != 0)
    {
        vector<int> espacios;
        int minimo = 25;

        cin.ignore();

        for(int i = 0; i < n; i++)
        {
            string fila;
            getline(cin, fila);

            int cont = 0;

            for(char c : fila)
            {
                if(c == ' ')
                {
                    cont++;
                }
            }

            espacios.push_back(cont);

            if(cont < minimo)
            {
                minimo = cont;
            }
        }

        int rpta = 0;

        for(int x : espacios)
        {
            rpta += x - minimo;
        }

        cout << rpta << endl;
    }

    return 0;
}