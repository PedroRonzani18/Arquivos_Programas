package org.example;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ManArqTexto {
    private String arquivo;
    private Scanner leitor;

    public void abreArquivoLeitura(){
        try {
            leitor = new Scanner(new File(arquivo));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<String> lerArquivo(){
        ArrayList<String> retorno = new ArrayList<>();

        while(leitor.hasNext())
            retorno.add(leitor.nextLine());

        return retorno;
    }

    public void fechaArquivoLeitura(){
        if(leitor != null)
            leitor.close();
    }
}
