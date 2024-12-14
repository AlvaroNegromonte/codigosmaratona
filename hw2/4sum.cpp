#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);

   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //hashtable para armazenar somas de pares e os índices dos elementos
    unordered_map<long long, pair<int, int>> soma_pares;

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long soma_atual = a[i] + a[j];
            long long complemento = x - soma_atual;

            //verifica se o complemento existe na hashtable
            if (soma_pares.count(complemento)) {
                auto [k, l] = soma_pares[complemento];
                //certifica que todos os indices sao diferentes(nao pode haver soma dos mesmos numeros)
                if (k != i && k != j && l != i && l != j) {
                    cout << k + 1 << " " << l + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }

            //armazena a soma atual e os índices no mapa
            soma_pares[soma_atual] = {i, j};
        }
    }

    // Se nenhuma solução for encontrada
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
