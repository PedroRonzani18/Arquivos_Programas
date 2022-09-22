package org.example;

public class Aluno extends Pessoa{
    private int matricula;
    private char curso;

    public Aluno(int matricula, char curso) {
        this.matricula = matricula;
        this.curso = curso;
    }

    public void pagarMensalidade(){
        System.out.println("Pagando");
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public char getCurso() {
        return curso;
    }

    public void setCurso(char curso) {
        this.curso = curso;
    }
}
