package com.mycompany.zoologico;

import java.util.Scanner;

public class Zoologico {

    public static void main(String[] args) {
        
        Scanner entrada = new Scanner(System.in);
        
        Animal[] animais = new Animal[5];
        
        for(int i=1; i<=2; i++){
            
            Animal aux = new Animal();
            
            System.out.println("Animal " + i);
            
            System.out.print("Nome: ");
                aux.setNome(entrada.next());
                
            System.out.print("Sexo: ");
                aux.setSexo(entrada.next());
                
            System.out.print("Idade: ");
                aux.setIdade(entrada.nextInt());
                
            System.out.print("Especie: ");
                aux.setEspecie(entrada.next());
                
            System.out.print("Local de Origem: ");
                aux.setLocalOrigem(entrada.next());
                
            System.out.print("Cor: ");
                aux.setCor(entrada.next());
                
            System.out.print("\n");
                
            animais[i-1] = aux;
        }
        
        System.out.println("EXIBINDO ANIMAIS\n");
        
        for(int j=0; j<2; j++){
            System.out.printf("Animal %d\n",j+1);
            
            System.out.print("Nome: ");
            System.out.println(animais[j].getNome());
            
            System.out.print("Sexo: ");
            System.out.println(animais[j].getSexo());
            
            System.out.print("Idade: ");
            System.out.println(animais[j].getIdade());
            
            System.out.print("Especie: ");
            System.out.println(animais[j].getEspecie());
            
            System.out.print("Local de Origem: ");
            System.out.println(animais[j].getLocalOrigem());
            
            System.out.print("Cor: ");
            System.out.println(animais[j].getCor());
            System.out.print("\n");
            
        }
    }
}
