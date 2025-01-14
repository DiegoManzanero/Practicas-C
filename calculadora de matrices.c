/*El metodo saca las soluciones del sistema multiplicando la inversa de una matriz por los resultados de las ecuaciones*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
float a[10][10],b[10][10],c[10][0],r[10][0],pivote;
 int i,j,n,m,x,y,k,l;        
//Ingresa y muestra el sistema de ecuaciones
 printf("Ingrese el numero de variables: ");
 scanf("%d",&n);
 printf("\nIngrese la matriz:\n");        
   for(i=0;i<n;i++){
      for(j=0;j<=n;j++){ 
         printf("Ingrese valor [%d][%d]: ",i,j);
         scanf("%f",&a[i][j]);
         }
      }
  printf("\nMatriz ingresada:\n");        
   for(i=0;i<n;i++){
      for(j=0;j<=n;j++){ 
         printf(" %f ",a[i][j]);
         }
         printf("\n");
      } 
 //Crea una matriz para los resultados del sistema 
  for(i=0;i<n;i++){
     j=n;
     c[i][0]=a[i][j];
     printf("%f\n",c[i][0]);
     }              
  
 /*Aqui saca la inversa por gauss jordan, una dos matrices, la original y una matriz identidad y despues va conviertiendo la original en una
 matriz identidad y la indentidad en la inversa*/
    for(i=0; i<n; i++)
    {
        j=i;
        pivote=a[i][j];
        b[i][j]=1/pivote;
        
    for(m=0; m<n; m++)
        if(m != i)
            b[i][m]=a[i][m]/pivote;
        
    for(m=0; m<n; m++)
        if(m != j)
            b[m][j]=-a[m][j]/pivote;
        
        for(x=0 ;x<n; x++)
        for(y=0; y<n; y++)
            if(x!=i && y!=j)
                b[x][y]=a[x][y]-(a[i][y]*a[x][j])/pivote;
        
        for(k=0; k<n; k++)
            for(l=0; l<n; l++)
                a[k][l]=b[k][l];
    }
    
    puts("\nMatriz inversa:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }

   //Aqui hace la multiplicacion de la matriz de los resultados con la inversa
   
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
       r[i][0]=0;               
       for(k=0;k<n;k++){
          r[i][0]=(r[i][0]+(a[i][k]*c[i][0]));
          }
       }
    }
  //Aqui muestra las soluciones del sistema                       
 printf("\nMultiplicacion:\n\n");   
 for(i=0;i<n;i++){
           printf("%f\t",r[i][0]);
       }
    printf("\n");
 printf("\n");      
      
}
