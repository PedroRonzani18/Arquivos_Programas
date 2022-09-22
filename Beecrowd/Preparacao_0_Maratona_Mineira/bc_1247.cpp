#include <bits/stdc++.h>

using namespace std;

int main(){
    int d, vf, vg;

    for(int x=0 ;scanf("%d %d %d",&d,&vf,&vg) != EOF; ){
        
        x = (d * vf) / sqrt(pow(vg,2)-pow(vf,2));

        if(0<=x && x<=12)
            cout << "S" << "\n";
        else
            cout << "N" << "\n";        
    }
}