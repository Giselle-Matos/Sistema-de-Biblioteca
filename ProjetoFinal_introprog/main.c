#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Projeto Final intro prog 
typedef struct usuario {
	char email[150];
	char senha[150];
	char id[10];
	char nome[200];
	char curso[100];
	long int cpf;
	int tipo;
}dadosUser;
typedef struct livro {
	char titulo[200];
	char autor[200];
	char data[11];
	char nregistro[10];
	char anoPubli[5];
	char ISBN[14];
	char vol[5];
	char editora[100];
}dadosLivro;
typedef struct reserva{
	char id[10];
	char nregistro[10];
}dadosReserva;
typedef struct renovacao{
	char id[10];
	char nregistro[10];
	char dataRenovacao[11];
	char dataDevolucao[11];
}dadosRenovacao;
typedef struct emprestimo{
	char id[10];
	char nregistro[10];
	char dataEmprestimo[11];
	char dataDevolucao[11];
}dadosEmprestimo;
	
// estetica

#define BLACK  30
#define BLUE   34
#define GREEN  32
#define CYAN   36
#define RED    31
#define PURPLE 35
#define YELLOW 33
#define WHITE  37
	
	
void ClearScreen(){
		printf("\e[1;1H\e[2J");
}

// Seleciona uma cor atual (fundo e frente) para o caracter
//==================================
void SetColor(int back, int color) {
     if (back <= 1) {
         printf("\033[%d;%dm", back, color);
     }
     else {
         printf("\033[0;%d;1;%dm", back+10, color);
        
     }
}

// Posiciona o cursor antes de escrever (printf) algo:
//==================================
void GotoXY(int XPos, int YPos)
{
    printf("\033[%d;%dH", YPos+1, XPos+1);
}
// chama os arquivos

FILE * dadosUsuarios;
FILE * dadosBib;
FILE * reserva;
FILE * emprestimos;
FILE * dadosBib_copy;

int main(){
	
	ClearScreen();
	// limpa a tela
	
	SetColor(CYAN, BLACK);
	
	int a;
	int i;
	int verificacao;
	int voltar;
	int b;
	int I;
	int contador = 0;
	char aux[30];
	char busca_titulo[200];
	int m;
	int n;
	char emaillogin[150];
	char senhalogin[150];
	char busca_autor[200];
	
	int teste;
	int teste_reserva;
	int teste_emprestimo;
	char empresta[10];
	char indice[10];
	int id;
	char v;
	
	dadosUser user[1000];
	dadosLivro book[10000];
	dadosRenovacao renovacao[10000];
	dadosEmprestimo loan[10000];
	dadosReserva reservas[10000];
	
	
	
	
	MENU_INICIAL:
	
	ClearScreen();
	
	printf("Bem vindo a biblioteca. \nSelecione uma opçao.\n\n");
	printf("\n1. Entrar no sistema				\n2. Cadastrar Usuario				\n3. Sair				\n");
	printf("\nOpçao:				");
	GotoXY(7,8);
	
	scanf("%d",&a);

	switch(a){
		case 1:
			
			LOGIN:
			
			ClearScreen();
			
			printf("\nDigite seu e-mail: ");
			scanf("%s",emaillogin);
			
			printf("Digite a sua senha: ");
			scanf("%s",senhalogin);
			
			dadosUsuarios = fopen("dadosUsuarios.txt", "r");
			
			verificacao = 0;
			
			while(fscanf(dadosUsuarios, "%s %s %s %s %s %ld %d", user[i].email,  user[i].senha, user[i].id, user[i].nome, user[i].curso, &user[i].cpf, &user[i].tipo) == 7){
			
				m = strcmp(user[i].email, emaillogin);
				n = strcmp(user[i].senha, senhalogin);
				
				if((m == 0) && (n == 0)){
					verificacao = 1;
					I = i; // armazena a posicao do usuario no vetor 
				}
				i++;
			}
			if(verificacao == 0){
					printf("\n\nEmail ou senha incorretos! \nTalvez voce nao tenha se cadastrado.\n");
					
						
					printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
					scanf("%s", &v);
						
					if(v == 's'){
						printf("\n\n");
						goto MENU_INICIAL;
					}
					
					if(v == 'n'){
						exit(0);
					}
			}
			ClearScreen();
			if(verificacao == 1){
				printf("Login efetuado com sucesso!\n\n");
				LOGIN_SUCESSO: 
				printf("4. Inserir novo livro\n5. Procurar livro por titulo\n6. Procurar livro por autor\n7. Apagar livro\n8. Listar livros existentes na biblioteca\n9. Registrar data de emprestimo e devolucao de um livro\n10. Registrar reservas\n11. Renovar emprestimo\n12. Sair\n\n\nOpçao: ");
				scanf("%d", &b);
			}
			fclose(dadosUsuarios);
			
			switch(b){
				case 4: // inserir novo livro
					ClearScreen();
					
					dadosUsuarios = fopen("dadosUsuarios.txt", "r");
					if(user[I].tipo == 3){
						int qttd;
						printf("Quantos livros deseja cadastrar? ");
						scanf("%d", &qttd);
						
						dadosBib = fopen("dadosBib.txt", "a");
						
						
						for(i=0;i<qttd;i++){
							printf("Digite o titulo: ");
							scanf("%s", book[i].titulo);
							
							printf("Digite o autor: ");
							scanf("%s", book[i].autor);
							
							printf("Digite o numero de registro: ");
							scanf("%s", book[i].nregistro);
							
							printf("Digite o ano de publicaçao: ");
							scanf("%s", book[i].anoPubli);
							
							printf("Digite o ISBN: ");
							scanf("%s", book[i].ISBN);
					
							printf("Digite o volume: ");
							scanf("%s", book[i].vol);
							
							printf("Digite a editora: ");
							scanf("%s", book[i].editora);
											
							
							fprintf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);	
							printf("Livro cadastrado!\n");
						}
						fclose(dadosBib);
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						// 
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						} // Observaçao: O uso constante dessa estrutura se da devido ao fato de nao podermos usar goto fora da funçao. Caso contrario, eu teria criado uma funcao para substituir essa estrutura que se repete diversas vezes no codigo.
						
					}
					
					if((user[I].tipo == 1) || (user[I].tipo == 2)){
						printf("Voce nao tem autorizaçao para inserir um novo livro\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					}
					
					else{
						printf("Voce nao marcou uma opcao valida no cadastro!\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					}
					fclose(dadosUsuarios);
					
					
					
					
				case 5: // procurar por titulo
					ClearScreen();
					dadosBib = fopen("dadosBib.txt", "r");
					
					printf("Esses sao os titulos disponiveis. \n");

					while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						printf(" %s\n", book[i].titulo);
						i++;
					}
					
					printf("Digite o titulo que deseja procurar: ");
					scanf("%s", busca_titulo);
					
					teste = 0;
					
					for(i = 0; i<1000; i++){
						m = strcmp(book[i].titulo, busca_titulo);
			
						if(m == 0){
							teste = 1;
						}
					}
						
					if(teste == 1){
						printf("Titulo encontrado! Voce pode reserva-lo ou realizar um emprestimo.\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
					scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					}
					
					if(teste == 0){
					
						printf("Titulo nao encontrado.\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					
					}
					fclose(dadosBib);
					break;
					
				case 6: // procurar por autor
					
					ClearScreen();
					dadosBib = fopen("dadosBib.txt", "r");
					
					printf("Esses sao os autores disponiveis. \n");
					
					teste = 0;
					while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
					printf("%s\n", book[i].autor);
						i++;
					}
					
					printf("Digite o autor que deseja procurar: ");
					scanf("%s", busca_autor);
					i = 0;
					for(i=0;i<1000;i++){
					
						m = strcmp(book[i].autor, busca_autor);
						
						if(m == 0){
							teste = 1;
							
						}
						
					}
					fclose(dadosBib);
					dadosBib = fopen("dadosBib.txt", "r");
					if(teste == 1){
						printf("Autor encontrado!\n\n");
						
						printf("Esses sao os livros desse autor: \n\n");
						
						while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						printf(" %s\n", book[i].titulo);
						i++;
					}
						
						fscanf(dadosBib, "%s \n", book[i].titulo);
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					}
					fclose(dadosBib);
					if(teste == 0){
					
						printf("Autor nao encontrado.\n\n");
						
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					
					}
					fclose(dadosBib);
					
				case 7: // apagar livro
					
					ClearScreen();
					dadosBib = fopen("dadosBib.txt", "r");
					dadosUsuarios = fopen("dadosUsuarios.txt", "r");
					contador = 0;
					if(user[I].tipo == 3){
						i = 0;
						while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						
							contador = contador + 1;
							printf("%s. %s %s %s %s %s %s %s\n", book[i].nregistro, book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);
							i++;
							
						}
						fclose(dadosBib);
						
						// le dadosBIb e mostra pro usuario
						
						dadosBib_copy = fopen("dadosBib_copy.txt", "a");
						printf("Digite o numero relacionado ao livro que deseja excluir: ");
						scanf("%s",aux);
			
						// pergunta pro usuario o que ele quer apagar

						for(i=0; i<contador; i++){
							if(strcmp(book[i].nregistro,aux) == 0){
								continue;
							}
						
							fprintf(dadosBib_copy, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);
						}
							// copia dadosBib para a copia exceto o que o usuario quis apagar
						fclose(dadosBib_copy);
						dadosBib_copy = fopen("dadosBib_copy.txt", "r");
						dadosBib = fopen("dadosBib.txt", "w");
						
						while(fscanf(dadosBib_copy, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
							fprintf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);
							i++;
						}
						
						// escreve os dados da copia de volta em dadosBib
		
						while(fscanf(dadosBib_copy, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						
							printf("%s. %s %s %s %s %s %s %s\n", book[i].nregistro, book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);
							
						}
						
						fclose(dadosBib_copy);
						fclose(dadosBib);
						dadosBib_copy = fopen("dadosBib_copy.txt", "w");
						fclose(dadosBib_copy);
						
					}
					
					if((user[I].tipo == 1) || (user[I].tipo == 2)){
						printf("Voce nao tem autorizaçao para inserir um novo livro\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					}
					
					fclose(dadosUsuarios);
					
				case 8: // listar livros existentes na biblioteca
				
					ClearScreen();
					dadosBib = fopen("dadosBib.txt", "r");
					
					while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						contador = contador + 1;
						printf("%d. %s %s %s %s %s %s %s\n", contador, book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora);
						i++;
					}
					printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					fclose(dadosBib);
					
				case 9: // registrar data de emprestimo e devolucao de um livro
					
					ClearScreen();
					dadosUsuarios = fopen("dadosUsuarios.txt", "r");
					if(user[I].tipo == 3){
						dadosBib = fopen("dadosBib.txt", "r");
						printf("Esses sao os livros disponiveis: \n\n");
						while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
						
							printf("%s. %s %s \n", book[i].nregistro, book[i].titulo, book[i].autor);
							
						}
						fclose(dadosBib);
						emprestimos = fopen("emprestimos.txt", "r");
						
						printf("Selecione o indice do livro que deseja pegar emprestado: ");
						scanf("%s", empresta);
						
						teste_emprestimo = 0;
						
						for(i=0;i<10000;i++){
							fscanf(emprestimos, "%s", loan[i].nregistro);
							n = strcmp(loan[i].nregistro, empresta);
							if(n == 0){
								teste_emprestimo = 1;
							} // verifica se o indice do livro solicitado ja foi emprestado
						}
						fclose(emprestimos);
						emprestimos = fopen("emprestimos.txt", "a");
						if(teste_emprestimo == 1){
							printf("Desculpe! O livro ja foi emprestado.\n\n");
							printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
							scanf("%s", &v);
							
							if(v == 's'){
								printf("\n\n");
								goto LOGIN_SUCESSO;
							}
							
							if(v == 'n'){
								printf("\n\n");
								goto MENU_INICIAL;
							}
						}
						
						if(teste_emprestimo == 0){
						
								printf("Para realizar o emprestimo, preencha as informaçoes abaixo: \n\n");
								printf("Digite a data de hoje (aa/aa/aaaa): ");
								scanf("%s", loan[0].dataEmprestimo);
								printf("Digite o seu id: ");
								scanf("%s", loan[0].id);
								printf("Digite novamente o indice (numero de registro) do livro: ");
								scanf("%s", loan[0].nregistro);
								printf("Digite a data de devoluçao acrescentando uma semana a data de hoje: ");
								scanf("%s", loan[0].dataDevolucao);
								
								fprintf(emprestimos, "%s %s %s %s\n", loan[0].id, loan[0].nregistro, loan[0].dataEmprestimo, loan[0].dataDevolucao);
								// imprime os dados que acabaram de ser gerados no arquivo emprestimos
								
								printf("Emprestimo realizado com sucesso!\n\n");
							
							
						}
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
							
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
						
						fclose(emprestimos);
					}
					
					if((user[I].tipo == 1) || (user[I].tipo == 2)){
						printf("Voce nao tem autorizaçao para inserir um novo livro\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					}
					fclose(dadosUsuarios);
					
				case 10: // registrar reservas
					dadosUsuarios = fopen("dadosUsuarios.txt", "r");
					if(user[I].tipo == 3){
						ClearScreen();
						dadosBib = fopen("dadosBib.txt", "r");
						reserva = fopen("reserva.txt", "r");
						char resv[6];
						
						while(fscanf(dadosBib, "%s %s %s %s %s %s %s\n", book[i].titulo, book[i].autor, book[i].nregistro, book[i].anoPubli, book[i].ISBN, book[i].vol, book[i].editora) == 7){
							
								printf("%s. %s %s \n", book[i].nregistro, book[i].titulo, book[i].autor);
							}
						
						fclose(dadosBib);
						printf("\n\nEsses sao os livros disponiveis.");
						printf("\nDigite o indice do livro que deseja reservar: ");
						scanf("%s", resv);
						teste = 0;
						
						for(i=0;i<10000;i++){
							fscanf(reserva, "%s", reservas[i].nregistro);
							m = strcmp(reservas[i].nregistro, resv);
							if(m==0){
								teste = 1;
							}
						}
						fclose(reserva);
						reserva = fopen("reserva.txt", "a");
						if(teste == 1){
							printf("\nO livro ja foi reservado\n");
							
							printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
							scanf("%s", &v);
										
							if(v == 's'){
								printf("\n\n");
								goto LOGIN_SUCESSO;
							}
											
							if(v == 'n'){
								printf("\n\n");
								goto MENU_INICIAL;
							}
						}
						if(teste == 0){
							printf("\nDigite o seu id: ");
							scanf("%s", reservas[0].id);
							printf("Digite o numero de registro do livro: ");
							scanf("%s", reservas[0].nregistro);
										
							printf("\nO livro foi reservado para voce.\n");
							fprintf(reserva, "%s %s", reservas[0].id, reservas[0].nregistro);
							
							printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
							scanf("%s", &v);
										
							if(v == 's'){
								printf("\n\n");
								goto LOGIN_SUCESSO;
							}
											
							if(v == 'n'){
								printf("\n\n");
								goto MENU_INICIAL;
							}
						}
						
						
						
						fclose(reserva);
					}
					ClearScreen();
					if((user[I].tipo == 1) || (user[I].tipo == 2)){
						printf("Voce nao tem autorizaçao para registrar reservas\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
						
					}
					fclose(dadosUsuarios);
					
					
					
				case 11: // renovar emprestimo 
				
					ClearScreen();
					printf("Digite o indice do livro que voce quer renovar: ");
					scanf("%s", indice);
					
					emprestimos = fopen("emprestimos.txt", "r");
					teste = 0;
					i = 0;
					for(i=0;i<10000;i++){
						m = strcmp(loan[i].nregistro, indice);
						if(m==0){
							teste = 1;
							break;
						}
					}
					fclose(emprestimos);
					emprestimos = fopen("emprestimos.txt", "w");
					if(teste == 0){
						printf("Esse livro nao foi emprestado!\n\n");
						
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
						
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					}
					if(teste ==1){
						printf("Vamos renovar o seu cadastro.\n\n");
						printf("Digite o seu id: ");
						scanf("%s", renovacao[0].id);
						printf("Digite novamente o indice (numero de registro) do livro: ");
						scanf("%s", renovacao[0].nregistro);
						printf("Digite a data de hoje: ");
						scanf("%s", renovacao[0].dataRenovacao);
						printf("Digite a proxima data de devolucao acrescentando uma semana a data atual (aa/aa/aaaa): ");
						scanf("%s", renovacao[0].dataDevolucao);
						
						fprintf(emprestimos, "%s %s %s %s", renovacao[i].id, renovacao[i].nregistro, renovacao[i].dataRenovacao, renovacao[i].dataDevolucao);
						
						printf("Pronto! Seu emprestimo foi renovado!\n\n");
						printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
						scanf("%s", &v);
						
						if(v == 's'){
							printf("\n\n");
							goto LOGIN_SUCESSO;
						}
							
						if(v == 'n'){
							printf("\n\n");
							goto MENU_INICIAL;
						}
					}
					fclose(emprestimos);
					
					
				case 12:
					goto MENU_INICIAL;
			}
				
			
			
		case 2:
		
			ClearScreen();
			dadosUsuarios = fopen("dadosUsuarios.txt","a");
			
			printf("Bem vindo, vamos começar o seu cadastro\n");
			
			printf("Digite o seu email: ");
			scanf("%s",user[0].email);
			printf("\nDigite a sua senha: ");
			scanf("%s",user[0].senha);
			printf("\nDigite o seu id: ");
			scanf("%s",user[0].id);
			printf("\nDigite o seu nome: ");
			scanf("%s",user[0].nome);
			printf("\nDigite o seu curso: ");
			scanf("%s",user[0].curso);
			printf("\nDigite o seu cpf: ");
			scanf("%ld",&user[0].cpf);
			printf("\nDigite o seu tipo(docente = 1, aluno = 2, funcionario = 3): ");
			scanf("%d", &user[0].tipo);
			
			fprintf(dadosUsuarios, "%s %s %s %s %s %ld %d", user[i].email,  user[i].senha, user[i].id, user[i].nome, user[i].curso, user[i].cpf, user[i].tipo);
				
			fclose(dadosUsuarios);
			printf("Deseja realizar mais alguma operaçao? (s/n)\n\n");
			scanf("%s", &v);
					
			if(v == 's'){
				printf("\n\n");
				goto MENU_INICIAL;
			}
							
			if(v == 'n'){
				exit(0);
			}
			
		case 3:
			exit(0);
			
	}
}

