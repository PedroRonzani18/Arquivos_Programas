package dominio;

public abstract class Conta implements Passivo{
    protected int dia; //dia de pagamento
    protected int mes; // mes de pagamento
    protected int valor;

    public Conta(int dia, int mes, int valor){
        this.dia = dia;
        this.mes = mes;
        this.valor = valor;
    }

    public int getDia() {
        return dia;
    }
    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return mes;
    }
    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getValor() {
        return valor;
    }
    public void setValor(int valor) {
        this.valor = valor;
    }
}
