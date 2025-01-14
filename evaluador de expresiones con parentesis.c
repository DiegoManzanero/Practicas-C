#include <stdio.h>
#include <stdlib.h>

typedef struct slot
{
  int posicion;
  char valor;
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
char top(pila *p)
{
  char *aux=malloc(sizeof(char));
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
void push(pila *p, char num)
{
 nodo *aux=malloc(sizeof(nodo));
 aux->valor=num;
 aux->posicion=p->size;
 p->size++;
 aux->sig=p->tope;
 p->tope=aux;
}
char pop(pila *p)
{
  int vac=isEmpty(p);
  char resp;
  if (vac==0)
  {
    printf("La pila esta vacia\n\n");
  }
  else
  {
    nodo *aux=malloc(sizeof(nodo));
    aux=p->tope;
    printf("\n\nValor que sale %c",aux->valor);
    resp=aux->valor;
    p->tope=p->tope->sig;
    p->size--;
    printf("\n\nValor nuevo del tope %c\n",p->tope->valor);
  }
  return resp;
}
char newpop(pila *p)
{
  int vac=isEmpty(p);
  char resp;
  if (vac==0)
  {
    printf("La pila esta vacia\n\n");
  }
  else
  {
    nodo*aux=malloc(sizeof(nodo));
    aux=p->tope;
    resp=aux->valor;
    p->tope=p->tope->sig;
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
    while(rec!=NULL)
    {
      printf("%c",rec->valor);
      rec=rec->sig;
      tam--;
    }
  }
  else
  {
    printf("\n\nNO hay valores para imprimir\n\n");
  }

}
int comparador(char *tope,char carac)
{
  int comT,comV,ans;
  switch(*tope)
  {
    case '+':
    {
      comT=1;
      break;
    }
    case '-':
    {
      comT=1;
      break;
    }
    case '*':
    {
      comT=2;
      break;
    }
    case '/':
    {
      comT=2;
      break;
    }
    case '^':
    {
      comT=3;
      break;
    }
    case '(':
    {
      comT=0;
      break;
    }
  }
  switch(carac)
  {
    case '+':
    {
      comV=1;
      break;
    }
    case '-':
    {
      comV=1;
      break;
    }
    case '*':
    {
      comV=2;
      break;
    }
    case '/':
    {
      comV=2;
      break;
    }
    case '^':
    {
      comV=3;
      break;
    }
  }
  if(comT>comV||comT==comV)
  {
    ans=1;
  }
  else
  {
    ans=0;
  }
  printf("\n\nCOMPARACION\n%c es el tope\n%c es el valor que quiere entrar\n %d y %d se comparan y %d es el modulo\n\n",*tope,carac,comT,comV,ans);
  return ans;
}

int main()
{
  pila *p;
  p=malloc(sizeof(pila));
  *p=inic(p);
  char var;
  char *retpop=malloc(sizeof(char));
  char *tope=malloc(sizeof(char));
  char *auxtop=malloc(sizeof(char));
  int cont,compare,compare2,contfin,x,itera;
  char cadena[100],*cad,cadfin[100];
  system("clear");
  printf("\nDame una operacion\n");
  scanf("%[^\n]",cadena);
  fflush(stdin);
  cad=cadena;
  cont=0;
  contfin=0;
  var=cad[0];
  while(var!='\0')
  {
    if (cad[cont]=='+'||cad[cont]=='-'||cad[cont]=='*'||cad[cont]=='/'||cad[cont]=='^'||cad[cont]=='('||cad[cont]==')')
    {
      x=isEmpty(p);
      if(x==0&&cad[cont]!=')')
      {
        push(p,cad[cont]);
        impri(p);
      }
      else
      {
        if(cad[cont]==')')
        {
          while(1)
          {
            *retpop=pop(p);
            if(*retpop=='(')
            {
              break;
            }
            else
            {
              cadfin[contfin]=*retpop;
              contfin++;
            }
          }
        }
        else
        {
          if(cad[cont]=='(')
          {
            push(p,cad[cont]);
          }
          else
          {
            *tope=top(p);
              compare=comparador(tope,cad[cont]);
              if(compare==1)
              {
                while(1)
                {
                  *retpop=newpop(p);
                  printf("%c es el retorno\n",*retpop);
                  cadfin[contfin]=*retpop;
                  printf("%c es el valor ingresado al final\n",cadfin[contfin]);
                  contfin++;
                  *auxtop=top(p);
                  if(*auxtop=='(')
                  {
                    push(p,cad[cont]);
                    impri(p);
                    break;
                  }
                  else
                  {
                    compare2=comparador(auxtop,cad[cont]);
                    if(compare2==1)
                    {
                      continue;
                    }
                    else
                    {
                      push(p,cad[cont]);
                      impri(p);
                      break;
                    }
                  }
                }
              }
              else
              {
                push(p,cad[cont]);
                impri(p);
              }
          }
        }
      }
    }
    else
    {
      cadfin[contfin]=cad[cont];
      contfin++;
    }
    var=cad[cont];
    cont++;
  }
  printf("\n\n%s",cadfin);
  impri(p);
  puts("\n");
  return 0;
}
