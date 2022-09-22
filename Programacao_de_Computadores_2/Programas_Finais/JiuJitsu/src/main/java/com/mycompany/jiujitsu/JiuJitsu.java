package com.mycompany.jiujitsu;

import java.util.Scanner;

public class JiuJitsu {

    public static void main(String[] args) {
     
        Scanner entrada = new Scanner(System.in);
        
        Turma[] turmas = new Turma[6];
        
        turmas[0] = new Turma();
        turmas[0].setDesc("Manhã Fem");
        
        turmas[1] = new Turma();
        turmas[1].setDesc("Tarde Fem");
        
        turmas[2] = new Turma();
        turmas[2].setDesc("Noite Fem");
        
        turmas[3] = new Turma();
        turmas[3].setDesc("Manhã Masc");
        
        turmas[4] = new Turma();
        turmas[4].setDesc("Tarde Masc");
        
        turmas[5] = new Turma();
        turmas[5].setDesc("Noite Masc");
        
        int continuar = 1;
        
        Aluno aux;
        
        while(continuar == 1){
            
            aux = new Aluno();
            
            System.out.print("Nome: ");
            aux.setNome(entrada.next());
            
            System.out.print("Sexo (M ou F): ");
            aux.setSexo(entrada.next());
            
            System.out.print("Idade: ");
            aux.setIdade(entrada.nextInt());
            
            System.out.print("Peso: ");
            aux.setPeso(entrada.nextDouble());
            
            System.out.print("Altura: ");
            aux.setAltura(entrada.nextDouble());
            
            System.out.print("Telefone de Contato: ");
            aux.setTelContato(entrada.next());
            
            if(aux.getSexo().equals("F")){
                if(aux.getIdade() >=9 && aux.getIdade() <= 12)                
                    turmas[0].adicionarAluno(aux);
                
                if(aux.getIdade() >= 13 && aux.getIdade() <= 18)
                    turmas[1].adicionarAluno(aux);
                
                if(aux.getIdade() >= 19 && aux.getIdade() <= 30)
                    turmas[2].adicionarAluno(aux);
            }
                
            if(aux.getSexo().equals("M")){
                if(aux.getIdade() >=9 && aux.getIdade() <= 12)                
                    turmas[3].adicionarAluno(aux);
                
                if(aux.getIdade() >= 13 && aux.getIdade() <= 18)
                    turmas[4].adicionarAluno(aux);
                
                if(aux.getIdade() >= 19 && aux.getIdade() <= 30)
                    turmas[5].adicionarAluno(aux);
            }
            
            System.out.print("Quer adicionar mais alunos? Sim = 1 | Não = 0: ");
            continuar = entrada.nextInt();    
        }  
        
        for(int i=0; i < turmas.length ; i++){
            if(turmas[i] != null){
                System.out.println("Turma " + (i+1));
                turmas[i].exibirTurmaAlunos();
            }
        }
    }
}
