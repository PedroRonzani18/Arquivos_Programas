package com.mycompany.jogodavelha;

import java.util.Random;

public class Teste {
    public static void main(String[] args) {
        JogoDaVelha jogo = new JogoDaVelha();
        Random rand = new Random();
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                jogo.fazJogada(i, j, 1 + rand.nextInt(2));
                
                switch(jogo.verificaVencedor())
                {
                    case 1:
                        System.out.println("Jogador 1 vence");
                        System.exit(0);
                    case 2:
                        System.out.println("Jogador 2 vence");
                        System.exit(0);
                }   
            }
        }
        
        switch(jogo.verificaVencedor())
        {
            case 1:
                System.out.println("Jogador 1 vence");
                System.exit(0);
            case 2:
                System.out.println("Jogador 2 vence");
                System.exit(0);
            case 0:
                System.out.println("Velha!");
                System.exit(0);
        }     
        
        
        JanelaPrincipal j = new JanelaPrincipal();
	j.setSize(500,300);
	j.setVisible(true);
    }
    
}
