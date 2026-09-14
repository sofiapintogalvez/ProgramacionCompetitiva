#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> bloques(n);

    for(int i = 0; i < n; i++)
    {
        bloques[i].push_back(i);
    }

    string comando1, comando2;
    int a, b;

    while(cin >> comando1)
    {
        if(comando1 == "quit")
            break;

        cin >> a >> comando2 >> b;

        int pilaA = -1;
        int pilaB = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < bloques[i].size(); j++)
            {
                if(bloques[i][j] == a)
                    pilaA = i;

                if(bloques[i][j] == b)
                    pilaB = i;
            }
        }

        if(pilaA == pilaB)
            continue;

        int posA = 0;

        for(int j = 0; j < bloques[pilaA].size(); j++)
        {
            if(bloques[pilaA][j] == a)
            {
                posA = j;
                break;
            }
        }

        if(comando1 == "move")
        {
            for(int j = posA + 1; j < bloques[pilaA].size(); j++)
            {
                int x = bloques[pilaA][j];
                bloques[x].push_back(x);
            }

            bloques[pilaA].resize(posA + 1);
        }

        if(comando2 == "onto")
        {
            int posB = 0;

            for(int j = 0; j < bloques[pilaB].size(); j++)
            {
                if(bloques[pilaB][j] == b)
                {
                    posB = j;
                    break;
                }
            }

            for(int j = posB + 1; j < bloques[pilaB].size(); j++)
            {
                int x = bloques[pilaB][j];
                bloques[x].push_back(x);
            }

            bloques[pilaB].resize(posB + 1);
        }

        for(int j = posA; j < bloques[pilaA].size(); j++)
        {
            bloques[pilaB].push_back(bloques[pilaA][j]);
        }

        bloques[pilaA].resize(posA);
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << ":";

        for(int j = 0; j < bloques[i].size(); j++)
        {
            cout << " " << bloques[i][j];
        }

        cout << endl;
    }

    return 0;
}