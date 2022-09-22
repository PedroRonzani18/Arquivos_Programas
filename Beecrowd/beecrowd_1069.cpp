#include <iostream>S
#include <string>
#include <cmath>

using namespace std;

int main(){
    
    int num;
    cin >> num;

    for(int i=0; i<num; i++){

        string dima;
        
        int menor=0, maior= 0;

        cin >> dima;

        fflush(stdin);

        for(int i=0; i<dima.size(); i++){
            if(dima[i] == '>') 
                menor++;
                
            if(dima[i] == '<')
                maior++;
        }

        cout << min(maior,menor) << "\n";
    }
}