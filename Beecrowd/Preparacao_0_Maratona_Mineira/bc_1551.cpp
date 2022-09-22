#include <bits/stdc++.h>

using namespace std;

int main(){
    int q; scanf("%d",&q);
    getchar();


    while(q--){
        int letras[26];
        int freq [26], aux = 'a';

        string frase;
        getline(cin,frase);
        getchar(); fflush(stdin);

        for(int i=0; i<26; i++) {
            freq[i] = 0;
            letras[i] = aux;
            aux++;
        }

        for(int i=0; i<frase.size(); i++){
            for(int j=0; j<26; j++){
                if(frase[i] == letras[j]){
                    freq[j]++;
                    break;

            printf("%d ",freq[i]);
                }
            }
        }

        int zeros = 0;

        for(int i=0; i<26; i++){
            printf("%d ",freq[i]);
            if(freq[i] == 0)
                zeros++;
        }

        if(zeros == 0) printf("\nfrase completa\n");
        if(0<zeros && zeros <=13) printf("\nfrase quase completa\n");
        if(13 < zeros) printf("\nfrase completa\n");
    }        
       
}