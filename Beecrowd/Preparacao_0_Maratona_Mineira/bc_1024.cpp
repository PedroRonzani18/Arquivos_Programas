#include <bits/stdc++.h>

using namespace std;

int main(){
    int quant_testes;
    scanf("%d",&quant_testes);
    getchar();     fflush(stdin);

    for(int i=0; i<quant_testes; i++){
        string linha;
        getline(cin,linha); 

        int size = linha.length(), p=0, c=0;

        if(size%2==1) p=1;

        for(int j=0; j<size; j++){
            if(97 <= linha[j] && linha[j] <= 122 || 65 <= linha[j] && linha[j] <= 89)
                linha[j] += 3;
        }

        char aux;

        for(int j=0, k=size-1; j <= size/2 + p-1 && k>=size/2 + p-1; j++, k--){
            aux = linha[j];
            linha[j] = linha[k];
            linha[k] = aux;
        }

        for(int j=linha.length()/2; j<linha.length(); j++){
            linha[j]--;
        }

        cout << linha << "\n";
        
    }
}