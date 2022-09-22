package org.example;

public class Professor extends Pessoa {
    private char especialidade;
    private float salario;

    public Professor(){}

    public Professor(char especialidade, float salario) {
        this.especialidade = especialidade;
        this.salario = salario;
    }

    public Professor(String nome, int idade, char sexo, char especialidade, float salario) {
        super(nome, idade, sexo);
        this.especialidade = especialidade;
        this.salario = salario;
    }

    public char getEspecialidade() {
        return especialidade;
    }

    public void setEspecialidade(char especialidade) {
        this.especialidade = especialidade;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public void receberAumento(float aumento){
        this.salario += aumento;
    }

}
