#include <bits/stdc++.h>

using namespace std;

int n, c, att, cont;
int aux = 0;
string s, resposta;

vector <string> vet;
vector < pair <string, int> > palavra;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++){

        cin >> s;
        
        for(int i = 0; i < c; i++){
            if(s[i] == '*'){
                att = i;
                break;
            }
        }

        for(int i = 0; i < 26; i++){
            s[att] = 'a' + i;
            vet.push_back(s);
        }
    }

    palavra.resize(vet.size());

    sort(vet.begin(), vet.end());
    
    for(int i = 0; i < vet.size(); i++){
        int j;
        cont = 1;
        j = i;
        if(j!=vet.size())
        {
            if(vet[j] == vet[j+1])
            {
                while(vet[j]==vet[j+1])
                {
                    cont++;
                    j++;               
                }

                i = j;
            }
        }
        
        palavra[i].first = vet[i];
        palavra[i].second = cont;
        if(cont>aux)
        {
            resposta = palavra[i].first;
            aux = cont;
        }
    }

    cout << resposta << " " << aux << "\n";

    return 0;
}
