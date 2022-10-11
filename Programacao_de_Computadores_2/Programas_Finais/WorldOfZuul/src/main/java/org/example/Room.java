package org.example;

import java.util.HashMap;

class Room
{
    public String description;
    public HashMap<String,Room> exits;
    public HashMap<String,String> items;

    public Room(String description)
    {
        this.description = description;
    }

    public Room() {
        inicializaExits();
    }

    public void addItem(String nome, String descricao)
    {
        items.put(nome,descricao);
    }

    public void inicializaExits()
    {
        Room aux = new Room();

        exits.put("northExit",aux);
        exits.put("southExit",aux);
        exits.put("eastExit",aux);
        exits.put("westExit",aux);
        exits.put("upExit",aux);
        exits.put("downExit",aux);
    }

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

    public String getDescription()
    {
        return description;
    }
}