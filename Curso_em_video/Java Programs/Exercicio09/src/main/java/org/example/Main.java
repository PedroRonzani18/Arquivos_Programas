package org.example;

public class Main {
    public static void main(String[] args) {
        Pessoa[] people = new Pessoa[2];
        Livro[] livros = new Livro[3];

        people[0] = new Pessoa("Pedro",18,'M');
        people[1] = new Pessoa("Isadora",19,'F');

        livros[0] = new Livro("Tituo1", "Messias1", 100, people[0]);
        livros[1] = new Livro("Tituo2", "Josias", 200, people[1]);
        livros[2] = new Livro("Tituo3", "Cleiton", 300, people[0]);

        livros[0].abrir();
        livros[0].folhear(2);


        System.out.println(livros[0].detalhes());
    }
}
