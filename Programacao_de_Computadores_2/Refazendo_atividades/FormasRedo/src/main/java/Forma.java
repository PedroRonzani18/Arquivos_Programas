public abstract class Forma {
    private Ponto[] pontos;

    public Ponto[] getPontos() {
        return pontos;
    }

    public void setPontos(Ponto[] pontos) {
        this.pontos = pontos;
    }

    public static Forma geraForma(Ponto[] pontos){
        Forma retorno = null;

        if(pontos.length == 2){
            float raio = pontos[0].calculaDistancia(pontos[1]);

            if(raio != 0) {
                retorno = new Circulo(raio);
                retorno.setPontos(pontos);
            }
        }

        if(pontos.length == 3){
            float lado1 = pontos[0].calculaDistancia(pontos[1]);
            float lado2 = pontos[1].calculaDistancia(pontos[2]);
            float lado3 = pontos[2].calculaDistancia(pontos[0]);

            if(lado1 < lado2 + lado3){
                retorno = new Triangulo(lado1,lado2,lado3);
                retorno.setPontos(pontos);
            }
        }

        if(pontos.length == 4){
            float lado1 = pontos[0].calculaDistancia(pontos[1]);
            float lado2 = pontos[1].calculaDistancia(pontos[2]);
            float lado3 = pontos[2].calculaDistancia(pontos[3]);
            float lado4 = pontos[3].calculaDistancia(pontos[0]);

            if((lado1 == lado2) && (lado2 == lado3) && (lado3 == lado4)){
                retorno = new Quadrado(lado1);
                retorno.setPontos(pontos);
            }
        }

        return retorno;
    }

    public abstract float calculaArea();

    public abstract float calculaPerimetro();
}
