package org.example;

public class Main {
    public static void main(String[] args) {
        System.out.println("Bem vindos à luta!");

        Lutador lista[] = new Lutador[4];

        lista[0] = new Lutador("Pretty boy", "França", 31, 1.75f, 68.9f, 11, 3, 1);
        lista[1] = new Lutador("Putscript","Brasil",29, 1.68f, 57.8f, 14, 2, 3);
        lista[2] = new Lutador("Snapshadow", "EUA", 35, 1.65f, 80.9f, 12, 2,1);
        lista[3] = new Lutador("Deadcode", "Austrália", 28, 1.93f, 81.3f,13,0,2);

        System.out.println("----LUTADORES-----");

        for(int i=0; i<4; i++){
            System.out.println("Nome: " + lista[i].getNome());
            System.out.println("Nacionalidade: " + lista[i].getNacionalidade());
            System.out.println("Idade: " + lista[i].getIdade());
            System.out.println("Peso: " + lista[i].getPeso());
            System.out.println("Categoria: " + lista[i].getCategoria());
            System.out.println("Altura: " + lista[i].getAltura());
            System.out.println("V/E/D: " + lista[i].getVitorias() + "/" + lista[i].getEmpates()  + "/" + lista[i].getDerrotas() + "\n");
        }
    }
}