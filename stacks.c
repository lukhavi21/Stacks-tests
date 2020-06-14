#include "stacks.h"

void destroyStacks(void){
	nodo *s;
	int i;
	for(i=0;i<NUM_STACKS;i++){
		while(stackPointers[i]){
			s = (stackPointers[i])->next;		// ligadura	
			free((nodo *)stackPointers[i]);		// libera tope
			stackPointers[i] = s;				// actualiza nuevo tope	
		}
	}	
}

int push(int valor,int iStack){

	if(iStack<1 || iStack>NUM_STACKS){
		fprintf(stderr,"\nError: ingrese indice de Stack de destino v\240lidos\n");
		exit(EXIT_FAILURE);
		}
	nodo *nuevo =(nodo*)malloc(sizeof(nodo));
		if(nuevo == NULL){
			perror("\nNo se puede asignar memoria al nodo\n");
			exit(EXIT_FAILURE);		
		}
		
	nuevo->dato=valor;
	iStack--;
	nuevo->next = stackPointers[iStack];			// enlaza nuevo nodo al tope de la pila
	stackPointers[iStack]=nuevo;					// actualiza tope de pila 
}

int stack(int nStack){
	nodo *tope;
	int buffSize[3] = {0,0,0}; // buffer de numero de discos en cada pila
	int i;
	
	for(i = 0;i<NUM_STACKS;i++)
		for(tope = stackPointers[i];tope;tope = tope->next) 
				buffSize[i]++;
	
	int stack;
	int max;
	
	for(max=buffSize[0],stack=0,i=1;i<nStack;i++)
		if(buffSize[i]>max){
			max = buffSize[i];
			stack = i;
		}
	return stack + 1;
}

void showStacks(void){
	nodo *maxTope = NULL;
	int nStack;
	
	if((nStack = stack(NUM_STACKS))== 1)	maxTope = stackPointers[0];
	else if(nStack == 2)					maxTope = stackPointers[1];
	else									maxTope = stackPointers[2];
							
	nodo *tope1 = stackPointers[0];
	nodo *tope2 = stackPointers[1];
	nodo *tope3 = stackPointers[2];
	
	//printf("Pila:%d\n",nStack);
	
	printf("\n");
	
	while(maxTope){
		
		if(tope1){
			printf("\t|%2d|\t",tope1->dato);
			tope1 = tope1->next;
		}else printf("\t\t");
	
		if(tope2){
			printf("|%2d|\t",tope2->dato);
			tope2 = tope2->next;
		}else printf("\t");
			
		if(tope3){
			printf("|%2d|\n",tope3->dato);
			tope3 = tope3->next;
		}else printf("\n");
		
		maxTope = maxTope->next;
	}
}

int pop(int iStack,int *checker){
	
	if(iStack<1 || iStack>NUM_STACKS){
		fprintf(stderr,"\nError: ingrese indice de Stack de origen v\240lidos\n");
		*checker = -1;
		return -1;
	}
	iStack--;	
	
	if(stackPointers[iStack]){
		int data				=	stackPointers[iStack]->dato;		// pop
		nodo *stackPointerOld 	= 	stackPointers[iStack];				// nodo a borrar
		stackPointers[iStack]	=	stackPointers[iStack]->next;		// retrocede un dato a nuevo tope de pila
		*checker 				= 	0;
		free(stackPointerOld);											// libera tope-nodo antiguo
		return data;
	}else	*checker = -1;	
}

