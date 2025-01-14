#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
    int Num;
    struct nodo *izq;
    struct nodo *der;
} Nodo;
Nodo *raiz=NULL;
void add(int num)
{
    Nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->Num = num;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else{
        Nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (num < reco->Num)
            {
              reco = reco->izq;
            }
            else
            {
              reco = reco->der;
            }
          }
        if (num < anterior->Num)
        {
          anterior->izq = nuevo;
        }
        else
        {
          anterior->der = nuevo;
        }
    }
}

void Preorden(Nodo *reco)
{
    if (reco != NULL)
    {
        printf("(%d) ",reco->Num);
        Preorden(reco->izq);
        Preorden(reco->der);
    }
}

void Inorden(Nodo *reco)
{
    if (reco != NULL)
    {
        Inorden(reco->izq);
        printf("(%d) ",reco->Num);
        Inorden(reco->der);
    }
}

void Postorden(Nodo *reco)
{
    if (reco != NULL)
    {
        Postorden(reco->izq);
        Postorden(reco->der);
        printf("(%d) ",reco->Num);
    }
}

void destroy(Nodo *reco)
{
    if (reco != NULL)
    {
        destroy(reco->izq);
        destroy(reco->der);
        free(reco);
    }
}

void Menu(){
	system("clear");
	printf("\n\n     ARBOLES BINARIOS\n\n");
	printf("(1) => Agregar nodo al arbol\n\n");
	printf("(2) => Preorden\n\n");
	printf("(3) => Inorden\n\n");
	printf("(4) => Postorden\n\n");
	printf("(5) => Cerrar Programa\n\n");
	printf("\nElige una opcion: ");
}
int main()
{
	int valor, control, pregunta;

	do{
		Menu();
		scanf("%d",&control);

		switch(control){

			case 1:
      {
        system("clear");
				printf("\nDigite un valor para el nuevo nodo: ");
				scanf("%d",&valor);
				add(valor);
				break;
      }
			case 2:
      {
        system("clear");
				printf("\nRecorrido preorden:\n");
				Preorden(raiz);
        printf("\n\n¿Deseas efectuar otra operacion?\nSI -> (1)\nNO -> (0)  ");
        scanf("%d",&pregunta);
        if(pregunta==0)
        {
          system("clear");
          printf("\nSaliendo del programa...");
          control=5;
        }
        break;
      }
			case 3:
      {
        system("clear");
				printf("\nRecorrido inorden\n");
				Inorden(raiz);
        printf("\n\n¿Deseas efectuar otra operacion?\nSI -> (1)\nNO -> (0)  ");
        scanf("%d",&pregunta);
        if(pregunta==0)
        {
          system("clear");
          printf("\nSaliendo del programa...");
          control=5;
        }
				break;
      }
			case 4:
      {
        system("clear");
				printf("\nRecorrido postorden\n");
				Postorden(raiz);
        printf("\n\n¿Deseas efectuar otra operacion?\nSI -> (1)\nNO -> (0)  ");
        scanf("%d",&pregunta);
        if(pregunta==0)
        {
          system("clear");
          printf("\nSaliendo del programa...\n\n");
          control=5;
        }
				break;
      }
			case 5:
      {
        system("clear");
        printf("\nSaliendo del programa...\n\n");
        control=5;
				break;
      }
			default:
      {
        printf("\nOpcion no definida, Digite otra opcion\n");
        break;
      }
		}
	}while(control!=5);
	return 0;
	destroy(raiz);
}
