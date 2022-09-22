#include <bits/stdc++.h>

using namespace std;

int main(){
    string joia;
    set<string> v;

    while(cin >> joia)
        v.insert(joia);

    cout << v.size() << endl;
}