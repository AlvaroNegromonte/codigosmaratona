#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string sequence;
    stack <char> pilha;

    cin >> sequence;

    int tam = sequence.size();

    for (int i=0; i< tam; i++){
        if(sequence[i] == 'C' && !pilha.empty() && pilha.top() == 'B'){
            pilha.pop();

            if(!pilha.empty() && pilha.top()=='A'){
                pilha.pop();
            }
            else {
                pilha.push('B');
                pilha.push('C');
            }
        }
        else {
            pilha.push(sequence[i]);
        }
    } 

    string reversed(pilha.size(), ' ');
    int indice = 0;

    while(!pilha.empty()){
        reversed[indice++] = pilha.top();
        pilha.pop();
    }

    for(int i = indice - 1; i>=0; i--){
        cout << reversed[i];
    }


    return 0;
}
