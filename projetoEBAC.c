//Adiciona bibliotecas

#include <stdio.h> //b. de comunicao com o usuario	
#include <stdlib.h> //b. de alocacao de espaco na memoria
#include <locale.h> //b. de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel da string

int registro() //Funcao responsavel por cadastrar osusuarios no sistemas
{
		//inicio criacao de variaveis/string
		char arquivo[40];
		char cpf[11];
		char nome[40];
		char sobrenome[40];	
		char cargo [40];
		//final criacao de variaveis/string
		
		////////////////////////////////////////////////////
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf); //%s = string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
		
		FILE *file; // cria o arquivo 
		file = fopen(arquivo, "w"); // cria o arquivo "w = escrever"
		fprintf(file, cpf); // salvo o valor da variavel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a");	
		fprintf(file, ",");
		fclose(file);
		
		//////////////////////////////////////////////////////
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");	
		fprintf(file, ",");
		fclose(file);
		
		//////////////////////////////////////////////////////
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");	 
		fprintf(file, ",");
		fclose(file);		
	
		//////////////////////////////////////////////////////
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file=fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		file = fopen(arquivo, "a");	 
		fprintf(file, ",");
		fclose(file);
		
		system("pause");
		
					
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar este CPF! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usuário não existe ou já foi deletado!\n");
			system("pause");
		}
	
		
}

int main()
{
	int opcao=0; //Colocando variavel
	int laco=1;
	
	char senha[10]="a";
	int comparacao;
	
	printf("### Cartório EBAC ###\n\n");
	printf("LOGIN CARTÓRIO EBAC!\n\n\nDigite sua senha:");
	scanf("%s", senha);
	
	comparacao = strcmp(senha, "admin");

	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); ///definindo linguagem para fucionar acentos
	
			printf("### Cartório EBAC ###\n\n" );
			printf("Escolha a opção que deseja do menu:\n\n");
			printf("\t1- Resgistrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n\n");
			printf("\t4- Sair do progrma\n\n");
			printf("Opção: "); 	//Fim
			
			scanf("%d" , &opcao); //Pausa para escolha de opcao
			system("cls"); //Limpa a tela
			
			switch(opcao) //inicio da selecao de menu
			{
				case 1:		
				registro(); //chamada de funcoes
				break;
				
				case 2:	
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("A equipe ****** agradece a preferência.");
				return 0;
				break;
				
				default:
				printf("Escolha uma das opções apresentadas!\n"); //Precaucao de erro
				system("pause");
				break;	
			}
		}
	}
	else	
		printf("Senha incorreta!");
			
}


