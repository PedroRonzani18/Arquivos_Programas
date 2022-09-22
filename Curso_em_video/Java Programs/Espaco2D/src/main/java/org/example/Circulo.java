package org.example;

public class Circulo extends Forma {
    private double raio;

    public Circulo(double raio){
        super();
        this.raio = raio;
    }

    @Override
    public double calculaArea() {
        return Math.PI * Math.pow(raio,2);
    }

    @Override
    public double calculaPerimetro() {
        return 0;
    }
}
