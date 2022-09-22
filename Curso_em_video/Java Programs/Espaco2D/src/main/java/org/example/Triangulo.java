package org.example;

public class Triangulo extends Forma {
    private double lado1;
    private double lado2;
    private double lado3;

    public Triangulo (double lado1, double lado2, double lado3){
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    @Override
    public double calculaArea() {
        double p = (lado1 + lado2 + lado3)/2;
        return Math.sqrt(p * (p-lado1) * (p-lado2) * (p-lado3));
    }

    @Override
    public double calculaPerimetro() {
        return lado1 + lado2 + lado3;
    }

    public String tipoTriangulo(){

        if((lado1 == lado2) && (lado2 == lado3))
            return "Equilátero";

        if((lado1 == lado2) && (lado2 != lado3))
            return "Isosceles";

        if((lado1 == lado3) && (lado3 != lado2))
            return "Isosceles";

        if((lado2 == lado3) && (lado3 != lado1))
            return "Isoscceles";

        if((lado1 != lado2) && (lado2 != lado3))
            return "Escaleno";

        return null;
    }
}
