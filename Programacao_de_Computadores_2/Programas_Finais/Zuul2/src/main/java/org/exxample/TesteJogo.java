package org.exxample;

public class TesteJogo {
    public static void main(String[] args){
        Game game = new Game();

        System.out.println();
        System.out.println("Welcome to Adventure!");
        System.out.println("Adventure is a new, incredibly boring adventure game.");
        System.out.println("Type 'help' if you need help.");
        System.out.println();
        System.out.println("You are " + game.getCurrentRoom().getDescription());
        System.out.print("Exits: ");

        System.out.println(game.play());

        System.out.println(game.comer());
    }
}