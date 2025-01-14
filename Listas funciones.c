#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
  struct nodo *sig;
  struct nodo *ant;
  char *nombre;
  char *num;
}nodo;

typedef struct lista
{
  int size;
  nodo *header;
}lista;

void inic(lista *l)
{
  l->size=0;
  l->header=NULL;
}

int size(lista *l)
{
  return l->size;
}

int isEmpty(lista *l)
{
  int resp;
  if(l->size==0)
  {
    resp=1;
  }
  else
  {
    resp=0;
  }
  return resp;
}

nodo* Buscar(lista *l,char *palabra);

int Asignador(char cadena)
{
  int numletra;
  switch (cadena)
  {
    case 'A':
    {
      numletra=1;
      break;
    }
    case 'a':
    {
      numletra=1;
      break;
    }
    case 'B':
    {
      numletra=2;
      break;
    }
    case 'b':
    {
      numletra=2;
      break;
    }
    case 'C':
    {
      numletra=3;
      break;
    }
    case 'c':
    {
      numletra=3;
      break;
    }
    case 'D':
    {
      numletra=4;
      break;
    }
    case 'd':
    {
      numletra=4;
      break;
    }
    case 'E':
    {
      numletra=5;
      break;
    }
    case 'e':
    {
      numletra=5;
      break;
    }
    case 'F':
    {
      numletra=6;
      break;
    }
    case 'f':
    {
      numletra=6;
      break;
    }
    case 'G':
    {
      numletra=7;
      break;
    }
    case 'g':
    {
      numletra=7;
      break;
    }
    case 'H':
    {
      numletra=8;
      break;
    }
    case 'h':
    {
      numletra=8;
      break;
    }
    case 'I':
    {
      numletra=9;
      break;
    }
    case 'i':
    {
      numletra=9;
      break;
    }
    case 'J':
    {
      numletra=10;
      break;
    }
    case 'j':
    {
      numletra=10;
      break;
    }
    case 'K':
    {
      numletra=11;
      break;
    }
    case 'k':
    {
      numletra=11;
      break;
    }
    case 'L':
    {
      numletra=12;
      break;
    }
    case 'l':
    {
      numletra=12;
      break;
    }
    case 'M':
    {
      numletra=13;
      break;
    }
    case 'm':
    {
      numletra=13;
      break;
    }
    case 'N':
    {
      numletra=14;
      break;
    }
    case 'n':
    {
      numletra=14;
      break;
    }
    case 'O':
    {
      numletra=15;
      break;
    }
    case 'o':
    {
      numletra=15;
      break;
    }
    case 'P':
    {
      numletra=16;
      break;
    }
    case 'p':
    {
      numletra=16;
      break;
    }
    case 'Q':
    {
      numletra=17;
      break;
    }
    case 'q':
    {
      numletra=17;
      break;
    }
    case 'R':
    {
      numletra=18;
      break;
    }
    case 'r':
    {
      numletra=18;
      break;
    }case 'S':
    {
      numletra=19;
      break;
    }
    case 's':
    {
      numletra=19;
      break;
    }
    case 'T':
    {
      numletra=20;
      break;
    }
    case 't':
    {
      numletra=20;
      break;
    }
    case 'U':
    {
      numletra=21;
      break;
    }
    case 'u':
    {
      numletra=21;
      break;
    }
    case 'V':
    {
      numletra=22;
      break;
    }
    case 'v':
    {
      numletra=22;
      break;
    }
    case 'W':
    {
      numletra=23;
      break;
    }
    case 'w':
    {
      numletra=23;
      break;
    }
    case 'X':
    {
      numletra=24;
      break;
    }
    case 'x':
    {
      numletra=24;
      break;
    }
    case 'Y':
    {
      numletra=25;
      break;
    }
    case 'y':
    {
      numletra=25;
      break;
    }
    case 'Z':
    {
      numletra=26;
      break;
    }
    case 'z':
    {
      numletra=26;
      break;
    }
    default:
    {
      printf("\n\nNO pertence al abecedario.\n\n");
      break;
    }
  }
  return numletra;
}
int Comparadorletras(char *cadena1, char *cadena2,int avance)
{
  int letra1,letra2,compara;
  letra1=Asignador(cadena1[avance]);
  letra2=Asignador(cadena2[avance]);
  if(letra1==letra2)
  {
    compara=0;
  }
  else
  {
    if(letra1>letra2)
    {
      compara=1;//Letra 2 va antes
    }
    else
    {
      compara=2;// Letra 2 va despues
    }
  }
  return compara;
}
int contadorletras(char*palabra)
{
  int cuenta=0;
  char recorrido;
  do
  {
    recorrido=palabra[cuenta];
    cuenta++;
  }
  while(recorrido!='\0');
  return cuenta-1;
}

int Comparador(char *cadena1, char *cadena2)
{
  int c1,c2,mayor,menor,avance=0,x,regreso;
  c1=contadorletras(cadena1);
  c2=contadorletras(cadena2);
  if(c1>=c2)
  {
    mayor=c1;
    menor=c2;
  }
  else
  {
    mayor=c2;
    menor=c1;
  }
  int compa[mayor];
  for(x=0;x<menor;x++)
  {
    compa[avance]=Comparadorletras(cadena1,cadena2,avance);
    avance++;
  }
  avance=0;
  do
  {
    printf("\n%d \n",compa[avance]);
    avance++;
  }
  while(compa[avance-1]==0);
  return compa[avance-1];
}

void insertarvacio(lista *l)
{
  char *numero=malloc(sizeof(char));
  char *name=malloc(sizeof(char));
  nodo *aux=malloc(sizeof(nodo));
  printf("\nDame un nombre\t");
  scanf("%s",name);
  printf("Dame un numero\t");
  scanf("%s",numero);
  aux->num=numero;
  aux->nombre=name;
  aux->sig=NULL;
  aux->ant=NULL;
  l->header=aux;
  l->size++;
  printf("\n==========\nel nombre ingresado al header es: %s\n==========\n",l->header->nombre);
}
void imprimir(lista *l)
{
  nodo *rec=malloc(sizeof(nodo));
  rec=l->header;
  if(rec!=NULL)
  {
    while(rec!=NULL)
    {
      printf("%s\n",rec->nombre);
      rec=rec->sig;
    }
  }
}
void insertarlleno(lista *l)
{
  //printf("header en la funcion %s\n",l->header->nombre);
  system("clear");
  char *name=malloc(sizeof(char));
  char *numero=malloc(sizeof(char));
  nodo *aux=malloc(sizeof(nodo));
  nodo *recorrido=malloc(sizeof(nodo));
  nodo *nuevo=malloc(sizeof(nodo));
  printf("\nDame un nombre\t");
  scanf("%s",name);
  printf("Dame un numero\t");
  scanf("%s",numero);
  recorrido=l->header;
  nuevo->nombre=name;
  nuevo->num=numero;
  int resp,x=0;
  /*if(size(l)=1)
  {
    resp=Comparador(nuevo->nombre,recorrido->nombre);
    switch (resp)
    {
      case 0:
      {
        nuevo->sig=NULL;
        recorrido->sig=nuevo;
        nuevo->ant=recorrido;
      }
      case 2:
      {
        nuevo->sig=NULL;
        recorrido->sig=nuevo;
        nuevo->ant=recorrido;
      }
      case 1:
      {
        nuevo->ant=NULL;
        recorrido->ant=nuevo;
        nuevo->sig=recorrido;
      }
    }
  }*/

  /*while(1)
  {
    resp=Comparador(recorrido->nombre,nuevo->nombre);
    if(resp==1)
    {
      nuevo->ant=NULL;
      recorrido->ant=nuevo;
      nuevo->sig=recorrido;
      l->size++;
    }
    else
    {
      if(recorrido->sig==NULL&&(resp==0||resp==2))
      {
        nuevo->sig=NULL;
        recorrido->sig=nuevo;
        nuevo->ant=recorrido;
        l->size++;
        break;
      }
      else
      {
        //printf("%s y %s se comparan\n",nuevo->nombre,recorrido->nombre);
        if(resp==0||resp==2)
        {
          recorrido=recorrido->sig;
        }
      }
    }
  }*/
  while(x==1||x==2||x==3||x==4)
  {
    resp=Comparador(recorrido->nombre,nuevo->nombre);
    if(recorrido->ant==NULL&&resp==1)
    {
      x=1;
    }
    if(recorrido->ant!=NULL&&resp==1)
    {
      x=2;
    }
    if(recorrido->sig==NULL&&(resp==0||resp==2))
    {
      x=3;
    }
    if(recorrido->sig!=NULL&&(resp==0||resp==2))
    {
      x=4;
    }
    switch (x)
    {
      case 1:
      {
        nuevo->ant=NULL;
        recorrido->ant=nuevo;
        nuevo->sig=recorrido;
        l->size++;
        break;
      }
      case 2:
      {
        nuevo->ant=recorrido->ant;
        nuevo->sig=recorrido;
        recorrido->ant=nuevo;
        nuevo->ant->sig=nuevo;
        l->size++;
        break;
      }
      case 3:
      {
        nuevo->sig=NULL;
        recorrido->sig=nuevo;
        nuevo->ant=recorrido;
        l->size++;
        break;
      }
      case 4:
      {
        nuevo->sig=recorrido->sig;
        nuevo->ant=recorrido;
        nuevo->ant=recorrido;
        recorrido->sig->ant=nuevo;
        recorrido->sig=nuevo;
        l->size++;
        break;
      }
    }

  }
}

int main ()
{
  lista *l=malloc(sizeof(lista));
  inic(l);
  int eleccion,salida=1;
  while(salida!=0)
  {
    printf("\n1...INSERTAR DATO\n");
    printf("\n2...ESTADO DE LA LISTA\n");
    printf("\n3...TAMAÑO\n");
    printf("\n4...IMPRIMIR\n");
    printf("\n5...SALIDA\n");
    printf("\nDigite una opcion: ");
    scanf("%d",&eleccion);
    switch (eleccion)
    {
      case 1:
      {
        if(isEmpty(l)==1)
        {
          insertarvacio(l);
        }
        else
        {
          insertarlleno(l);
        }
        break;
      }
      case 2:
      {
        if(isEmpty(l)==1)
        {
          printf("\nLa lista esta vacia");
        }
        else
        {
          printf("\nLa lista contiene datos");
        }
        break;
      }
      case 3:
      {
        printf("El tamaño de la lista es %d\n",size(l));
        break;
      }
      case 4:
      {
        imprimir(l);
        break;
      }
      case 5:
      {
        salida=0;
        break;
      }
    }
  }
  /*while(1)
  {
    if(isEmpty(l)==1)
    {
      insertarvacio(l);
    }
    else
    {
      insertarlleno(l);
    }
    printf("HEADER %s",l->header->nombre);
  }*/
  /*int comparacion;
  char *cad1=malloc(sizeof(char)),*cad2=malloc(sizeof(char));
  printf("\nDame una cadena prro \t");
  scanf("%s",cad1);
  printf("\nDame una cadena prro \t");
  scanf("%s",cad2);
  comparacion=Comparador(cad1,cad2);
  switch(comparacion)
  {
    case 0:
    {
      printf("\nEl nombre va despues\n");
      break;
    }
    case 1:
    {
      printf("\nEl nombre va antes\n");
      break;
    }
    case 2:
    {
      printf("\nLas cadenas SON IGUALES El nombre entra\n");
      break;
    }
  }*/

  return 0;
}
