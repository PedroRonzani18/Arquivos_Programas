package org.example;

class Game
{
    private Parser parser;
    private Room currentRoom;
    private CommandWords commandWords;

    //* Create the game and initialise its internal map.


    public Room getCurrentRoom() {
        return currentRoom;
    }
    public void setCurrentRoom(Room currentRoom) {
        this.currentRoom = currentRoom;
    }

    public Game()
    {
        createRooms();
        parser = new Parser();
    }

    // Create all the rooms and link their exits together.
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
        outside.setExits(null, theatre, lab, pub, null, null);
        theatre.setExits(null, null, null, outside, null, null);
        pub.setExits(null, outside, null, null, null, null);
        lab.setExits(outside, office, null, null, null, null);
        office.setExits(null, null, null, lab, attic,basement );

        currentRoom = outside;  // start game outside
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
    public void play()
    {
        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.

        boolean finished = false;
        while (! finished) {
            Command command;
            command = parser.getCommand();
            finished = processCommand(command);
        }
        System.out.println("Thank you for playing.  Good bye.");
    }

    public String printWelcomeExit()
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
    }

    /**
     * Given a command, process (that is: execute) the command.
     * If this command ends the game, true is returned, otherwise false is
     * returned.
     */
    private boolean processCommand(Command command)
    {
        if(commandWords.processarComando(command) == 3)
            goRoom(command);
        if(commandWords.processarComando(command) == 4)
            return quit(command);

        return false;
/*
        if(command.isUnknown()) {
            System.out.println("I don't know what you mean...");
            return false;
        }
*/
    }

    // implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the
     * command words.
     */

    public String comer(){return "Você comeu e não está mais com fome ";}

    /**
     * Try to go to one direction. If there is an exit, enter
     * the new room, otherwise print an error message.
     */
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


        if (nextRoom == null)
            System.out.println("There is no door!");
        else {
            currentRoom = nextRoom;
            System.out.println("You are " + currentRoom.getDescription());


            System.out.println("Items: "); // percorre arraylist de items e printa suas respectivas descrições
                for(String i: currentRoom.items.keySet())
                    System.out.println(i + ": " + currentRoom.items.get(i));

            System.out.print("Exits: ");

            for(String i: currentRoom.exits.keySet())
            {
                if(currentRoom.exits.get(i) != null)
                    System.out.println(currentRoom.exits.get(i));
            }
            /*
            if(currentRoom.exits.get("northExit") != null)
                System.out.print("north ");
            if(currentRoom.exits.get("eastExit") != null)
                System.out.print("east ");
            if(currentRoom.exits.get("southExit") != null)
                System.out.print("south ");
            if(currentRoom.exits.get("westExit") != null)
                System.out.print("west ");
            if(currentRoom.exits.get("upExit") != null)
                System.out.print("up ");
            if(currentRoom.exits.get("downExit") != null)
                System.out.print("down ");*/
        }
    }

    /**
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game. Return true, if this command
     * quits the game, false otherwise.
     */
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
