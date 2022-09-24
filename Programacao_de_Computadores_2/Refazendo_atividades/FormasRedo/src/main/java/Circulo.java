public class Circulo extends Forma{
    private float raio;

    public Circulo(float raio) {
        this.raio = raio;
    }

    public float getRaio() {
        return raio;
    }

    public void setRaio(float raio) {
        this.raio = raio;
    }

    @Override
    public float calculaArea() {
        return (float) (Math.PI * Math.pow(this.raio,2));
    }

    @Override
    public float calculaPerimetro() {
        return (float) (2 * Math.PI * this.raio);
    }
}
