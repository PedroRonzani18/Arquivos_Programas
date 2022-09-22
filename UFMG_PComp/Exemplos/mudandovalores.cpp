#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n), ordv(n);

    for(int i=0; i<n; i++) {cin >> v[i]; ordv[i] = v[i];} //recebe valores

    sort(ordv.begin(), ordv.end()); // ordena valores

    map<int,int> novoidx;

    for(int i=0; i<n; i++) novoidx[ordv[i]] = i; 

    for(int i=0; i<n; i++) v[i] = novoidx[v[i]];

    for(int i=0; i<n; i++) cout << v[i] << " ";
    cout << endl;
}