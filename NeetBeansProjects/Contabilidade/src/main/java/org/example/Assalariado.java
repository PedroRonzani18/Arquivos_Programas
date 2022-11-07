package org.example;

public class Assalariado extends Empregado {
    private double horasExtra;

    public Assalariado(String nome, String sobrenome, int numIdent, double horasExtra) {
        super(nome, sobrenome, numIdent);
        this.horasExtra = horasExtra;
    }

    public double getHorasExtra() {
        return horasExtra;
    }
    public void setHorasExtra(double horasExtra) {
        this.horasExtra = horasExtra;
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        return SALARIO + this.horasExtra * HORA;
    }
}
