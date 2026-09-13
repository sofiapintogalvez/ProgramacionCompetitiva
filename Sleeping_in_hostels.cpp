#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    string fila;

    while(getline(cin, fila)) 
    {
        int n = fila.size();
        int mejor = 0;
        int primera_x = -1;
        int ultima_x = -1;

        for(int i = 0; i < n; i++) 
        {
            if (fila[i] == 'X') 
            {
                if (primera_x == -1) primera_x = i;
                ultima_x = i;
            }
        }

        int puntos_antes = primera_x;
        if(puntos_antes > 0) 
            mejor = max(mejor, puntos_antes - 1);

        int puntos_despues = n - 1 - ultima_x;
        if(puntos_despues > 0) 
            mejor = max(mejor, puntos_despues - 1);

        int anterior = primera_x;
        for(int i = primera_x + 1; i <= ultima_x; i++) 
        {
            if(fila[i] == 'X') 
            {
                int gap = i - anterior - 1;
                if(gap > 0)
                    mejor = max(mejor, (gap - 1) / 2);

                anterior = i;
            }
        }

        cout << mejor << endl;
    }

    return 0;
}