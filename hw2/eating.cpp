#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, q;
        cin >> n >> q;

        vector<int> array(n);
        for (int i = 0; i < n; i++) {
            cin >> array[i];//le array de qtd de açucar
        }

        
        sort(array.rbegin(), array.rend());//ordena em ordem decrescente

    
        vector<long long> soma(n);//esse vetor vai armazenar a soma para cada indice do vetor array
        soma[0] = array[0];
        
        for (int i = 1; i < n; i++) {
            soma[i] = soma[i - 1] + array[i];
        }

        vector<int> infos(q);//vetor com quant de açucar desejadas
        for (int i = 0; i < q; i++) {
            cin >> infos[i];
        }

        
        for (int i = 0; i < q; i++) {
            int x = infos[i];

            //retorna o primeiro indice no qual a quantidade de açucar é maior ou igual a desejada
            auto iterador = lower_bound(soma.begin(), soma.end(), x);

            if (iterador == soma.end()) {//se nao encontrar soma possivel no array de somas eh impossivel
                cout << -1 << '\n'; 
            } else {
                
                cout << (iterador - soma.begin() + 1) << '\n'; 
            }
        }
    }

    return 0;
}
