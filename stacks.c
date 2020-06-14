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
	int buffSize[NUM_STACKS]; 	// buffer de numero de discos en cada pila
	int i;
	
	for(i=0;i<NUM_STACKS;i++)	// inicializamos buff
		buffSize[i] = 0;

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
	maxTope = stackPointers[stack(NUM_STACKS)-1];
							
	nodo *spSave[NUM_STACKS];
	int i;

	for(i=0;i<NUM_STACKS;i++)
		spSave[i] = stackPointers[i];
	
	printf("\n");
	
	while(maxTope){
		// primera stack
		if(spSave[0]){
			printf("\t|%2d|\t",spSave[0]->dato);
			spSave[0] = spSave[0]->next;
		}else printf("\t\t");
	
		// stack intermedias
		for()
		if(spSave[1]){
			printf("|%2d|\t",spSave[1]->dato);
			spSave[1] = spSave[1]->next;
		}else printf("\t");
		
		// ultima stack
		if(spSave[NUM_STACKS-1]){
			printf("|%2d|\n",spSave[NUM_STACKS-1]->dato);
			spSave[NUM_STACKS-1] = spSave[NUM_STACKS-1]->next;
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

