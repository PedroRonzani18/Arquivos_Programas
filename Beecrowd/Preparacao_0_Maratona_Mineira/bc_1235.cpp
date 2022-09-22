#include <bits/stdc++.h>

using namespace std;

int main(){
    int quant;
    scanf("%d",&quant);
    getchar();     fflush(stdin);

    for(int i=0; i<quant; i++){
        string line;
        getline(cin,line);

        int size = line.length();

        for(int i=size/2 -1; i>=0; i--){
            cout << line[i];
        }

        for(int i = size-1; i>=size/2 ; i--)
            cout << line[i];
        cout << "\n";
    }
}