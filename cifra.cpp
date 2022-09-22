#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, incremento = 1;
    string c;

    cin >> c;
    cin >> n;

    int v[n];

    for(int i=0; i<n; i++) v[i] = 0;

    char mat[n][c.size()];

    for(int i=0, j=0; j<c.size(); j++){
        mat[i][j] = ' ';
        //cout << "i: " << i << endl;
        //getchar();
        if(i != c.size() -1)
            v[i+1]++;
        
        i+= incremento;
        if(i == n-1 || i== 0)
            incremento = -incremento;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=i-1; j>=1; j--){
            v[i] += v[j];
        }
    }

    for(int i=0, j=0; j<c.size(); j++){
        cout << c[v[i]];
        v[i]++;
        i+= incremento;
        if(i == n-1 | i== 0)
            incremento = -incremento;
    }   
    cout << endl;
}