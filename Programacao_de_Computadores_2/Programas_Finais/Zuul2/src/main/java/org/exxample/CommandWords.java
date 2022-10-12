package org.exxample;
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
    private static final String validCommands[] = {"go", "quit", "help", "look", "search"};
    private Parser parser;

    /**
     * Constructor - initialise the command words.
     */
    public CommandWords()
    {
        // nothing to do at the moment...
    }

    /**
     * Check whether a given String is a valid command word.
     * Return true if it is, false if it isn't.
     */

    public int verifyCommand(Command com)
    {
        Command aux = com;

        System.out.println(aux);

        int finished;

        //while (finished != 1) {
        aux = parser.getCommand(); // armazena o comando
        finished = processCommand(aux);
        return finished;
        //}
        //return 0;
    }

    private int processCommand(Command command)
    {
        int wantToQuit = 0;
/*
        if(command.isUnknown()) {
            System.out.println("I don't know what you mean...");
            return false;
        }
*/
        String commandWord = command.getCommandWord();
        if (commandWord.equals("help"))
            return 5;
            //printHelp();

        else if (commandWord.equals("go"))
            return 2;
            //goRoom(command);

        else if (commandWord.equals("search"))
            return 3;
            //searchItems();

        else if (commandWord.equals("quit"))
            wantToQuit = quit(command);

        return wantToQuit;
    }

    private int quit(Command command)
    {
        if(command.hasSecondWord()) {
            System.out.println("Quit what?");
            return 0;
        }
        else
            return 1;  // signal that we want to quit
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