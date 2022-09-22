package org.example;

public class Funcionario extends Pessoa{
    private char setor;
    private boolean trabalhando;

    public Funcionario(){}

    public Funcionario(char setor, boolean trabalhando) {
        this.setor = setor;
        this.trabalhando = trabalhando;
    }

    public Funcionario(String nome, int idade, char sexo, char setor, boolean trabalhando) {
        super(nome, idade, sexo);
        this.setor = setor;
        this.trabalhando = trabalhando;
    }

    public char getSetor() {
        return setor;
    }

    public void setSetor(char setor) {
        this.setor = setor;
    }

    public boolean isTrabalhando() {
        return trabalhando;
    }

    public void setTrabalhando(boolean trabalhando) {
        this.trabalhando = trabalhando;
    }

    public void mudarTrabalho(char setor){
        this.setor = setor;
    }
}
