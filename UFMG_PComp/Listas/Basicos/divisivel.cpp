#include <bits/stdc++.h>

using namespace std;

int main(){
    int q; cin >> q;

    while(q--){
        int n1, n2, v=0;
        scanf("%d %d",&n1,&n2);

        if(n1%n2 == 0) cout << 0 << endl;
        else cout << n2-n1 % n2 << endl;
    }
}