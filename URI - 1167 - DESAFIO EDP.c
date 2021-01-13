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

1) A atividades consiste em agrupar as crian�as em um c�rculo (organizado no sentido anti-hor�rio)
do qual seriam retiradas uma a uma at� que sobrasse apenas uma crian�a, que seria a vencedora.

2) No momento em que entra no c�rculo, cada crian�a recebe uma pequena ficha que cont�m um valor de 1 a 500.

3) Depois que o c�rculo � formado, conta-se, iniciando na crian�a que est� ao lado da primeira que entrou no
 c�rculo, o n�mero correspondente � ficha que a primeira det�m.
 
4) A crian�a onde o n�mero contado cair, deve ser retirada do grupo.

5) A contagem inicia novamente segundo a ficha da crian�a que acabou de ser eliminada. 
       POR�M:
       a) quando o valor que consta na ficha � par, a contagem � feita no sentido hor�rio
	   b) quando o valor que consta na ficha � �mpar, a contagem � feita no sentido anti-hor�rio. 

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

//::::::: Inclus�o das bibliotecas : ::::::::::::::::::::::::: 

#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <locale.h> 
 

//:::::::::::::::::: Configura��o dos nodos: ::::::::::::::::::
 
 typedef struct{             
       int numero;        //mesma estrutura das atividades de filas duplamente encadeadas, por�m mudando a info
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     
       struct nodo* prox;    
       struct nodo* ant;    
}NODO;


//::::::::::::::::::  Declara��o das fun��es  ::::::::::::::::::

void entrada_dados ( NODO* aux );  		//fun��o para preencher novo nodo
void confere_circulo ( NODO* aux );     //fun��o para conferir o c�rculo (lista)
void inserir_no_circulo ( NODO **l );   //fun��o para inserir nodo (participante) no inicio da lista


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::      PROGRAMA  PRINCIPAL     ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main (void) {
	
	NODO *l = NULL;  						//lista criada
	setlocale(LC_ALL, "Portuguese");
	int participantes;						

	
	while (1) {     //"while True"
	
		printf("\nQuantos participantes: ");  
		scanf("%d", &participantes);		//1� entrada: quantos participantes?
	
		if (participantes == 0){	//caso o usu�rio informe 0:		
		exit(0);					//o programa encerra a execu��o
		}	 
		else {
			int contador;
			for (contador = 0; contador < participantes; contador++){
				inserir_no_circulo ( &l );  // 2� entrada: nome e numero (qtas vezes forem o numero de participantes)
				}
			
			confere_circulo ( l );    		// verifica��o do circulo
			
						
			NODO *inicio = l->ant;          // faz um ponteiro para marcar a primeira entrada (que � a "�ltima" da lista devido � inser��o no inicio)
			NODO *varredor = inicio;        // faz um ponteiro para varrer a lista, come�ando da primeira entrada
			
									
			while (inicio->prox != inicio && inicio->ant != inicio) {  //la�o de repeti��o at� que reste apenas 1 nodo (aponte para ele mesmo)
			
				if (inicio->info.numero % 2 == 0) {     //se o numero do inicio for par:
					int cont = 0;	//ponteiro contador
					while (cont != inicio->info.numero) {  //enquanto o contador n�o chegar no n�mero do participante, continua varrendo
						varredor = varredor->prox;         //varre a lista em sentido hor�rio
						printf("\nContagem: %d --- Numero do papel: %d", cont, varredor->info.numero);   //** prints s� para verificar os ponteiros [descart�veis]
						cont += 1;
					}
				}
				else {										//se o numero do inicio for impar:
					int cont = 0;
					while (cont != inicio->info.numero) {  
						varredor = varredor->ant;		   // varre a lista em sentido anti-hor�rio
						printf("\nContagem: %d --- Numero do papel: %d", cont, varredor->info.numero);    //** prints s� para verificar os ponteiros [descart�veis]
						cont += 1;
						}
				}
												
				//EXCLUS�O DO ELEMENTO		
				printf("\nN�mero exclu�do: %d", varredor->info.numero);
				inicio = varredor;   					// posiciona o ponteiro inicio no nodo excluido
				inicio->info = varredor->info;			//copia as informa��es para o ponteiro inicio para serem usadas no proximo looping
			
				varredor->ant->prox = varredor->prox;	//o prox do anterior recebe o prox de P
				varredor->prox->ant = varredor->ant;	//o ant do posterior recebe o ant de P
				}
				
			printf("\nVencedor(a): %s", inicio->info.nome);
			
			//print para verificar a posi��o dos ponteiros:
			printf("\nOnde est� o ponteiro inicio: %d\nOnde est� o ponteiro l: %d\nOnde est� o ponteiro varredor: %d", inicio->info.numero,l->info.numero,varredor->info.numero);
			
			free(l);
		}
	}
}  
	

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::    Fun��o: entrada_dados()   ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void entrada_dados( NODO* aux ){
	  
    fflush( stdin );        // limpa buffer do teclado
    printf("\nDigite o nome e o numero: ");
	scanf("%s %d", &aux->info.nome, &aux->info.numero);  // l� o nome e o n�mero: 

    aux->prox= aux;         // registro aponta para ele mesmo 
    aux->ant = aux;         // registro aponta para ele mesmo 
 
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::  Fun��o: inserir_no_circulo()  :::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void inserir_no_circulo ( NODO **l ){
	
	NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espa�o em mem�ria
    if( no != NULL ){  
		entrada_dados( no );           // l� dados
        if( *l == NULL ){              // verifica se lista vazia, caso sim o novo registro ser� o primeiro
           no->prox = no;              // lista circular, nodo aponta para ele mesmo
           no->ant  = no;
        }else{                         // caso n�o seja o primeiro da lista:
           no->ant = (*l)->ant;        // ant do novo registro (no) aponta para �ltimo da lista 
		   no->prox = *l;              // prox do novo registro (no) aponta para o primeiro registro da lista (*l) 
           (*l)->ant->prox = no;       // prox do �ltimo registro da lista aponta para o novo registro (no)
		   (*l)->ant = no;             // ant do primeiro registro da lista aponta para o novo registro (no)
        } // fim if ( *l == NULL ) 
		*l = no;					   // *l recebe novo nodo, que passa a ser o primeiro da lista
	
	   	printf( "\n Participante incluido" );
    } 
    else
        printf( "\n Lista cheia!" ); 
    	
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::  Fun��o: confere_circulo()   ::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void confere_circulo( NODO* aux ){
    
	int i= 0;                     		  // indica n�mero de registro na lista
		 	 
    if( aux == NULL )	             	  // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	     printf("\n FORMA��O DO C�RCULO EM SENTIDO ANTI-HOR�RIO  ------------------ ");
         NODO *inicio= aux;		          // ponteiro auxiliar para percorrer a lista
         do{                        
		 	    printf( "\n Registro[%d]", i );
                printf( "\t Numero do papel: %d", aux->info.numero );
                printf( "\t Nome...........: %s", aux->info.nome );
                aux = aux->prox;          // aponta para o pr�ximo registro da lista
                i++;					  //incremento do contador
         }while( aux != inicio );         // fim while( aux->prox != inicio )    
    } // fim if( aux == NULL )
 	getchar();                            // parada da tela
}


