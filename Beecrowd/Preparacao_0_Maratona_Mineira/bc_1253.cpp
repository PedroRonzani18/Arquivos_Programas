#include <bits/stdc++.h>

using namespace std;

int main(){
    int quant;
    scanf("%d",&quant);
    getchar(); fflush(stdin);

    while(quant--){
        string linha;
        int pula=0;

        getline(cin,linha);
        scanf("%d",&pula);
        getchar(); fflush(stdin);

        for(int i=0; i<linha.length(); i++){
            for(int j=0; j<pula; j++){
                if(linha[i] == 'A')
                    linha[i] = 'Z';             
                else linha[i]--;
            }
        }
        cout << linha << "\n";
    }
}