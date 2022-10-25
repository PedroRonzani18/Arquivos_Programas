package com.mycompany.jogodavelha;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JToggleButton;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JSeparator;

public class JanelaPrincipal extends JFrame{
    
    private JTextField [][] tabuleiro;
    
    private JToggleButton botaoX, botao0;
    private JButton botaoLimpar;
    public JButton botaoSair;
    
    private JLabel labelInstrucoes;
    
    private JSeparator separator1;
    
    private JPanel centro1, norte1, ladoCentro, ladoNorte, ladoSul;

    public JanelaPrincipal()
    {
        super("Jogo da Velha");
        setLayout(new BorderLayout());
        instanciaComponentes();
        adicionaComponentes();
    } 
    
    private void instanciaComponentes()
    {
        norte1 = new JPanel();
        norte1.setLayout(new GridLayout(2, 1));
        
        separator1 = new JSeparator();
        labelInstrucoes = new JLabel("Escolha sua peça e clique na posição desejada");
        
        centro1 = new JPanel();
	centro1.setLayout(new BorderLayout());
        
        ladoNorte = new JPanel();
	ladoNorte.setLayout(new GridLayout(1,2));
        
        botaoX = new JToggleButton("X");
        botao0 = new JToggleButton("0");
        
        ladoCentro = new JPanel();
	ladoCentro.setLayout(new GridLayout(3,3));
        
        tabuleiro = new JTextField[3][3];
        
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j++)
                tabuleiro[i][j] = new JTextField();
          
        ladoSul = new JPanel();
        ladoSul.setLayout(new GridLayout(1,2));
        
        botaoLimpar = new JButton("Limpar");
        botaoSair = new JButton("Sair");
    }
    
    private void adicionaComponentes()
    {    
        add(norte1, BorderLayout.NORTH);
        add(centro1, BorderLayout.CENTER);
        
        norte1.add(labelInstrucoes);
        norte1.add(separator1);
        
        centro1.add(ladoNorte, BorderLayout.NORTH);
        
        ladoNorte.add(botaoX);
        ladoNorte.add(botao0);
        
        centro1.add(ladoCentro, BorderLayout.CENTER);
        
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j++)
                ladoCentro.add(tabuleiro[i][j]);
        
        centro1.add(ladoSul, BorderLayout.SOUTH);
        
        ladoSul.add(botaoLimpar);
        ladoSul.add(botaoSair);
        
    }
}
