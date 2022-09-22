package org.example;

public class Turma {
    private String descricao;
    private Aluno[] alunos;

    public Turma() {
        descricao = " ";
        alunos = new Aluno[10];
    }

    public Turma(String descricao, Aluno[] alunos) {
        this.descricao = descricao;
        this.alunos = alunos;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public Aluno[] getAlunos() {
        return alunos;
    }

    public void setAlunos(Aluno[] alunos) {
        this.alunos = alunos;
    }

    public boolean adicionarAluno(Aluno aux){
        for(int i=0; i<10; i++){
            if(alunos[i] == null){
                alunos[i] = aux;
                return true;
            }
        }
        return false;
    }

    public void exibirTurma(){
        for(int i=0; i<10; i++)
            if(alunos[i] != null){
                System.out.println("Nome: " + alunos[i].getNome());
                System.out.println("Idade: " + alunos[i].getIdade());
                System.out.println("Sexo: " + alunos[i].getSexo());
                System.out.println("Peso: " + alunos[i].getPeso());
                System.out.println("Altura: " + alunos[i].getAltura());
                System.out.println("Telefone de Contato: " + alunos[i].getTelContato());
            }
    }
}
