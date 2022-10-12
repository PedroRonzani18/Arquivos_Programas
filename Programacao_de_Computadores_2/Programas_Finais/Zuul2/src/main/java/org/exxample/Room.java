package org.exxample;
/*
 * Class Room - a room in an adventure game.
 *
 * This class is the main class of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * A "Room" represents one location in the scenery of the game.  It is
 * connected to other rooms via exits.  The exits are labelled north,
 * east, south, west.  For each direction, the room stores a reference
 * to the neighboring room, or null if there is no exit in that direction.
 *
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */

import java.util.ArrayList;
import java.util.HashMap;

class Room
{
    public String description;
    public HashMap<String,Room> exits = new HashMap<>();
    public HashMap<String,String> items = new HashMap<>();

    /*
    public Room northExit;
    public Room southExit;
    public Room eastExit;
    public Room westExit;
    public Room upExit;
    public Room downExit;*/

    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     */

    public ArrayList showItems(){
        ArrayList<String> aux = new ArrayList<>();

        for(String i: items.keySet()){
            //System.out.println("Item: " + i + "| Description: " + items.get(i));
            aux.add("Item: " + i + "| Description: " + items.get(i));
        }
        return aux ;
    }

    public void addItem(String nome, String descricao)
    {
        items.put(nome,descricao);
    }

    public void initExits()
    {
        Room aux = new Room();

        exits.put("northExit", aux);
        exits.put("southExit",aux);
        exits.put("eastExit",aux);
        exits.put("westExit",aux);
        exits.put("upExit",aux);
        exits.put("downExit",aux);
    }

    public Room(){}

    public Room(String description)
    {
        initExits();
        this.description = description;
    }

    /**
     * Define the exits of this room.  Every direction either leads
     * to another room or is null (no exit there).
     */
    public void setExits(Room north, Room east, Room south, Room west, Room up, Room down)
    {
        if(north != null)
            exits.put("northExit",north);
        if(east != null)
            exits.put("southExit",east);
        if(south != null)
            exits.put("southExit",south);
        if(west != null)
            exits.put("westExit",west);
        if(up != null)
            exits.put("upExit",up);
        if(down != null)
            exits.put("downExit",down);
    }

    /**
     * Return the description of the room (the one that was defined
     * in the constructor).
     */
    public String getDescription()
    {
        return description;
    }

}