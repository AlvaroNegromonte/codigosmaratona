#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int consultas, numero;
    cin >> consultas;

    string comando;
    deque <int> fila; 
    bool invertida = false; 

    for (int i = 0; i < consultas; i++) {
        cin >> comando;

        if (comando == "toFront") {
            cin >> numero;
            if (invertida) {
                fila.push_back(numero); 
            } else {
                fila.push_front(numero); 
            }
        } 
        else if (comando == "front") {
            if (!fila.empty()) {
                
                if (invertida) {
                    cout << fila.back() << endl; 
                    fila.pop_back();
                    
                } 
                else {
                    cout << fila.front() << endl; 
                    fila.pop_front();
                }
                
            } 
            else {
                cout << "No job for Ada?\n";
            }
        } 
        else if (comando == "back") {
            
            if (!fila.empty()) {
                
                if (invertida) {
                    cout << fila.front() << endl; 
                    fila.pop_front();
                    
                } 
                else {
                    cout << fila.back() << endl; 
                    fila.pop_back();
                }
                
            } else {
                cout << "No job for Ada?\n";
            }
        } 
        else if (comando == "push_back") {
            cin >> numero;
            if (invertida) {
                fila.push_front(numero); 
                
            } 
            else {
                fila.push_back(numero); 
            }
        } 
        else if (comando == "reverse") {
            invertida = !invertida;
        }
    }

    return 0;
}
