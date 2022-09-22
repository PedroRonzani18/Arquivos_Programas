package com.mycompany.callcenter;

import java.util.HashSet;

public class Interpretadora {
    private HashSet<String> palavrasChave;    //para separar as palavras da mensagem em palavras individuais sem rempetição
    
    public Interpretadora(){
        palavrasChave = new HashSet<String>();
    }

    public HashSet<String> getPalavrasChave() {
        return palavrasChave;
    }

    public void setPalavrasChave(HashSet<String> palavrasChave) {
        this.palavrasChave = palavrasChave;
    }    
    
    public HashSet<String> interpretarQueixa(String queixa){ //particiona o problema do usuario
        String[] palavras = queixa.split(" ");
        
        for(String aux: palavras){
            palavrasChave.add(aux.toLowerCase());
        }
        
        return palavrasChave;
    }
}
