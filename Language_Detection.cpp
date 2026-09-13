#include <string>
#include <iostream>

using namespace std;

int main()
{   
    string palabra;
    int t = 1;
    
    cin >> palabra;

    while(palabra != "#")
    {
        cout << "Case " << t << ": ";
        
        if(palabra == "HELLO")
            cout << "ENGLISH" << endl;

        else if(palabra == "HOLA")
            cout << "SPANISH" << endl;
        
        else if(palabra == "HALLO")
            cout << "GERMAN" << endl;

        else if(palabra == "BONJOUR")
            cout << "FRENCH" << endl;

        else if(palabra == "CIAO")
            cout << "ITALIAN" << endl;

        else if(palabra == "ZDRAVSTVUJTE")
            cout << "RUSSIAN" << endl;

        else
            cout << "UNKNOWN" << endl;

        t++;
        
        cin >> palabra;
    }

    return 0;
}