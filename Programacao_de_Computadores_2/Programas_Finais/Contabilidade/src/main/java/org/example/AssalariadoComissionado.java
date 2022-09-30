package org.example;

public class AssalariadoComissionado extends Comissionado{
    private double percentualBonus;

    public AssalariadoComissionado(String nome, String sobrenome, int numIdent, double percentualBonus) {
        super(nome, sobrenome, numIdent);
        this.percentualBonus = percentualBonus;
    }

    public double getPercentualBonus() {
        return percentualBonus;
    }
    public void setPercentualBonus(double percentualBonus) {
        this.percentualBonus = percentualBonus;
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        return SALARIO * 1.1 + super.getValorVendas() * 0.06;
    }
}