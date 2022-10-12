package org.exxample;
/**
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 */

class Game
{
    private Parser parser;
    private Room currentRoom;
    private Command command = new Command();
    private CommandWords commandWords = new CommandWords();

    public Parser getParser() {
        return parser;
    }
    public void setParser(Parser parser) {
        this.parser = parser;
    }

    public Room getCurrentRoom() {
        return currentRoom;
    }
    public void setCurrentRoom(Room currentRoom) {
        this.currentRoom = currentRoom;
    }

    /**
     * Create the game and initialise its internal map.
     */
    public Game()
    {
        createRooms();
        parser = new Parser();
    }

    /**
     * Create all the rooms and link their exits together.
     */
    private void createRooms()
    {
        Room outside, theatre, pub, lab, office, basement, attic;

        // create the rooms
        outside = new Room("outside the main entrance of the university");
        theatre = new Room("in a lecture theatre");
        pub = new Room("in the campus pub");
        lab = new Room("in a computing lab");
        office = new Room("in the computing admin office");
        basement = new Room("in the basement");
        attic = new Room("in the attic");

        // initialise room exits
        outside.setExits(null, theatre, lab, pub,null, null);
        theatre.setExits(null, null, null, outside, null, null);
        pub.setExits(null, outside, null, null, null, null);
        lab.setExits(outside, office, null, null, null, null);
        office.setExits(null, null, null, lab, attic, basement);

        currentRoom = outside;  // start game outside
    }

    public String comer(){return "Você comeu e não está mais com fome ";}
    /**
     *  Main play routine.  Loops until end of play.
     */
    public String play()
    {
        printWelcome();

        int retorno;

        retorno = this.commandWords.verifyCommand(this.command);
        System.out.println("REtorno: " + retorno);
        /*
        boolean finished = false;
        while (finished == false) {
            //Command command;
            command = parser.getCommand(); // armazena o comando
            finished = processCommand(command);
        }*/

        if(retorno == 5)
            printHelp();

        if(retorno == 2)
            goRoom(command);

        if(retorno == 3)
            searchItems();

        if(retorno == 1)
            return "Thank you for playing. Good bye.";

        return null;
    }

    private String printWelcome()
    {
        if(currentRoom.exits.get("northExit") != null)
            return "north ";
        if(currentRoom.exits.get("eastExit") != null)
            return "east ";
        if(currentRoom.exits.get("southExit") != null)
            return "south ";
        if(currentRoom.exits.get("westExit") != null)
            return "west ";
        if(currentRoom.exits.get("upExit") != null)
            return "up ";
        if(currentRoom.exits.get("downExit") != null)
            return "down ";
        return "printwelcome null";

        /*
        if(currentRoom.northExit != null)
            System.out.print("north ");
        if(currentRoom.eastExit != null)
            System.out.print("east ");
        if(currentRoom.southExit != null)
            System.out.print("south ");
        if(currentRoom.westExit != null)
            System.out.print("west ");
        System.out.println();*/
    }

    private void searchItems()
    {
        currentRoom.showItems();
    }

    private void goRoom(Command command)
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Go where?");
            return;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = null;

        if(direction.equals("north"))
            nextRoom = currentRoom.exits.get("northExit");
        else if(direction.equals("east"))
            nextRoom = currentRoom.exits.get("eastExit");
        else if(direction.equals("south"))
            nextRoom = currentRoom.exits.get("southExit");
        else if(direction.equals("west"))
            nextRoom = currentRoom.exits.get("westExit");
        else if(direction.equals("up"))
            nextRoom = currentRoom.exits.get("upExit");
        else if(direction.equals("down"))
            nextRoom = currentRoom.exits.get("downExit");

        /*
        if(direction.equals("north"))
            nextRoom = currentRoom.northExit;
        if(direction.equals("east"))
            nextRoom = currentRoom.eastExit;
        if(direction.equals("south"))
            nextRoom = currentRoom.southExit;
        if(direction.equals("west"))
            nextRoom = currentRoom.westExit;*/

        if (nextRoom == null)
            System.out.println("There is no door!");
        else {
            currentRoom = nextRoom;
            System.out.println("You are " + currentRoom.getDescription());
            System.out.print("Exits: ");

            for(String i: currentRoom.exits.keySet())
            {
                if(currentRoom.exits.get(i) != null)
                    System.out.println(currentRoom.exits.get(i));
            }

            /*
            if(currentRoom.northExit != null)
                System.out.print("north ");
            if(currentRoom.eastExit != null)
                System.out.print("east ");
            if(currentRoom.southExit != null)
                System.out.print("south ");
            if(currentRoom.westExit != null)
                System.out.print("west ");
            System.out.println();*/
        }
    }

    private void printHelp()
    {
        System.out.println("You are lost. You are alone. You wander");
        System.out.println("around at the university.");
        System.out.println();
        System.out.println("Your command words are:");
        System.out.println("   go quit help");
    }

    private boolean quit(Command command)
    {
        if(command.hasSecondWord()) {
            System.out.println("Quit what?");
            return false;
        }
        else
            return true;  // signal that we want to quit
    }

}