#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    vector<vector<int>> vecinos = {
        {1,3},     {0,2,4},   {1,5},
        {0,4,6},   {1,3,5,7}, {2,4,8},
        {3,7},     {4,6,8},   {5,7}
    };

    auto f = [&](int estado) {
        int nuevo = 0;
        for(int celda = 0; celda < 9; celda++) 
        {
            int suma = 0;
            for(int v : vecinos[celda]) 
            {
                suma += (estado >> v) & 1;
            }
            if(suma % 2 == 1) 
                nuevo |= (1 << celda);
        }
        return nuevo;
    };

    int t;
    cin >> t;

    while(t--) 
    {
        int estado = 0;
        for(int fila = 0; fila < 3; fila++) 
        {
            string linea;
            cin >> linea;
            for(int col = 0; col < 3; col++) 
            {
                if (linea[col] == '1') 
                    estado |= (1 << (fila * 3 + col));
            }
        }

        vector<int> visto(512, -1);
        int idx = 0;
        int actual = estado;

        while(visto[actual] == -1) 
        {
            visto[actual] = idx;
            actual = f(actual);
            idx++;
        }

        int primer_idx = visto[actual];
        cout << (primer_idx - 1) << endl;
    }

    return 0;
}