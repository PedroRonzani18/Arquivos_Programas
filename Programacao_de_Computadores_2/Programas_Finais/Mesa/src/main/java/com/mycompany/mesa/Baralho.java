package com.mycompany.mesa;

import java.security.SecureRandom;

public class Baralho {
    private Carta[] baralho;
    private String[] naipe = {"Copas","Ouros","Paus","Espadas"};
    private SecureRandom gerador = new SecureRandom();

    public Carta[] getBaralho() {
        return baralho;
    }

    public String[] getNaipe() {
        return naipe;
    }

    public void setBaralho(Carta[] baralho) {
        this.baralho = baralho;
    }

    public void setNaipe(String[] naipe) {
        this.naipe = naipe;
    }
    
    public Baralho(){   
        baralho = new Carta[52];
        int posicao = 0;        
        for(int j=0; j<naipe.length; j++){
            for(int i=1; i<13; i++){
                baralho[posicao] = new Carta(i,naipe[j]);
                posicao++;
            }
        }      
    }
    
    public void embaralhar(){
        int posicao;
        Carta aux;
        
        for(int i=0; i<baralho.length; i++){
             posicao = gerador.nextInt(52);
             
             aux = baralho[posicao];          
             baralho[posicao] = baralho[i];
             baralho[i] = aux;
        }
        
    }
    
    public Carta[] distribuirCartas(int quantidade){ 
        Carta[] retorno = new Carta[quantidade];
        int posicao = 0;
        
        for(int i=0; i < this.baralho.length; i++){
            
            if(baralho[i] != null){
                retorno[posicao] = baralho[i];
                baralho[i] = null;
                posicao++;
            }

            if(posicao >= quantidade){
                return retorno;
            }
        }
        return null;
    }
}
