package org.example;

import java.util.Scanner;

public class Teste {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int quant=2;
        Espaco2D espaco = new Espaco2D();

        for(int j=0; j<3; j++) {

            if(j==0) {
                System.out.println("Digite os pontos do Circulo:");
                quant = 2;
            }
            if(j==1){
                System.out.println("Digite os pontos do triangulo");
                quant = 3;
            }
            if(j==2){
                System.out.println("Digite os pontos do quadrado");
                quant = 4;
            }

            Ponto2D[] auxVetor = new Ponto2D[quant];

            for (int i = 0; i <quant; i++) {
                Ponto2D auxPonto = new Ponto2D();

                System.out.printf("X do ponto %d: ", i + 1);
                auxPonto.setX(entrada.nextInt());

                System.out.printf("Y do ponto %d: ", i + 1);
                auxPonto.setY(entrada.nextInt());

                auxVetor[i] = auxPonto;
            }

            espaco.adicionaForma(espaco.criaForma(auxVetor));
        }

        System.out.println("Tipos de triangulos formados: " + espaco.mostraTipoTriangulos());
        System.out.println("AREA TOTAL: " + espaco.calculaAreaTotal());
        System.out.println("PERÍMETRO TOTAL: " + espaco.calculaPerimetroTotal());
    }
}
