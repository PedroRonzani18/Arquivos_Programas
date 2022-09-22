package com.mycompany.lojabike;

public class Produto {
    private String modelo;
    private String marca;
    private String numSerie;
    private float preco;

    public String getModelo() {
        return modelo;
    }

    public String getMarca() {
        return marca;
    }

    public String getNumSerie() {
        return numSerie;
    }

    public float getPreco() {
        return preco;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setNumSerie(String numero) {
        numSerie = numero;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }
    
    
}
