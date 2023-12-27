#include <stdio.h> //biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca que armazena as strings
  
  int registro()//responsavel por cadastrar o usuario no sistema
  {
  	//inicio da cria��o de variaveis/strings
  	
  	char arquivo[40];
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
  	char cargo[40];
  	
  	//final da cria��o de variaveis/strings
  	
  	printf("Digite o cpf a ser cadastrado:\n");//coletando informa��es dos usu�rios
	scanf("%s", cpf);// %s se refere ao armazenamento em uma string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file;//cria o qrquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo, w significa write (escrever)
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
  	
  	file = fopen(arquivo, "a");//abre o arquivo e atualiza as informa��es
  	fprintf(file, ",");//a virgula � usada para separar com virgula as informa��es
  	fclose(file);//fclose sempre fecha o arquivo
  	
  	printf("Digite o nome a ser cadastrado: ");
  	scanf("%s", nome);
  	
  	file = fopen(arquivo, "a");
  	fprintf(file,nome);
  	fclose(file);
  	
  	file = fopen(arquivo, "a");
  	fprintf(file, ",");
  	fclose(file);
  	
  	printf("Digite o sobrenome a ser cadastrado:\n ");
  	scanf("%s", sobrenome);
  	
  	file = fopen(arquivo, "a");
  	fprintf(file,sobrenome);
  	fclose(file);
  	
  	file = fopen(arquivo, "a");
  	fprintf(file, ",");
  	fclose(file);
  	
  	printf("Digite o cargo a ser cadastrado: ");
  	scanf("%s", cargo);
  	
  	file = fopen(arquivo, "a");
  	fprintf(file,cargo);
  	fclose(file);
  	
  	system("pause");//pausa o systema e vita que ele apague rapidamente
  	
 
  }
  
  int consulta()
  {
    setlocale (LC_ALL,"Portuguese"); //definindo a linguagem
    
  	char cpf[40];
  	char conteudo[200];
  	
  	printf("Digite o cpf a ser cadastrado: ");
  	scanf("%s", cpf);
  	
  	FILE *file;//chama o arquivo 
  	file = fopen(cpf,"r");
  	
  	if(file == NULL)//diz para o computador o que fazer quando o dado � nulo
  	{
  		printf("N�o foi possivel abrir o arquivo, usuario n�o encontrado!\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio:");
    	printf("%s", conteudo);
    	printf("\n\n");//pula linha 
	}
  	
	system("pause");
  }
  
  int deletar()
  {
  	 char cpf[40];
  	 
  	 printf("Digite o CPF do usu�rio a ser deletado: ");
  	 scanf("%s", cpf); 
  	 
  	 remove(cpf);//deleta o arquivo
  	 
  	 FILE *file;
  	 file = fopen(cpf, "r");
  	 
  	 if(file == NULL)
  	 {
  	 	printf("O usu�rio foi deletado do sistema!.\n ");
   	}
   	system("pause");
  	 
  }
  
  int main()
  {
	     
        int opcao=0;// definindo vari�veis
        int laco=1;
        char senhadigitada[40]= "a";
        int comparacao;
       
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Login do administrador.\n\nDigite a senha de acesso:");
        scanf("%s",senhadigitada);
        
        comparacao = strcmp(senhadigitada, "adimin");
       
        if(comparacao == 0)
        {
        	system("cls");
        	for(laco=1;laco=10;)
           {
	     
	          system("cls");//usado para limpar a tela
	     
             setlocale (LC_ALL,"Portuguese"); //definindo a linguagem
        
    	      printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
    	      printf("Escolha a op��o desejada do menu abaixo:\n");
    	      printf("\t1- Registrar nomes\n");
	          printf("\t2- Consultar nomes\n");
    	      printf("\t3- Deletar nomes\n\n"); 
    	      printf("\t4- Sair do sistema?\n\n");
	          printf("Op��o:");//Fim do menu
	    
	         scanf("%d", &opcao);// armazenando a escolha do usu�rio
	    
	         system("cls");
	     
	         switch(opcao)
	          {
	               case 1://chama a fun��o
	               registro();
	               break;//encerra
	     	
	     	       case 2:
	     	       consulta();
		           break;
			
		        	case 3:
		        	deletar();
			        break;
			        
			        case 4:
		        	printf("Obrigada por usar nosso sistema!");
		        	return 0;
		        	break;
			
		           default:
			       printf("Esta op��o n�o est� disponivel! Tente novamente\n");
			       system("pause");
			       break;
				
		 
		        }
		    } 
	   
           
         }
         
         else
         printf("Senha incorreta");
   }

