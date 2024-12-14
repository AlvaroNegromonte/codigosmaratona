#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
   
    
    cin >> n;   

    vector<int> vetor(n);

    for(int i=0; i < n; i++){
        cin >> vetor[i];
    }

    int second = INT_MIN;
    int maior = vetor[0];

    for(int i=1; i<n;i++){
        if(vetor[i]>maior){
            second = maior;
            maior = vetor[i];
        }
        else if(vetor[i] > second && vetor[i] != maior){
            second = vetor[i];
        }
    }
    cout << second;
    return 0;
}
