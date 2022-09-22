package com.mycompany.baralhocartas;

public class Jogador {
    private Carta[] mao;
    
    public Jogador(){
        this.mao = null;        
    }

    public Carta[] getMão() {
        return mao;
    }

    public void setMao(Carta[] mao) {
        this.mao = mao;
    }    
    
    public Carta jogar(int quant){
        Carta aux = new Carta();
        aux.setValor(-1);
        
        for(int i=0; i< mao.length; i++){
            if(this.mao[i].getValor() > aux.getValor()){
                aux.setValor(mao[i].getValor());
                aux.setNaipe(mao[i].getNaipe());
            }
        }
        return aux;
    }
}
