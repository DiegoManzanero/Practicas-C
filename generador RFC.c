#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int x,year,mesdif,dia;
    /*char enero[5]="ENERO",febrero[7]="FEBRERO",marzo[5]="MARZO",abril[5]="ABRIL",mayo[4]="MAYO",junio[5]="JUNIO";
    char julio[5]="JULIO",agosto[6]="AGOSTO",septiembre[10]="SEPTIEMBRE",octubre[7]="OCTUBRE",noviembre[9]="NOVIEMBRE",diciembre[9]="DICIEMBRE";*/
    char mes1[10];
    char nombre1[20],nombre2[20],apellido1[20],apellido2[20];//CADENAS PARA NOMBRES
    char n1[2],n2[2],a1[3],a2[2],ini[5];//CADENAS PARA LETRAS
    puts("Escribe el primer nombre");
    scanf("%s",&nombre1);
    strncat(n1,nombre1,1);
    puts("Escribe el segundo nombre");
    scanf("%s",&nombre2);
    strncat(n2,nombre2,1);
    puts("Escribe el primer apellido");
    scanf("%s",&apellido1);
    strncat(a1,apellido1,2);;
    puts("Escribe el segundo apellido");
    scanf("%s",&apellido2);
    strncat(a2,apellido2,1);
    puts("Ingresa el ano de nacimiento (AA/MM/DD)");
    scanf("%d",&year);
    if(year<2000)
    {
        year=year-1900;
    }
    else
    {
        year=year-2000;
    }
    puts("Ingresa el mes de nacimiento (AA/MM/DD)");
    scanf("%s",&mes1);
    puts("Ingresa el dia de nacimiento (AA/MM/DD)");
    scanf("%d",&dia);
    /*puts("Ingresa el mes de nacimiento");
    scanf("%s",&mes1);
    mesdif=strcmp(mes1,enero);
    printf("%d\n",mesdif);*/
    
    /*x=strlen(mes1);
    printf("%d",x);*/
    
    printf("\n\n%s%s%s%d%s%d",a1,a2,n1,year,mes1,dia);//SE JUNTAN LAS CADENAS
    return 0;
} 