#include <bits/stdc++.h>

using namespace std;

int main(){
    int quant;
    scanf("%d",&quant);
    getchar(); fflush(stdin);

    while(quant--){
        string linha;
        getline(cin, linha);
        int v[26];

        for(int i=0; i<26; i++) v[i] = 0;
        int maior=-1;

        for(int i=0; i<linha.length(); i++){
            linha[i] = tolower(linha[i]);
            v[linha[i]-97]++;
        }

        for(int i=0; i<26; i++){
            if(v[i] > maior)
                maior = v[i];
        }

        for(int i=0; i<26; i++){
            if(v[i] == maior)
                printf("%c",i+97);
        }
        printf("\n");
        
    }
}