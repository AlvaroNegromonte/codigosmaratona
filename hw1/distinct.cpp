#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long int number;

    cin >> n;

    set <int> conjunto;

    for(int i=0; i<n; i++){
        cin >> number;
        conjunto.insert(number);
    }

    cout << conjunto.size();



    return 0;
}
