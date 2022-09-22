#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n';

int main(){
    int m=1, n=1, a, b;

    while(1){
    
        cin >> m >> n;
        if(m==0 && n==0)break;

        string s;
        vector<string> v;

        for(int i=0; i<m; i++){ 
            cin >> s;
            v.push_back(s);
        }
        
        cin >> a >> b;

        for(int i=0; i<m; i++){
            for(int y=0; y<a/m; y++){
                for(int j=0; j<n; j++){
                    for(int x=0; x < b/n; x++){
                        cout << v[i][j];
                    }
                }
                cout << endl;
            }                
        }
    }
}