package org.example;

public class Mamifero extends Animal {
    private String corPele;

    @Override
    public void locomover() {
        System.out.println("Correndo");
    }

    @Override
    public void alimentar() {
        System.out.println("Comendo");
    }

    @Override
    public void emitirSom() {
        System.out.println("Som mamifero");
    }
}
