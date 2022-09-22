#include <bits/stdc++.h>

int main(){
    int quant=1, num=0, aux;

    while(quant != 0){
        num++; scanf("%d",&quant);

        if(quant==0) break;  

        for(int i=1; i<quant; i++){
            scanf("%d",&aux);
            if(aux == i){
                printf("Teste %d\n%d\n\n",num,i);
                break;
            }                
        }
    }   
}