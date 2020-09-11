//Programa punto2.
//Andrés Gómez CODIGO 2154714 David Sandoval codigo 2142786
//Version 1.0

//incluir librerias.
#include<stdio.h>
#include<string.h>
#define CANT_PALABRA 23
#define MAX_PALABRA 69

//Definición de prototipos
void bienvenida();
typedef struct palabras{
	char w1[CANT_PALABRA];//palabra 1
	char w2[CANT_PALABRA]; //palabra 2
	char w3[CANT_PALABRA]; //palabra 3 
	}palabra;

char menu();
void ingreso();
void comparar();
void reves();
void concatenar();
char longitud();
void sumdecimal();
void salir();

//Codigo principal
int main (void) 
{
	palabra recibidas;
	char salir=0;
	int men=0;
	char flag1=0;
	bienvenida();
	men=menu();


do 					//estructura del programa en general y ciclo infinito hasta que salir sea igual a 1

	switch(men)
	{
		case 1:		//ingreso de palabras
			ingreso(&recibidas,&flag1);
			men=menu();
			break;
			
		case 2:		//comparacion de las palabras, verificar primero si hay datos
			if (flag1==1){
				comparar(&recibidas);
				men=menu();
				break;}
			else {
				printf("\n \e[1;34mPorfavor ingresa primero las palabras !\n\e[0m");
				men=menu();
			break;
			}
					
		 case 3:	// las palabras al reves, verificar primero si hay datos
			if (flag1==1){
				reves(&recibidas);
				men=menu();
				break;}
			else {
				printf("\n \e[1;34mPorfavor ingresa primero las palabras !\n\e[0m");
				men=menu();
			break;
			}
			
		case 4:		// las palabras concatenadas, verificar primero si hay datos
			if (flag1==1){
				concatenar(&recibidas);
				men=menu();
				break;}
			else {
				printf("\n \e[1;34mPorfavor ingresa primero las palabras !\n\e[0m");
				men=menu();
			break;
			}
		
		case 5:		// longitud de las palabras, verificar primero si hay datos
			if (flag1==1){
				longitud(&recibidas);
				men=menu();
				break;}
			else {
				printf("\n \e[1;34mPorfavor ingresa primero las palabras !\n\e[0m");
				men=menu();
			break;
			}
		
		case 6:		//suma decimal de las palabras, verificar primero si hay datos
			if (flag1==1){
				sumdecimal(&recibidas);
				men=menu();
				break;}
			else {
				printf("\n \e[1;34mPorfavor ingresa primero las palabras !\n\e[0m");
				men=menu();
			break;
			}
		
		case 7:		//salir
			printf("\nHasta luego.\n");
			salir=1;
			break;
			
		
		default:	//verifcamos si se introduce un dato valido para el menu
			printf("\nIngresa un numero válido.\n");
			men=menu();
			break;
			
		
		
	}


while(salir ==0);

}
//Definición de funciones
void bienvenida() // imprime bienvenida
{
	printf("\n ¡Bienvenido al programa! \n");
	printf("\n Ingreso de 3 palabras \n");
}
char menu() // imprime opciones del menu y recibe el dato para la opcion elegida
{
	int men=0;
	printf("\n MENÚ \n");
	printf("\n 1. Ingresar palabras. \n");
	printf("\n 2. Comparar palabras. \n");
	printf("\n 3. Mostrar palabras al revés. \n");
	printf("\n 4. Concatenar palabras. \n");
	printf("\n 5. Mostrar longitud de cada palabra. \n");
	printf("\n 6. Mostrar la suma decimal de los caracteres de cada palabra. \n");
	printf("\n 7. Salir. \n");
	printf("Ingresa tu opción seguido de la tecla enter: ");
	scanf("%d",&men);
	return men;
}
void ingreso(palabra *word, char *flag1)//recibe las palabras y activa la bandera de dato recibido
{
	 printf("\n  Ingrese la primera palabra: \n");
	 scanf("%s", word[0].w1);	 
	 printf("\n  Ingrese la segunda palabra: \n");
	 scanf("%s", word[1].w2);
	 printf("\n  Ingrese la tercera palabra: \n");
	 scanf("%s", word[2].w3);
	 printf("\n Las palabras ingresadas son:  %s  %s  %s ", word[0].w1, word[1].w2,word[2].w3);
	 printf("\n ¿Ahora que opción desea realizar?");
	 *flag1=1;

}

void comparar(palabra *word )//compara las palabras e imprime el mensaje dependiendo de las palabras
{
	int comp=0;//creamos variables para guardar el dato de la comparacion
	int comp1=0;
	int comp2=0;
	comp=strncmp(word[0].w1,word[1].w2,CANT_PALABRA );//compara 1 y 2
	comp1=strncmp(word[1].w2,word[2].w3,CANT_PALABRA );//compara 2 y 3
	comp2=strncmp(word[0].w1,word[2].w3,CANT_PALABRA );//compara 1 y 3
	if(comp	==0){
		if (comp1==0){
			if(comp2==0){
				printf("\n Todas las palabras son iguales\n");// todas las comparaciones dan 0
			}
		}
		else{
			if(comp2!=0){
				printf("\n La palabra 1: %s  y la palabra 2: %s  son iguales.\n", word[0].w1, word[1].w2 );//la primera comparacion da 0 y las demas diferente de 0
			}
		}
	}
	
	else{
		if(comp1==0){
			if(comp2!=0){
				printf("\n La palabra 2: %s  y la palabra 3: %s  son iguales.\n", word[1].w2, word[2].w3 );//la segunda comparacion da 0 y las demas diferente de 0
			}
		}
		else{
			if(comp2==0){
				printf("\n La palabra 1: %s  y la palabra 3: %s  son iguales.\n", word[0].w1, word[2].w3 );//la tercera comparacion da 0 y las demas diferente de 0
			}
			else{
				printf("\n Todas las palabras son diferentes\n");// todas las comparaciones dan diferente de 0
			}
		}
	}
		
 printf("\n ¿Ahora que opción desea realizar?");
}	
		

 void reves(palabra *word) //imprime al reves las palabras
{
	int u,v;
	char a[CANT_PALABRA];//vector para guardar la palabra
	for (u=0 ; (a[u]=word[0].w1[u])!='\0' ; u++){	//guardo la palabra en a

	}
	printf("\n La palabra 1 al revés es:\n");		//imprime la palabra desde la ultima posicion hasta la primera
	for(v = u;v>=0;v--){
	printf("%c",a[v]);}
	
	for (u=0 ; (a[u]=word[1].w2[u])!='\0' ; u++){	//guardo la palabra en a

	}
	printf("\n La palabra 2 al revés es:\n");		//imprime la palabra desde la ultima posicion hasta la primera
	for(v = u;v>=0;v--){
	printf("%c",a[v]);}
	
	for (u=0 ; (a[u]=word[2].w3[u])!='\0' ; u++){	//guardo la palabra en a

	}
	printf("\n La palabra 3 al revés es:\n");		//imprime la palabra desde la ultima posicion hasta la primera
	for(v = u;v>=0;v--){
	printf("%c",a[v]);}
	
printf("\n ¿Ahora que opción desea realizar?");	
}	
	
void concatenar(palabra *word)//une todas las palabras
{
	char concatenada[MAX_PALABRA]=" ";//crea cocatenada para concatenar todo en este vector
	strcat(concatenada,(word[0].w1));//concatena la primera palabra con el espacio
	strcat(concatenada,(word[1].w2));//concatena lo anterior con la segunda palabra 
	strcat(concatenada,(word[2].w3));//concatena lo anterior con la tercera palabra
	printf("Las palabras concatenadas : %s  ",concatenada);// imprime las palabras concatenadas
}

char longitud(palabra *word)//imprime las longitudes de cada palabra
{
	//creamos variables para guardar el tamaño de las palabras
	int tamano1=0;
	int tamano2=0;
	int tamano3=0;
	tamano1 = strlen(word[0].w1);//guardamos el tamaño de la palabra 1
	tamano2 = strlen(word[1].w2);//guardamos el tamaño de la palabra 2
	tamano3 = strlen(word[2].w3);//guardamos el tamaño de la palabra 3
	printf("\nLa longitud de la palabra 1 es: %d\n",tamano1);//imprime el tamaño de la palabra 1
	printf("\nLa longitud de la palabra 2 es: %d\n",tamano2);//imprime el tamaño de la palabra 2
	printf("\nLa longitud de la palabra 3 es: %d\n",tamano3);//imprime el tamaño de la palabra 3
} 

void sumdecimal(palabra *word)//suma las longitudes de las palabras
{
	char a[CANT_PALABRA];
	int u=0,v=0,x=0,p=0,y=0,q=0,z=0;	//creamos variables para el for y guardar las sumas decimales de cada palabra
	for (u=0 ; (a[u]=word[2].w3[u])!='\0' ; u++){	//palabra 3
		v=(a[u]=word[2].w3[u]);
		x=x+v;//va acumulando el valor de cada posicion y guarda en x
	}
	for (u=0 ; (a[u]=word[1].w2[u])!='\0' ; u++){	//palabra 2
		p=(a[u]=word[1].w2[u]);
		y=y+p;//va acumulando el valor de cada posicion y guarda en y
	}
	for (u=0 ; (a[u]=word[0].w1[u])!='\0' ; u++){	//palabra 1
		q=(a[u]=word[0].w1[u]);
		z=z+q;//va acumulando el valor de cada posicion y guarda en z
	}

	printf("\nLa suma decimal de la palabra 1 es: %d\n",z);//imprime la suma decimal de la palabra 3
	printf("\nLa suma decimal de la palabra 2 es: %d\n",y);//imprime la suma decimal de la palabra 2
	printf("\nLa suma decimal de la palabra 3 es: %d\n",x);//imprime la suma decimal de la palabra 1
	printf("\nLa suma decimal total es: %d\n",(x+y+z));//imprime la suma decimal de todas las palabras
}