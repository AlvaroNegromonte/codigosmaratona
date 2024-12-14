#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n;
    vector<int> valores(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    sort(valores.begin(), valores.end());

    cin >> q;
    vector<int> moedas_num_dia(q);

    for (int i = 0; i < q; i++) {
        cin >> moedas_num_dia[i];
    }

    for (int i = 0; i < q; i++) {

        //upper_bound faz busca binaria no array de valores
        int numlojas = upper_bound(valores.begin(), valores.end(), moedas_num_dia[i]) - valores.begin();
        //diz quantas lojas oferecem bebidas q sao possiveis de comprar 
        cout << numlojas << '\n';
    }

    return 0;
}
