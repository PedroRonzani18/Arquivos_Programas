package com.mycompany.mesa;

public class Carta {
    private int valor;
    private String naipe;
    
    public Carta(){
        this.valor = 0;
        this.naipe = null;
    }
    
    public Carta(int valor, String naipe){
        this.valor = valor;
        this.naipe = naipe;
    }

    public int getValor() {
        return valor;
    }

    public String getNaipe() {
        return naipe;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }

    public void setNaipe(String naipe) {
        this.naipe = naipe;
    }
    
    public int comparaValor(Carta c){
        if(this.valor > c.getValor()) 
                return 1;
        if(this.valor == c.getValor()) 
                return 0;
        if(this.valor < c.getValor()) 
                return -1;
        return 0;
    }
    
    public boolean comparaNaipe(Carta c){
        if(this.naipe.equals(c.getNaipe()))
            return true;
        return false;
    }
}
