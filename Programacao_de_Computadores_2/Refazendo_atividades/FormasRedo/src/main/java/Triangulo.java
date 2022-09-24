public class Triangulo extends Forma {
    private float lado1;
    private float lado2;
    private float lado3;

    public Triangulo() {
    }

    public Triangulo(float lado1, float lado2, float lado3) {
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    public float getLado1() {
        return lado1;
    }

    public void setLado1(float lado1) {
        this.lado1 = lado1;
    }

    public float getLado2() {
        return lado2;
    }

    public void setLado2(float lado2) {
        this.lado2 = lado2;
    }

    public float getLado3() {
        return lado3;
    }

    public void setLado3(float lado3) {
        this.lado3 = lado3;
    }

    @Override
    public float calculaArea() {
        return 0;
    }

    @Override
    public float calculaPerimetro() {
        return 0;
    }

    public String tipoTriangulo(){
        if((lado1 == lado2) && (lado2 == lado3) && (lado3 == lado1))
            return "Equilatero";

        if((lado1 == lado2) && (lado2 == lado3) && (lado3 != lado1))
            return "Isoceles";

        if((lado1 == lado2) && (lado2 != lado3) && (lado3 == lado1))
            return "Isoceles";

        if((lado1 != lado2) && (lado2 == lado3) && (lado3 == lado1))
            return "Isoceles";

        if((lado1 != lado2) && (lado2 != lado3) && (lado3 != lado1))
            return "Escaleno";

        return null;
    }
}
