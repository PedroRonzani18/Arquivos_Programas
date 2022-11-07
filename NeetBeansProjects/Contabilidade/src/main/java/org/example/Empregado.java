package org.example;

public class Empregado implements Passivo{
    protected String nome;
    protected String sobrenome;
    protected int numIdent;

    public Empregado(String nome, String sobrenome, int numIdent) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.numIdent = numIdent;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }
    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public int getNumIdent() {
        return numIdent;
    }
    public void setNumIdent(int numIdent) {
        this.numIdent = numIdent;
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        return 0;
    }
}
