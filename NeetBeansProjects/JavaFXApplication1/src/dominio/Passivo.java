package dominio;

public interface Passivo {
    public static final double SALARIO = 1212;
    public static final double HORA = 45;

    public abstract double getValorAPagar(int diaPagto, int mesPagto);

}

