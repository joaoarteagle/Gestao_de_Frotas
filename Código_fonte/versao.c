#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>


#define TAM_VET 10 //quantidade limite de vetores de estruturas
#define TAM_STR 80 //quantidade limite de caracteres de strings
#define VALIDAR_SIMNAO(w) w != 'S' && w != 'N'
#define VALIDAR_MINUSC(w) w >= 'a' && w <= 'z'
   
   void mostrarResultado(int A); 	   //prot�tipo
   void desejaRetorno(int A, char *B); //prot�tipo
   char letraMaiusc(char A); 		   //prot�tipo
   
   char simnao,           //decis�o (sim/n�o)
   		codigo[11];       //c�digo digitado por algum usu�rio
   int decisao,           //decisao de algum usu�rio
	   erro,              //contador de erros para bloquear o acesso do administrador
	   quantVeiculo = 0,  //quantidade de ve�culos no programa
	   quantMotorista = 0,//quantidade de motoristas no programa
	   *pV = &quantVeiculo,//ponteiro apontado pra qua ntVeiculo
	   *pM = &quantMotorista;//ponteiro apontado pra quantMotorista
   const char codAdm[11] = {"prefeitura"}; //c�digo de acesso do administrador
   
   struct veiculos{
  	char nomeVeiculo[TAM_STR];  //nomes dos ve�culos
   	char marcaVeiculo[TAM_STR]; //marcas dos ve�culos
   	char modeloVeiculo[TAM_STR];//modelos dos ve�culos
   	float quilVeiculo;      //quilometragem dos ve�culos
   	int idadeVeiculo;       //idade dos ve�culos
	bool dispVeiculo;       //disponibilidade do ve�culo
	char codVeiculo[4];		//c�digo individual do ve�culo
	
   };
   
   struct motoristas{
   	char loginMotorista[TAM_STR];//login de acesso do motorista
   	char senhaMotorista[TAM_STR];//senha de acesso do motorista
   	char emailMotorista[TAM_STR];//e-mail do motorista
   	char nomeMotorista[TAM_STR]; //nome do motorista
   	int idadeMotorista;      //idade do motorista
   	bool dispMotorista;      //disponibilidade do acesso do motorista
   	char codMotorista[4];	 //c�digo individual do motorista
   };
   
   struct veiculos veiculo[TAM_VET];//estrutura criada
   struct motoristas motorista[TAM_VET];//estrutura criada
   
   
   
//Programa principal...
int main(){
		setlocale(LC_ALL,"Portuguese");
		printf(" _______  _______  _       _________ _______  _______  _        _______\n"); 
		printf("(  ____ \\(  ___  )( (    /|\\__   __/(  ____ )(  ___  )( \\      (  ____ \\ \n");  
		printf("| (    \\/| (   ) ||  \\  ( |   ) (   | (    )|| (   ) || (      | (    \\/\n");  
		printf("| |      | |   | ||   \\ | |   | |   | (____)|| |   | || |      | (__\n");     
		printf("| |      | |   | || (\\ \\) |   | |   |     __)| |   | || |      |  __)\n");     
		printf("| |      | |   | || | \\   |   | |   | (\\ (   | |   | || |      | (\n");        
		printf("| (____/\\| (___) || )  \\  |   | |   | ) \\ \\__| (___) || (____/\\| (____/\\ \n");  
		printf("(_______/(_______)|/    )_)   )_(   |/   \\__/(_______)(_______/(_______/\ \n");  
                                                                          
		printf(" ______   _______\n");                                                       
		printf("(  __  \\ (  ____ \\ \n");                                                        
		printf("| (  \\  )| (    \\/\n");                                                        
		printf("| |   ) || (__ \n");                                                           
		printf("| |   | ||  __)\n");                                                           
		printf("| |   ) || (   \n");                                                           
		printf("| (__/  )| (____/\\ \n");                                                        
		printf("(______/ (_______/\n");                                                        
                                                                          
		printf(" _______  _______  _______ _________ _______  _______ \n");                    
		printf("(  ____ \\(  ____ )(  ___  )\\__   __/(  ___  )(  ____ \\ \n");                    
		printf("| (    \\/| (    )|| (   ) |   ) (   | (   ) || (    \\/\n");                    
		printf("| (__    | (____)|| |   | |   | |   | (___) || (_____ \n");                    
		printf("|  __)   |     __)| |   | |   | |   |  ___  |(_____  )\n");                    
		printf("| (      | (\\ (   | |   | |   | |   | (   ) |      ) |\n");                    
		printf("| )      | ) \\ \\__| (___) |   | |   | )   ( |/\\____) |\n");                    
		printf("|/       |/   \\__/(_______)   )_(   |/     \\|\\_______)\n\n");
		system("pause");
		system("cls");     		
    	simnao = 'S';//simnao atribui o valor de 's' para entrar no la�o
    	while(simnao == 'S'){
    		simnao = 'Z';//simnao atribui um caractere aleat�rio para evitar conflitos com o uso desta vari�vel novamente
    		decisao = 0;//decisao atribui um inteiro aleat�rio para evitar conflitos com o uso desta vari�vel novamente
    		erro = 0;//erro atribui um inteiro aleat�rio para evitar conflitos com o uso desta vari�vel novamente
    		strcpy(codigo,"AAA");//string "codigo" atribui um valor aleat�rio para evitar conflitos com o uso desta vari�vel novamente
    		while(decisao != 2 && decisao != 1){
	  	    	printf("Digite 1 p/ iniciar como Administrador\n");
	    		printf("Digite 2 p/ iniciar como Motorista\n");
	  			scanf("%i",&decisao);
	    		fflush(stdin);
	    		system("cls");	 
    		} 
   		 /*permiss�o adm*/	
    		if(decisao == 1){ 
				decisao = 0; 
    			while(erro < 3 && (strcmp(codigo,codAdm)) != 0){
    				if(erro != 0){
    					printf("Quantidade de erros: %i\n",erro);
					}
    				printf("Digite o c�digo do administrador: ");
    				fgets(codigo,11,stdin);
    				fflush(stdin);
    				erro++;
    				system("cls");
 	     		}
    	    
    	    	/*acesso liberado para o adm*/
    			if((strcmp(codigo,codAdm)) == 0){
    				system("cls");
    				printf("Acesso liberado\n\n");
    				system("pause");
    		
            		/*atividades do adm*/
    				while(decisao<1||decisao>5){
        				system("cls");
            			printf("Digite 1 - Registrar veiculos\n");
            			printf("Digite 2 - Verificar veiculos registrados\n");
            			printf("Digite 3 - Verificar cadastros efetuados\n");
            			printf("Digite 4 - Excluir/Bloquear veiculos\n");
            			printf("Digite 5 - Excluir/Bloquear motoristas\n");
            			scanf("%i",&decisao);
            			fflush(stdin);     			
    				/*cadastrando veiculos*/
    				switch(decisao){
    					case 1:
							do{	
    							system("cls");
								printf("Atualmente, o programa possui %i ve�culo(s) registrado(s)\n\n",*pV);
    							printf("Vaga%i - Informe o nome do ve�culo: ",*pV+1);
    							fgets(veiculo[*pV].nomeVeiculo,TAM_STR,stdin);
    							fflush(stdin);
    							printf("Vaga%i - Informe a marca do ve�culo: ",*pV+1);
    							fgets(veiculo[*pV].marcaVeiculo,TAM_STR,stdin);
    							fflush(stdin);
    							printf("Vaga%i - Informe o modelo do ve�culo: ",*pV+1);
    							fgets(veiculo[*pV].modeloVeiculo,TAM_STR,stdin);
    							fflush(stdin);
    							printf("Vaga%i - Informe a quilometragem do ve�culo: ",*pV+1);
    							scanf("%f",&veiculo[*pV].quilVeiculo);
    							fflush(stdin);
    							printf("Vaga%i - Informe a idade do ve�culo: ",*pV+1);
    							scanf("%i",&veiculo[*pV].idadeVeiculo);
    							fflush(stdin);
    							system("cls");
    							if (veiculo[*pV].idadeVeiculo > 10){
    								strcpy(veiculo[*pV].nomeVeiculo,"");
    								strcpy(veiculo[*pV].marcaVeiculo,"");
    								strcpy(veiculo[*pV].modeloVeiculo,"");
    								veiculo[*pV].quilVeiculo = 0;
    								veiculo[*pV].idadeVeiculo = 0;
    								veiculo[*pV].dispVeiculo = 0;
    								printf("O ve�culo n�o p�de ser cadastrado porque possui idade superior � 10 anos\n");
    								system("pause");
    								system("cls");
    								desejaRetorno(6,&simnao);
    								if(simnao == 'S'){
    									printf("Ve�culo encaminhado para o leil�o\n");
									}
								}else{
									printf("Ve�culo cadastrado com sucesso!\n");
									printf("Gerando c�digo do ve�culo...\n\n");
									sprintf(veiculo[*pV].codVeiculo,"00%i",*pV+1);
									veiculo[*pV].dispVeiculo = 1;
									quantVeiculo += 1;
									system("pause");
								}
								system("cls");
                   			    desejaRetorno(1,&simnao);
							}while(simnao == 'S' || simnao == 's');
                   				system("cls");
								simnao = 'z';//valor aleat�rio
    						break;
    					case 2:
    						mostrarResultado(1);
    						system("pause");
    						system("cls");
    						break;
    					case 3:
    						mostrarResultado(2);
    						system("pause");
    						system("cls");
    						break;
    					case 4:
    						do{
    							system("cls");
    							printf("Digite 1 - Bloquear Veiculo\n");
    							printf("Digite 2 - Excluir Veiculo\n");
    							scanf("%i",&decisao);
    							fflush(stdin);
    							system("cls");
							}while(decisao < 1||decisao > 2);
							if(*pV == 0){
								system("cls");
								printf("O programa n�o possui ve�culos cadastrados\n");
								system("pause");
							}else{
								if(decisao == 1){
									do{
										do{
											mostrarResultado(1);
											printf("Informe o n�mero da vaga de ve�culo que voc� deseja bloquear: ");
											scanf("%i",&decisao);
											fflush(stdin);
											system("cls");
										}while(decisao < 1 || decisao > *pV);
										do{
											printf("Bloqueio de ve�culo\n\n");
											printf("- Nome do ve�culo: %s- C�digo: %s",veiculo[decisao-1].nomeVeiculo,
																		  			   veiculo[decisao-1].codVeiculo);
											printf("\n\nTem certeza que deseja bloquear este ve�culo?\n");
											scanf("%c",&simnao);
											fflush(stdin);
											simnao = letraMaiusc(simnao);
											system("cls");
										}while(VALIDAR_SIMNAO(simnao));
										if(simnao == 'S'){
											veiculo[decisao-1].dispVeiculo = 0;
											printf("Ve�culo bloqueado com sucesso!\n\n");
											system("pause");	
											mostrarResultado(1);
											system("pause");
										}
										system("cls");
										desejaRetorno(4,&simnao);
										system("cls");
									}while(simnao == 'S');
							}else if(decisao == 2){
								do{
									if(*pV == 0){
										printf("N�o h� carros para excluir\n\n");
										simnao = 'N';
										system("pause");
										system("cls");
									}else{
										do{
											mostrarResultado(1);
											printf("Informe o n�mero da vaga de ve�culo que voc� deseja excluir: ");
											scanf("%i",&decisao);
											fflush(stdin);
											system("cls");
										}while(decisao < 1 || decisao > *pV);
										do{
											printf("Excluir ve�culo\n\n");
											printf("- Nome do ve�culo: %s- C�digo: %s",veiculo[decisao-1].nomeVeiculo,
																		  			   veiculo[decisao-1].codVeiculo);
											printf("\n\nTem certeza que deseja excluir este ve�culo?\n");
											scanf("%c",&simnao);
											fflush(stdin);
											simnao = letraMaiusc(simnao);
											system("cls");
										}while(VALIDAR_SIMNAO(simnao));
										if(simnao == 'S'){
											strcpy(veiculo[decisao-1].nomeVeiculo,"");
    										strcpy(veiculo[decisao-1].marcaVeiculo,"");
    										strcpy(veiculo[decisao-1].modeloVeiculo,"");
    										strcpy(veiculo[decisao-1].codVeiculo,"");
    										veiculo[decisao-1].quilVeiculo = 0;
    										veiculo[decisao-1].idadeVeiculo = 0;
    										veiculo[decisao-1].dispVeiculo = 0;
    										quantVeiculo -= 1;
											printf("Ve�culo excluido com sucesso!\n\n");	
											system("pause");	
											mostrarResultado(1);
											system("pause");
										}
										system("cls");
										desejaRetorno(5,&simnao);
										system("cls");	
									}
								}while(simnao == 'S');	
							}
						}
    						break;
    					case 5:
    						do{
    							system("cls");
    							printf("Digite 1 - Bloquear Motorista\n");
    							printf("Digite 2 - Excluir Motorista\n");
    							scanf("%i",&decisao);
    							fflush(stdin);
    							system("cls");
							}while(decisao < 1||decisao > 2);
							if(*pM == 0){
								system("cls");
								printf("O programa n�o possui motoristas cadastrados\n");
								system("pause");
							}else{
								if(decisao == 1){
									do{
										do{
											mostrarResultado(2);
											printf("Informe o digito do motorista que voc� deseja bloquear: ");
											scanf("%i",&decisao);
											fflush(stdin);
											system("cls");
										}while(decisao < 1 || decisao > *pM);
										do{
											printf("Bloqueio de motorista\n\n");
											printf("- Nome do motorista: %s- C�digo: %s",motorista[decisao-1].nomeMotorista,
																		  			     motorista[decisao-1].codMotorista);
											printf("\n\nTem certeza que deseja bloquear este motorista?\n");
											scanf("%c",&simnao);
											fflush(stdin);
											simnao = letraMaiusc(simnao);
											system("cls");
										}while(VALIDAR_SIMNAO(simnao));
										if(simnao == 'S'){
											motorista[decisao-1].dispMotorista = 0;
											printf("Motorista bloqueado com sucesso!\n\n");
											system("pause");	
											mostrarResultado(2);
											system("pause");
										}
										system("cls");
										desejaRetorno(4,&simnao);
										system("cls");
									}while(simnao == 'S');
								}else if(decisao == 2){
									do{
										if(*pM == 0){
											printf("N�o h� motoristas para excluir\n\n");
											simnao = 'N';
											system("pause");
											system("cls");
										}else{
											do{
												mostrarResultado(2);
												printf("Informe o digito do motorista que voc� deseja excluir: ");
												scanf("%i",&decisao);
												fflush(stdin);
												system("cls");
											}while(decisao < 1 || decisao > *pM);
											do{
												printf("Excluir motorista\n\n");
												printf("- Nome do motorista: %s- C�digo: %s",motorista[decisao-1].nomeMotorista,
																		  			         motorista[decisao-1].codMotorista);
												printf("\n\nTem certeza que deseja excluir este motorista?\n");
												scanf("%c",&simnao);
												fflush(stdin);
												simnao = letraMaiusc(simnao);
												system("cls");
											}while(VALIDAR_SIMNAO(simnao));
											if(simnao == 'S'){
												strcpy(motorista[*pM].emailMotorista,"");
												strcpy(motorista[*pM].loginMotorista,"");
												strcpy(motorista[*pM].senhaMotorista,"");
												strcpy(motorista[*pM].nomeMotorista,"");
												motorista[*pM].idadeMotorista = 0;
    											motorista[*pM].dispMotorista = 0;
    											quantMotorista -= 1;
												printf("Motorista excluido com sucesso!\n\n");	
												system("pause");	
												mostrarResultado(2);
												system("pause");
											}
											system("cls");
											desejaRetorno(5,&simnao);
											system("cls");	
										}
									}while(simnao == 'S');	
    							}	
    							break;
							}
						}
					}
    			}else{
    				printf("Acesso negado. Digitou o c�digo errado tr�s vezes\n\n");
    				system("pause");
    			}
    		}else if(decisao==2){
    			//acesso do motorista
    			decisao = 0;
    			while(decisao<1||decisao>3){
    				printf("Digite 1 - Cadastrar Motorista\n");
    				printf("Digite 2 - Visualizar Veiculos\n");
    				printf("Digite 3 - Reservar Ve�culo\n");
    				scanf("%i",&decisao);    	
    				fflush(stdin);
    				system("cls");
				}
				switch(decisao){
					case 1:
						do{
						printf("Tela de cadastro\n\n");
						printf("Informe o seu email: ");
						fgets(motorista[*pM].emailMotorista,TAM_STR,stdin);
						fflush(stdin);
						printf("Informe o login: ");
						fgets(motorista[*pM].loginMotorista,TAM_STR,stdin);
						fflush(stdin);
						printf("Informe a senha: ");
						fgets(motorista[*pM].senhaMotorista,TAM_STR,stdin);
						fflush(stdin);
						printf("Informe o seu nome: ");
						fgets(motorista[*pM].nomeMotorista,TAM_STR,stdin);
						fflush(stdin);
						do{
							printf("Informe a sua idade: ");
							scanf("%i",&motorista[*pM].idadeMotorista);
							fflush(stdin);
							if(motorista[*pM].idadeMotorista < 18){
								system("cls");
								printf("!!! ERRO !!!\n");
								printf("Idade insuficiente\n\n");
								system("pause");
								system("cls");
								mostrarResultado(3);
							}else if(motorista[*pM].idadeMotorista > 99){
								system("cls");
								printf("!!! ERRO !!!\n");
								printf("Idade inv�lida\n\n");
								system("pause");
								system("cls");
								mostrarResultado(3);
							}
						}while(motorista[*pM].idadeMotorista < 18 || motorista[*pM].idadeMotorista > 99);
						/*do{
							printf("Informe o seu sexo: ");
							scanf("%c",&sexoMotorista[*pM]);
							fflush(stdin);
							if(sexoMotorista[*pM] == 'f'){
								sexoMotorista[*pM] = 'F';	
							}else if(sexoMotorista[*pM] == 'm'){
								sexoMotorista[*pM] = 'M';
							}
							if(sexoMotorista[*pM] != 'F' || sexoMotorista[*pM] != 'M'){
								system("cls");
								printf("!!! ERRO !!!\n");
								printf("Sexo inv�lido\n\n");
								system("pause");
								system("cls");
								mostrarResultado(3);	
							}	
						}while(sexoMotorista[*pM] != 'F' || sexoMotorista[*pM] != 'M');
						*/
						printf("Possui carteira de habilita��o? ");
						scanf("%c",&simnao);
						fflush(stdin);
						simnao = letraMaiusc(simnao);
						system("pause");
						system("cls");
						if(simnao == 'N'){
							printf("O cadastro n�o p�de ser realizado porque voc� n�o atende as exig�ncias\n\n");
							strcpy(motorista[*pM].emailMotorista,"");
							strcpy(motorista[*pM].loginMotorista,"");
							strcpy(motorista[*pM].senhaMotorista,"");
							strcpy(motorista[*pM].nomeMotorista,"");
							motorista[*pM].idadeMotorista = 0;
							system("pause");
							system("cls");
							desejaRetorno(2,&simnao);
						}else{
							printf("O cadastro foi realizado com sucesso\n");
							printf("Gerando c�digo do motorista...\n\n");
							sprintf(motorista[*pM].codMotorista,"00%i",*pM+1);
							motorista[*pM].dispMotorista = 1;
							quantMotorista += 1;
							simnao = 'N';
							system("pause");
						}
						system("cls");
					}while(simnao == 'S');
						break;
					case 2:
						//se o motorista escolher a op��o 2 ou 3 e n�o tiver carros registrados, ent�o aparece a mensagem/erro
						if(*pV == 0){
							printf("N�o h� ve�culos registrados\n\n");
							system("pause");	
						}else{
							mostrarResultado(1);
    						system("pause");
    						system("cls");	
						}
						break;
					case 3:
						if(*pV != 0){
							do{
								mostrarResultado(1);
								printf("Informe o n�mero da vaga de ve�culo que voc� deseja reservar: ");
								scanf("%i",&decisao);
								fflush(stdin);
								system("cls");
							}while(decisao < 1 || decisao > *pV);
								if (veiculo[decisao-1].dispVeiculo == 0){
									printf("O veiculo n�o p�de ser reservado, pois ele est� indispon�vel\n\n");
									system("pause");	
								}else{
									veiculo[decisao-1].dispVeiculo = 0;
									//incompleto; Na hora de reservar tem que inserir a hora para ficar registrado no hist�rico de reservas
									printf("Ve�culo reservado com sucesso!\n\n");
									system("pause");	
									mostrarResultado(1);
									system("pause");
								}
						}else{
							printf("N�o h� ve�culos registrados\n\n");
							system("pause");
						}
						break;
				}
			}
		system("cls");
		desejaRetorno(3,&simnao);
		system("cls");
		}
		return 0;
}

void mostrarResultado(int A){
   	//procedimento para mostrar o resultado dos cadastros (ve�culos / motoristas)
   		system("cls");
   		switch(A){
   			case 1:
   				printf("Atualmente, o programa possui %i ve�culo(s) registrado(s)\n\n",*pV);
				for (int i = 0; i<*pV; i++){
    				printf("Vaga%i - Nome do ve�culo:   %s",i+1,veiculo[i].nomeVeiculo);
    				printf("Vaga%i - Marca do ve�culo:  %s",i+1,veiculo[i].marcaVeiculo);
    				printf("Vaga%i - Modelo do ve�culo: %s",i+1,veiculo[i].modeloVeiculo);
    				printf("Vaga%i - Quilometragem:   %f\n",i+1,veiculo[i].quilVeiculo);
    				printf("Vaga%i - Idade do ve�culo:  %i Anos\n",i+1,veiculo[i].idadeVeiculo);
    				printf("Vaga%i - C�digo do ve�culo: %s\n",i+1,veiculo[i].codVeiculo);
    				printf("Vaga%i - Status do ve�culo: ",i+1);
    				if (veiculo[i].dispVeiculo == 1){
    					printf("Dispon�vel\n\n");
					}else{
						printf("Indispon�vel\n\n");
					}
    			}
   				break;
   			case 2:
   				printf("Atualmente, o programa possui %i motorista(s) cadastrado(s)\n\n",*pM);
   				for (int i = 0; i<*pM; i++){
   					printf("Motorista%i - Nome: %s",i+1,motorista[i].nomeMotorista);
   					printf("Motorista%i - Idade: %i Anos\n",i+1,motorista[i].idadeMotorista);
   					//printf("Motorista%i - Sexo: %c\n",i+1,sexoMotorista[i]);
   					printf("Motorista%i - Email: %s",i+1,motorista[i].emailMotorista);
   					printf("Motorista%i - C�digo do motorista: %s\n",i+1,motorista[i].codMotorista);
   					printf("Motorista%i - Status do acesso: ",i+1);
    				if (motorista[i].dispMotorista == 1){
    					printf("Dispon�vel\n\n");
					}else{
						printf("Indispon�vel\n\n");
					}
				}
   				break;
   			case 3:
   				printf("Tela de cadastro\n\n");
				printf("Informe o seu email: %s",motorista[*pM].emailMotorista);
				printf("Informe o login: %s",motorista[*pM].loginMotorista);
				printf("Informe a senha: %s",motorista[*pM].senhaMotorista);
				printf("Informe o seu nome: %s",motorista[*pM].nomeMotorista);
				if (motorista[*pM].idadeMotorista >= 18 && motorista[*pM].idadeMotorista <= 99){
					printf("Informe a sua idade: %i\n",motorista[*pM].idadeMotorista);	
				}
   				break;
   			case 4:
   				
   				break;
		   }			 	
   }
   
void desejaRetorno(int A, char *B){
	//procedimento para perguntas ao usu�rio
	switch(A){
		case 1:
			do{
				printf("Deseja cadastrar mais ve�culos? (S/N):\n");
               	scanf("%c",&*B);
               	fflush(stdin);
               	*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
			break;
		case 2:
			do{
				printf("Deseja tentar novamente? (S/N)\n");
				scanf("%c",&*B);
				fflush(stdin);
				*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
				break;
		case 3:
			do{
				printf("Deseja retornar ao menu principal do programa? (S/N)\n");
				scanf("%c",&*B);
				fflush(stdin);
				*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
			break;
		case 4:
			do{
				printf("Deseja retornar ao menu de bloqueio? (S/N)\n");
				scanf("%c",&*B);
				fflush(stdin);
				*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
			break;
		case 5:
			do{
				printf("Deseja retornar ao menu de exclus�o? (S/N)\n");
				scanf("%c",&*B);
				fflush(stdin);
				*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
			break;
		case 6:
			do{
				printf("Deseja encaminh�-lo para o leil�o? (S/N):\n");
				scanf("%c",&*B);
				fflush(stdin);
				*B = letraMaiusc(*B);
				system("cls");
			}while(VALIDAR_SIMNAO(*B));
			break;
		}	
	}
char letraMaiusc (char x){
	if(VALIDAR_MINUSC(x)){
		return x-32;
	}else{
		return x;
	}
	
}