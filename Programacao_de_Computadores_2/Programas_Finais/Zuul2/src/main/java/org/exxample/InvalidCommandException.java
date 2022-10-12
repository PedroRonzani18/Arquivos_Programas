package org.exxample;

public class InvalidCommandException extends Exception{
    public InvalidCommandException(){
        super("Comando inválido. Tente digitar help");
    }
}
