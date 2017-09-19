#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int main(void) {
	
	char caminho[]="agenda.txt",
	     nome[50], 
		 telefone[50], 
		 email[50],
		 contato;
		 
	int escolha,
		opcao = 1,
		indice;
	
	FILE *agenda;
	
	while(true) {
		
		system("cls");
		printf("============== AGENDA ==============\n\n");
		printf("1 - INSERIR DADOS\n");
		printf("2 - CONSULTAR DADOS\n");
		printf("3 - SAIR\n\n");
		printf("O QUE DESEJA FAZER? ");
		scanf("%d", &escolha);
	
		if (escolha == 1) {
			
			agenda = fopen(caminho, "a");
			
			while (opcao == 1) {
				system("cls");
				printf("========== INSERINDO DADOS =========\n\n");
				fflush(stdin);
				printf("\nNome: ");
	  			gets(nome);
	  			printf("Telefone: ");
	  			gets(telefone);
				printf("Email: ");
	  			gets(email);
	  			fprintf(agenda,"%s # %s # %s\n", nome, telefone, email);
	  			
				printf("\nDESEJA REALIZAR UM NOVO CADASTRO?\n1 - SIM\n2 - NAO\n");
	  			scanf("%d",&opcao);
  			}
  			opcao = 1;
			fclose(agenda);
			
		}else if (escolha == 2) {
			
			agenda = fopen(caminho, "r");
			
			if (agenda == NULL) {
				
				printf("\nArquivo AGENDA.TXT nao pode ser aberto.");
				getch();
				
			}else {
				
				indice = 0;
				system("cls");
				printf("============= CONTATOS =============\n");					
				
				contato = (fscanf(agenda, "%s # %s # %s", &nome, &telefone, &email));
				
				while (contato != EOF) {
					
					indice++ ;
					printf("\n%d§ contato\n", indice);
					printf("\nNome......: %s", nome);
					printf("\nTelefone..: %s ", telefone);
					printf("\nEmail.....: %s", email);
					printf("\n-------------------------------------------------------------- [Tecle algo]");
					getch();
					contato = (fscanf(agenda, "%s # %s # %s", &nome, &telefone, &email));
				}
				printf("\n\n*** FIM ***\n");
				getch();
			}
			fclose (agenda);
			
		}else if(escolha == 3) {
			break;
		}
	}
	return 0;
}

