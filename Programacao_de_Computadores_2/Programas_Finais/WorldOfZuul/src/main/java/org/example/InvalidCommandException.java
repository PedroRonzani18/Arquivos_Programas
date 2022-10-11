package org.example;

public class InvalidCommandException extends Exception{
    public InvalidCommandException(){
        super("Comando inválido. Tente digitar help");
    }
}
