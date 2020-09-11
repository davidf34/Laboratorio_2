//Programa punto1.
//Andrés Gómez CODIGO 2154714 David Sandoval codigo 2142786
//Version 1.0

//incluir librerias.
#include<stdio.h>
#include<string.h>
#define CANT_PUNTO 2

//Definición de prototipos
typedef struct puntos{
	float x; //punto en el eje x
	float y; //punto en el eje y
}punto;
void bienvenida();
char menu();
void pedir();
void pendiente();
void ecuacion();
void cruce();
void salir();


//Codigo principal
int main (void) 
{
	punto punto1,punto2;
	char salir=0;
	int men=0;
	char flag1=0;
	bienvenida();
	men=menu();
do                   //estructura del programa en general y ciclo infinito hasta que salir sea igual a 1

	switch(men)
	{
		case 1:       // pedir datos
			pedir(&punto1,&punto2,&flag1);
			men=menu();
			break;
		
		case 2:		// dar pendiente, verificar primero si hay datos
			if (flag1==1){
				pendiente(&punto1,&punto2);
				men=menu();
				break;
			}
			else{
				printf("\n \e[1;34mPorfavor ingresa primero los puntos !\n\e[0m");// indica que no se han dado los primeros datos al iniciar el programa
				men=menu();
			break;}
			
		case 3:		// dar el cruce, verificar primero si hay datos
			if (flag1==1){
				cruce(&punto1,&punto2);
				men=menu();
				break;
			}
			else{
				printf("\n \e[1;34mPorfavor ingresa primero los puntos !\n\e[0m");// indica que no se han dado los primeros datos al iniciar el programa
				men=menu();
			break;}
			
		case 4:		// dar ecuacion, verificar primero si hay datos
			if (flag1==1){
				ecuacion(&punto1,&punto2);
				men=menu();
				break;
			}
			else{
				
				printf("\n \e[1;34mPorfavor ingresa primero los puntos !\n\e[0m");// indica que no se han dado los primeros datos al iniciar el programa
				men=menu();
			break;}
			
		case 5:		//salida del programa
			printf("\nHasta luego.\n");
			salir=1;
			break;
			
		
		default:	//verifcamos si se introduce un dato valido para el menu
			printf("\nIngresa un numero valido.\n");
			men=menu();
			break;
					
	}


while(salir ==0);

}

//Definición de funciones
void bienvenida()
{
	printf("\n ¡Bienvenido al programa! \n"); // imprime la bienvenida
	
}
char menu() //imprime el menu y recibe el dato para seleccionar una opcion
{
	int men=0;
	printf("\n MENÚ \n");//imprimir todas las opciones del menu
	printf("\n 1. Ingresar Puntos. \n");
	printf("\n 2. Mostrar Pendiente \n");
	printf("\n 3. Mostrar cruce con el eje y. \n");
	printf("\n 4. Mostrar ecuación completa. \n");
	printf("\n 5. Salida. \n");
	printf("Ingresa tu opción: ");
	scanf("%d",&men);//recibe dato para el menu
	return men;
}
void pedir(punto *p1, punto *p2,char *flag1)//recibir los puntos que da el usuario
{
	 printf("\n  Ingrese X1: \n");
	 scanf("%f", &p1[0].x);	 
	 printf("\n  Ingrese Y1: \n");
	 scanf("%f", &p1[1].y);
	 printf("\n  Ingrese X2: \n");
	 scanf("%f", &p2[0].x);
	 printf("\n  Ingrese Y2: \n");
	 scanf("%f", &p2[1].y);
	 // se recibieron todos los datos dados por el usuario
	 printf("\n los puntos ingresados son: X1= %.3f Y1= %.3f X2= %.3f Y2= %.3f", p1[0].x, p1[1].y,p2[0].x,p2[1].y);//verificamos los datos recibidos
	 printf("\n ¿Ahora que opción desea realizar?");
	 *flag1=1;// bandera para indicar que ya se recibieron puntos a los otros subprogramas
}

void pendiente(punto *p1, punto *p2)// operaciones para dar la pendiente
{
	float pend =0;
	pend = ((p2[1].y) - (p1[1].y))/((p2[0].x) - (p1[0].x));// proceso para sacar la pendiente
	printf("\nEl resultado de la pendiente es: m= %.3f ", pend );// imprime la pendiente
	printf("\n ¿Ahora que opción desea realizar?");
	}
	

void cruce(punto *p1, punto *p2)// operaciones para sacar el cruce
{
	float pend =0;
	float b = 0;
	pend = ((p2[1].y) - (p1[1].y))/((p2[0].x) - (p1[0].x));// proceso para sacar la pendiente
	b = (-(pend)*(p1[0].x))+ (p1[1].y);// proceso para sacar el cruce con el eje Y
	printf("\n El cruce con el eje y es: y= %.3f ", b );// imprime el cruce con el eje Y
	printf("\n ¿Ahora que opción desea realizar?");
}	
	
void ecuacion(punto *p1, punto *p2)// operaciones para mostrar la ecuacion completa
{
	float pend =0;
	float b = 0;
	pend = ((p2[1].y) - (p1[1].y))/((p2[0].x) - (p1[0].x));// proceso para sacar la pendiente
	b = (-(pend)*(p1[0].x))+ (p1[1].y);// proceso para sacar el cruce con el eje Y
	printf("\nEl resultado de la ecuación es: Y= %.3f X + %.3f", pend, b );// imprime la ecuacion de forma ordenada despues de sacar la pendiente y el cruce en Y
	printf("\n ¿Ahora que opción desea realizar?");
}