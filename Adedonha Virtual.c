#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>  // biblioteca de local usada para chamar o setclocale no codigo
#include <time.h>
#define TAM 20

// Estrutura que cria a ficha do jogo e declara??o das vari?veis

struct ficha_resposta {
	char v_nome[TAM]; 
	char v_pais[TAM];
	char v_animal[TAM];
	char v_objeto[TAM];
	char v_fruta[TAM];
	char v_cor[TAM];
	char v_profissao[TAM];
};

// Cria??o da resposta do tipo ficha_resposta 

struct ficha_resposta resposta[10];

void inicializacao () {
    printf ("================================================================================\n");
    printf ("==                                                                            ==\n");
    printf ("==                         JOGO ADEDONHA VIRTUAL			      ==\n");
    printf ("==                                                                            ==\n");
    printf ("================================================================================\n\n");
}

void intrucoes() {
    printf ("=========================================================================================================\n");
    printf ("==                                                                                            		==\n");
    printf ("==                                                                                             		==\n");
    printf ("==                 INSTRU??ES DO JOGO ADEDONHA VIRTUAL		                         					==\n");
	printf ("== 																									==\n");
    printf ("==   *  Para jogar, inicialmente voc? precisa informar a quantidade de participantes;       		==\n");
    printf ("==   *  O progrmama sortear? a letra que os joadores dever?o preencher sua lista;              		==\n");
    printf ("==   *  Cada jogador responder? sua lista, que possui as seguintes itens:                      		==\n");
    printf ("==	    	|   NOME       |                                                                    	==\n");
    printf ("== 	    |   PAIS       |                                                                   		==\n");
    printf ("==     	|   ANIMAL     |                                                                    		==\n");
    printf ("==     	|   OBJETO     |                                                                    		==\n");
    printf ("==     	|   FRUTA      |                                                                    		==\n");
    printf ("==     	|   COR        |                                                                    		==\n");
    printf ("==     	|   PROFISS?O  |                                                                    		==\n");
    printf ("==   Pontua??oo:                                                                               		==\n");
    printf ("==     -> Se dois ou mais jogadores respoderem a mesma resposta pa o mesmo item, recebera 5 pontos   	==\n");
    printf ("==     -> Se responder o item sem repeti??o, receber? 10 pontos                                		==\n");
    printf ("==   Pontua??o m?xima: 70 PONTOS                                                               		==\n");
    printf ("==                                                                                             		==\n");
    printf ("=========================================================================================================\n\n");
}

// Procediemnto que realiza o sorteio da letra para cada jogada

void random_ (){
    int i = 0;
    char letra [27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q','R', 'S', 'T', 'U','V','W','Y', 'Z','X'};
    char letra_escolhida;
    srand((unsigned) time(NULL));
    
    printf ("Sorteando letra...\n\n");
    
    i = 1 + rand() % 27; 
   /* printf ("Posi??o escolhida: %d\n", i); */
    
    letra_escolhida = letra[i];
    printf ("Letra escolhida: %c\n\n", letra_escolhida);
    printf ("================================================================================\n\n");
    
    getch();
}

// Procediemnto que inicializa a struct

void start_estrutura(){ 
    int i;
    
    for (i=0; i<10; i++){ 
        strcpy(resposta[i].v_nome, "\0");
        strcpy(resposta[i].v_pais, "\0");
        strcpy(resposta[i].v_animal, "\0");
        strcpy(resposta[i].v_objeto, "\0");
        strcpy(resposta[i].v_fruta, "\0");
        strcpy(resposta[i].v_cor, "\0");
        strcpy(resposta[i].v_profissao, "\0");
    }
}

// Procedimento utilizado para realizar o preenchimento da tabela do jogo

void jogo ( int jogador){
    
    setlocale(LC_ALL,"Portuguese");
	char Nome[TAM], Pais[TAM], Animal[TAM], Objeto[TAM], Fruta[TAM], Cor[TAM], Profissao[TAM];
    
    printf("\n? a vez do jogador %d ! \n", jogador);
    printf("\nAgora preencha a tabela com suas respostas : \n\n");
    printf("|   ITEM       |   RESPOSTA   \n");
    printf("|   NOME       |   ");
    scanf("%s", Nome); 
    printf("|   PAIS       |   ");
    scanf("%s", Pais); 
    printf("|   ANIMAL     |   ");
    scanf("%s", Animal); 
    printf("|   OBJETO     |   ");
    scanf("%s", Objeto); 
    printf("|   FRUTA      |   ");
    scanf("%s", Fruta); 
    printf("|   COR        |   ");
    scanf("%s", Cor); 
    printf("|   PROFISS?O  |   ");
    scanf("%s", Profissao); 
    
    strcpy(resposta[jogador].v_nome, Nome);
    strcpy(resposta[jogador].v_pais, Pais);
    strcpy(resposta[jogador].v_animal, Animal);
    strcpy(resposta[jogador].v_objeto, Objeto);
    strcpy(resposta[jogador].v_fruta, Fruta);
    strcpy(resposta[jogador].v_cor, Cor);
    strcpy(resposta[jogador].v_profissao, Profissao);

    printf ("================================================================================\n\n");
}

void respostas(int qt_jogadores){   // qt_jogadores --> representa a quantidade de jogadores
    
    int i;
    printf ("\n\n================================================================================\n\n");
    printf ("\n\n             RESULTADO DO JOGO          \n\n");
    
    // la?o que imprime as respotas dos jogadores
    for (i=1; i<=qt_jogadores; i++){ 
        
        printf ("Respostas do jogador %d \n", i);
        printf ("================================================================================\n\n");
        printf("| NOME      | %s |\n",resposta[i].v_nome);
        printf("| PAIS      | %s |\n",resposta[i].v_pais);
        printf("| ANIMAL    | %s |\n",resposta[i].v_animal);
        printf("| OBJETO    | %s |\n",resposta[i].v_objeto);
        printf("| FRUTA     | %s |\n",resposta[i].v_fruta);
        printf("| COR       | %s |\n",resposta[i].v_cor);
        printf("| PROFISSAO | %s |\n",resposta[i].v_profissao);
        printf ("================================================================================\n\n");
    }
}

// Procediemnto para valida??o dos resultados dos jogadores

void validacao(int qt_jogadores){
    
    int i, j;
    int pontuacao [qt_jogadores];
    int flag_nome = 0;
    int flag_pais = 0;
    int flag_animal = 0;
    int flag_objeto = 0;
    int flag_fruta = 0;
    int flag_cor = 0;
    int flag_profissao = 0;
    
    
    /*Inicializando array da pontua??o*/
    for (i=0; i<=qt_jogadores; i++){
        pontuacao [i] = 0;
    }
    
    /*Contabilizando pontuacao*/
    for (i=1; i<=qt_jogadores; i++){
        flag_nome = 0;
        flag_pais = 0;
        flag_animal = 0;
        flag_objeto = 0;
        flag_fruta = 0;
        flag_cor = 0;
        flag_profissao = 0;
        
        for (j=1; j<=qt_jogadores; j++){
            
            if(i!=j){     /* Valid??o pra não comparar a resposta do jogador com a propria resposta */
                if(strcmp(resposta[i].v_nome, "") == 0){
                    flag_nome = 1;
                }
                else if(strcmp(resposta[i].v_nome, resposta[j].v_nome) == 0){
                    flag_nome = 2;
                }
                
                if(strcmp(resposta[i].v_pais, "") == 0){
                    flag_pais = 1;
                }
                else if(strcmp(resposta[i].v_pais, resposta[j].v_pais) == 0){
                    flag_pais = 2;
                }
                
                if(strcmp(resposta[i].v_animal, "") == 0){
                    flag_animal = 1;
                }
                else if(strcmp(resposta[i].v_animal, resposta[j].v_animal) == 0){
                    flag_animal = 2;
                }
                
                if(strcmp(resposta[i].v_objeto, "") == 0){
                    flag_objeto = 1;
                }
                else if(strcmp(resposta[i].v_objeto, resposta[j].v_objeto) == 0){
                    flag_objeto = 2;
                }
                
                if(strcmp(resposta[i].v_fruta, "") == 0){
                    flag_fruta = 1;
                }
                else if(strcmp(resposta[i].v_fruta, resposta[j].v_fruta) == 0){
                    flag_fruta = 2;
                }
                
                 if(strcmp(resposta[i].v_cor, "") == 0){
                    flag_cor = 1;
                }
                else if(strcmp(resposta[i].v_cor, resposta[j].v_cor) == 0){
                    flag_cor = 2;
                }
                
                 if(strcmp(resposta[i].v_profissao, "") == 0){
                    flag_profissao = 1;
                }
                else if(strcmp(resposta[i].v_profissao, resposta[j].v_profissao) == 0){
                    flag_profissao = 2;
                }
            }
        }
        
        /* Somat?rio da pontua??o de cada jogador */
        switch (flag_nome) {
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
       
        switch (flag_pais){
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        switch (flag_animal) {
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        switch (flag_objeto){
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        switch (flag_cor) {
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        switch (flag_fruta) {
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        switch (flag_profissao) {
        case 0:
            pontuacao [i] = pontuacao [i] + 10;
            break;
        case 1:
            pontuacao [i] = pontuacao [i] + 0;
            break;
        case 2:
            pontuacao [i] = pontuacao [i] + 5;
            break;
        default:
            pontuacao [i] = pontuacao [i] + 0;
        }
        
        printf ("PONTUAC?O DO JODADOR %d: %d\n", i, pontuacao[i]);
    }
}

//Programa principal

int main() {
   
    setlocale(LC_ALL,"Portuguese");
    int i, nota, Total, qt_jogadores, v_opcao;
	
	start_estrutura();
	inicializacao();
	
	printf("        O que deseja fazer agora? \n\n");
	printf("    Para ir direto para jogo, informe op??o 1;\n");
	printf("    Para ver as instrucoes do jogo, informe op??o 2;\n");
	printf("    Para finalizar o jogo, informe op??o 3;\n\n");
	printf("    Sua op??o: ");
	v_opcao = 0;
	scanf ("%d", &v_opcao);
	
	while(v_opcao != 3){
	
    	if(v_opcao != 1 && v_opcao != 2 ){
    	    printf("\n         Opcao inv?lida!\n\n");
    	    
    	    printf("           O que deseja fazer agora? \n\n");
	        printf("    Para ir direto para jogo, informe op??o 1;\n");
	        printf("    Para ver as instrucoes do jogo, informe op??o 2;\n");
	        printf("    Para finalizar o jogo, informe op??o 3;\n\n");
	        printf("    Sua op??o: ");
        	scanf ("%d", &v_opcao);
        	
    	}
    	
    	if(v_opcao = 2){
    	    
    	    intrucoes();
    	    
    	    printf("           O que deseja fazer agora? \n\n");
	        printf("    Para ir direto para jogo, informe op??o 1;\n");
	        printf("    Para ver as instrucoes do jogo, informe op??o 2;\n");
	        printf("    Para finalizar o jogo, informe op??o 3;\n\n");
	        printf("    Sua op??o: ");
        	scanf ("%d", &v_opcao);
    	    
    	    printf ("================================================================================\n\n");
    	}
    	
    	if(v_opcao = 1){
    	    
        	printf("  Informe a quantidade de jogadores: ");
        	scanf ("%d", &qt_jogadores);
        	printf("  Nesta rodada participar?o %d jogadores!! \n\n", qt_jogadores);
        	printf ("================================================================================\n\n");
        	
        	random_();
        	
        	printf("                           INICIO DO JOGO \n ");
        	for(i=0; i<qt_jogadores; i++){
        	    
        	    jogo(i+1);
        	    system("@cls||clear");
        	}
        	
        	respostas(qt_jogadores);
        	
        	validacao(qt_jogadores);
        	
        	printf ("================================================================================\n\n");
        	
        	start_estrutura();
        	
    	    printf("      		O que deseja fazer agora? \n\n");
	        printf("    Para ir direto para jogo, informe op??o 1;\n");
	        printf("    Para ver as instrucoes do jogo, informe op??o 2;\n");
	        printf("    Para finalizar o jogo, informe op??o 3;\n\n");
	        printf("    Sua op??o: ");
        	scanf ("%d", &v_opcao);
    	}
	}
	
	printf ("\n\n          FIM DE JOGO !");
    return 0;
}
