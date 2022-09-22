package org.example;

import java.util.Scanner;

public class Academia {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        Turma[] turmas = new Turma[6];
        Aluno aux = new Aluno();

        turmas[0].setDescricao("Manha feminino");
        turmas[0].setDescricao("Tarde feminino");
        turmas[0].setDescricao("Noite feminino");
        turmas[0].setDescricao("Manha Masculino");
        turmas[0].setDescricao("Tarde Masculino");
        turmas[0].setDescricao("Noite Mascculino");

        for(int i=0; i<10; i++){

            System.out.print("Nome: ");
            aux.setNome(entrada.next());

            System.out.print("Sexo: ");
            aux.setSexo(entrada.next());

            System.out.print("Idade: ");
            aux.setIdade(entrada.nextInt());

            System.out.print("Peso: ");
            aux.setPeso(entrada.nextDouble());

            System.out.print("Altura: ");
            aux.setAltura(entrada.nextDouble());

            System.out.print("Telefone de Contato: ");
            aux.setNome(entrada.next());
        }

        if(aux.getSexo().equals("M")){
            if(9 <= aux.getIdade() && aux.getIdade() <=12)
                turmas[3].adicionarAluno(aux);

            if(13 <= aux.getIdade() && aux.getIdade() <=18)
                turmas[4].adicionarAluno(aux);

            if(19 <= aux.getIdade() && aux.getIdade() <=30)
                turmas[5].adicionarAluno(aux);
        }

        if(aux.getSexo().equals("F")){
            if(9 <= aux.getIdade() && aux.getIdade() <=12)
                turmas[3].adicionarAluno(aux);

            if(13 <= aux.getIdade() && aux.getIdade() <=18)
                turmas[3].adicionarAluno(aux);

            if(19 <= aux.getIdade() && aux.getIdade() <=30)
                turmas[3].adicionarAluno(aux);
        }

        for(int i=0; i<6; i++){
            if(turmas[i] != null){
                System.out.println("Turma:  " + (i+1));
                turmas[i].exibirTurma();
            }
        }
    }
}
