#include <bits/stdc++.h>

using namespace std;

int main(){
    int n_teste;
    int stack = 0, diamonds=0;
    char* input = (char*) malloc(sizeof(char)*1001);
    cin >> n_teste;

    for(int i=0; i<n_teste; i++){
        diamonds = 0;
        stack=0;
        cin >> input;

        for(int j=0; input[j] != '\0'; j++){
            if(input[j] == '<')
                stack++;
            if(input[j] == '>' && stack > 0){
                stack--;
                diamonds++;
            }
        }
        printf("%d\n",diamonds);
    }
    return 0;
}
