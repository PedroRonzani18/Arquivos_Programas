package com.mycompany.jogodavelha;

import java.util.ArrayList;

public class JogoDaVelha {
    private int [][] tabuleiro;
    private int vencedor;

    public JogoDaVelha() {
        tabuleiro = new int[3][3];
    }
    
    public boolean fazJogada(int linha, int coluna, int jogador) // realiza 1 jogada
    {
        if(!(jogador == 1 || jogador == 2)) return false;
        if(tabuleiro[linha][coluna] != 0) return false; 
        
        tabuleiro[linha][coluna] = jogador;
        
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                System.out.print("[" + tabuleiro[i][j] + "]");
            }
            System.out.println();
        }        
        System.out.println();
        return true;
    }
    
    public int verificaVencedor()
    {
        ArrayList<Integer> jogadas1 = new ArrayList<>();
        ArrayList<Integer> jogadas2 = new ArrayList<>();
        
        //Analisa Diagonal 1
        for(int i=0, j=0; i<3; i++, j++)
        {
            if(tabuleiro[i][j] == 1)jogadas1.add(1);
            if(tabuleiro[i][j] == 2)jogadas2.add(1);
        }
        
        if(jogadas1.size() == 3) return 1;
        if(jogadas2.size() == 3) return 2;
        
        jogadas1.clear();
        jogadas2.clear();
        
        //Analisa Diagonal 2
        for(int i=2, j=0; j<3; i--, j++)
        {
            if(tabuleiro[i][j] == 1)jogadas1.add(1);
            if(tabuleiro[i][j] == 2)jogadas2.add(1);
        }
        
        if(jogadas1.size() == 3) return 1;
        if(jogadas2.size() == 3) return 2;
        
        jogadas1.clear();
        jogadas2.clear();
        
        //Analisa Linhas
        for(int i=0; i<3; i++)
        {
            if((tabuleiro[i][0] == tabuleiro[i][1]) && (tabuleiro[i][1] == tabuleiro[i][2]))
            {
                if(tabuleiro[i][1] == 1)return 1;
                if(tabuleiro[i][1] == 2)return 2;
            }
        }
        
        //Analisa Colunas
        for(int j=0; j<3; j++)
        {
            if((tabuleiro[0][j] == tabuleiro[1][j]) && (tabuleiro[1][j] == tabuleiro[2][j]))
            {
                if(tabuleiro[1][j] == 1)return 1;
                if(tabuleiro[1][j] == 2)return 2;
            }
        }
        
        
        
        return 0;
    }
}
