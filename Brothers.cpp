#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, R, C, K;

    while(cin >> N >> R >> C >> K)
    {
        if(N == 0 && R == 0 && C == 0 && K == 0)
            break;

        vector<vector<int>> matriz(R, vector<int>(C));

        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin >> matriz[i][j];
            }
        }

        for(int batalla = 0; batalla < K; batalla++)
        {
            vector<vector<int>> nueva = matriz;

            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    int actual = matriz[i][j];
                    int gana = (actual + 1) % N;

                    if(i > 0 && matriz[i - 1][j] == gana)
                        nueva[i - 1][j] = actual;

                    if(i < R - 1 && matriz[i + 1][j] == gana)
                        nueva[i + 1][j] = actual;

                    if(j > 0 && matriz[i][j - 1] == gana)
                        nueva[i][j - 1] = actual;

                    if(j < C - 1 && matriz[i][j + 1] == gana)
                        nueva[i][j + 1] = actual;
                }
            }

            matriz = nueva;
        }

        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(j > 0)
                    cout << " ";

                cout << matriz[i][j];
            }

            cout << endl;
        }
    }

    return 0;
}