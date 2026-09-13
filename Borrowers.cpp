#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<pair<string, string>> todos;
    vector<pair<string, string>> estante;
    string linea;

    auto autorDe = [&](string titulo) {
        for (int i = 0; i < todos.size(); i++)
            if (todos[i].second == titulo) return todos[i].first;
        return string("");
    };

    while(getline(cin, linea) && linea != "END") 
    {
        int c = linea.find('"', 1);
        string titulo = linea.substr(0, c + 1);
        string autor = linea.substr(c + 5);
        todos.push_back({autor, titulo});
        estante.push_back({autor, titulo});
    }

    sort(estante.begin(), estante.end());

    vector<string> devueltos;

    while(getline(cin, linea) && linea != "END") 
    {
        if(linea.substr(0,6) == "BORROW") 
        {
            string titulo = linea.substr(7);
            for (int i = 0; i < estante.size(); i++)
                if (estante[i].second == titulo) 
                { 
                    estante.erase(estante.begin()+i); 
                    break; 
                }

        } 
        else if(linea.substr(0,6) == "RETURN")
            devueltos.push_back(linea.substr(7));

        else 
        {
            sort(devueltos.begin(), devueltos.end(), [&](string a, string b) {
                return make_pair(autorDe(a), a) < make_pair(autorDe(b), b);
            });

            for(string titulo : devueltos) 
            {
                pair<string,string> l = {autorDe(titulo), titulo};
                int pos = 0;
                while(pos < estante.size() && estante[pos] < l) 
                    pos++;

                if(pos == 0) 
                    cout << "Put " << titulo << " first\n";

                else 
                    cout << "Put " << titulo << " after " << estante[pos-1].second << endl;

                estante.insert(estante.begin() + pos, l);
            }

            devueltos.clear();
            cout << "END\n";
        }
    }

    return 0;
}