#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int casos_prueba;
    cin >> casos_prueba;
    
    for(int i = 0; i < casos_prueba; i++)
    {
        vector<int> amigos[3];

        // Leer problemas de los 3 amigos
        for(int j = 0; j < 3; j++)
        {
            int cant_resueltos;
            cin >> cant_resueltos;

            amigos[j].resize(cant_resueltos);

            for(int k = 0; k < cant_resueltos; k++)
                cin >> amigos[j][k];
        }

        vector<int> exclusivos[3];

        for(int j = 0; j < 3; j++)
        {
            for(int problema : amigos[j])
            {
                bool estaEnOtro = false;

                for(int otro = 0; otro < 3; otro++)
                {
                    if(otro == j)
                        continue;

                    for(int x : amigos[otro])
                    {
                        if(x == problema)
                        {
                            estaEnOtro = true;
                            break;
                        }
                    }

                    if(estaEnOtro)
                        break;
                }

                if(!estaEnOtro)
                {
                    exclusivos[j].push_back(problema);
                }
            }
        }

        for(int j = 0; j < 3; j++)
            sort(exclusivos[j].begin(), exclusivos[j].end());

        int mayor = 0;

        for(int j = 0; j < 3; j++)
        {
            if(exclusivos[j].size() > mayor)
                mayor = exclusivos[j].size();
        }

        cout << "Case #" << i + 1 << ":\n";

        for(int j = 0; j < 3; j++)
        {
            if(exclusivos[j].size() == mayor)
            {
                cout << j + 1 << " " << mayor;

                for(int problema : exclusivos[j])
                    cout << " " << problema;

                cout << endl;
            }
        }
    }

    return 0;
}