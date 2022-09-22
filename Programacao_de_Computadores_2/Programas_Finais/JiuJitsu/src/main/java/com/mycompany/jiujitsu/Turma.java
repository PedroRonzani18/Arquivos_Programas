package com.mycompany.jiujitsu;

public class Turma {
    
    private String desc;
    private Aluno[] alunos;
    
    public Turma(){
        alunos = new Aluno[10];
        desc = " ";
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public String getDesc() {
        return desc;
    }

    public void setAlunos(Aluno[] alunos) {
        this.alunos = alunos;
    }

    public Aluno[] getAlunos() {
        return alunos;
    }
    
    public boolean adicionarAluno(Aluno aluno){
        for(int i=0 ; i<alunos.length ; i++){
            if(alunos[i] == null){
                alunos[i] = aluno;
                return true;
            }                 
        }
        return false;
    }
    
    public void exibirTurmaAlunos(){
        for(int j=0; j<alunos.length; j++){
            if(alunos[j] != null){
                System.out.print(alunos[j].getNome() + " ");
                System.out.print(alunos[j].getIdade() + " anos ");
                System.out.print(alunos[j].getSexo() + " ");
                System.out.print(alunos[j].getPeso() + " Kg ");
                System.out.print(alunos[j].getAltura() + " metros ");
                System.out.println(alunos[j].getTelContato() + " "); 
            }
        }    
    }
}
