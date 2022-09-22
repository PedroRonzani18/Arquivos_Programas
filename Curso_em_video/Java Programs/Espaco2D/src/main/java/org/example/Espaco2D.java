package org.example;

import java.util.ArrayList;

public class Espaco2D {
    private ArrayList<Forma> formas = new ArrayList<>();

    public ArrayList<Forma> getFormas() {
        return formas;
    }

    public void setFormas(ArrayList<Forma> formas) {
        this.formas = formas;
    }

    public Forma criaForma(Ponto2D[] pontos){
        if(pontos.length == 2){
            double raio = pontos[0].calculaDistancia(pontos[1]);

            Circulo c = new Circulo(raio);
            return c;
        }

        if(pontos.length == 3){
            double lado1 = pontos[0].calculaDistancia(pontos[1]);
            double lado2 = pontos[1].calculaDistancia(pontos[2]);
            double lado3 = pontos[2].calculaDistancia(pontos[0]);

            Triangulo t = new Triangulo(lado1, lado2, lado3);
            return t;
        }

        if(pontos.length == 4){
            double lado = pontos[0].calculaDistancia(pontos[1]);

            Quadrado q = new Quadrado(lado);
            return q;
        }
        return null;
    }

    public void adicionaForma(Forma forma){
        formas.add(forma);
    }

    public double calculaAreaTotal(){
        double areas=0;

        for(Forma i: formas){
            areas += i.calculaArea();
        }

        return areas;
    }

    public double calculaPerimetroTotal(){
        double perimetro = 0;

        for(Forma i: formas){
            perimetro += i.calculaPerimetro();
        }

        return perimetro;
    }



    public String mostraTipoTriangulos(){
        String frase = "";

        for (Forma aux : formas) {
            if (aux instanceof Triangulo) {
                frase = ((Triangulo) aux).tipoTriangulo();
            }
        }
        return frase;
    }
}
