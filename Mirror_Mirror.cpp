#include <iostream>
#include <vector>

using namespace std;

bool iguales(vector<vector<char>> a, vector<vector<char>> b, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != b[i][j])
                return false;
        }
    }

    return true;
}

vector<vector<char>> rotar90(vector<vector<char>> a, int n)
{
    vector<vector<char>> b(n, vector<char>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            b[j][n - 1 - i] = a[i][j];
        }
    }

    return b;
}

vector<vector<char>> reflejar(vector<vector<char>> a, int n)
{
    vector<vector<char>> b(n, vector<char>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            b[n - 1 - i][j] = a[i][j];
        }
    }

    return b;
}

int main()
{
    int n;
    int caso = 1;

    while(cin >> n)
    {
        vector<vector<char>> original(n, vector<char>(n));
        vector<vector<char>> nueva(n, vector<char>(n));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> original[i][j];
            }

            for(int j = 0; j < n; j++)
            {
                cin >> nueva[i][j];
            }
        }

        vector<vector<char>> r90 = rotar90(original, n);
        vector<vector<char>> r180 = rotar90(r90, n);
        vector<vector<char>> r270 = rotar90(r180, n);
        vector<vector<char>> ref = reflejar(original, n);
        vector<vector<char>> ref90 = rotar90(ref, n);
        vector<vector<char>> ref180 = rotar90(ref90, n);
        vector<vector<char>> ref270 = rotar90(ref180, n);

        cout << "Pattern " << caso;

        if(iguales(original, nueva, n))
            cout << " was preserved." << endl;
        else if(iguales(r90, nueva, n))
            cout << " was rotated 90 degrees." << endl;
        else if(iguales(r180, nueva, n))
            cout << " was rotated 180 degrees." << endl;
        else if(iguales(r270, nueva, n))
            cout << " was rotated 270 degrees." << endl;
        else if(iguales(ref, nueva, n))
            cout << " was reflected vertically." << endl;
        else if(iguales(ref90, nueva, n))
            cout << " was reflected vertically and rotated 90 degrees." << endl;
        else if(iguales(ref180, nueva, n))
            cout << " was reflected vertically and rotated 180 degrees." << endl;
        else if(iguales(ref270, nueva, n))
            cout << " was reflected vertically and rotated 270 degrees." << endl;
        else
            cout << " was improperly transformed." << endl;

        caso++;
    }

    return 0;
}