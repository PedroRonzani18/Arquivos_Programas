package com.mycompany.lojabike;

import java.util.Scanner;

public class LojaBike {

    public static void main(String[] args) {
        
        System.out.println("Bem vindo à minha loja!!");
        
        Produto p1 = new Produto();
        
        p1.setModelo("Cross");
        p1.setMarca("Caloi");
        p1.setNumSerie("1234");
        p1.setPreco(200);
        
        Produto p2 = new Produto();
        
        Scanner entrada = new Scanner(System.in);
        
        System.out.print("Modelo: ");
        p2.setModelo(entrada.next());
        
        System.out.print("Marca: ");
        p2.setMarca(entrada.next());
        
        System.out.print("NumSerie: ");
        p2.setNumSerie(entrada.next());
        
        System.out.print("Preco: ");
        p2.setPreco(entrada.nextFloat());
        
        System.out.println("Esses são so produtos da loja: \n");
        
        System.out.println("Produto 1");
        
        System.out.println(p1.getModelo());
        System.out.println(p1.getMarca());
        System.out.println(p1.getNumSerie());
        System.out.println(p1.getPreco());
        
        System.out.println("\nProduto 2\n");
        
        System.out.println(p2.getModelo());
        System.out.println(p2.getMarca());
        System.out.println(p2.getNumSerie());
        System.out.println(p2.getPreco());      
        
        
    }
}
