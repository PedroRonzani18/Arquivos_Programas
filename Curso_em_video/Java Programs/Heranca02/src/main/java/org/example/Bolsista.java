package org.example;

public class Bolsista extends Aluno{
    private int bolsa;

    public Bolsista(int matricula, char curso) {
        super(matricula, curso);
    }

    public void renovarBolsa(){}

    @Override
    public void pagarMensalidade(){}
}
