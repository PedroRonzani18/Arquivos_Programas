package org.example;

public class Titulo extends Conta {

    public Titulo(int dia, int mes, int valor){
        super(dia,mes,valor);
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        if(diaPagto > this.dia && mesPagto >= this.mes)
            return this.valor * 1.1;
        else return this.valor;
    }


}
