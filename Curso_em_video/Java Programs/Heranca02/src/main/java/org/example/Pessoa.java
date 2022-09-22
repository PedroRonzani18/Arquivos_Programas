package org.example;

public abstract class Pessoa {
        private String nome;
        private int idade;
        private char sexo;

        public String getNome() {
                return nome;
        }

        public void setNome(String nome) {
                this.nome = nome;
        }

        public int getIdade() {
                return idade;
        }

        public void setIdade(int idade) {
                this.idade = idade;
        }

        public char getSexo() {
                return sexo;
        }

        public void setSexo(char sexo) {
                this.sexo = sexo;
        }

        public final void fazerAiversario(){this.idade++;}

        @Override
        public String toString() {
                return "Pessoa{" +
                        "nome='" + nome + '\'' +
                        ", idade=" + idade +
                        ", sexo=" + sexo +
                        '}';
        }
}
