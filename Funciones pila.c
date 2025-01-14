#include <stdio.h>
#include <stdlib.h>

typedef struct slot
{
  int posicion;
  int valor;
  struct slot *sig;
}nodo;
typedef struct
{
  int size;
  nodo *tope;
}pila;

pila inic(pila *p )
{
  p->size=0;
  p->tope=NULL;
  return *p;

}

int isEmpty(pila *p)
{
  int status=p->size;
  int validacion;

  if (status!=0)
  {
     validacion=1;
  }
  else
  {
    validacion=0;
  }
  return validacion;
}

int size(pila *p)
{
  return p->size;
}
int top(pila *p)
{
  int *aux=malloc(sizeof(int));
  if (p->tope!=NULL)
  {
    *aux=p->tope->valor;
  }
  else
  {
    printf("\nNo hay tope\n\n");
  }
  return *aux;
}
void push(pila *p, int num)
{
 nodo *aux=malloc(sizeof(nodo));
// printf("llamada desde push");
 printf("\n\nDigita un valor: ");
 scanf("%d",&num);
 aux->valor=num;
 //printf("\n\nEl valor del nodo es %d",aux->valor);
 aux->posicion=p->size;
 printf("\nLa posicion del nuevo nodo es: %d",aux->posicion);
 p->size++;
 printf("\n\nNuevo tamaño de pila: %d\n\n",p->size);
 aux->sig=p->tope;
 p->tope=aux;
}
int pop(pila *p)
{
  int x=isEmpty(p);
  int resp;
  if (x==0)
  {
    printf("La pila esta vacia\n\n");
  }
  else
  {
    nodo *aux=malloc(sizeof(nodo));
    //printf("\n\nValor del tope %d",aux->valor);
    aux=p->tope;
    printf("\n\nValor que sale %d",aux->valor);
    resp=aux->valor;
    p->tope=p->tope->sig;
    p->size--;
    printf("\n\nValor nuevo del tope %d\n",p->tope->valor);
  }
  return resp;
}
void impri(pila *p)
{
  int tam=p->size;
  nodo *rec=malloc(sizeof(nodo));
  rec=p->tope;
  if(rec!=NULL)
  {
    printf("El orden de la pila es:\n");
    while(rec!=NULL)
    {
      printf("valor #%d es: %d\n",tam,rec->valor);
      rec=rec->sig;
      tam--;
    }
  }
  else
  {
    printf("\n\nNO hay valores para imprimir\n\n");
  }

}

int main()
{
  pila *p;
  p=malloc(sizeof(pila));
  int tope;
  int x,value,resp,control;
  int safe,num,retpop;
  control=1;
  *p=inic(p);
  while(control>0)
  {
    system("clear");
    printf("\tPILAS DE DATOS\n\n");
    printf("Elige una opcion:  \n\n");
    printf("'0'  Revisar si la pila esta vacia\n");
    printf("'1'  Tamaño actual de la pila\n");
    printf("'2'  Ingresar un dato\n");
    printf("'3'  Sacar un dato\n");
    printf("'4'  Consultar el tope de la pila\n");
    printf("'5'  Imprimir pila\n");
    printf("'6'  Salir\n\n");

    scanf("%d",&resp);
    switch (resp)
    {
      case 0:
      {
        system("clear");
        printf("IS EMPTY?\n\n");
        x=isEmpty(p);
        if (x==0)
        {
          printf("\nLa pila esta vacia\n\n");
        }
        else
        {
          printf("La pila no esta vacia\n\n");
        }
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;
      }
      case 1:
      {
        system("clear");
        printf("SIZE\n\n");
        x=size(p);
        printf("Tamaño de la pila: %d\n\n",x);
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;
      }
      case 2:
      {
        system("clear");
        printf("PUSH\n\n");
        push(p,num);
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;

      }
      case 3:
      {
        system("clear");
        printf("POP\n\n");
        retpop=pop(p);
        if (retpop==0)
        printf("hola perro");
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;
      }
      case 4:
      {
        system("clear");
        printf("TOP\n\n");
        tope=top(p);
        printf("El tope es %d",tope);
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;
      }
      case 5:
      {
        system("clear");
        printf("IMPRIMIR\n\n");
        impri(p);
        printf("\n\n¿Deseas hacer otra operacion?\n");
        printf("SI = 1\tNO = 0\n\nRespuesta: ");
        scanf("%d",&safe);
        if(safe==1||safe==0)
        {
          control=safe;
        }
        else
        {
          printf("\n\nNo es una opcion valida");
          control=0;
        }
        break;
      }
      case 6:
      {
        control=0;
        break;
      }
    }
  }
  printf("\n\nSaliendo del programa...\n");
}
