#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n;

    while(cin >> n && n != 0)
    {
        vector<long long> monedas(n);

        long long sum = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> monedas[i];
            sum += monedas[i];
        }

        long long prom = sum / n;

        vector<long long> sobras(n);
        long long acumulado = 0;

        for(int i = 0; i < n; i++) 
        {
            acumulado += monedas[i] - prom;
            sobras[i] = acumulado;
        }

        vector<long long> ordenado = sobras;
        sort(ordenado.begin(), ordenado.end());
        long long mediana = ordenado[n / 2];
        
        long long rpta = 0;
        for(int i = 0; i < n; i++) 
        {
            long long dife = sobras[i] - mediana;

            if (dife < 0) 
                dife = -dife;
                
            rpta += dife;
        }

        cout << rpta << endl;
    }

    return 0;
}     