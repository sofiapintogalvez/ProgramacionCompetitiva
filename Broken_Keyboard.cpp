#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    string oracion;

    while(getline(cin, oracion))
    {
        list<char> textoFinal;
        list<char>::iterator cursor = textoFinal.begin();

        for(char c : oracion)
        {
            if(c == '[')
            {
                cursor = textoFinal.begin();
            }
            else if(c == ']')
            {
                cursor = textoFinal.end();
            }
            else
            {
                textoFinal.insert(cursor, c);
            }
        }

        for(char c : textoFinal) 
            cout << c;
        cout << endl;

    }
    return 0;
}