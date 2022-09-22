package com.mycompany.callcenter;

import java.util.Scanner;

public class CallCenter {

    public static void main(String[] args) {

        SuporteTecnico t = new SuporteTecnico();
        Interpretadora i = new Interpretadora();
        Scanner entrada = new Scanner(System.in);

        String continuar;
        int contador_padrao = 9;

        System.out.println("Bem-vindo ao sistema de Suporte Técnico");

        System.out.print("Digite 'continuar' para continuar ou digite 'sair' para sair do sistema: ");
        continuar = entrada.next();
        System.out.println();

        while (continuar.equals("continuar")) {
            entrada.nextLine();
            if(contador_padrao == 9)
                System.out.print("Descreva seu problema de maneira sucinta: ");

            if(contador_padrao < 9)
                System.out.print("Disserte: ");
            String queixa = entrada.nextLine();

            if(contador_padrao < 9)
                System.out.println();

            if (t.buscaSolucao(i.interpretarQueixa(queixa)) != null) {
                System.out.println(t.buscaSolucao(i.interpretarQueixa(queixa)));
                break;
            } else {
                if(contador_padrao > 0){
                    System.out.println(t.buscaSolucaoPadrao(contador_padrao));
                }
                contador_padrao--;
            }

            i.getPalavrasChave().clear();

            //Enquanto o usuario nao digitar algo que esteja no banco de soluções, até 9 respostas padrão serao geradas.
            //Se as 9 msg forem exibidas, o programa dirá que não conseguiu ajudar, e o programa acaba.

            if(contador_padrao > -1) {
                if (contador_padrao > 0)
                    System.out.print("'Continuar' ou digite 'sair'?: ");

                if (contador_padrao == 0)
                    System.out.print("Ultima tentativa: 'continuar' ou 'sair'?: ");

                continuar = entrada.next();
            }

            if(contador_padrao == -1) {
                System.out.println("Não conseguimos resolver seu problema.");
                break;
            }
        }
    }
}
