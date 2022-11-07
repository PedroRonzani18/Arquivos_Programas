/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.jogodavelhanew;

import java.awt.TextField;
import javax.swing.JOptionPane;

/**
 *
 * @author pedro
 */
public class JanelaPrincipal extends javax.swing.JFrame {

    /**
     * Creates new form JanelaPrincipal
     */
    public JanelaPrincipal() {
        jogo = new JogoDaVelha();
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    
    public void popUpFim(int v)
    {
        if(v == 1)
            JOptionPane.showConfirmDialog(this,"Jogador O vence!", "EndGame",JOptionPane.DEFAULT_OPTION);
        if(v == 2)
            JOptionPane.showConfirmDialog(this,"Jogador X vence!", "EndGame",JOptionPane.DEFAULT_OPTION);
        if(v == 3)
            JOptionPane.showConfirmDialog(this,"Velha!", "EndGame",JOptionPane.DEFAULT_OPTION);
        jogo.limparTela();
        jTextField1.setText("");
        jTextField2.setText("");
        jTextField3.setText("");
        jTextField4.setText("");
        jTextField5.setText("");
        jTextField6.setText("");
        jTextField7.setText("");
        jTextField8.setText("");
        jTextField9.setText("");
        
        jTextField1.setFocusable(false);
        jTextField2.setFocusable(false);
        jTextField3.setFocusable(false);
        jTextField4.setFocusable(false);
        jTextField5.setFocusable(false);
        jTextField6.setFocusable(false);
        jTextField7.setFocusable(false);
        jTextField8.setFocusable(false);
        jTextField9.setFocusable(false);
        
        jTextField1.setFocusable(true);
        jTextField2.setFocusable(true);
        jTextField3.setFocusable(true);
        jTextField4.setFocusable(true);
        jTextField5.setFocusable(true);
        jTextField6.setFocusable(true);
        jTextField7.setFocusable(true);
        jTextField8.setFocusable(true);
        jTextField9.setFocusable(true);
    }
    
    JogoDaVelha jogo;
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ButGrup = new javax.swing.ButtonGroup();
        jLabel1 = new javax.swing.JLabel();
        ToggleButtonX = new javax.swing.JToggleButton();
        jPanel1 = new javax.swing.JPanel();
        jTextField1 = new javax.swing.JTextField();
        jTextField2 = new javax.swing.JTextField();
        jTextField3 = new javax.swing.JTextField();
        jTextField4 = new javax.swing.JTextField();
        jTextField5 = new javax.swing.JTextField();
        jTextField6 = new javax.swing.JTextField();
        jTextField7 = new javax.swing.JTextField();
        jTextField8 = new javax.swing.JTextField();
        jTextField9 = new javax.swing.JTextField();
        ToggleButtonO = new javax.swing.JToggleButton();
        BotaoLimpar = new javax.swing.JButton();
        BotaoSair = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jLabel1.setText("Escolha sua peça e clique na posição desejada");

        ButGrup.add(ToggleButtonX);
        ToggleButtonX.setText("X");
        ToggleButtonX.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ToggleButtonXActionPerformed(evt);
            }
        });

        jPanel1.setLayout(new java.awt.GridLayout(3, 3));

        jTextField1.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField1.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField1FocusGained(evt);
            }
        });
        jPanel1.add(jTextField1);

        jTextField2.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField2.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField2FocusGained(evt);
            }
        });
        jPanel1.add(jTextField2);

        jTextField3.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField3.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField3FocusGained(evt);
            }
        });
        jPanel1.add(jTextField3);

        jTextField4.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField4.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField4FocusGained(evt);
            }
        });
        jPanel1.add(jTextField4);

        jTextField5.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField5.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField5FocusGained(evt);
            }
        });
        jPanel1.add(jTextField5);

        jTextField6.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField6.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField6FocusGained(evt);
            }
        });
        jPanel1.add(jTextField6);

        jTextField7.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField7.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField7FocusGained(evt);
            }
        });
        jPanel1.add(jTextField7);

        jTextField8.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField8.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField8FocusGained(evt);
            }
        });
        jPanel1.add(jTextField8);

        jTextField9.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField9.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextField9FocusGained(evt);
            }
        });
        jPanel1.add(jTextField9);

        ButGrup.add(ToggleButtonO);
        ToggleButtonO.setText("O");
        ToggleButtonO.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ToggleButtonOActionPerformed(evt);
            }
        });

        BotaoLimpar.setText("Limpar");
        BotaoLimpar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BotaoLimparMouseClicked(evt);
            }
        });

        BotaoSair.setText("Sair");
        BotaoSair.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                BotaoSairMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel1))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(54, 54, 54)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 325, Short.MAX_VALUE)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(56, 56, 56)
                                .addComponent(ToggleButtonX, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(47, 47, 47)
                                .addComponent(ToggleButtonO, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(0, 48, Short.MAX_VALUE)))))
                .addContainerGap(52, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(91, 91, 91)
                .addComponent(BotaoLimpar)
                .addGap(58, 58, 58)
                .addComponent(BotaoSair)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ToggleButtonX)
                    .addComponent(ToggleButtonO))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BotaoLimpar)
                    .addComponent(BotaoSair))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void ToggleButtonXActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ToggleButtonXActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_ToggleButtonXActionPerformed

    private void ToggleButtonOActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ToggleButtonOActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_ToggleButtonOActionPerformed

    private void BotaoLimparMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BotaoLimparMouseClicked
        // TODO add your handling code here:
        jogo.limparTela();
        jTextField1.setText("");
        jTextField2.setText("");
        jTextField3.setText("");
        jTextField4.setText("");
        jTextField5.setText("");
        jTextField6.setText("");
        jTextField7.setText("");
        jTextField8.setText("");
        jTextField9.setText("");
    }//GEN-LAST:event_BotaoLimparMouseClicked

    private void BotaoSairMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_BotaoSairMouseClicked

        System.exit(0);
    }//GEN-LAST:event_BotaoSairMouseClicked

    private void jTextField1FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField1FocusGained
        // TODO add your handling code here:
        if(ToggleButtonO.isSelected())
        {
            jogo.jogar(0, 0, 1);
            jTextField1.setText("O");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(0, 0, 2);
            jTextField1.setText("X");  
        }
        
        if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField1FocusGained

    private void jTextField2FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField2FocusGained
        // TODO add your handling code here:
        if(ToggleButtonO.isSelected())
        {
            jogo.jogar(0, 1, 1);
            jTextField2.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(0, 1, 2);
            jTextField2.setText("X");  
        }
        
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField2FocusGained

    private void jTextField3FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField3FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(0, 2, 1);
            jTextField3.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(0, 2, 2);
            jTextField3.setText("X");    
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField3FocusGained

    private void jTextField4FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField4FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(1, 0, 1);
            jTextField4.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(1, 0, 2);
            jTextField4.setText("X");   
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField4FocusGained

    private void jTextField5FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField5FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(1, 1, 1);
            jTextField5.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(1, 1, 2);
            jTextField5.setText("X");   
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField5FocusGained

    private void jTextField6FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField6FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(1, 2, 1);
            jTextField6.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(1, 2, 2);
            jTextField6.setText("X");    
        }
         
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField6FocusGained

    private void jTextField7FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField7FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(2, 0, 1);
            jTextField7.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(2, 0, 2);
            jTextField7.setText("X");
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField7FocusGained

    private void jTextField8FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField8FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(2, 1, 1);
            jTextField8.setText("0");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(2, 1, 2);
            jTextField8.setText("X");  
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField8FocusGained

    private void jTextField9FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextField9FocusGained
        // TODO add your handling code here:
                if(ToggleButtonO.isSelected())
        {
            jogo.jogar(2, 2, 1);
            jTextField9.setText("O");
        }else if(ToggleButtonX.isSelected())
        {
            jogo.jogar(2, 2, 2);
            jTextField9.setText("X"); 
        }
                
                if(jogo.verificaVencedor() == 1)
            popUpFim(1);
            
        if(jogo.verificaVencedor() == 2)
            popUpFim(2);
        if(jogo.verificaVencedor() == 3)
            popUpFim(3);
    }//GEN-LAST:event_jTextField9FocusGained

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JanelaPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BotaoLimpar;
    private javax.swing.JButton BotaoSair;
    private javax.swing.ButtonGroup ButGrup;
    private javax.swing.JToggleButton ToggleButtonO;
    private javax.swing.JToggleButton ToggleButtonX;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    private javax.swing.JTextField jTextField4;
    private javax.swing.JTextField jTextField5;
    private javax.swing.JTextField jTextField6;
    private javax.swing.JTextField jTextField7;
    private javax.swing.JTextField jTextField8;
    private javax.swing.JTextField jTextField9;
    // End of variables declaration//GEN-END:variables
}