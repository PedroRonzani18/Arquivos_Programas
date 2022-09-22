package com.mycompany.zoologico;

public class Animal {
    private String nome;
    private String sexo;
    private int idade;
    private String especie;
    private String localOrigem;
    private String cor;
    
    public Animal(){
        this.nome = " ";
        this.sexo = " ";
        this.idade = 0;
        this.especie = " ";
        this.localOrigem = " ";
        this.cor = " ";        
    }
    
    public Animal(String nome, String sexo, int idade, String especie, String localOrigem, String cor){
        this.nome = nome;
        this.sexo = sexo;
        this.idade = idade;
        this.especie = especie;
        this.localOrigem = localOrigem;
        this.cor = cor;        
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

    public String getEspecie() {
        return especie;
    }

    public String getLocalOrigem() {
        return localOrigem;
    }

    public String getCor() {
        return cor;
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

    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public void setLocalOrigem(String localOrigem) {
        this.localOrigem = localOrigem;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }
    
    
}
