#include "stacks.h"
#include <time.h>	// time()

int Loop(void){
int i,x=1,torreA,torreB,data;
int check;

	do{	
		switch(menu()){
			case 1:	// imprimir	
				showStacks();
				break;	
			case 2:	// cambio
				printf("\nDe que torre extraeras el dato: ");
				scanf("%d",&torreA);
				
				printf("\nEn que torre dejaras el disco: ");
				scanf("%d",&torreB);
				
				data=pop(torreA,&check);		// saca dato de pila origen
				
				if(check!=-1) push(data,torreB);	// mete dato a pila destino
				else printf("\nMovimiento invalido");
						
				break;
			case 3:	// Salir
				 destroyStacks();
				 printf("\nSaliendo...\n");
				x--;
				break;
			default :
				printf("Opcion desconocida\n");
		}
	}while(x==1);
}

int menu(void){
	int op;
	printf("\nQue desea hacer?");
	printf("\n1)Imprimir");
	printf("\n2)hacer cambio");
	printf("\n3)Salir\n");
	scanf("%d",&op);
	return op;
}

void initSetup(void){
	int i,j,stackSize;
	
	srand((unsigned int)time(NULL));
	
	for(i=0; i<NUM_STACKS;i++)		// asegura pilas nulas
		stackPointers[i] = NULL;
		
	printf("Cantidad de discos que desea: ");
	scanf("%d",&stackSize);
	if(stackSize<0)
		stackSize = -stackSize;
	// llena las pilas con datos aleatorios
	for(j=1;j<=NUM_STACKS;j++)
		for(i=stackSize;i>0;i--){
			push(rand()%100,j);
			}
}
