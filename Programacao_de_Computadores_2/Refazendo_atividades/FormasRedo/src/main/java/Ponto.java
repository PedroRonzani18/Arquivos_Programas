public class Ponto {
    private float x;
    private float y;

    public Ponto() {
        this.x = 0;
        this.y = 0;
    }

    public Ponto(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public Ponto(Ponto p){
        this.x = p.getX();
        this.y = p.getY();
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public float calculaDistancia(Ponto ponto){
        return (float) Math.sqrt(Math.pow((this.x-ponto.getX()),2) + Math.pow((this.y-ponto.getY()),2));
    }


}