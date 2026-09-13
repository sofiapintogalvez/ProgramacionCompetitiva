#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int caso = 1; caso <= t; caso++) 
    {
        string road;
        cin >> road;

        int n = road.size();
        int contador = 0;

        for(int i = 0; i < n; i++) 
        {
            if(road[i] != '-') 
                continue; // solo posiciones vacias son candidatas

            bool valido = true;

            if(i + 1 < n && road[i + 1] == 'B') 
                valido = false; // 5m antes de un bus stop

            if(i + 2 < n && road[i + 2] == 'B')
                valido = false; // 10m antes de un bus stop

            if(i + 1 < n && road[i + 1] == 'S') 
                valido = false; // 5m antes de un side street

            if(i - 1 >= 0 && road[i - 1] == 'S') 
                valido = false; // 5m despues de un side street

            if(valido) 
                contador++;
        }

        cout << "Case " << caso << ": " << contador << endl;
    }

    return 0;
}