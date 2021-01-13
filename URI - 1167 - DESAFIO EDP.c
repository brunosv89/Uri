/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::::::::::::::::::::::: DESAFIO EDP :::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::              EQUIPE: ADA LOVELACE           :::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::     Alunos: Bruno Vasques && Maria Grasieli     :::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::            Data: Outubro/2020               :::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:::::::::::::::::::::::::::::::::    REGRAS DA GINGANA:    ::::::::::::::::::::::::::::::::::::::::::::::::::

1) A atividades consiste em agrupar as crianças em um círculo (organizado no sentido anti-horário)
do qual seriam retiradas uma a uma até que sobrasse apenas uma criança, que seria a vencedora.

2) No momento em que entra no círculo, cada criança recebe uma pequena ficha que contém um valor de 1 a 500.

3) Depois que o círculo é formado, conta-se, iniciando na criança que está ao lado da primeira que entrou no
 círculo, o número correspondente à ficha que a primeira detém.
 
4) A criança onde o número contado cair, deve ser retirada do grupo.

5) A contagem inicia novamente segundo a ficha da criança que acabou de ser eliminada. 
       PORÉM:
       a) quando o valor que consta na ficha é par, a contagem é feita no sentido horário
	   b) quando o valor que consta na ficha é ímpar, a contagem é feita no sentido anti-horário. 

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

//::::::: Inclusão das bibliotecas : ::::::::::::::::::::::::: 

#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <locale.h> 
 

//:::::::::::::::::: Configuração dos nodos: ::::::::::::::::::
 
 typedef struct{             
       int numero;        //mesma estrutura das atividades de filas duplamente encadeadas, porém mudando a info
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     
       struct nodo* prox;    
       struct nodo* ant;    
}NODO;


//::::::::::::::::::  Declaração das funções  ::::::::::::::::::

void entrada_dados ( NODO* aux );  		//função para preencher novo nodo
void confere_circulo ( NODO* aux );     //função para conferir o círculo (lista)
void inserir_no_circulo ( NODO **l );   //função para inserir nodo (participante) no inicio da lista


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::      PROGRAMA  PRINCIPAL     ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main (void) {
	
	NODO *l = NULL;  						//lista criada
	setlocale(LC_ALL, "Portuguese");
	int participantes;						

	
	while (1) {     //"while True"
	
		printf("\nQuantos participantes: ");  
		scanf("%d", &participantes);		//1ª entrada: quantos participantes?
	
		if (participantes == 0){	//caso o usuário informe 0:		
		exit(0);					//o programa encerra a execução
		}	 
		else {
			int contador;
			for (contador = 0; contador < participantes; contador++){
				inserir_no_circulo ( &l );  // 2ª entrada: nome e numero (qtas vezes forem o numero de participantes)
				}
			
			confere_circulo ( l );    		// verificação do circulo
			
						
			NODO *inicio = l->ant;          // faz um ponteiro para marcar a primeira entrada (que é a "última" da lista devido à inserção no inicio)
			NODO *varredor = inicio;        // faz um ponteiro para varrer a lista, começando da primeira entrada
			
									
			while (inicio->prox != inicio && inicio->ant != inicio) {  //laço de repetição até que reste apenas 1 nodo (aponte para ele mesmo)
			
				if (inicio->info.numero % 2 == 0) {     //se o numero do inicio for par:
					int cont = 0;	//ponteiro contador
					while (cont != inicio->info.numero) {  //enquanto o contador não chegar no número do participante, continua varrendo
						varredor = varredor->prox;         //varre a lista em sentido horário
						printf("\nContagem: %d --- Numero do papel: %d", cont, varredor->info.numero);   //** prints só para verificar os ponteiros [descartáveis]
						cont += 1;
					}
				}
				else {										//se o numero do inicio for impar:
					int cont = 0;
					while (cont != inicio->info.numero) {  
						varredor = varredor->ant;		   // varre a lista em sentido anti-horário
						printf("\nContagem: %d --- Numero do papel: %d", cont, varredor->info.numero);    //** prints só para verificar os ponteiros [descartáveis]
						cont += 1;
						}
				}
												
				//EXCLUSÃO DO ELEMENTO		
				printf("\nNúmero excluído: %d", varredor->info.numero);
				inicio = varredor;   					// posiciona o ponteiro inicio no nodo excluido
				inicio->info = varredor->info;			//copia as informações para o ponteiro inicio para serem usadas no proximo looping
			
				varredor->ant->prox = varredor->prox;	//o prox do anterior recebe o prox de P
				varredor->prox->ant = varredor->ant;	//o ant do posterior recebe o ant de P
				}
				
			printf("\nVencedor(a): %s", inicio->info.nome);
			
			//print para verificar a posição dos ponteiros:
			printf("\nOnde está o ponteiro inicio: %d\nOnde está o ponteiro l: %d\nOnde está o ponteiro varredor: %d", inicio->info.numero,l->info.numero,varredor->info.numero);
			
			free(l);
		}
	}
}  
	

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::    Função: entrada_dados()   ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void entrada_dados( NODO* aux ){
	  
    fflush( stdin );        // limpa buffer do teclado
    printf("\nDigite o nome e o numero: ");
	scanf("%s %d", &aux->info.nome, &aux->info.numero);  // lê o nome e o número: 

    aux->prox= aux;         // registro aponta para ele mesmo 
    aux->ant = aux;         // registro aponta para ele mesmo 
 
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::  Função: inserir_no_circulo()  :::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void inserir_no_circulo ( NODO **l ){
	
	NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espaço em memória
    if( no != NULL ){  
		entrada_dados( no );           // lê dados
        if( *l == NULL ){              // verifica se lista vazia, caso sim o novo registro será o primeiro
           no->prox = no;              // lista circular, nodo aponta para ele mesmo
           no->ant  = no;
        }else{                         // caso não seja o primeiro da lista:
           no->ant = (*l)->ant;        // ant do novo registro (no) aponta para último da lista 
		   no->prox = *l;              // prox do novo registro (no) aponta para o primeiro registro da lista (*l) 
           (*l)->ant->prox = no;       // prox do último registro da lista aponta para o novo registro (no)
		   (*l)->ant = no;             // ant do primeiro registro da lista aponta para o novo registro (no)
        } // fim if ( *l == NULL ) 
		*l = no;					   // *l recebe novo nodo, que passa a ser o primeiro da lista
	
	   	printf( "\n Participante incluido" );
    } 
    else
        printf( "\n Lista cheia!" ); 
    	
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::  Função: confere_circulo()   ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void confere_circulo( NODO* aux ){
    
	int i= 0;                     		  // indica número de registro na lista
		 	 
    if( aux == NULL )	             	  // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	     printf("\n FORMAÇÃO DO CÍRCULO EM SENTIDO ANTI-HORÁRIO  ------------------ ");
         NODO *inicio= aux;		          // ponteiro auxiliar para percorrer a lista
         do{                        
		 	    printf( "\n Registro[%d]", i );
                printf( "\t Numero do papel: %d", aux->info.numero );
                printf( "\t Nome...........: %s", aux->info.nome );
                aux = aux->prox;          // aponta para o próximo registro da lista
                i++;					  //incremento do contador
         }while( aux != inicio );         // fim while( aux->prox != inicio )    
    } // fim if( aux == NULL )
 	getchar();                            // parada da tela
}


