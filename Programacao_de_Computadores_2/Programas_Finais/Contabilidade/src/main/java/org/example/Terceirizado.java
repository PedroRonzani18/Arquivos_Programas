package org.example;

public class Terceirizado extends Empregado {
    private double horasTrabalhadas;

    public Terceirizado(String nome, String sobrenome, int numIdent) {
        super(nome, sobrenome, numIdent);
    }

    public double getHorasTrabalhadas() {
        return horasTrabalhadas;
    }
    public void setHorasTrabalhadas(double horasTrabalhadas) {
        this.horasTrabalhadas = horasTrabalhadas;
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        return this.horasTrabalhadas * HORA;
    }
}
