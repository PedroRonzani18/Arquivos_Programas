package dominio;

public class SistemaPagamentoTeste {
    public static void main(String[] args) {

        ControlePagamento controle = new ControlePagamento();

        Passivo terc = new Terceirizado("Pedro", "Augusto",1);
        Passivo comicio = new Comissionado("Lucas","Andrade",2);
        Passivo assalar = new Assalariado("Ulisses", "Andrade", 3, 20);
        Passivo assalarComissio = new AssalariadoComissionado("Mateus","Soares",4,0.2);

        Passivo titule = new Titulo(1,1,150);
        Passivo concessionaria = new Concessionaria(2,2,200);

        controle.adicionaPassivo(terc);
        controle.adicionaPassivo(comicio);
        controle.adicionaPassivo(assalar);
        controle.adicionaPassivo(assalarComissio);
        controle.adicionaPassivo(titule);
        controle.adicionaPassivo(concessionaria);

        System.out.println("Total dos salários pagos: " + controle.calculaSalarioTotal());
        System.out.println("Total impostos pagos: " + controle.calculaImpostoTotal());
        System.out.println("Valor total: " + (controle.calculaImpostoTotal() + controle.calculaSalarioTotal()));
    }
}
