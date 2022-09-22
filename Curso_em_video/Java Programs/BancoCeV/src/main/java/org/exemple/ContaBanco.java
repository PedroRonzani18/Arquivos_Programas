package org.exemple;

public class ContaBanco {
    private int numConta;
    private char tipo;
    private String dono;
    private float saldo;
    private boolean status;

    public ContaBanco(){
        this.saldo = 0;
        this.status = false;
    }

    public int getNumConta() {
        return numConta;
    }

    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }

    public char getTipo() {
        return tipo;
    }

    public void setTipo(char tipo) {
        this.tipo = tipo;
    }

    public String getDono() {
        return dono;
    }

    public void setDono(String dono) {
        this.dono = dono;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public void abrirConta(char tipo){
        this.status = true;
        if(tipo == 'c')
            this.saldo = 30;
        if(tipo == 'p')
            this.saldo = 150;
    }
    public boolean fehcarConta(){
        if(saldo != 0)
            return false;
        else {
            this.status = false;
            return true;
        }
    }
    public void depositar(int quant){
        if(this.status)
            this.saldo =+ quant;
    }
    public boolean sacar(int quant){
        if(this.saldo > 0 && quant >= this.saldo) {
            this.saldo -= quant;
            return true;
        }
        return false;
    }
    public boolean pagarMensal(){
        if(this.tipo == 'c') {
            if(this.saldo >=12) {
                this.saldo -= 12;
                return true;
            }
            else
                return false;
        }
        if(this.tipo == 'p') {
            if (this.saldo >= 20) {
                this.saldo -= 20;
                return true;
            } else
                return false;
        }
        return false;
    }
}