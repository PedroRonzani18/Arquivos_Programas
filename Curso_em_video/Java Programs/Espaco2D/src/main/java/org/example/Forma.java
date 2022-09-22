package org.example;

public abstract class Forma {  //não deixa criar instâncias
    protected Ponto2D[] pontos;

    public Forma(Ponto2D[] pontos) {
        this.pontos = pontos;
    }

    public Ponto2D[] getPontos() {
        return pontos;
    }

    public void setPontos(Ponto2D[] pontos) {
        this.pontos = pontos;
    }

    public abstract double calculaArea();

    public abstract double calculaPerimetro();

    public static Forma geraForma(Ponto2D[] pontos){

        if((pontos.length == 2) && (pontos[0].calculaDistancia(pontos[1]) != 0)){
            Forma retorno = new Circulo(pontos[0].calculaDistancia(pontos[1]));
            retorno.setPontos(pontos);
            return retorno;
        }

        if(pontos.length == 3){
            double lado1 = pontos[0].calculaDistancia(pontos[1]);
            double lado2 = pontos[1].calculaDistancia(pontos[2]);
            double lado3 = pontos[0].calculaDistancia(pontos[2]);

            if(((lado1+lado2) > lado3) && ((lado1 + lado3) > lado2) && ((lado2+lado3) > lado1)) {
                Forma retorno = new Triangulo(lado1, lado2, lado3);
                retorno.setPontos(pontos);
                return retorno;
            }
        }

        if(pontos.length ==4){
            double lado1 = pontos[0].calculaDistancia(pontos[1]);
            double lado2 = pontos[1].calculaDistancia(pontos[2]);
            double lado3 = pontos[2].calculaDistancia(pontos[3]);
            double lado4 = pontos[3].calculaDistancia(pontos[0]);

            if((lado1 == lado2) && (lado2 ==lado3) && (lado3 == lado4)){
                Forma retorno = new Quadrado(lado1);
                retorno.setPontos(pontos);
                return retorno;
            }
        }
        System.out.println("Teste 2");
        return null;
    }
}
