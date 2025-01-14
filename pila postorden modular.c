#include <stdio.h>
#include <stdlib.h>
#include "tda.h"
#include "pila.h"

void imprimirPila(Pila *p);
char *convPostfija(Pila *,char *);
void vaciarPila(Pila*,char *);
Nodo *clasificar(char );

int main(){
	int opcion;
	Pila *p;
	Nodo n;
	p = (Pila *)malloc(sizeof(Pila));
	initialize(p);
	char*infija, *postfija;
	infija = malloc(200);
	printf("Instroduce tu expresion Infija:\n");
	scanf("%[^\n]",infija);
	printf("La expresion infija es:%s\n",infija);
	postfija=convPostfija(p,infija);
	printf("\nLa expresion postfija es ---->%s",postfija);
	return 0;
}

char *convPostfija(Pila *p,char *infija){
	char *postfija;
	int i=0,j=0;
	Nodo *n, *top,*aux;
	n=(Nodo *)malloc(sizeof(Nodo));
	postfija = malloc(200);
	while(*(infija+i)){
		printf("\n..>>%d",infija[i]);
		if(*(infija+i)>=65 && infija[i]<=90){
			postfija[j]=infija[i];
			j++;
		}else{
			n=clasificar(infija[i]);
			while(1){
				imprimirPila(p);
				if(isEmpty(p)){
					push(p,*n);
					break;
				}else{
					top=tope(p);
					if(n->valor > top->valor){
						push(p,*n);
						break;
					}
					else{
						aux = pop(p);
						postfija[j]=aux->op;
						j++;	
					}
				}
			}
		}	
		i++;
	}
	postfija[j]='\0';
	vaciarPila(p,postfija);
	return postfija;
}

Nodo *clasificar(char c){
	Nodo *n, *top,*aux;
	n=(Nodo *)malloc(sizeof(Nodo));
	n->sig=NULL;
			switch(c){
				case '+':
				case '-':
					printf("\nsimbolo + o -");
					n->op=c;
					n->valor=1;
					break;
				case '/':
				case '*':
					printf("\nsimbolo / o *");
					n->op=c;
					n->valor=2;
					break;
				case '^':
					printf("\nsimbolo ^");
					n->op=c;
					n->valor=3;
					break;
				default:
					printf("\nEl simbolo no existe\n");
					break;
			}
	return n;
}

void vaciarPila(Pila* p,char *postfija){
	Nodo *aux;
	int i=0;
	while(postfija[i]){
		i++;
	}
	while(!isEmpty(p)){
			aux=pop(p);
			postfija[i]=aux->op;
			i++;
	}
	postfija[i]='\0';
}

void imprimirPila(Pila *p){
	Nodo *aux;
	aux = p->tope;
	printf("\n--------------------\n");
	while(aux){
		printf("Nodo - OP:\t%C\n",aux->op);
		printf("Nodo - valor:\t%d\n",aux->valor);
		printf("Nodo - posi:\t%d\n",aux->posicion);
		aux = aux->sig;
		printf("--------------------\n");
	}
}

