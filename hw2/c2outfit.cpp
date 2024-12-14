#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ,counter=0;
    string comando, roupa;
    deque <string> bagunca;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> comando;
        if(comando == "put"){
            cin >> roupa;
            if(roupa == "snowcoat"){ 
                counter++;
                bagunca.push_back(roupa);
            }
            else{
                bagunca.push_front(roupa);
            }
        }
        
        else if(comando == "iditarod"){
            if(!bagunca.empty()&& counter > 0){
                if (bagunca.back() == "snowcoat"){
                    counter--;
                }
                bagunca.pop_back();
                cout << "winner winner chicken dinner :)" << endl;    
            }
                else{
                    cout << "oopsimcold :(" << endl;
                }
            
            
        }
        else if (comando == "get"){
            if(!bagunca.empty()){
                cout << bagunca.front() << endl;
                if(bagunca.front() == "snowcoat"){
                    counter--;
                }
                bagunca.pop_front();
            }
            else{
                cout << "empty" << endl;
            }
        }
    }


    return 0;
}