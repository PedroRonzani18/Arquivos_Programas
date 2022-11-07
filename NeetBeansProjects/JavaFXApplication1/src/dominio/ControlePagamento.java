package dominio;

import java.util.ArrayList;

public class ControlePagamento {
    private ArrayList<Passivo> pagamentos = new ArrayList<>();

    public ControlePagamento(ArrayList<Passivo> pagamentos) {
        this.pagamentos = pagamentos;
    }

    public ControlePagamento(){}

    public ArrayList<Passivo> getPagamentos() {
        return pagamentos;
    }
    public void setPagamentos(ArrayList<Passivo> pagamentos) {
        this.pagamentos = pagamentos;
    }

    public void adicionaPassivo(Passivo passivo){
        pagamentos.add(passivo);
    }

    public double calculaSalarioTotal(){
        int valor=0;

        for(Passivo i: pagamentos) {
            if (i instanceof Empregado)
                valor += i.getValorAPagar(20, 9);
        }
        return valor;
    }

    public double calculaImpostoTotal(){
        int valor=0;

        for(Passivo i: pagamentos) {
            if (i instanceof Conta)
                valor += i.getValorAPagar(20, 9);
        }
        return valor;
    }
}
