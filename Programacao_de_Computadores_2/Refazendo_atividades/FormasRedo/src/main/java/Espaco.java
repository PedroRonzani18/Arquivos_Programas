import java.util.ArrayList;

public class Espaco {
    private ArrayList<Forma> formas = new ArrayList<>();

    public Espaco(ArrayList<Forma> formas) {
        this.formas = formas;
    }

    public Espaco(){}

    public void adicionaForma(Forma f){
        formas.add(f);
    }

    public float calculaAreaTotal(){
        float areasAux = 0;

        for(Forma i: formas){
            areasAux += i.calculaArea();
        }
        return areasAux;
    }

    public float calculaPerimetroTotal(){
        float perimetroAux = 0;

        for(Forma i: formas){
            perimetroAux += i.calculaPerimetro();
        }
        return perimetroAux;
    }
}
