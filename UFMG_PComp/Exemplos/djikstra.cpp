#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<string>v;
    string joia;

    while(cin >> joia){
        
        int encontro = 0;

        for(int i=0; i<v.size(); i++){
            if(v[i] == joia) 
                encontro = 1;            
        }

        if(encontro == 0)
            v.push_back(joia);
    }

    cout << v.size() << endl;
}