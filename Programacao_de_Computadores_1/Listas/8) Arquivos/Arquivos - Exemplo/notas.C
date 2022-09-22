//Escrita de arquivo com fprintf ("%c")

#include <stdio.h>
#include <string.h>

main(int argc, char*argv[])
{
    FILE *arquivo;
    //Abrir arquivo no modo de escrita
	 char nome_do_arquivo[30];
    printf("Digite o nome do arquivo: ");
 	 gets(nome_do_arquivo);

    arquivo = fopen(nome_do_arquivo,"a");

    char   nome[50];
    int nota=1;
	 while (nota>0){
		 printf("Digite o nome: ");
	 	 gets(nome);
		 getchar();
		 printf("Digite a nota: ");
		 scanf("%d",&nota);
		 getchar();
		 fprintf(arquivo,"%s %d\n",nome,nota);
	 }
}


