#ifndef __STACKS__H__
#define __STACKS__H__
#include <stdio.h>
#include <stdlib.h>

#define NUM_STACKS 3					// numero de pilas 

typedef struct nodo{
	int dato;
	struct nodo* next;
}nodo;

static nodo *stackPointers[NUM_STACKS];		// arreglo de punteros de pilas

void showStacks(void);					// imprime las pilas
void destroyStacks(void);				// libera memoria de las pilas
int stack(int nStack);					// retorna la pila que tiene mas datos
int push(int valor,int iStack);			// mete datos a la pila
int pop(int iStack,int *check);		// retira el dato de la i-esima pila
void initSetup(void);					
int menu(void);	
int Loop(void);

#endif 	// end __STACKS__H__
