public class Quadrado extends Forma{
    private float lado;

    public Quadrado(float lado) {
        this.lado = lado;
    }

    public float getLado() {
        return lado;
    }

    public void setLado(float lado) {
        this.lado = lado;
    }

    @Override
    public float calculaArea() {
        return lado * lado;
    }

    @Override
    public float calculaPerimetro() {
        return 4*lado;
    }
}
