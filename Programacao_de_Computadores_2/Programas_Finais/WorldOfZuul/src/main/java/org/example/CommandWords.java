package org.example;

/*
 * This class is the main class of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */

class CommandWords
{
    // a constant array that holds all valid command words
    private static final String validCommands[] = {"go", "quit", "help", "look"};

    /**
     * Constructor - initialise the command words.
     */
    public CommandWords(){// nothing to do at the moment...
        }

    /**
     * Check whether a given String is a valid command word.
     * Return true if it is, false if it isn't.
     */

    public int processarComando(Command command){
/*
        if(command.isUnknown()) {
            System.out.println("I don't know what you mean...");
            return false;
        }
*/
        String commandWord = command.getCommandWord();
        if (commandWord.equals("help"))
            printHelp();
        else if (commandWord.equals("go"))
            return 3;
            //goRoom(command);
        else if (commandWord.equals("quit"))
            return 4;
        return 0;
    }

    private void printHelp()
    {
        System.out.println("You are lost. You are alone. You wander");
        System.out.println("around at the university.");
        System.out.println();
        System.out.println("Your command words are:");
        System.out.println("   go quit help");
    }

    public void isCommand(String aString) throws InvalidCommandException
    {
       boolean erro = true;
       for(int i=0; i< validCommands.length; i++){
           if(validCommands[i].equals(aString)){
               erro = false;
           }
       }
       if(erro){
           throw new InvalidCommandException();
       }
        // if we get here, the string was not found in the commands
    }

}
