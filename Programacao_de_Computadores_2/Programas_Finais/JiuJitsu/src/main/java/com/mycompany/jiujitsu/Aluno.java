package com.mycompany.jiujitsu;

public class Aluno {
    private String nome;
    private String sexo;
    private int idade;  
    private double peso;
    private double altura;
    private String telContato;
    
    public Aluno(){
        nome = " ";
        sexo = " ";
        idade = 0;
        peso = 0;
        altura = 0;
        telContato = " ";
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public void setTelContato(String telContato) {
        this.telContato = telContato;
    }

    public String getNome() {
        return nome;
    }

    public String getSexo() {
        return sexo;
    }

    public int getIdade() {
        return idade;
    }

    public double getPeso() {
        return peso;
    }

    public double getAltura() {
        return altura;
    }

    public String getTelContato() {
        return telContato;
    }
    
}
