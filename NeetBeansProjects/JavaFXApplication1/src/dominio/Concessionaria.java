package dominio;

public class Concessionaria extends Conta{

    public Concessionaria(int dia, int mes, int valor) {
        super(dia, mes, valor);
    }

    @Override
    public double getValorAPagar(int diaPagto, int mesPagto) {
        return this.valor;
    }
}
