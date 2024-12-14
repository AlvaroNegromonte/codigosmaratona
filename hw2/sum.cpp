#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x; 
    vector<long long> a(n);
    unordered_map<long long, int> mapavalores; //usei map para armazenar os valores e seus respectivos indices(tabela hash)
    mapavalores.reserve(n);//reserva espaço para n elementos da tabela hashing, evitando redimensionamento dinamico

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        long long diferenca = x - a[i];//diferenca eh o numero que somado com a[i] resulta em x
        
        //map.count(chave) verifica se a chave existe no mapa.
        if (mapavalores.count(diferenca)) { //verifica se existe, no array, um numero que seja a diferenca entre x e a[i]
            cout << mapavalores[diferenca] + 1  << " " << i + 1  << endl;//printa o indice dos numeros cuja soma dá x
            return 0;
        }
        
    
        mapavalores[a[i]] = i;//atualiza o valor de a[i] no mapa e o associa ao indice;
    }


    cout << "IMPOSSIBLE" << endl;
    return 0;
}
