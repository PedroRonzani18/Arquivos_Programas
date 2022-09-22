package org.example;

public class Livro implements Publicacao {
    private String titulo;
    private String autor;
    private int totalPaginas;
    private int pagAtual;
    private boolean aberto;
    private Pessoa Leitor;

    public Livro(String titulo, String autor, int totalPaginas, Pessoa leitor) {
        this.titulo = titulo;
        this.autor = autor;
        this.totalPaginas = totalPaginas;
        this.pagAtual = 0;
        this.aberto = false;
        Leitor = leitor;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getTotalPaginas() {
        return totalPaginas;
    }

    public void setTotalPaginas(int totalPaginas) {
        this.totalPaginas = totalPaginas;
    }

    public int getPagAtual() {
        return pagAtual;
    }

    public void setPagAtual(int pagAtual) {
        this.pagAtual = pagAtual;
    }

    public boolean getAberto() {
        return aberto;
    }

    public void setAberto(boolean aberto) {
        this.aberto = aberto;
    }

    public Pessoa getLeitor() {
        return Leitor;
    }

    public void setLeitor(Pessoa leitor) {
        Leitor = leitor;
    }


    public String detalhes() {
        return "Livro{" + '\n' +
                "Titulo: " + titulo + '\n' +
                "Autor: '" + autor + '\n' +
                "Total de paginas: " + totalPaginas + '\n' +
                "Pagina Atual: " + pagAtual + '\n' +
                "Aberto: " + aberto + '\n' +
                "Leitor: " + Leitor.getNome() + '\n' +
                '}';
    }

    @Override
    public void abrir() {
        this.aberto = true;
    }

    @Override
    public void fehcar() {
        this.aberto = false;
    }

    public void folhear(int pmax) {
        this.pagAtual = pmax;
    }

    @Override
    public void avancarPag() {
        this.pagAtual++;
    }

    @Override
    public void voltarPag() {
        this.pagAtual--;
    }
}
