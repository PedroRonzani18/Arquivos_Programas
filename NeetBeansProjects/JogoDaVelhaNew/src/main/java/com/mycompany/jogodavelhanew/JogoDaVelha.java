package com.mycompany.jogodavelhanew;

import java.util.ArrayList;

public class JogoDaVelha {
    private int [][]tabuleiro = new int[3][3];
    private int vencedor;
    
    public void jogar(int i, int j, int jogada) 
    {
        if(tabuleiro[i][j] == 0)
            tabuleiro[i][j] = jogada;
        
        for(int x = 0; x<3; x++)
        {
            for(int y = 0; y<3; y++)
            {
                System.out.print("[" + tabuleiro[x][y] + "]");
            }
            System.out.println();
        }  
        System.out.println();
    }
    
    public void limparTela()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                tabuleiro[i][j] = 0;
            }
        }
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
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(tabuleiro[i][j] == 0) return 0;
            }
        }
        
        return 3;
    }
}
