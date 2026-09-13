#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int caso = 1;

    while(cin >> n && n != 0)
    {   
        vector<int> cubos; 
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            cubos.push_back(h);
            sum += h;
        }

        int div = sum / n;
        int rpta = 0;

        for(int d : cubos)
        {
            if(d > div) 
                rpta += d - div;
        }

        cout << "Set #" << caso << endl;
        cout << "The minimum number of moves is " << rpta << "." << endl;
        cout << endl;
        caso++;
    }
    
    return 0;
}