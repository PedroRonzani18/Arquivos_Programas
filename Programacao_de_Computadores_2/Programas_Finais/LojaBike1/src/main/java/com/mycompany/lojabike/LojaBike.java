package com.mycompany.lojabike;

import java.util.Scanner;

public class LojaBike {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.println("Bem vindo á Loja!!");
        
        Produto p = new Produto();
        
        p.setModelo("Cross");
        p.setMarca("Caloi");
        p.setNumSerie("ABC123");
        p.setPreco(200);
        
        Produto p2 = new Produto();
        
        System.out.print("Modelo: ");
        p2.setModelo(entrada.next());
        
        System.out.print("Marca: ");
        p2.setMarca(entrada.next());
        
        System.out.print("Numero de serie: ");
        p2.setNumSerie(entrada.next());
        
        System.out.print("Preco: ");
        p2.setPreco(entrada.nextFloat());
        
        System.out.println("Produtos da loja: ");
        
        System.out.println(p.getModelo());
        System.out.println(p.getMarca());
        System.out.println(p.getNumSerie());
        System.out.println(p.getPreco());
        
        System.out.println(p2.getModelo());
        System.out.println(p2.getMarca());
        System.out.println(p2.getNumSerie());
        System.out.println(p2.getPreco());
    }
}
