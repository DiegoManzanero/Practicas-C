#include<stdio.h>
#include<stdlib.h>
typedef struct cliente
{
	int nproductos;
	int prioridad;
	struct cliente *sig;
}Nodo;


typedef struct cajas
{
	char *cajero;
	int num_caja;
	Nodo* inicio;
	Nodo* fin;
	int size;
	struct cajas *sig;
	struct cajas *ant;
}Cajas;

typedef struct cola
{
	Cajas *iniC;
	Cajas *finC;
	int sizeC;
}Cola;

void inicializar(Cola *);
int esVaciapencola(Cola*,int e);
int esVaciaC(Cola*);
int esVacia(Cola* c);
void encolarcaja(Cola *,int , char*);
void encolarcliente(Cola *,int e,int prior);
Nodo *desencolarcliente(Cola *,int e);
Cajas *desencolarcajas(Cola *,int);
int tamanio(Cola *);
Nodo *frente(Cola *);
Nodo *final(Cola *);
Cajas* asignacaja(Cola *, int);
void abrir_caja(Cola *,int);
void cerrar_caja(Cola *, int);
void agregar_cliente(Cola *);
void despachar_cliente(Cola *,int);
void imprimir_cajas(Cola *);
void imprimir_clientes(Cola *,int);
int existe_caja(Cola *, int );

void inicializar(Cola *c)
{
	c->iniC=NULL;
	c->finC=NULL;
	c->sizeC=0;
}

int esVaciapencola(Cola* c, int e)
{
  printf("hola\n");
  int resp,x;
	x=0;
  if(x==0)
  {
    printf("correcto");
    resp=1;
  }
  else
  {
    printf("correcto2");
    resp=0;
  }
  printf("h%d",resp);
  return resp;
}
int esVacia(Cola* c)
{
	int resp;
	if(c->iniC==NULL)
	resp=1;
	else
	resp=0;
	return resp;
}
int esVaciaC(Cola* c)
{
	int resp;
	if(c->iniC==NULL)
	resp=1;
	else
	resp=0;
	return resp;
}

void encolarcaja(Cola *c,int e,char *nombre)
{
	Cajas *nuevo;
	nuevo=(Cajas*)malloc(sizeof(Cajas));
	nuevo->num_caja=e;
	nuevo->cajero=nombre;
	if(esVaciaC(c))
	{
		c->iniC=nuevo;
		c->finC=nuevo;
		c->iniC->inicio=NULL;
		c->iniC->fin=NULL;
		c->iniC->size=0;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
		c->sizeC++;
	}
	else
	{
		c->finC->sig=nuevo;
		nuevo->sig=NULL;
		nuevo->ant=c->finC;
		c->finC=nuevo;
		c->finC->inicio=NULL;
		c->finC->fin=NULL;
		c->finC->size=0;
		c->sizeC++;
	}
}
void encolarcliente(Cola *c,int e, int prior)
{
  int *x=malloc(sizeof(int));
  printf("\nDigite la cantidad de productos del cliente: ");
  scanf("%d",x);
  e=*x;
	Nodo *nuevo,*aux;
	Cajas *caja;
	caja=(Cajas*)malloc(sizeof(Cajas));
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	aux=(Nodo*)malloc(sizeof(Nodo));
	nuevo->nproductos=e;
	nuevo->prioridad=prior;
	caja=c->iniC;
  if(c->sizeC==0)
  {
    caja->inicio=nuevo;
    caja->fin=nuevo;
    nuevo->sig=NULL;
    caja->size++;
  }
  else
  {
    caja->fin->sig=nuevo;
    nuevo->sig=NULL;
    caja->fin=nuevo;
    caja->size++;
  }
	/*while(caja)
	{
		if(caja->num_caja==prior)
		{
			if(esVaciapencola(c,prior))
			{
        printf("hola prro\n");
				caja->inicio=nuevo;
				caja->fin=nuevo;
				nuevo->sig=NULL;
				caja->size++;
				break;
			}
			else
			{
				caja->fin->sig=nuevo;
				nuevo->sig=NULL;
				caja->fin=nuevo;
				caja->size++;
				break;
			}
		}
		else
    {
      caja=caja->sig;
		}
	}*/
}

Nodo *desencolarcliente(Cola *c, int e)
{
	Nodo *aux;
	Cajas *caja;
	aux=(Nodo*)malloc(sizeof(Nodo));
	caja=(Cajas*)malloc(sizeof(Cajas));
	caja=c->iniC;
		while(caja)
		{
			if(caja->num_caja==e)
			{
				aux=caja->inicio;
				caja->inicio=caja->inicio->sig;
				caja->size--;
				break;
			}
			else
				caja=caja->sig;
		}
	return aux;
}

Cajas *desencolarcajas(Cola *c, int e)
{
	Cajas *caja,*aux;
	caja=(Cajas*)malloc(sizeof(Cajas));
	aux=(Cajas*)malloc(sizeof(Cajas));
	caja=c->iniC;
	if(esVaciaC(c))
	{
		printf("Esta vacia la cola elige otra opcion\n");
		aux=NULL;
	}
	else
	{
		while(caja)
		{
			if(caja->num_caja==e)
			{
				aux=caja;
				if(caja->sig!=NULL)
				{
					caja->sig->ant=caja->ant;
				}
				else
				{
					caja->ant->sig=caja->sig;
					c->finC=caja->ant;
				}
				if(caja->ant!=NULL)
				{
					caja->ant->sig=caja->sig;
				}
				else
				{
					c->iniC=caja->sig;
				}
				c->sizeC--;
				break;
			}
			else
				caja=caja->sig;
		}
	}
	return aux;
}
int tamaniocajas(Cola *c)
{
	int aux;
	aux=c->sizeC;
	return aux;
}
int existe[60];
int contcajas=0;
Cajas* asignacaja(Cola *c,int e)
{
	Cajas *aux1,*retorno;
	retorno=(Cajas*)malloc(sizeof(Cajas));
	int siono,i=0;
	int resp,cont=0;
  if(esVaciaC(c))
  {

  }
	else
	{
		aux1=(Cajas*)malloc(sizeof(Cajas));
		aux1=c->iniC;
		while(i<tamaniocajas(c))
		{
			if(tamaniocajas(c)==1)
			{
				if(aux1->num_caja==e)
				{
				*retorno=*aux1;
				break;
				}
			}
			else
			{
					if(aux1->num_caja!=e)
					{
						aux1=aux1->sig;
					}
					else
					{
						*retorno=*aux1;
						break;
					}
			}
			i++;
		}

	}
	return retorno;
}
void abrir_caja(Cola *cajas,int a)
{
	int i=0,cont=0,j=0,tamanio=0,k=0;
	char *nombre;
	nombre=malloc(50);
	if(existe_caja(cajas,a))
	{
		printf("La caja esta disponible\n");
	}
	else
	{
		printf("\nIngrese nombre del dependiente: ");
		scanf("%s",nombre);
		encolarcaja(cajas,a,nombre);
		contcajas++;
		while(i<contcajas)
		{
			tamanio++;
			i++;
		}
		i=0;
		while(i<tamanio)
		{
			if(existe[i]==a)
			{
				break;
			}
			else
			{
				j=i+1;
				while(j<=tamanio)
				{
					if(existe[j]==a)
					existe[j]=a;
					j++;
				}
				existe[i+k]=a;
				k++;
			}
		i++;
		}
	}
}
void imprimir_cajas(Cola *c)
{
	Cajas *aux;
	char *auxnom;
	auxnom=malloc(60);
	if(esVaciaC(c))
		printf("\nNo hay cajas disponibles\n");
	else
	{
		aux=c->iniC;
		while(aux)
		{
			printf("Caja %d\n",aux->num_caja);
			printf("Cajero: %s\n",aux->cajero);
			aux=aux->sig;
		}
	}
}
void imprimir_clientes(Cola *c,int qcaja)
{
	Nodo *aux;
	aux=(Nodo*)malloc(sizeof(Nodo));
	Cajas* aux1;
	aux1=(Cajas*)malloc(sizeof(Cajas));
	int cont=0;
	if(esVaciaC(c))
	{
		printf("\nNo hay cajas abiertas\n");
	}
	else
	{
		if(existe_caja(c,qcaja))
		{
			*aux1=*asignacaja(c,qcaja);
			aux=aux1->inicio;
			if(aux)
			{
				while(aux)
				{
					printf("Cliente: %d\n",cont+1);
					printf("Prioridad: %d\n",aux->prioridad);
					printf("Numero de productos: %d\n",aux->nproductos);
					aux=aux->sig;
					cont++;
				}
			}
			else
			printf("No hay clientes\n");
		}
		else
		{
			printf("\nNO esta disponible esa caja\n");
		}
	}
}
int existe_caja(Cola *c, int e)
{
	Cajas *aux1;
	int siono,i=0;
	int resp,cont=0;
	if(esVaciaC(c))
	{
		resp=0;
	}
	else
	{
		aux1=(Cajas*)malloc(sizeof(Cajas));
		aux1=c->iniC;
		while(i<tamaniocajas(c))
		{
			if(tamaniocajas(c)==1)
			{
				if(aux1->num_caja==e)
        {
          resp=1;
				}
				else
				{
					resp=0;
				}
			}
			else
			{
					if(aux1->num_caja!=e)
					{
						aux1=aux1->sig;
						resp=0;
					}
					else
					{
						resp=1;
					}
			}
			i++;
		}

	}
	return resp;
}
void despachar_cliente(Cola *c,int numcaja)
{
	Nodo* aux;
	aux=(Nodo*)malloc(sizeof(Nodo));
	if(existe_caja(c,numcaja)==0)
	{
		printf("\nNO esta disponible la caja\n");
	}
	else
	{
		if(esVaciapencola(c,numcaja)==1)
		{
			printf("No hay clientes en la fila\n");
		}
		else
		{
				aux=desencolarcliente(c,numcaja);
				printf("Cliente despachado con %d articulos\n",aux->nproductos);
		}
	}
}
void cerrar_caja(Cola*c, int e)
{
	int i=0,cont=0,j=0,tamanio=0,k=0;
	Cajas*caja;
	caja=(Cajas*)malloc(sizeof(Cajas));
	if(existe_caja(c,e))
	{
		caja=desencolarcajas(c,e);
		contcajas--;

	}
	else
	{
		printf("\n\nNO esta disponible\n\n");
	}
}
int main()
{
	int resp,prior,aux,productos,qcaja,acerrar;
	char bucle;
	Cola* c;
	Cajas *cajaaux;
	c=(Cola*)malloc(sizeof(Cola));
	inicializar(c);
	Nodo *nodo1;
	printf("Walmart\n");
	while(resp!=-1)
	{
		printf("\n\nELIJA UNA OPCION:\n\n\n1 => Abrir nueva caja\n2 => Agregar cliente\n3 => Despachar cliente\n4 => Mostrar cajas disponibles\n5 => Mostrar fila \n6 => Numero de cajas disponibles\n7 => Cerrar caja\n8 => Salir \n");
		scanf("%d",&resp);
		switch(resp)
		{
			case 1:
        system("clear");
				printf("Ingrese el numero de caja que desea abrir\n");
        scanf("%d",&prior);
				abrir_caja(c,prior);
				break;
			case 2:
      system("clear");
				printf("ingrese la prioridad del cliente\n");
				scanf("%d",&prior);
        printf("%d es la prioridad ingresada",prior);
				aux=existe_caja(c,prior);
				if(aux!=0)
				{
					system("clear");
					//printf("\nDigite la cantidad de productos del cliente: ");
          productos=1;
					encolarcliente(c,productos,prior);
					printf("\nEl cliente ha sido agregado\n");
				}
				else
				{
					printf("\nCaja %d no se encuentra en servicio\n",prior);
				}
				break;
			case 3:
      system("clear");
				printf("Que caja desea despachar\n");
				scanf("%d",&qcaja);
				despachar_cliente(c,qcaja);
				break;
			case 4:
      system("clear");
				printf("\nMostrando cajas abiertas\n\n\n");
				imprimir_cajas(c);
				break;
			case 5:
      system("clear");
				printf("\nMostrando filas de clientes \n\n\n");
				printf("De que caja desea ver la fila?\n");
				scanf("%d",&qcaja);
				imprimir_clientes(c,qcaja);
				break;
			case 6:
      system("clear");
				if(esVaciaC(c))
				{
					printf("No hay cajas disponibles\n");
				}
				else
				printf("\nHay (%d) cajas disponibles",contcajas);
				break;
			case 7:
      system("clear");
				printf("Digite el numero de caja que desea cerrar: ");
				scanf("%d",&acerrar);
				cerrar_caja(c,acerrar);
				break;
			case 8:
      system("clear");
				return 0;
				break;
		}
	}
	return 0;
}
