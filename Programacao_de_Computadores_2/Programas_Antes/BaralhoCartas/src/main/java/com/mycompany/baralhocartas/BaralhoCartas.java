package com.mycompany.baralhocartas;

import java.util.Scanner;

public class BaralhoCartas  {

    public static void main(String[] args) {
        
        Scanner entrada = new Scanner(System.in);
        
        int q_carta_mao, vencimento=0;
        
        Baralho b = new Baralho();
        Jogador j1 = new Jogador();
        Jogador j2 = new Jogador();
        Carta c1 = new Carta();
        Carta c2 = new Carta();
        
        System.out.println("Mesa embaralhando..........");
        b.embaralhar();
        
        System.out.print("Numero de cartas por jogador: ");
        q_carta_mao = entrada.nextInt();
        
        if(q_carta_mao == 1) 
            System.out.println("Mesa distribui a carta para os jogadores A e B");
        else 
            System.out.println("Mesa distribui as " + q_carta_mao + " cartas para os jogadores A e B");
        
        j1.setMao(b.distribuirCartas(q_carta_mao));
        j2.setMao(b.distribuirCartas(q_carta_mao));
        
        c1 = j1.jogar(q_carta_mao); 
        c2 = j2.jogar(q_carta_mao);
        
        System.out.println("Jogador A: "+ c1.getValor() + " de " + c1.getNaipe());
        System.out.println("Jogador B: "+ c2.getValor() + " de " + c2.getNaipe());
        
        if(c1.comparaValor(c2)==1)
                System.out.println("Jogador A ganha");
        if(c1.comparaValor(c2)==-1)
                System.out.println("Jogador B ganha");
        
        if(c1.comparaValor(c2)==0){                     //se tiver mesmo valor, ouro ganha
            if(c1.getNaipe().equals("Ouros") && vencimento == 0){
                vencimento = 1;
                System.out.println("Jogador A ganha");
            }
                
            if(c1.getNaipe().equals("Ouros") && vencimento == 0){
                vencimento = 1;
                System.out.println("Jogador B ganha");
            }
                
            if(vencimento == 0){
                System.out.println("Empate!");
            }    
        }
    }
}
