package org.example;

import java.util.HashSet;

public class Interpretador {
    private HashSet<String> palavrasChave;

    public Interpretador() {
        palavrasChave = new HashSet<>();
    }

    public HashSet<String> getPalavrasChave() {
        return palavrasChave;
    }

    public void setPalavrasChave(HashSet<String> palavrasChave) {
        this.palavrasChave = palavrasChave;
    }

    public HashSet<String> interpretaQueixa(String queixa){
        String[] palavras = queixa.split(" ");

        for(String aux: palavras)
            palavrasChave.add(aux.toLowerCase());

        return palavrasChave;
    }
}
