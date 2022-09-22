#include <bits/stdc++.h>

using namespace std;

int main(){

    int p;
    char linha[60];
    int quant, numr;

    while(scanf("%s\n",linha) != EOF && scanf("%d",&p) != EOF)
    {
        quant=0;
        numr=0;

        for(int i=0; linha[i] != '\0'; i++){   //escaneia a sring toda
            //cout << linha[i] << " " << numr << " " << quant << endl; 

            if(linha[i] == 'W')
                quant++;

            if(linha[i] == 'R')
            {
                numr++;
                if(numr%p == 1)
                    quant++;
            }

           // cout << linha[i] << " " << numr << " " << quant << endl << endl; 
            
            /*if(linha[i] =='R' && numr == 0){
                numr++;
                cout << "teste1" << endl;
                quant++;
            }else{
            
            if(linha[i] == 'R' && numr > 0){
                numr++;
                cout << "teste2" << endl;
            }}
            
            if(numr == p){
                numr=0;
            }  */        
        }
        cout <<quant << "\n";   
    }
    
}